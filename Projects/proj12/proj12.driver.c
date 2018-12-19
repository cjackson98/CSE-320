#include <stdio.h>
#include "/user/cse320/Projects/project12.support.h"

int main(){
    
    // unsigned PC, IR, CPSR;
	unsigned result;
	
	printf("The next 4 lines test data processing/data movement instructions:\n\n");
	
    result = update(0x00000000, 0xF0FFFFFF, 0x00000000); 				// Data Processing
    printf("PC: 0x00000000, IR: 0xF0FFFFFF, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0xF3FFFFFF, 0x00000000); 				// Data Processing
    printf("PC: 0x00000000, IR: 0xF3FFFFFF, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
	
    result = update(0x00000000, 0x07000000, 0x00000000); 				// Data Movement
    printf("PC: 0x00000000, IR: 0x07000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
	
    result = update(0x00000000, 0x04000000, 0x00000000); 				// Data Movement
    printf("PC: 0x00000000, IR: 0x04000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
	
	// Branch instructions:
	printf("The next 3 lines test invalid branch instructions:\n\n");
	
    result = update(0x00000000, 0x08000000, 0x00000000);				// 1L not 1
    printf("PC: 0x00000000, IR: 0x08000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000000. %s.\n\n", result, result==0x00000000?"True":"False");   
    
    result = update(0x00000000, 0xFA000000, 0xF0000000);				// Condition 15
    printf("PC: 0x00000000, IR: 0xFA000000, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000000. %s.\n\n", result, result==0x00000000?"True":"False");   
    
    result = update(0x00000000, 0xFA000111, 0xF0000000);				// Condition 15
    printf("PC: 0x00000000, IR: 0xFA000111, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000000. %s.\n\n", result, result==0x00000000?"True":"False");   
    
	// Test branch with successful conditions ((simm24 *4) + PC)
	printf("The next 15 lines test branch instructions with successful conditions ((simm24*4)+PC):\n\n");
	
    result = update(0x00000000, 0x0A000111, 0x40000000);				// Condition 0
    printf("PC: 0x00000000, IR: 0x0A000111, CPSR: 0x40000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   

	result = update(0x00000000, 0x1A000111, 0x00000000);				// Condition 1
	printf("PC: 0x00000000, IR: 0x1A000111, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   

    result = update(0x00000000, 0x2A000111, 0x20000000);				// Condition 2
    printf("PC: 0x00000000, IR: 0x2A000111, CPSR: 0x20000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0x3A000111, 0x00000000);				// Condition 3
    printf("PC: 0x00000000, IR: 0x3A000111, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0x4A000111, 0x80000000);				// Condition 4
    printf("PC: 0x00000000, IR: 0x4A000111, CPSR: 0x80000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0x5A000111, 0x00000000);				// Condition 5
    printf("PC: 0x00000000, IR: 0x5A000111, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0x6A000111, 0x10000000);				// Condition 6
    printf("PC: 0x00000000, IR: 0x6A000111, CPSR: 0x10000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0x7A000111, 0x00000000);				// Condition 7
    printf("PC: 0x00000000, IR: 0x7A000111, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0x8A000111, 0x20000000);				// Condition 8
    printf("PC: 0x00000000, IR: 0x8A000111, CPSR: 0x20000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0x9A000111, 0x40000000);				// Condition 9
    printf("PC: 0x00000000, IR: 0x9A000111, CPSR: 0x40000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0xAA000111, 0x90000000);				// Condition 10
    printf("PC: 0x00000000, IR: 0xAA000111, CPSR: 0x90000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0xBA000111, 0x80000000);				// Condition 11
    printf("PC: 0x00000000, IR: 0xBA000111, CPSR: 0x80000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0xCA000111, 0x90000000);				// Condition 12
    printf("PC: 0x00000000, IR: 0xCA000111, CPSR: 0x90000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0xDA000111, 0xC0000000);				// Condition 13
    printf("PC: 0x00000000, IR: 0xDA000111, CPSR: 0xC0000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    result = update(0x00000000, 0xEA000111, 0x12345678);				// Condition 14 (Always)
    printf("PC: 0x00000000, IR: 0xEA000111, CPSR: 0x12345678\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
	
	// Test branch without successful conditions (PC + 4)
	printf("The next 15 lines test branch instructions without successful conditions (PC + 4):\n\n");
	
	result = update(0x00000000, 0x0A000000, 0x00000000);				// Condition 0
	printf("PC: 0x00000000, IR: 0x0A000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   

	result = update(0x00000000, 0x1A000000, 0xF0000000);				// Condition 1
	printf("PC: 0x00000000, IR: 0x1A000000, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   

    result = update(0x00000000, 0x2A000000, 0x00000000);				// Condition 2
    printf("PC: 0x00000000, IR: 0x2A000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0x3A000000, 0xF0000000);				// Condition 3
    printf("PC: 0x00000000, IR: 0x3A000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0x4A000000, 0x00000000);				// Condition 4
    printf("PC: 0x00000000, IR: 0x4A000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0x5A000000, 0xF0000000);				// Condition 5
    printf("PC: 0x00000000, IR: 0x5A000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0x6A000000, 0x00000000);				// Condition 6
    printf("PC: 0x00000000, IR: 0x6A000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0x7A000000, 0xF0000000);				// Condition 7
    printf("PC: 0x00000000, IR: 0x7A000000, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0x8A000000, 0xF0000000);				// Condition 8
    printf("PC: 0x00000000, IR: 0x8A000000, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0x9A000000, 0x20000000);				// Condition 9
    printf("PC: 0x00000000, IR: 0x9A000000, CPSR: 0x20000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0xAA000000, 0x80000000);				// Condition 10
    printf("PC: 0x00000000, IR: 0xAA000000, CPSR: 0x80000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0xBA000000, 0xF0000000);				// Condition 11
    printf("PC: 0x00000000, IR: 0xBA000000, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0xCA000000, 0xF0000000);				// Condition 12
    printf("PC: 0x00000000, IR: 0xCA000000, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0xDA000000, 0x00000000);				// Condition 13
    printf("PC: 0x00000000, IR: 0xDA000000, CPSR: 0x00000000\n");
    printf("Answer: %08x. Should be: 00000004. %s.\n\n", result, result==0x00000004?"True":"False");   
    
    result = update(0x00000000, 0xEA000111, 0xF0000000);				// Condition 14 (Always)
    printf("PC: 0x00000000, IR: 0xEA000111, CPSR: 0xF0000000\n");
    printf("Answer: %08x. Should be: 00000448. %s.\n\n", result, result==0x00000448?"True":"False");   
    
    printf("The following lines are additional examples from self study excersise #11:\n\n");
    
    result = update(0x00012000, 0xEAFFFFF6, 0xA0000000);
    printf("PC: 0x00012000, IR: 0xEAFFFFF6, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00011FDC. %s.\n\n", result, result==0x00011FDC?"True":"False"); 
    
    result = update(0x00012000, 0xE00B0005, 0xA0000000);
    printf("PC: 0x00012000, IR: 0xE00B0005, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00012004. %s.\n\n", result, result==0x00012004?"True":"False"); 
    
    result = update(0x00012000, 0x638610CC, 0xA0000000);
    printf("PC: 0x00012000, IR: 0x638610CC, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00012004. %s.\n\n", result, result==0x00012004?"True":"False"); 
    
    result = update(0x00012000, 0x40292005, 0xA0000000);
    printf("PC: 0x00012000, IR: 0x40292005, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00012004. %s.\n\n", result, result==0x00012004?"True":"False"); 
    
    result = update(0x00012000, 0xE5983004, 0xA0000000);
    printf("PC: 0x00012000, IR: 0xE5983004, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00012004. %s.\n\n", result, result==0x00012004?"True":"False"); 
    
    result = update(0x00012000, 0xE5864002, 0xA0000000);
    printf("PC: 0x00012000, IR: 0xE5864002, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00012004. %s.\n\n", result, result==0x00012004?"True":"False"); 
    
    result = update(0x00012000, 0x0A000005, 0xA0000000);
    printf("PC: 0x00012000, IR: 0x0A000005, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00012004. %s.\n\n", result, result==0x00012004?"True":"False"); 
    
    result = update(0x00012000, 0xEB000009, 0xA0000000);
    printf("PC: 0x00012000, IR: 0xEB000009, CPSR: 0xA0000000\n");
    printf("Answer: %08x. Should be: 00012028. %s.\n\n", result, result==0x00012028?"True":"False"); 
    
    return 0;
}
