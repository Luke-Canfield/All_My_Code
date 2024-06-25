/**
  ******************************************************************************
  * @file    main.c
  * @author  Weili An
  * @version V1.0
  * @date    Nov 4, 2022
  * @brief   ECE 362 Lab 9 Student template
  ******************************************************************************
*/

#include "stm32f0xx.h"
#include <math.h>   // for M_PI

void nano_wait(int);

// 16-bits per digit.
// The most significant 8 bits are the digit number.
// The least significant 8 bits are the segments to illuminate.
uint16_t msg[8] = { 0x0000,0x0100,0x0200,0x0300,0x0400,0x0500,0x0600,0x0700 };
extern const char font[];
// Print an 8-character string on the 8 digits
void print(const char str[]);
// Print a floating-point value.
void printfloat(float f);


//============================================================================
// Lab 9 Functions
//============================================================================
void setup_tim3(void) {
    // TODO: Enable GPIO C
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

    // TODO: Configure the PC6-9 to be the outputs of TIM3 Ch 1-4
    // TODO: First we clear their MODER bits
    // TODO: Then we set them to AF mode
    GPIOC->MODER &= ~GPIO_MODER_MODER6;
    GPIOC->MODER &= ~GPIO_MODER_MODER7;
    GPIOC->MODER &= ~GPIO_MODER_MODER8;
    GPIOC->MODER &= ~GPIO_MODER_MODER9;
    GPIOC->MODER |= 0xAA000;

    // TODO: Set PC6-9 to use AF0 since this corresponds to the TIM3 Ch1-4
    // AFR[0] -> AFRL
    // AFR[1] -> AFRH
    GPIOC->AFR[0] &= ~(GPIO_AFRL_AFR6 | GPIO_AFRL_AFR7);
    GPIOC->AFR[1] &= ~(GPIO_AFRH_AFR8 | GPIO_AFRH_AFR9);

    // TODO: Enable TIM3 with 1 Hz timer
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->PSC = 48000-1;
    TIM3->ARR = 1000-1;

    // TODO: Set to PWM mode 1 for all channels
    // Can use the following code to set a channel to PWM mode 1 (110)
    // This line set Timer x's channel 1 to be PWM mode 1 (OC1M bits with 110)
    // TIMx->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;
    TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
    TIM3->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2;

    // TODO: Enable all 4 channel outputs in `TIM3_CCER` using `CC1E` bit
    TIM3->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E;

    // TODO: Enable TIM3 counter
    TIM3->CR1 |= TIM_CR1_CEN;

    // TODO: Set CCR values
    TIM3->CCR1 = 800;
    TIM3->CCR2 = 400;
    TIM3->CCR3 = 200;
    TIM3->CCR4 = 100;
}

void setup_tim1(void) {
    // Generally the steps are similar to those in setup_tim3
    // However, we will need to set the MOE bit in BDTR
    //Activate RCC clock for Port A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    //Configure pins to alternate function
    GPIOA->MODER &= ~GPIO_MODER_MODER8;
    GPIOA->MODER &= ~GPIO_MODER_MODER9;
    GPIOA->MODER &= ~GPIO_MODER_MODER10;
    GPIOA->MODER &= ~GPIO_MODER_MODER11;
    GPIOA->MODER |= 0xAA0000;

    //Route timer function to external pins with AFR[1]
    GPIOA->AFR[1] &= ~(GPIO_AFRH_AFR8 | GPIO_AFRH_AFR9 | GPIO_AFRH_AFR10 | GPIO_AFRH_AFR11);
    GPIOA->AFR[1] |= 0x02222;

    //Activate RCC clock for Timer 1
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    // Enable MOE bit in BDTR
    TIM1->BDTR |= TIM_BDTR_MOE;

    //Set prescaler to divide by 1 & 20000 Hz
    TIM1->PSC = 0;
    TIM1->ARR = 2400-1;

    //Set channels 1,2,3,4 for PWM mode 1
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
    TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2;

    //Set "output compare preload enable" bit for CCMR2
    TIM1->CCMR2 |= TIM_CCMR2_OC4PE;

    //Enable uninverted channels for all four channels
    TIM1->CCER |= (TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E);

    //Enable timer
    TIM1->CR1 |= TIM_CR1_CEN;
}

