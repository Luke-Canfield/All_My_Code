// Lab 3 template file
.data

.global login_name
login_name:
    .asciz "lcanfiel"

.global puid
puid:
    .asciz "0032342067"

.balign 4

.equ TEST_SORT,         0x1
.equ TEST_STRCONCAT,    0x2
.equ TEST_FIB,          0x4
.equ TEST_BSEARCH,      0x8
.equ TEST_ALL,          (TEST_SORT | TEST_STRCONCAT | TEST_FIB | TEST_BSEARCH)

// Replace the TEST_ALL with the tests you want to run
// OR expression also support like the TEST_ALL above
// i.e. replace the TEST_ALL below with TEST_SORT | TEST_STRCONCAT
//      will test on the sort and strconcat
.global test
test:
    .word TEST_ALL


// Align to 4bytes boundary as we have a string above
.balign 4

.text
.global asm_sort_int
asm_sort_int:
    /* void asm_sort_int(int64_t* arr, uint64_t n)
     * relies on `qsort` in C standard library to 
     * sort in ascending order
     **/

    /* Enter your code after this comment */
    //ldr x5, =asm_sort_int
    ldr x3, =asm_cmp
    mov x19, lr
    mov x2, #8
	bl qsort
	mov lr, x19

    /* Enter your code above this comment */
    ret

.global asm_cmp
asm_cmp:
    // int asm_cmp(const void * a, const void * b)
    // Compare function to int64_t
    // used for qsort
    /* Enter your code after this comment */
	mov x4, #0
	ldr x2, [x0]
	ldr x3, [x1]
	sub x5, x2, x3
	cmp x5, x4
	b.lt _end1
	mov x0, #1
	ret

	_end1:
		mov x0, #-1
		ret
    /* Enter your code above this comment */
    ret

.global asm_strconcat
asm_strconcat:
    /* char* asm_strconcat(char * str1, char * str2)
     * First assign memory space with `malloc`, 
     * concatenating `str1` and `str2`, 
     * and return the resulted string.
     **/
    /* Enter your code after this comment */
	mov x19, lr
	mov x26, x0 //str1
	mov x21, x1 //str2
	bl strlen
	mov x20, x0 //contains length str1
	mov x0, x21 //contains str2
	bl strlen
	mov x22, x0 //contains length str2
	mov x23, #1 //size of char
	add x24, x20, x22
	add x24, x24, x23 //int size
	mov x0, x23
	mov x1, x24
	bl malloc
	mov x28, x0 // buf
	mov x1, x26 //str1
	mov x2, x20 //n1
	bl memcpy
	add x0, x28, x20
	mov x1, x21
	mov x2, x22
	bl memcpy
	sub x24, x24, x23
	mov w29, #0
	strb w29, [x28, x24]
	mov lr, x19
	mov x0, x28
    /* Enter your code above this comment */
    ret

.global asm_fib
asm_fib:
    /* uint64_t asm_fib(uint64_t n)
     * accept an index term `n` and return 
     * the Fn fibonacci term (F0 = 0, F1 = 1)
     **/

    /* Enter your code after this comment */
	//ldr x19, =asm_fib
	sub sp, sp, #32
	stur lr, [sp,#8]
	stur x0, [sp,#0]

	cmp x0, #2
	b.lt _if
	mov x22, x0
	sub x20, x0, #1  //n - 1
	mov x0, x20
	bl asm_fib
	stur x0, [sp,#16]
	ldur x0, [sp,#0]
	sub x21, x0, #2 //n - 2
	mov x0, x21
	bl asm_fib
	mov x24, x0      //asm_fib(n - 2)
	ldur x0, [sp,#16]
	add x0, x24, x0
	ldur lr, [sp,#8]
	add sp, sp, #32
	ret

	_if:
		add sp, sp, #32
		ret
    /* Enter your code above this comment */
    ret

.global asm_bsearch
asm_bsearch:
    /* int64_t asm_bsearch(int *arr, int key, 
                    int64_t start,
                    int64_t end)
     * Return the index of the element in the array
     * if the element does not exist, return -1 instead
     * arr: integer array to be searched
     * key: the element we want to search on
     * start: start index of subarray, inclusive
     * end: end index of subarray, inclusiveloop through an entire string and only convert
     **/

    /* Enter your code after this comment */

    /* Enter your code above this comment */
    ret
