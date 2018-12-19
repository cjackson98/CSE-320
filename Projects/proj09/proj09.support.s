@ Name: Chris Jackson
@ Project 9
@ 11/6/18
@ A set of ARM assembly language functions which implement common mathematical operations.
			.global negate
			.global absolute
			.global add
			.global sub
			.global mul
			.global divide
			.global zero
			.global power
			.global factorial
			.global overflow
			.text

negate:																	@ Function "negate" will return the negation of N.
			push {r4, r5, r6, lr}
						
			mov r6, #0													@ Set register 6 value to -1
			mov r4, r0													@ Set register 4 value to first parameter passed to function
			
			cmp r4, #0x80000000
			beq overflow
			
			@ mul r5, r4, r6											@ Multiply parameter by -1 (to negate)
			
			subs r5, r6, r4												@ Professor McCullen advised against multiplying by -1 because it is inneficient

			mov r0, r5													@ Move result into register 0 (return register)
						
			pop {r4, r5, r6, lr}
			bx lr



absolute:																@ Function "absolute" will return the absolute value of N.
			push {r4, r5, r6, lr}
			mov r6, #0													@ Set register 6 value to -1
			mov r4, r0													@ Set register 4 value to first parameter passed to function
			
			cmp r4, #0x80000000
			beq overflow
			
			cmp r4, #0													@ Compare value to 0
			bge endabsolute												@ If value is positive or - (greater than or equal to 0) no calculation is needed. Move value into return register (register 0)
			
			subs r5, r6, r4												@ Professor McCullen advised against multiplying by -1 because it is inneficient
			
			@ mul r5, r4, r6											@ Otherwise, multiply value by -1 to get the positive equivilant
			mov r0, r5													@ Move result into register 0 (return register)
endabsolute:
			pop {r4, r5, r6, lr}
			bx lr



add:																	@ Function "add" will return the sum of A and B.
			push {r4, r5, r6, lr}
			mov r4, r0													@ Set register 4 value to first parameter passed to function
			mov r5, r1													@ Set register 5 value to second parameter passed to function
			
			adds r6, r4, r5												@ Add two values and store result in register 6 (adds updates S bit)
						
			bvs overflow												@ Check for overflow
			
			mov r0, r6													@ Move result into register 0 (return register)
			
			pop {r4, r5, r6, lr}
			bx lr



sub:																	@ Function "sub" will return the value of B subtracted from A.
			push {r4, r5, r6, lr}
			mov r4, r0													@ Set register 4 value to first parameter passed to function
			mov r5, r1													@ Set register 5 value to second parameter passed to function
			
			subs r6, r4, r5												@ Subtract two values and store result in register 6 (subs updates S bit)
			
			bvs overflow												@ Check for overflow
			
			mov r0, r6													@ Move result into register 0 (return register)
			
			pop {r4, r5, r6, lr}
			bx lr



mul:																	@ Function "mul" will return the product of A and B.
			push {r4, r5, r6, r7, lr}
			mov r4, r0													@ Set register 4 value to first parameter passed to function
			mov r5, r1													@ Set register 5 value to second parameter passed to function
			
			smull r6, r7, r5, r4										@ Smull registers 4 and 5 and store the result in registers 6 and 7
						
			cmp r6, #0													@ Compare RDlo to 0
			bgt mulif1													@ If RDlo is positive, send to first if statement
			blt mulif2													@ If RDlo is negative, send to second if statement
			beq end_mul													@ If RDlo is 0, send to end_mul

mulif1:
			cmp r7, #0x00000000											@ Compare RDhi to all zeros
			beq end_mul													@ If RDhi is all zeros, send to end_mul
			bne overflow												@ If RDhi is not all zeros, send to overflow
mulif2:
			cmp r7, #0xffffffff											@ Compare RDhi to all ones
			beq end_mul													@ If RDhi is all ones, send to end_mul
			bne overflow												@ If RDhi is not all zeros, send to overflow
end_mul:	
			mov r0, r6													@ Move result into register 0 (return register)
			pop {r4, r5, r6, r7, lr}
			bx lr



divide:
			push {r4, r5, r6, lr}										@ Function "divide" will return the quotient of A divided by B. 

			mov r4, r0													@ Set register 4 value to first parameter passed to function
			mov r5, r1													@ Set register 5 value to first parameter passed to function
					
			cmp r1, #0													@ Compare second value passed to function to 0
			beq zero_division											@ If value equals 0, send to ifzero
			bne notzero													@ If value does not equal 0, send to ifnotzero
notzero:
			sdiv r6, r4, r5												@ Divide two numbers and place result in register 6
			mov r0, r6													@ Set return register (r0) value equal to the result (r6)
			b enddivide													@ Send to done
