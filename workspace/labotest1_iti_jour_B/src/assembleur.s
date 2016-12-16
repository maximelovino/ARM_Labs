.section .text,"ax"
.cpu cortex-m3
.thumb
.syntax unified

.global funcexo1
/*****************************************************
 * function     : exercice1
 * arguments    : register R0, input char sequence
 * return       : register R0, int32_t number
 *   Code for the first exercise
 *****************************************************/
.thumb_func
funcexo1:
	push {r4}
	// pushed here when called from funcexo2, could do cleaner by pushing in funcexo2
	push {r1}
	push {r2}
	push {r3}
	mov r3,#0
	//we read the current character
	reading:
		ldr r1, [r0]
		lsl r1,r1, #24
		lsr r1,r1, #24
		//comparison with 9, if it's less than the 9, we continue
		subs r2,r1,#0x39
		ble secondcheck
		b end
	secondcheck:
	//comparison with 0, if it's bigger, we continue
		subs r2,r1,#0x30
		bge good
		b end
	good:
		//r2 already equal to r2 - 48, so in r2 we already have the int value
		//here we multiply what exists already by 10, and we add the int value of the current char
		mov r1, #10
		mov r4,r3
		mul r3, r4, r1
		add r3,r3,r2
		add r0,r0,#1
		b reading
	end:
	mov r0,r3
	//repopping from stack for funcexo2
	pop {r3}
	pop {r2}
	pop {r1}
	pop {r4}
	mov	pc, r14	   /* end of subroutine */

.global funcexo2
/*****************************************************
 * function     : exercice2
 * arguments    : register R0, input char sequence of number 1
 *              : register R1, input char sequence of number 2
 *              : register R2, char representing the operation
 * return       : register R0, int32_t result of expression
 *   Code for the second exercise
 *****************************************************/
.thumb_func
funcexo2:
	//we store lr before calling funcexo1 on first param r0
	sub sp,#4
	str lr,[sp]
	bl funcexo1
	ldr lr,[sp]
	//we put the value of the first param in r3
	mov r3, r0
	//we call funcexo1 with second param, result will be in r0
	mov r0, r1
	str lr,[sp]
	bl funcexo1
	ldr lr,[sp]
	add sp,[4]
	//if operand is + (43) we add, otherwise we sub
	cmp r2,#43
	beq plusex2
	b minusex2
	plusex2:
		add r0,r0,r3
		b endfunc2
	minusex2:
		sub r0,r3,r0
		b endfunc2
	endfunc2:
		mov	pc, r14	   /* end of subroutine */


.weak funcexo1,funcexo2
.ltorg
