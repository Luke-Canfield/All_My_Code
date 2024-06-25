// Lab 2 template file
.data
.global lowercase_string
lowercase_string:
    // Specify a string ending with '\0'
    .asciz "hello\0"

.global login_name
login_name:
    .asciz "lcanfiel"

.global puid
puid:
    .asciz "0032342067"

// Align to 4bytes boundary as we have a string above
.balign 4

.text
.global asm_strlen
asm_strlen:
    /* uint64_t asm_strlen(char *str)
     * Take in a pointer to a string and return
     * its length up to the null terminating
     * character `\0`
     **/

    /* Enter your code after this comment */
	mov x2, #0 //counter
	cmp x0, #0
	b.eq _while_end

	_while:
		ldrb w3, [x0]
		cmp x3, #0
		b.eq _while_end
		add x0, x0, #1 //shifts pointer
		add x2, x2, #1 //increments counter
		b _while

	_while_end:
		mov x0, x2
		ret

    /* Enter your code above this comment */
    ret

.global asm_fib
asm_fib:
    /* void asm_fib(int *arr, uint64_t length)
     * Accept a pointer to an array of integer and
     * the length of the array, then generate fibonacci
     * series starting at `0` and store the result
     * back to the array `arr` at corresponding indices.
     **/

    /* Enter your code after this comment */

	//x0 is arr
	//x1 is length of array

	cmp x0, #0
	b.eq _for_end
	cmp x1, #0
	b.eq _for_end

	mov x2, #0 //prev
	mov x3, #1 //curr
	mov x4, #0 //i variable
	mov x5, #0 //temp variable

	_for:
		cmp x4, x1
		b.ge _for_end

		cmp x4, #0
		b.eq _for_if

		cmp x4, #1
		b.eq _for_else_if

		mov x5, x3       		//temp = curr
		add x3, x3, x2   		//curr = curr + prev
		mov x2, x5       		//prev = temp
		str w3, [x0, x4, lsl#2]  //arr[i] = curr
		add x4, x4, #1
		b _for

	_for_if:
		str w2, [x0, x4, lsl#2]
		add x4, x4, #1
		b _for

	_for_else_if:
		str w3, [x0, x4, lsl#2]
		add x4, x4, #1
		b _for

	_for_end:
		ret
    /* Enter your code above this comment */
    ret

.global asm_toUppercase
asm_toUppercase:
    /* void asm_toUppercase(char *str)
     * loop through an entire string and only convert
     * the lowercase letter to uppercase, leaving the
     * rest of the string intact
     **/

    /* Enter your code after this comment */
	cmp x0, #0
	b.eq _while_end_2
	//mov x1, #0 //temp var to hold char value

	_while_2:
		ldrb w3, [x0]
		cmp w3, #0
		b.eq _while_end_2

		//ldrb w1, [x0]
		cmp w3, #97
		b.lt _while_str
		cmp w3, #122
		b.gt _while_str
		sub x3, x3, #32  //*str = c - 32
		strb w3, [x0]
		add x0, x0, #1  //shifts pointer
		b _while_2

	_while_str:
		add x0, x0, #1  //shifts pointer
		b _while_2

	_while_end_2:
		ret
    /* Enter your code above this comment */
    ret