zero_division:
			mov r0, #0x80000000											@ Can't divide by 0. Set return register (r0) to 0x80000000
enddivide:
			pop {r4, r5, r6, lr}
			bx lr



power:																	@ Function "power" will return N raised to the Ith power. 
			push {r4, r5, r6, r7, lr}
			mov r4, r0													@ Set register 4 to the first parameter passed to function
			mov r5, r1													@ Set register 5 to the second parameter passed to function
			mov r6, r0													@ Set register 6 to the first parameter passed to function
			
			cmp r1, #0													@ Check if the exponenet is a negative number
			blt power_negative											@ if exponenet is negative, send to power_negative
			
			cmp r0, #0													@ Check if number is 0 (0^x)
            beq endpower												@ If number is 0, send to endpower

            cmp r0, #1													@ Check if number is 1 (1^x)
            beq endpower												@ If number is 1, send to endpower

            cmp r1, #1													@ Check if power is 1 (x^1)
            beq endpower												@ If power is q, send to endpower

            cmp r1, #0													@ Check if power is 0 (x^0)
            beq zero_power												@ If power is 0, send to zero_power



loop_power: 
            cmp r5, #1													@ Compare exponent value to 1
            beq endpower												@ If exponent is 1, send to endpower

            smull r6, r7, r6, r4										@ Smull r6 by r4 (current total * number) and put result into r6 and r7
            sub r5, r5, #1												@ Subtract the exponent count by 1
            
            cmp r6, #0													@ Compare RDlo to 0
			bgt pwrif1													@ If RDlo is positive, send to first if statement
			blt pwrif2													@ If RDlo is negative, send to second if statement
			beq loop_power												@ If RDlo is 0, send back to start of loop

pwrif1:
			cmp r7, #0x00000000											@ Compare RDhi to all zeros
			beq loop_power												@ If RDhi is all zeros, send back to start of loop
			bne overflow												@ If RDhi is not all zeros, send to overflow
pwrif2:
			cmp r7, #0xffffffff											@ Compare RDhi to all ones
			beq loop_power												@ If RDhi is all ones, send back to start of loop
			bne overflow												@ If RDhi is not all ones, send to overflow
zero_power:
			mov r6, #1													@ Place 1 into register 6 (register I'm using for the running total)
            b endpower													@ Send to endpower
power_negative:
			mov r6, #0x80000000											@ Place 0x80000000 (error value) into register 6 (register I'm using for the running total)
endpower:
			mov r0, r6													@ Move r6 (running total) into return register (r0)
			pop {r4, r5, r6, r7, lr}
			bx lr



factorial:																@ Function "factorial" will return N!. 
			push {r4, r5, r6, r7, lr}
			
			mov r4, r0													@ Place value of first parameter into register 4
			mov r5, r0													@ Place value of first parameter into register 5
			
            cmp r4, #0													@ Compare number being calculated to 0 
            beq zero_factorial											@ If it is equal to 0, send to zero_factorial
            blt negative_factorial										@ If it is less than 0 (negative number) send to negative_factorial

loop_factorial:
            cmp	r5, #1													@ Compare number being multiplied (number - 1) to 1
            ble	endfactorial											@ If it is less than or equal to 0, factorial is done. Send to endfactorial

            sub	r5, r5, #1												@ Subtract 1 from number being multiplied
            smull r6, r7, r5, r4										@ Multiply r4 by r5 ( number * ( number -1 )) and store result into r6 and r7
            
			cmp r6, #0													@ Compare RDlo to 0
			bgt fctif1													@ If RDlo is positive, send to first if statement
			blt fctif2													@ If RDlo is negative, send to second if statement
			beq good													@ If RDlo equals 0, send to good

fctif1:
			cmp r7, #0x00000000											@ Compare RDhi to all zeros
			beq good													@ If RDhi is all zeros, send to good
			bne overflow												@ If RDhi is not all zeros, send to overflow
fctif2:
			cmp r7, #0xffffffff											@ Compare RDhi to all ones
			beq good													@ If RDhi is all ones, send to good
			bne overflow												@ If RDhi is not all ones, send to overflow
good:
			mov r4, r6													@ Move running total (r6) to r4 (current number)
			b loop_factorial											@ Return to start of loop
zero_factorial:
			mov r6, #1													@ Move 1 into r6 (register used for running total)
			b endfactorial												@ Send to endfactorial
negative_factorial:
			mov r6, #0x80000000											@ Move #0x80000000 (error value) into r6 (register used for running total)
			b endfactorial												@ Send to endfactorial
endfactorial:
			mov r0, r6													@ Move running total into return register (r0)
			pop {r4, r5, r6, r7, lr}
			bx lr

overflow:
			mov r0, #0x80000000 										@ Set value of return register (r0) to 0x80000000 (error value)
			bx lr
