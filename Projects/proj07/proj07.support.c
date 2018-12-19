/*
* Name: Chris Jackson
* Project: 7
* Date: 10/23/18
* Description: A disassembler for ARM machine language instruction. 
*/
#include <stdio.h>
#include "/user/cse320/Projects/project07.support.h"

void decode( unsigned bit_pattern, char result[] )	//(bit_pattern,address of array)
{	
	//int test = 0;
	
	unsigned valid = bit_pattern >> 26;									// 111000
	unsigned i_bit = (bit_pattern << 6 >> 6) >> 25;						// Bit 25 I bit
	unsigned s_bit = (bit_pattern << 11 >> 11) >> 20;					// Bit 20 S bit
	unsigned opcode = (bit_pattern << 7 >> 7) >> 21;					// Bits 24:21 opcode
	unsigned rn = (bit_pattern << 12 >> 12) >> 16;						// Bits 19:16 Rn
	unsigned rd = (bit_pattern << 16 >> 16) >> 12;						// Bits 15:12 Rd
	unsigned immediate = (bit_pattern << 24 >> 24);						// Bits 7:0 immediate value (when I=1)
	unsigned valid2 = (bit_pattern << 24 >> 28);// << 24 >> 31;			// When using Rm (instead of immediate) bits 7:4 should be 0
	unsigned rm = (bit_pattern << 28 >> 28);							// Bits 3:0 Rm (when I=0)

	/*
	if(test){
		printf( "Pattern   : %08x\n", bit_pattern );
		printf( "Test valid: %08x\n", valid);
		printf( "Test i_bit: %08x\n", i_bit);
		printf( "Test s bit: %08x\n", s_bit);
		printf( "Test op   : %08x\n", opcode);
		printf( "Test Rn   : %08x\n", rn);
		printf( "Test Rd   : %08x\n", rd);
		printf( "Test Rm   : %08x\n", rm);
		printf( "Test immed: %08x\n", immediate);
	}
	*/
	
	if(valid != 0x38){
		sprintf(result, "Invalid instruction should begin with the bits: 111000.");
	}
	else{
		if(opcode == 0x0){
			//printf("Opcode: 0 - and");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "ands r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "and r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "ands r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "and r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x1){
			//printf("Opcode: 1 - eor");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "eors r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "eor r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "eors r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "eor r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x2){
			//printf("Opcode: 2 - sub");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "subs r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "sub r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "subs r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "sub r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x3){
			//printf("Opcode: 3 - rsb");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "rsbs r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "rsb r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "rsbs r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "rsb r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x4){
			//printf("Opcode: 4 - add");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "adds r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "add r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "adds r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "add r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x5){
			//printf("Opcode: 5 - adc");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "adcs r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "adc r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "adcs r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "adc r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x6){
			//printf("Opcode: 6 - sbc");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "sbcs r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "sbc r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "sbcs r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "sbc r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x7){
			//printf("Opcode: 7 - rsc");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "rscs r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "rsc r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "rscs r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "rsc r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0x8){
			//printf("Opcode: 8 - tst");
			if(s_bit != 0x1){
				sprintf(result, "Invalid instruction. S bit should be 1 for test/compare instructions");
				//printf("Result: %s", result);
			}
			else if(i_bit == 1){
				sprintf(result, "tst r%d, #0x%01x", rn, immediate);
				//printf("Result: %s", result);
			}
			else{
				sprintf(result, "tst r%d, r%d", rn, rm);
				//printf("Result: %s", result);
			}
		}
		if(opcode == 0x9){
			//printf("Opcode: 9 - teq");
			if(s_bit != 0x1){
				sprintf(result, "Invalid instruction. S bit should be 1 for test/compare instruction");
				//printf("Result: %s", result);
			}
			else if(i_bit == 1){
				sprintf(result, "teq r%d, #0x%01x", rn, immediate);
				//printf("Result: %s", result);
			}
			else{
				sprintf(result, "teq r%d, r%d", rn, rm);
				//printf("Result: %s", result);
			}
		}
		if(opcode == 0xa){
			//printf("Opcode: a - cmp");
			if(s_bit != 0x1){
				sprintf(result, "Invalid instruction. S bit should be 1 for test/compare instruction");
				//printf("Result: %s", result);
			}
			else if(i_bit == 1){
				sprintf(result, "cmp r%d, #0x%01x", rn, immediate);
				//printf("Result: %s", result);
			}
			else{
				sprintf(result, "cmp r%d, r%d", rn, rm);
				//printf("Result: %s", result);
			}
		}
		if(opcode == 0xb){
			//printf("Opcode: b - cmn");
			if(s_bit != 0x1){
				sprintf(result, "Invalid instruction. S bit should be 1 for test/compare instruction");
				//printf("Result: %s", result);
			}
			else if(i_bit == 1){
				sprintf(result, "cmn r%d, #0x%01x", rn, immediate);
				//printf("Result: %s", result);
			}
			else{
				sprintf(result, "cmn r%d, r%d", rn, rm);
				//printf("Result: %s", result);
			}
		}
		if(opcode == 0xc){
			//printf("Opcode: c - orr/n");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "orrs r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "orr r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "orrs r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "orr r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0xd){		
			//printf("Opcode: d - mov");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "movs r%d, #0x%01x", rd, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "mov r%d, #0x%01x", rd, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "movs r%d, r%d", rd, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "mov r%d, r%d", rd, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0xe){
			//printf("Opcode: e - bic");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "bics r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "bic r%d, r%d, #0x%01x", rd, rn, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "bics r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "bic r%d, r%d, r%d", rd, rn, rm);
					//printf("Result: %s", result);
				}
			}
		}
		if(opcode == 0xf){
			//printf("Opcode: f - mvn");
			if(i_bit == 0x1){
				if(s_bit == 0x1){
					sprintf(result, "mvns r%d, #0x%01x", rd, immediate);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "mvn r%d, #0x%01x", rd, immediate);
					//printf("Result: %s", result);
				}
			}
			else{
				if(valid2 != 0x0){
					sprintf(result ,"Invalid instruction. When an immediate value is not being used, bits 7:4 should be 0");
				}
				else if(s_bit == 0x1){
					sprintf(result, "mvns r%d, r%d", rd, rm);
					//printf("Result: %s", result);
				}
				else{
					sprintf(result, "mvn r%d, r%d", rd, rm);
					//printf("Result: %s", result);
				}
			}
		}
	}
}     
