
  
.include "/home/sreekanth/m328Pdef.inc"

Start:
	ldi r17, 0b11000011 ; identifying input pins 10,11,12,13
	out DDRB,r17		; declaring pins as input
	ldi r17, 0b11111111 ;
	out PORTB,r17		; activating internal pullup for pins 10,11,12,13  
	in r17,PINB
	
	ldi r20,0b00000010
	rcall loopr
	;21,22,23 and 24 are the inputs
	
	ldi r21,0b00000001
	and r21,r17 ;w
	lsr r17
	ldi r22,0b00000001
	and r22,r17 ;z
	lsr r17
	ldi r23,0b00000001
	and r23,r17 ;y
	lsr r17
	ldi r24,0b00000001
	and r24,r17 ;x

	ldi r25,0b00000001
	
    ldi r26,0b00000001 
	ldi r27,0b00000001 
    ldi r28,0b00000001 
	ldi r29,0b00000001
	
	;Mov all inputs to other registers
	mov r26,r21 ; w
    mov r27,r22 ; z
    mov r28,r23 ; y
    mov r29,r24 ; x
    
    ;Compliment all the inputs   
    eor r21, r25 ; w'
    eor r22, r25 ; z'
    eor r23, r25 ; y'
    eor r24, r25 ; x'
    
    ;First implicant : im1 = x'yzw'
    ;store first implicant in x' as we are not using it further
    
    and r24,r28
    and r24,r27
    and r24,r21
         
    ;Second implicant : im2 = xzw ; wxz
    ;store second implicant in w as we are not using it further
    
    and r26,r29
    and r26,r27
    
    ;Third implicant : im3 = xz'w' ;w'z'x
    ;store third implicant in w' as we are not using it further
    and r21,r22
    and r21,r29

    ;Fourther implicant : im4 = xy'
    ;store fourth implicant in x as we are not using it further
    and r29,r23
    
    ;Fifth implicant : im5 = y'z'
    ;store fifth implicant in y' as we are not using it further
    and  r23,r22
    
    ;Final implicant
    or r24,r26 ; im1+im2
    or r24,r21 ; im1+im2+im3
    or r24,r29 ; im1+im2+im3+im4
    or r24,r23 ; im1+im2+im3+im4+im5    
    
   

	ldi r20,0b00000010
	rcall loopl

	ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
	out DDRD,r16		;declaring pins as output
	out PORTD,r24		;writing output to pins 2,3,4,5
	

	rjmp Start

loopr:	lsr r17
	dec r20
	brne loopr
	ret

loopl:	lsl r24
	dec r20
	brne loopl
	ret
