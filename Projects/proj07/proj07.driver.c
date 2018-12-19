#include <stdio.h>
#include "/user/cse320/Projects/project07.support.h"

int main(){
	
	char test1[80];
	decode( 0xe0060007, test1 );// and r0, r6, r7
	printf("Result1: %s. Should be 'and r0, r6, r7'\n", test1);
	
	char test2[80];
	decode( 0xe1861007, test2 );// orr r1, r6, r7
	printf("Result2: %s. Should be 'orr r1, r6, r7'\n", test2);

	char test3[80];
	decode( 0xe0262007, test3 );// eor r2, r6, r7
	printf("Result3: %s. Should be 'eor r2, r6, r7'\n", test3);
	
	char test4[80];
	decode( 0xe1c63007, test4 );// bic r3, r6, r7
	printf("Result4: %s. Should be 'bic r3, r6, r7'\n", test4);
	
	char test5[80];
	decode( 0xe0860007, test5 );// add r0, r6, r7
	printf("Result5: %s. Should be 'add r0, r6, r7'\n", test5);
	
	char test6[80];
	decode( 0xe0a61007, test6 );// adc r1, r6, r7
	printf("Result6: %s. Should be 'adc r1, r6, r7'\n", test6);
	
	char test7[80];
	decode( 0xe0462007, test7 );// sub r2, r6, r7
	printf("Result7: %s. Should be 'sub r2, r6, r7'\n", test7);
	
	char test8[80];
	decode( 0xe0c63007, test8 );// sbc r3, r6, r7
	printf("Result8: %s. Should be 'sbc r3, r6, r7'\n", test8);
	
	char test9[80];
	decode( 0xe0664007, test9 );// rsb r4, r6, r7
	printf("Result9: %s. Should be 'rsb r4, r6, r7'\n", test9);
	
	char test10[80];
	decode( 0xe0e65007, test10 );// rsc r5, r6, r7
	printf("Result10: %s. Should be 'rsc r5, r6, r7'\n", test10);
	
	char test11[80];
	decode( 0xe1a00007, test11 );// mov r0, r7
	printf("Result11: %s. Should be 'mov r0, r7'\n", test11);
	
	char test12[80];
	decode( 0xe1e01007, test12 );// mvn r1, r7
	printf("Result12: %s. Should be 'mvn r1, r7'\n", test12);
	
	char test13[80];
	decode( 0xe086a007, test13 );// add r10, r6, r7
	printf("Result13: %s. Should be 'add r10, r6, r7'\n", test13);
	
	char test14[80];
	decode( 0xe096a007, test14 );// adds r10, r6, r7
	printf("Result14: %s. Should be 'adds r10, r6, r7'\n", test14);
	
	char test15[80];
	decode( 0xe2860001, test15 );// add r0, r6, #0x1
	printf("Result15: %s. Should be 'add r0, r6, #0x1'\n", test15);
	
	char test16[80];
	decode( 0xe28600ff, test16 );// add r0, r6, #0xff
	printf("Result16: %s. Should be 'add r0, r6, #0xff'\n", test16);
	
	char test17[80];
	decode( 0xe086a007, test17 );// add r10, r6, r7
	printf("Result17: %s. Should be 'add r10, r6, r7'\n", test17);
	
	char test18[80];
	decode( 0xe096a007, test18 );// adds r10, r6, r7
	printf("Result18: %s. Should be 'adds r10, r6, r7'\n", test18);
	
	char test19[80];
	decode( 0xe286a007, test19 );// add r10, r6, #0x7
	printf("Result19: %s. Should be 'add r10, r6, #0x7'\n", test19);
	
	char test20[80];
	decode( 0xe1520003, test20 );// cmp r2, r3
	printf("Result20: %s. Should be 'cmp r2, r3'\n", test20);
	
	char test21[80];
	decode( 0xe1a01003, test21 );// mov r1, r3
	printf("Result21: %s. Should be 'mov r1, r3'\n", test21);
	
	char test22[80];
	decode( 0xe1a01013, test22 );// Invalid (when using rm bits 7:4 should not be 0)
	printf("Result22: %s. Should be Invalid\n", test22);
	
	char test23[80];
	decode( 0xffffffff, test23 );// Invalid (instructions should start with the bits "111000"
	printf("Result23: %s. Should be Invalid\n", test23);
	
	char test24[80];
	decode( 0xe1020003, test24 );
	printf("Result24: %s. Should be Invalid\n", test24);//Invalid (test/compare instructions should have an S bit of 1)
	
	return 0;
}
