@ Name: Chris Jackson
@ Project 11
@ 11/27/18
@ 	

			.global search
			.global insert
			.global delete
			.data
address:  	
			.word    0
X:
			.single 0r0.0
			.text
			
@ r0: pointer to table of players
@ r1: jersey number of player to be located
@ r2: pointer to pointer to player
search:
			push    	{r4, r5, r6, r7, r8, r9, r10, lr}
			
			mov			r7, #0					@ Initialize a counter (used in loop)
			mov			r10, #40				@ Store value 40 (to be used later to get data of last player)

			ldrh		r9, [r0, #2]			@ Get number of players in data
			
			cmp			r9, #0					@ If player data is empty (compare to 0)
			ble			notfound				@ Branch to not found
			
			sub			r9, r9, #1
			ldr			r6, [r0, #4]			@ Get player array and put into r6 (so can use r6 to get stats for player)
			
			mul			r10, r10, r9			@ Get address of final player data ( count * 40 )
			ldrh		r8, [r6, #0]			@ Get first player's jersey number
			ldrh		r4, [r6, r10]			@ Get last player's jersey number

			str			r6, [r2, #0]			@ Place the address of the first record into r2 (will be used in insert/delete)
			cmp			r1, r8					@ If search key is less than the lowest (first) jersey number
			blt			notfound				@ Branch to notfound			

searchloop:					
			ldrh		r4, [r6, #0]			@ Get current jersey number
			str			r6, [r2]				@ Place the address of the current record into r2 (will be used in insert/delete)
			cmp			r1, r4					@ Check if matches jersey number in 2nd argument (r1)
			beq			found					@ If found, end loop (player found)
			blt			notfound				@ If search key is less than the jersey key then key is not in list (return 0 and current position in list)
						
			cmp			r7, r9					@ Compare current counter number to count of players
			bge			notfound				@ If counter is greater than or equal to number of players, end loop (player not found)
			
			add			r7, r7, #1				@ Increase counter by 1
			add			r6, r6, #40				@ Add result of above to r6 (get next player data)
			b			searchloop				@ Branch back to beginning of loop
found:
			mov			r0, #1					@ Player was found, return 0
			b			end						@ Branch to end
notfound:
			mov 		r0, #0					@ Player not found, return 0
			b			end						@ Branch to end
end:
			pop 		{r4, r5, r6, r7, r8, r9, r10, lr}
			bx			lr



@ r0: pointer to table of players
@ r1: jersey number of player to be deleted	
delete:
			push		{r4, r5, r6, r7, r8, r9, lr}
						
			ldrh		r6, [r0, #2]			@ Get number of players in data
			cmp			r6, #0					@ If player data is empty (compare to 0)
			ble			delete1					@ Can't delete from empty list, delete failed (branch to delete1)
			
			mov			r4, r0					@ Move first argument into r4 for later use
			mov			r9, r0					@ Move first argument into r9 for later use
			mov			r5, r1					@ Move second argument into r5 for later use
			mov			r8, #40					@ Store #40 for later use
			
			ldr      	r2, =address			@ Set aside 4 bytes to be used when calling search

			bl	 		search					@ Search for jersey number to be deleted
			cmp			r0, #0					@ Compare return value of search (0 if not found, 1 if found)
			beq			delete1					@ If jersey number is not found, delete failed (branch to delete1)
			
			@ get r2 to be address of item to be deleted (destination)
			ldr			r2, =address
			ldr			r2, [r2]
			
			add			r7, r2, #40				@ Get address of next player (used as source in memmove)		
						
			ldr			r4, [r4, #4]			@ Get address of first player (used in calculation of bytes to be moved in memmove)
			subs		r4, r2, r4				@ Address of player to be deleted - starting player address
			sdiv		r4, r4, r8				@ Divide solution of above by 40 to get number of players to NOT move
			subs		r4, r6, r4				@ Total players - players to NOT move = players to be moved
			mul			r4, r4, r8				@ Multiply by 40 to get number of bytes to move
			
			mov			r0, r2					@ Place destination in proper register
			mov			r1, r7					@ Place source in proper register
			mov			r2, r4					@ Place number of bytes to be moved in proper register
			bl			memmove					@ Call memmove
			
			subs		r6, r6, #1				@ Update count
			strh		r6, [r9, #2]			@ Store updated count
			b			delete2					@ Branch to delete2 (successful delete)

delete1:
			mov			r0, #0					@ Return 0 (delete failed)
			b			enddelete				@ branch to enddelete
delete2:
			mov			r0, #1					@ Return 1 (delete succesful)
			b			enddelete				@ branch to enddelete
enddelete:
			pop			{r4, r5, r6, r7, r8, r9, lr}
			bx			lr



@ r0: pointer to table of players
@ r1: jersey number of player to be inserted
@ r2: pointer to name of player
@ r3: number of games played
@ stack: number of goals scored
@ stack: number of assists scored
insert:	
			push		{r4, r5, r6, r7, r8, r9, r10, lr}
						
			ldrh		r4, [r0, #2]			@ Get number of players in data
			ldrh		r5, [r0, #0]			@ Get capacity of list
			cmp			r4, r5					@ If player data is empty (compare to 0)
			bge			insert1					@ Can't insert in a full list, insert failed (branch to insert1)

			mov			r10, #40				@ Store value 40 (to be used later to get data of last player)
			ldrh		r9, [r0, #2]			@ Get number of players in data
			sub			r9, r9, #1
			ldr			r6, [r0, #4]			@ Get player array and put into r6 (so can use r6 to get stats for player)
			mul			r10, r10, r9			@ Get address of final player data ( count * 40 )
			ldrh		r8, [r6, #0]			@ Get first player's jersey number
			ldrh		r4, [r6, r10]			@ Get last player's jersey number
			add			r6, r6, r10				@ Get address of last player in data
			add			r6, r6, #40				@ Get address after the last player in data
			mov			r9, r6					@ Set r9 to the address after the last player address in the data
			cmp			r1, r4					@ If jersey number to be inserted is larger than the last jersey number currently in the data
			bgt			last					@ Branch to last
			
			mov			r4, r0					@ Preserve value of r0
			mov			r5, r1					@ Preserve value of r1
			mov			r6, r2					@ Preserve value of r2
			mov			r7, r3					@ Preserve value of r3
			
			ldr      	r2, =address			@ Set aside 4 bytes to be used when calling search
			bl	 		search					@ Search for jersey number to be deleted
			cmp			r0, #1					@ Compare return value of search (0 if not found, 1 if found)
			beq			insert1					@ If jersey number is found, insert failed (branch to insert1)
			
			mov			r0, r4					@ Preserve value of r0
			mov			r1, r5					@ Preserve value of r1
			mov			r2, r6					@ Preserve value of r2
			mov			r3, r7					@ Preserve value of r3
			
			@ get r2 to be address of item to be deleted (destination)
			ldr			r9, =address
			ldr			r9, [r9]
			
			mov			r8, #40					@ Move 40 for use in future calculations
			mov			r10, r3					@ Preserve value of r3
			ldrh		r6, [r0, #2]			@ Get player count
			
			add			r3, r9, #40				@ Get address of next player (used as source in memmove)
			ldr			r4, [r0, #4]			@ Get address of first player (used in calculation of bytes to be moved in memmove)
			subs		r4, r9, r4				@ Address of player to be deleted - starting player address
			sdiv		r4, r4, r8				@ Divide solution of above by 40 to get number of players to NOT move
			subs		r4, r6, r4				@ Total players - players to NOT move = players to be moved
			mul			r4, r4, r8				@ Multiply by 40 to get number of bytes to move
			
			mov			r5, r0					@ Preserve value of r0
			mov			r6, r1					@ Preserve value of r1
			mov			r7, r2					@ Preserve value of r2
			
			mov			r0, r3					@ Place destination in proper register
			mov			r1, r9					@ Place source in proper register
			mov			r2, r4					@ Place number of bytes to be moved in proper register
			bl			memmove					@ Call memmove
			
			mov			r0, r5					@ Preserve value of r0
			mov			r1, r6					@ Preserve value of r1
			mov			r2, r7					@ Preserve value of r2
			mov			r3, r10					@ Preserve value of r3		
			b			last	
last:			

			ldr			r4, [sp, #32]			@ Get fifth argument
			ldr			r5, [sp, #36]			@ Get sixth argument
			strh		r1, [r9, #0]			@ Jersey #
			
			mov			r8, #0					@ Counter used in name loop
			mov			r10, #2					@ Counter used in name loop
name:
			ldrb		r7, [r2, r8]			@ Load current letter
			strb		r7, [r9, r10]			@ Store current letter
			cmp			r8, #24					@ Compare to 24 (size of name array)
			beq			continue				@ If reached, break out of loop
			
			adds		r8, r8, #1				@ Increment count(s) by 1
			adds		r10, r10, #1			@ Increment count(s) by 1
			b			name					@ Branch to start of loop
continue:
			
			@ strb		r7, [r9, r10]			@ ????????????????????
			
			strh		r3, [r9, #28]			@ Games played
			strh		r4, [r9, #30]			@ Goals
			strh		r5, [r9, #32]			@ Assists

			adds		r6, r4, r5				@ Add goals + assists
			strh		r6, [r9, #34]			@ Points
			
			cmp			r3, #0					@ If player has 0 games played, PPG = 0
			beq			nogames					@ Branch to nogames to set PPG to 0
			
			@ CALCULATE PPG
			fmsr		s0, r6					@ Copy value to FPU register
			fsitos		s1, s0					@ Covert from int to float
			fmsr		s2, r3					@ Copy value to FPU register
			fsitos		s3, s2					@ Covert from int to float
			fdivs		s4, s1, s3				@ Divide
			
			ldr     	r10, =X
			fsts   		s4, [r10]    			@ store result at loc X
			ldr			r10, [r10]				@ Load value
						
			str			r10, [r9, #36]
			@ CALCULATE PPG
			
			b			done					@ Branch to done
			
nogames:
			mov			r7, #0					@ When 0 games played, PPG = 0
			
			fmsr		s0, r7					@ Copy value to FPU register
			fsitos		s1, s0					@ Covert from int to float
			
			ldr     	r10, =X
			fsts    	s1, [r10]    			@ store result at loc X
			
			str			r10, [r9, #36]
			b			done					@ Branch to done
done:		

			ldrh		r6, [r0, #2]			@ Get number of players in data
			adds		r6, r6, #1				@ Update number of players
			strh		r6, [r0, #2]			@ Store updated count
			b			insert2					@ Branch to insert2 (successful insert)


insert1:
			mov			r0, #0					@ Place 0 (failed insert) into return register
			b			endinsert				@ Branch to endinsert
insert2:
			mov			r0, #1					@ Place 1 (succsesful insert) into return register
			b			endinsert				@ Branch to endinsert
endinsert:	
			pop			{r4, r5, r6, r7, r8, r9, r10, lr}
			bx			lr
