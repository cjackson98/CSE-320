// Name: Chris Jackson
// Project 12
// 12/2/18
// Simulates some of the actions taken during the fetch-execute cycle for the ARM microprocessor.  

#include "/user/cse320/Projects/project12.support.h"
#include <stdio.h>

unsigned update( unsigned PC, unsigned IR, unsigned CPSR ){
	
	unsigned category, cond, one, simm24, n, z, c, v, result, sign;
	category = (IR << 4 >> 4) >> 26;
	PC = PC + 4;
	result = PC;
		
	if(category == 0){													// Data processing instruction
		return result;
	}
	else if(category == 1){												// Data movement instruction
		return result;
	}
	else if(category == 2){												// Branch instruction
		cond = IR >> 28;
		one = (IR << 6 >> 6) >> 25;
		simm24 = (IR << 8 >> 8);

		sign = simm24 >> 23;

		if(sign == 1){
			simm24 = simm24 | 0xFF000000;
		}
		
		n = CPSR >> 31;
		z = (CPSR << 1 >> 1) >> 30;
		c = (CPSR << 2 >> 2) >> 29;
		v = (CPSR << 3 >> 3) >> 28;
				
		if(one != 1){
			return 0;
		}
		if(cond == 0){													// Equal
			if(z == 1){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 1){													// Not equal
			if(z == 0){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 2){													// Carry
			if(c == 1){
				result = (simm24 * 4) + PC;
			}
			return result;
		}
		if(cond == 3){													// Not carry
			if(c == 0){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 4){													// Negative
			if(n == 1){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 5){													// Not negative
			if(n == 0){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 6){													// Overflow
			if(v == 1){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 7){													// Not overflow
			if(v == 0){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 8){													// Unsigned greater than
			if(c == 1 && z == 0){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 9){													// Unsigned less than or equal to
			if(c == 0 || z == 1){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 10){													// Signed greater than or equal to
			if(n == v){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 11){													// Signed less than
			if(n != v){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 12){													// Signed greater than
			if(z == 0 && (n == v)){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 13){													// Signed less than or equal to
			if(z == 1 || (n != v)){
				result = (simm24 * 4) + PC;
				return result;
			}
			return result;
		}
		if(cond == 14){		
			result = (simm24 << 2) + PC;
		}
		if(cond == 15){													// Invalid
			result = 0;
		}
	}
	else{																// Invalid instruction
		return 0;
	}
	return result;
}
