import machine, neopixel
from time import sleep
from machine import Pin

Neo_Power = Pin(2, Pin.OUT) #creates output pin
Neo_Power.value(1) #set to 1

User_Input = Pin(38, Pin.IN)

Neo_Pixel = neopixel.NeoPixel(machine.Pin(0), 1) #creates output pin
Neo_Pixel[0] = (255, 0, 0) #sets to red
Neo_Pixel.write() #outputs colors to LED

count = 0

while(count < 5): 
    if(User_Input.value() == 0):
        Neo_Pixel[0] = (0, 255, 0)
        Neo_Pixel.write()
        count += 1
        sleep(0.5)
    else:
        Neo_Pixel[0] = (255, 0, 0)
        Neo_Pixel.write()

Neo_Power.value(0)
print("You have successfully implemented LAB1!")
        
    