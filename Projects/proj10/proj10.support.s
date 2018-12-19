@ Name: Chris Jackson
@ Project 10
@ 11/13/18
@ An ARM assembly language function which searches through statistics for a hockey team.		

			.global search
			.text
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
			
			cmp			r1, r8					@ If search key is less than the lowest (first) jersey number
			blt			notfound				@ Branch to notfound
			
			cmp			r1, r4					@ If search key is greater than the highest (last) jersey number
			bgt			notfound				@ Branch to notfound

loop:					
			ldrh		r4, [r6, #0]			@ Get current jersey number
			str			r6, [r2]				@ Place the address of the current record into r2 (will be used in insert/delete)
			cmp			r1, r4					@ Check if matches jersey number in 2nd argument (r1)
			beq			found					@ If found, end loop (player found)
			blt			notfound				@ If search key is less than the jersey key then key is not in list (return 0 and current position in list)
						
			cmp			r7, r9					@ Compare current counter number to count of players
			bge			notfound				@ If counter is greater than or equal to number of players, end loop (player not found)
			
			add			r7, r7, #1				@ Increase counter by 1
			add			r6, r6, #40				@ Add result of above to r6 (get next player data)
			b			loop					@ Branch back to beginning of loop
found:
			mov			r0, #1					@ Player was found, return 0
			b			end						@ Branch to end
notfound:
			mov 		r0, #0					@ Player not found, return 0
			str			r6, [r2]
			b			end						@ Branch to end
end:
			pop 		{r4, r5, r6, r7, r8, r9, r10, lr}
			bx			lr
