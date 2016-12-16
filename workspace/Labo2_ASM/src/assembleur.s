
.section .text,"ax"
.cpu cortex-m3
.thumb
.syntax unified

.global funcexo1
.global funcexo2
.global funcexo3
.global funcexo4

/*****************************************************
 * function     : exercice1
 * arguments    : unsigned integer number: register R0
                : unsigned integer number: register R1
 * return value : unsigned integer result: register R0
 *   Code for the first exercise
 *****************************************************/
.thumb_func
funcexo1:
	subs r2, r0, r1
	bhi  funcexo1_next
	sub  r2, r1, r0
funcexo1_next:
    mov  r0, r2

	mov	pc, r14		/* same as: mov pc,lr // end of subroutine */


/*****************************************************
 * function     : exercice2
 * arguments    : unsigned integer number: register R0
 * return value : unsigned integer result: register R0
 *   Code for the second exercise
 *****************************************************/
.thumb_func
funcexo2:
	mov	  r1, #0
	mov	  r2, #1
funcexo2_loop:
	add   r1, r1, r2
	add   r2, r2, #1
	subs  r3, r0, r1
	bpl   funcexo2_loop
	mov   r0, r1

	mov	pc, r14		/* end of subroutine */



/*****************************************************
 * function     : exercice3 - Fibonacci
 * arguments    : unsigned integer number: register R0
 * return value : unsigned integer number: register R0
 *   Code for the third exercise
 *****************************************************/
.thumb_func
funcexo3:
	mov r1,#1
	mov r2,#0
	mov r3,#0
funcexo3_loop:
	add r1,r1,r2
	sub r2,r1,r2
	subs r4,r0,r3
	add r3,#1
	bpl funcexo3_loop
	mov r0,r1

	mov	pc, r14		/* end of subroutine */


/*****************************************************
 * function     : exercice4
 * arguments    : long long: register R1,R0
                : unsigned integer: register R2
 * return value : long long: register R1,R0
 *   Code for the fourth exercise
 *****************************************************/
.thumb_func
funcexo4:
	mov r3,#0
	mov r4,#1
	subs r5,r2,r3
	beq func4_left
	subs r5,r2,r4
	beq func4_right
	b end
func4_left:
//we move to the left the weak bits, and we take the carry
	lsls r0,#1
// we move to the left the strong bits and we add the carry from the weaks
	lsl r1,#1
	adc r1,r1,#0
b end
func4_right:
//to make sure that C is 0
	adds r3,r3,#0
//we shift right, updating the C with the rightmost bit
	rrxs r1,r1
//we rotate right, adding the carry to the left
	rrx r0,r0
b end
end:
	mov	pc, r14		/* end of subroutine */


.weak funcexo1, funcexo2, funcexo3, funcexo4
.ltorg
