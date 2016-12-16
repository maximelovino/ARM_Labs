
.section .text,"ax"
.cpu cortex-m3
.thumb
.syntax unified

.global funcexo1
.global funcexo2
.global add_struct


/*****************************************************
 * function     : exercice1
 * arguments    : pointer valA : register R0
                : pointer valB : register R1
 * return value : unsigned integer result: register R0
 *   Code for the first exercise
 *****************************************************/
.thumb_func
funcexo1:
	ldr r0, [r0]
	ldr r1, [r1]
	adds r0,r1,r0
	bcs withcarry
	b end
withcarry:
	mov r0, #0
end:
	mov	pc, lr		/* end of subroutine */


/*****************************************************
 * function     : exercice2
 * arguments    : pointer tabA: register R0
 				  pointer tabB: register R1
 * return value : error result code: register R0
 *   Code for the second exercise
 *****************************************************/
.thumb_func
funcexo2:
	mov r2, #9
funcexo2loop:
	ldr r3,[r0]
	adds r3,r3,r3
	bcs error
	str r3,[r1]
	add r0,r0,#4
	add r1,r1,#4
	subs r2,r2,#1
	bge funcexo2loop
	b good
error:
	mov r0,#0
	b endfunc2
good:
	mov r0,#1
	b endfunc2
endfunc2:
	mov	pc, lr		/* end of subroutine */



/*****************************************************
 * function     : add_sat

  --> paramètres à commenter
 *****************************************************/
.thumb_func
add_struct:
	//we have to keep the sign of the 8 bit d
	lsl r2,#24
	asr r2,#24
	//we add r0,r2 and r3, so we can reuse r2,r3
	add r0,r0,r2
	add r0,r0,r3
	//b and c are in r1, we have to take part of the 32 bits
	mov r2,r1
	//asr to keep the sign
	asr r2,#16
	//r2 contains c now
	add r0,r0,r2
	mov r2,r1
	//we shift left to remove c, and asr to keep sign of b
	lsl r2,#16
	asr r2,#16
	add r0,r0,r2
	mov	  pc, lr    /* end of subroutine */


.weak funcexo1, funcexo2
.ltorg