int getrgb(void);

// Helper function for you
// Accept a byte in BCD format and convert it to decimal
uint8_t bcd2dec(uint8_t bcd) {
    // Lower digit
    uint8_t dec = bcd & 0xF;

    // Higher digit
    dec += 10 * (bcd >> 4);
    return dec;
}

void setrgb(int rgb) {
    uint8_t b = bcd2dec(rgb & 0xFF);
    uint8_t g = bcd2dec((rgb >> 8) & 0xFF);
    uint8_t r = bcd2dec((rgb >> 16) & 0xFF);

    // TODO: Assign values to TIM1->CCRx registers
    // Remember these are all percentage
    // Also LEDs are on when the corresponding PWM output is low
    // so you might want to invert some numbers
    TIM1->CCR1 = ((100 - r) / 100) *2400;
    TIM1->CCR2 = ((100 - g) / 100) *2400;
    TIM1->CCR3 = ((100 - b) / 100) *2400;

}

//============================================================================
// Lab 9 Functions end, rest are just copying your previous lab code
//============================================================================


//============================================================================
// enable_ports()
//============================================================================
void enable_ports(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    GPIOB->MODER &= ~GPIO_MODER_MODER0;
    GPIOB->MODER &= ~GPIO_MODER_MODER1;
    GPIOB->MODER &= ~GPIO_MODER_MODER2;
    GPIOB->MODER &= ~GPIO_MODER_MODER3;
    GPIOB->MODER &= ~GPIO_MODER_MODER4;
    GPIOB->MODER &= ~GPIO_MODER_MODER5;
    GPIOB->MODER &= ~GPIO_MODER_MODER6;
    GPIOB->MODER &= ~GPIO_MODER_MODER7;
    GPIOB->MODER &= ~GPIO_MODER_MODER8;
    GPIOB->MODER &= ~GPIO_MODER_MODER9;
    GPIOB->MODER &= ~GPIO_MODER_MODER10;
    GPIOB->MODER |= 0x155555;

    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR0;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR1;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR2;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR3;
    GPIOC->PUPDR |= 0x55;

    GPIOC->OTYPER &= ~GPIO_OTYPER_OT_4;
    GPIOC->OTYPER &= ~GPIO_OTYPER_OT_5;
    GPIOC->OTYPER &= ~GPIO_OTYPER_OT_6;
    GPIOC->OTYPER &= ~GPIO_OTYPER_OT_7;
    GPIOC->OTYPER |= 0xF0;

    GPIOC->MODER &= ~GPIO_MODER_MODER0;
    GPIOC->MODER &= ~GPIO_MODER_MODER1;
    GPIOC->MODER &= ~GPIO_MODER_MODER2;
    GPIOC->MODER &= ~GPIO_MODER_MODER3;
    GPIOC->MODER &= ~GPIO_MODER_MODER4;
    GPIOC->MODER &= ~GPIO_MODER_MODER5;
    GPIOC->MODER &= ~GPIO_MODER_MODER6;
    GPIOC->MODER &= ~GPIO_MODER_MODER7;
    GPIOC->MODER |= 0x5500;
}

//============================================================================
// setup_dma()
//============================================================================
void setup_dma(void) {
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;
    DMA1_Channel5->CCR &= ~DMA_CCR_EN;
    DMA1_Channel5->CPAR = &(GPIOB->ODR);
    DMA1_Channel5->CMAR = msg;
    DMA1_Channel5->CNDTR = 8;
    DMA1_Channel5->CCR |= DMA_CCR_DIR;
    DMA1_Channel5->CCR |= DMA_CCR_MINC;
    DMA1_Channel5->CCR |= DMA_CCR_MSIZE_0;
    DMA1_Channel5->CCR |= DMA_CCR_PSIZE_0;
    DMA1_Channel5->CCR |= DMA_CCR_CIRC;
}

