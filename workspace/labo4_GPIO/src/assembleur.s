.section .text,"ax"
.cpu cortex-m3
.thumb
.syntax unified

.equ _FIO2DIR, 0x2009C040
.equ _FIO2SET, 0x2009C058
.equ _FIO2CLR, 0x2009C05C

.global exercice1

 /***********************************
 * function     : exercice1
 * arguments    : none
 * return value : none
 *   CONTROLE DE LEDs
 ***********************************/

.thumb_func
exercice1:
	// Initialisation de FIO2DIR
	LDR R0, =_FIO2DIR		// R0 contient l'adresse du registre FIO2DIR
	MOV R1, #0xFF			// P2.0 -> P2.7 en sortie
	STR R1, [R0]			// Ecriture dans le registre FIO2DIR
	//your code here
	ldr r0, =_FIO2SET
	ldr r1, =_FIO2CLR
	mov r2, #0xff
	str r2, [r1]
	mov r2, #0x01
	str r2, [r0]
	mov r2, #0x03
	str r2, [r0]
	mov r2, #0x01
	str r2, [r1]
	mov r2, #0x03
	str r2, [r1]

	mov	pc, r14		/* end of subroutine */



.weak exercice1
.ltorg
