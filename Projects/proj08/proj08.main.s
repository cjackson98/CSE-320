@ Name: Chris Jackson
@ Project 08
@ 10/30/18
@ ARM Assembly program that classifies each character in an input stream, and then produces a summary about that input stream. 

			.global main
			.text
main:
			push {lr}
			mov	r4, #0													@ Initialize total number of characters
			mov	r5, #0													@ Initialize number of newline characters
			mov	r6, #0													@ Initialize number of whitespace characters (blanks, tabs and newlines)
			mov	r7, #0													@ Initialize number of octal digits (in the set {0-7})
			mov	r8, #0													@ Initialize number of decimal digits (in the set {0-9})
			mov	r9, #0													@ Initialize number of hexadecimal digits (in the set {0-9, A-F, a-f})
			mov	r10, #0													@ Initialize number of letters (in the set {A-Z, a-z})
loop:
			bl getchar													@ Read one character (returned in r0)
			cmp r0, #-1													@ Compare to EOF
			beq end														@ End loop if equal to EOF
			bl putchar													@ Write character to standard output stream
			add r4, r4, #1												@ Increment character count
			

ifNewline:
			cmp r0, #0x0a												@ Compare to newline (#0x0a)
			bne endNewline												@ If not equal, end if statement
thenNewline:
			add r5, r5, #1												@ Increment newline count
endNewline:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If equal to EOF, end loop



ifWhitespace1:
			cmp r0, #0x20												@ Compare to blank (#0x20)
			bne endWhitespace1											@ If not equal, end if statement
thenWhitespace1:
			add r6, r6, #1												@ Increment whitespace count
endWhitespace1:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If euqal to EOF, end if statement



ifWhitespace2:
			cmp r0, #0x09												@ Compare with tab (#0x09)
			bne endWhitespace2											@ If not equal, end if statement
thenWhitespace2:
			add r6, r6, #1												@ Increment whitespace count
endWhitespace2:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If euqal to EOF, end if statement



ifOctal:
			cmp r0, #'0'												@ Compare to '0'
			blt endOctal												@ If less than 0, end if statement
			cmp r0, #'7'												@ Compare to '7'
			bgt endOctal												@ If greater than 7, end if statement
thenOctal:
			add r7, r7, #1												@ Increment octal count
endOctal:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If euqal to EOF, end if statement



ifDecimal:
			cmp r0, #'0'												@ Compare to '0'
			blt endDecimal												@ If less than 0, end if statement
			cmp r0, #'9'												@ Compare to '9'
			bgt endDecimal												@ If greater than 9, end if statement
thenDecimal:
			add r8, r8, #1												@ Increment decimal count
			add r9, r9, #1												@ Increment hex count (all decimal values are valid hex values {0-9})
endDecimal:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If euqal to EOF, end if statement
	
	
			
ifHex1:
			cmp r0, #'a'												@ Compare to 'a'
			blt endHex1													@ If less than a, end if statement
			cmp r0, #'f'												@ Compare to 'f'
			bgt endHex1													@ If greater than f, end if statement
thenHex1:
			add r9, r9, #1												@ Increment hex count
endHex1:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If equal to EOF, end if statement



ifHex2:
			cmp r0, #'A'												@ Compare to 'A'
			blt endHex2													@ If less than A, end if statement
			cmp r0, #'F'												@ Compare to 'F'
			bgt endHex2													@ If greater than F, end if statement
thenHex2:
			add r9, r9, #1												@ Increment hex count
endHex2:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If euqal to EOF, end if statement



ifLetter1:
			cmp r0, #'a'												@ Compare to 'a'
			blt endLetter1												@ If less than a, end if statement
			cmp r0, #'z'												@ Compare to 'f'
			bgt endLetter1												@ If greater than f, end if statement
thenLetter1:
			add r10, r10, #1											@ Increment letter count
endLetter1:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If euqal to EOF, end if statement
	
	
	
ifLetter2:
			cmp r0, #'A'												@ Compare to 'A'
			blt endLetter2												@ If less than A, end if statement
			cmp r0, #'Z'												@ Compare to 'F'
			bgt endLetter2												@ If greater than F, end if statement
thenLetter2:
			add r10, r10, #1											@ Increment letter count
endLetter2:
			cmp r0, #-1													@ Compare with EOF
			beq end														@ If euqal to EOF, end if statement

			b loop														@ Return to start of loop



end:
		ldr r0, =fmt1													@ First arg -- address of first format string
		mov r1, r4														@ Second arg -- Character count
		bl printf														@ Display the count
		
		ldr r0, =fmt2													@ First arg -- address of second format string
		mov r1, r5														@ Second arg -- Newline count
		bl printf														@ Display the count
		
		ldr r0, =fmt3													@ First arg -- address of third format string
		mov r1, r6														@ Second arg -- Whitespace count
		bl printf														@ Display the count
		
		ldr r0, =fmt4													@ First arg -- address of fourth format string
		mov r1, r7														@ Second arg -- Octal count
		bl printf														@ Display the count
		
		ldr r0, =fmt5													@ First arg -- address of fifth format string
		mov r1, r8														@ Second arg -- Decimal count
		bl printf														@ Display the count
		
		ldr r0, =fmt6													@ First arg -- address of sixth format string
		mov r1, r9														@ Second arg -- Hexadecimal count
		bl printf														@ Display the count
		
		ldr r0, =fmt7													@ First arg -- address of seventh format string
		mov r1, r10														@ Second arg -- Letter count
		bl printf														@ Display the count
		
		pop {lr}
		bx lr



fmt1: .asciz "\nThe file has %d total characters.\n"
fmt2: .asciz "The file has %d newlines characters.\n"
fmt3: .asciz "The file has %d whitespaces characters.\n"
fmt4: .asciz "The file has %d octal characters.\n"
fmt5: .asciz "The file has %d decimal characters.\n"
fmt6: .asciz "The file has %d hexadecimal characters.\n"
fmt7: .asciz "The file has %d letters.\n"
