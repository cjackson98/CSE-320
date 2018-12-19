#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"

int main(){
	int final_conversion;
	const char test1[] = "  +1011A";//Test for +
	int base1 = 2;
	
	const char test2[] = "  -7EQ";//Test for -
	int base2 = 16;
	
	const char test3[] = "  +124A";//Test for neither +/-
	int base3 = 8;
	
	const char test4[] = "+34A";//Test for no spaces with +
	int base4 = 5;
	
	const char test5[] = "-24Z";//Test for no spaces with -
	int base5 = 18;
	
	const char test6[] = "32FQ";//Test for no spaces without +/-
	int base6 = 18;
	
	const char test7[] = "-418A";//Test for base < 2
	int base7 = 1;
	
	const char test8[] = "                     285Z";//Test for base > 36
	int base8 = 37;
	
	const char test9[] = "  		 	 	   	28Z";//Test for many random spaces (including tabs)
	int base9 = 28;
	
	const char test10[] = "  +7eq";//Test for lower case letters.
	int base10 = 16; 
	
	const char test11[] = "aaa";//Test for no start character.
	int base11 = 10;
	
	const char test12[] = "123";//Test for no termination character.
	int base12 = 10;
	
	const char test13[] = "-aaa";//Test for no digits between starting +/- and ending character.
	int base13 = 10;
		
		
	int result1 = convert(test1, base1, &final_conversion);//Test for +. Should be 11.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result1, final_conversion, final_conversion );
	
	int result2 = convert(test2, base2, &final_conversion);//Test for -. Should be -126.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result2, final_conversion, final_conversion );
	
	int result3 = convert(test3, base3, &final_conversion);//Test without + or -. Should be 84.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result3, final_conversion, final_conversion );
	
	int result4 = convert(test4, base4, &final_conversion);//Test for no spaces with +. Should be 19.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result4, final_conversion, final_conversion );
	
	int result5 = convert(test5, base5, &final_conversion);//Test for no spaces with -. Should be -40.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result5, final_conversion, final_conversion );
	
	int result6 = convert(test6, base6, &final_conversion);//Test for no spaces without +/-. Should be 1023.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result6, final_conversion, final_conversion );
	
	int result7 = convert(test7, base7, &final_conversion);//Test for base below 2. Should return 0.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result7, final_conversion, final_conversion );

	int result8 = convert(test8, base8, &final_conversion);//Test for base over 36. Should return 0.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result8, final_conversion, final_conversion );
	
	int result9 = convert(test9, base9, &final_conversion);//Test for random spaces. Should be 64.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result9, final_conversion, final_conversion );
	
	int result10 = convert(test10, base10, &final_conversion);//Test for lower case letters. Should be 126.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result10, final_conversion, final_conversion );
	
	int result11 = convert(test11, base11, &final_conversion);//Test for no start character. Should return 0.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result11, final_conversion, final_conversion );
	
	int result12 = convert(test12, base12, &final_conversion);//Test for no termination character. Should return 123.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result12, final_conversion, final_conversion );
	
	int result13 = convert(test13, base13, &final_conversion);//Test for no termination character. Should return 0.
	printf( "Converted(1/0): %d.  Number in base 10: %d. Number in hexadecimal: (%08x).\n", result13, final_conversion, final_conversion );


}