//============================================================================
// enable_dma()
//============================================================================
void enable_dma(void) {
    DMA1_Channel5->CCR |= DMA_CCR_EN;
}

//============================================================================
// init_tim15()
//============================================================================
void init_tim15(void) {
    RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;
    TIM15->PSC = 4800-1;
    TIM15->ARR = 10-1;
    TIM15->DIER |= TIM_DIER_UDE;
    TIM15->CR1 |= TIM_CR1_CEN;
}

uint8_t col; // the column being scanned

void drive_column(int);   // energize one of the column outputs
int  read_rows();         // read the four row inputs
void update_history(int col, int rows); // record the buttons of the driven column
char get_key_event(void); // wait for a button event (press or release)
char get_keypress(void);  // wait for only a button press event.
float getfloat(void);     // read a floating-point number from keypad
void show_keys(void);     // demonstrate get_key_event()

//============================================================================
// The Timer 7 ISR
//============================================================================
// TODO To be copied
void TIM7_IRQHandler() {
    TIM7->SR &= ~TIM_SR_UIF;
    int rows = read_rows();
    update_history(col, rows);
    col = (col + 1) & 3;
    drive_column(col);
}

//============================================================================
// init_tim7()
//============================================================================
void init_tim7(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
    TIM7->PSC = 4800-1;
    TIM7->ARR = 10-1;
    TIM7->DIER |= TIM_DIER_UIE;
    TIM7->CR1 |= TIM_CR1_CEN;
    NVIC->ISER[0] |= (1<<TIM7_IRQn);
}

//=============================================================================
// Part 3: Analog-to-digital conversion for a volume level.
//=============================================================================
uint32_t volume = 2400;

//============================================================================
// setup_adc()
//============================================================================
void setup_adc(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER1;
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    RCC->CR2 |= RCC_CR2_HSI14ON;
    while(!(RCC->CR2 & RCC_CR2_HSI14RDY));
    ADC1->CR |= ADC_CR_ADEN;
    while(!(ADC1->ISR & ADC_ISR_ADRDY));
    ADC1->CHSELR = 0;
    ADC1->CHSELR |= ADC_CHSELR_CHSEL1;
    while(!(ADC1->ISR & ADC_ISR_ADRDY));
}

//============================================================================
// Varables for boxcar averaging.
//============================================================================
#define BCSIZE 32
int bcsum = 0;
int boxcar[BCSIZE];
int bcn = 0;

//============================================================================
// Timer 2 ISR
//============================================================================
// TODO To be copied
void TIM2_IRQHandler() {
    TIM2->SR &= ~TIM_SR_UIF;
    ADC1->CR |= ADC_CR_ADSTART;
    while(!(ADC1->ISR & ADC_ISR_EOC));
    bcsum -= boxcar[bcn];
    bcsum += boxcar[bcn] = ADC1->DR;
    bcn += 1;
    if (bcn >= BCSIZE)
        bcn = 0;
    volume = bcsum / BCSIZE;
}

//============================================================================
// init_tim2()
//============================================================================
void init_tim2(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    TIM2->PSC = 4800-1;
    TIM2->ARR = 1000-1;
    TIM2->DIER |= TIM_DIER_UIE;
    TIM2->CR1 |= TIM_CR1_CEN;
    NVIC->ISER[0] |= (1<<TIM2_IRQn);
}


//===========================================================================
// Part 4: Create an analog sine wave of a specified frequency
//===========================================================================
void dialer(void);

// Parameters for the wavetable size and expected synthesis rate.
#define N 1000
#define RATE 20000
short int wavetable[N];
int step0 = 0;
int offset0 = 0;
int step1 = 0;
int offset1 = 0;

