;*******************************************************************************
; DISCLAIMER
; This software is supplied by Renesas Electronics Corporation and is only 
; intended for use with Renesas products. No other uses are authorized. This 
; software is owned by Renesas Electronics Corporation and is protected under
; all applicable laws, including copyright laws.
; THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
; THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
; LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
; AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
; TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
; ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
; FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
; ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
; BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
; Renesas reserves the right, without notice, to make changes to this software
; and to discontinue the availability of this software. By using this software,
; you agree to the additional terms and conditions found by accessing the 
; following link:
; http://www.renesas.com/disclaimer *
; Copyright (C) 2019 Renesas Electronics Corporation. All rights reserved.    
;******************************************************************************/
;*****************************************************************************
; History : DD.MM.YYYY Version  Description
;         : 20.06.2019 2.09     Added 1/IAR Compiler
;*****************************************************************************/






    .SECTION    .text._cksum
    .global     __cksum






__cksum:                           ; function: _cksum


	.stack      __cksum=4







	movu.w      r2, r2
	movu.w      r3, r3


	cmp         #0, r2
	beq         CKSUM_ZERO_EXIT

	btst	#0, r1
	beq	CKSUM_EVEN

;   data is odd


	add	#-1, r1
	movu.w	[r1+], r4
	revw	r3, r3

	revw	r4, r4

	and	#0ffH, r4

	revw	r4, r4

	add	r4, r3
	add	#-1, r2

	shlr	#3, r2, r15
	beq	CKSUM_ODD_NEXT4

cksum_loop1:
	movu.w	[r1+], r5
	movu.w	[r1+], r4
	add	r5, r3
	movu.w	[r1+], r5
	add	r4, r3
	movu.w	[r1+], r4
	add	r5, r3
	add	r4, r3
	sub	#1, r15
	bne	cksum_loop1

CKSUM_ODD_NEXT4:
	btst	#2, r2
	beq	CKSUM_ODD_NEXT2
	movu.w	[r1+], r5
	movu.w	[r1+], r4
	add	r5, r3
	add	r4, r3

CKSUM_ODD_NEXT2:
	btst	#1, r2
	beq	CKSUM_ODD_NEXT1
	movu.w	[r1+], r5
	add	r5, r3

CKSUM_ODD_NEXT1:
	btst	#0, r2
	beq	CKSUM_ODD_NBYTES_NOT_ODD
	movu.w	[r1], r5

	revw	r5, r5

	and	#0ff00H, r5

	revw	r5, r5

	add	r5, r3

CKSUM_ODD_NBYTES_NOT_ODD:
	mov.l	#0000ffffh, r4
	shlr	#16, r3, r5
	and	r4, r3
	add	r5, r3
	shlr	#16, r3, r5
	and	r4, r3
	add	r5, r3
	revw	r3, r1

	revw	r1, r1

	not	r1
	movu.w	r1, r1
	rts




CKSUM_EVEN:


	shlr	#3, r2, r15
	beq	CKSUM_EVEN_NEXT4

cksum_loop2:
	movu.w	[r1+], r5
	movu.w	[r1+], r4
	add	r5, r3
	movu.w	[r1+], r5
	add	r4, r3
	movu.w	[r1+], r4
	add	r5, r3
	add	r4, r3
	sub	#1, r15
	bne	cksum_loop2

CKSUM_EVEN_NEXT4:
	btst	#2, r2
	beq	CKSUM_EVEN_NEXT2
	movu.w	[r1+], r5
	movu.w	[r1+], r4
	add	r5, r3
	add	r4, r3

CKSUM_EVEN_NEXT2:
	btst	#1, r2
	beq	CKSUM_EVEN_NEXT1
	movu.w	[r1+], r5
	add	r5, r3

CKSUM_EVEN_NEXT1:
	btst	#0, r2
	beq	CKSUM_EVEN_NBYTES_NOT_ODD
	movu.w	[r1], r5

	revw	r5, r5

	and	#0ff00H, r5

	revw	r5, r5

	add	r5, r3

CKSUM_EVEN_NBYTES_NOT_ODD:
	mov.l	#0000ffffh, r4
	shlr	#16, r3, r5
	and	r4, r3
	add	r5, r3
	shlr	#16, r3, r5
	and	r4, r3
	add	r5, r3

CKSUM_EXIT:

	revw	r3, r3

	not	r3
	movu.w	r3, r1
	rts

CKSUM_ZERO_EXIT:

	revw	r3, r3

	not	r3, r1
	movu.w	r1, r1
	rts




	.end