//===========================================================================
// init_wavetable()
// Write the pattern for a complete cycle of a sine wave into the
// wavetable[] array.
//===========================================================================
void init_wavetable(void) {
    for(int i=0; i < N; i++)
        wavetable[i] = 32767 * sin(2 * M_PI * i / N);
}

//============================================================================
// set_freq()
//============================================================================
void set_freq(int chan, float f) {
    if (chan == 0) {
        if (f == 0.0) {
            step0 = 0;
            offset0 = 0;
        } else
            step0 = (f * N / RATE) * (1<<16);
    }
    if (chan == 1) {
        if (f == 0.0) {
            step1 = 0;
            offset1 = 0;
        } else
            step1 = (f * N / RATE) * (1<<16);
    }
}

//============================================================================
// setup_dac()
//============================================================================
void setup_dac(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER4;
    RCC->APB1ENR |= RCC_APB1ENR_DACEN;
    DAC->CR &= ~DAC_CR_TSEL1;
    DAC->CR |= DAC_CR_TEN1;
    DAC->CR |= DAC_CR_EN1;
}

//============================================================================
// Timer 6 ISR
//============================================================================
// TODO To be copied
void TIM6_DAC_IRQHandler() {
    TIM6->SR &= ~TIM_SR_UIF;
    offset0 += step0;
    offset1 += step1;
    if (offset0 >= (N << 16))
        offset0 -= (N << 16);
    if (offset1 >= (N << 16))
        offset1 -= (N << 16);
    int samp = wavetable[offset0>>16] + wavetable[offset1>>16];
    samp = samp * volume;
    samp = samp >> 18;
    samp += 1200;
    TIM1->CCR4 = samp;
}

//============================================================================
// init_tim6()
//============================================================================
void init_tim6(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
    TIM6->PSC = 240-1;
    TIM6->ARR = 10-1;
    TIM6->DIER |= TIM_DIER_UIE;
    //TIM6->CR2 |= 0b0100000;
    TIM6->CR1 |= TIM_CR1_CEN;
    NVIC->ISER[0] |= (1<<TIM6_DAC_IRQn);
}

//============================================================================
// All the things you need to test your subroutines.
//============================================================================
int main(void) {

    // Demonstrate part 1
//#define TEST_TIMER3
#ifdef TEST_TIMER3
    setup_tim3();
    for(;;) { }
#endif

    // Initialize the display to something interesting to get started.
    msg[0] |= font['E'];
    msg[1] |= font['C'];
    msg[2] |= font['E'];
    msg[3] |= font[' '];
    msg[4] |= font['3'];
    msg[5] |= font['6'];
    msg[6] |= font['2'];
    msg[7] |= font[' '];

    enable_ports();
    setup_dma();
    enable_dma();
    init_tim15();
    init_tim7();
    setup_adc();
    init_tim2();
    init_wavetable();
    init_tim6();

    setup_tim1();

    // demonstrate part 2
//#define TEST_TIM1
#ifdef TEST_TIM1
    for(;;) {
        for(float x=10; x<2400; x *= 1.1) {
            TIM1->CCR1 = TIM1->CCR2 = TIM1->CCR3 = 2400-x;
            nano_wait(100000000);
        }
    }
#endif

    // demonstrate part 3
#define MIX_TONES
#ifdef MIX_TONES
    set_freq(0, 1000);
    for(;;) {
        char key = get_keypress();
        if (key == 'A')
            set_freq(0,getfloat());
        if (key == 'B')
            set_freq(1,getfloat());
    }
#endif

    // demonstrate part 4
//#define TEST_SETRGB
#ifdef TEST_SETRGB
    for(;;) {
        char key = get_keypress();
        if (key == 'A')
            set_freq(0,getfloat());
        if (key == 'B')
            set_freq(1,getfloat());
        if (key == 'D')
            setrgb(getrgb());
    }
#endif

    // Have fun.
    dialer();
}
