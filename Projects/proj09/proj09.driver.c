#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"
int main(){
	
    printf("Negate:\n");
    printf("Negation of %d is: %d. Solution should be: %d.\n", 2, negate(2), -2);
    printf("Negation of %d is: %d. Solution should be: %d.\n", -2, negate(-2), 2);
    printf("Negation of %d is: %d. Solution should be: %d.\n", 100, negate(100), -100);
    printf("Negation of %d is: %d. Solution should be: %d.\n", -100, negate(-100), 100);
    printf("Negation of %d is: %d. Solution should be: %d.\n", 0, negate(0), 0);
    printf("Negation of %d is: %d. Solution should be: %d.\n", 2147483647, negate(2147483647), -2147483647);
    printf("Negation of %d is: %d. Solution should be: %d.\n", -2147483647, negate(-2147483647), 2147483647);	
	printf("Negation of %d is: %d. Solution should be: %d.\n", 0x80000000, negate(0x80000000), 0x80000000);		//Overflow test
	
	printf("\n\n");
	
	printf("Absolute Value:\n");
    printf("Abs(%d) = %d. Solution should be: %d.\n", 1, absolute(1), 1);
    printf("Abs(%d) = %d. Solution should be: %d.\n", -1, absolute(-1), 1);
    printf("Abs(%d) = %d. Solution should be: %d.\n", 10, absolute(10), 10);
    printf("Abs(%d) = %d. Solution should be: %d.\n", -10, absolute(-10), 10);
    printf("Abs(%d) = %d. Solution should be: %d.\n", 2147483647, absolute(2147483647), 2147483647);
    printf("Abs(%d) = %d. Solution should be: %d.\n", -2147483647, absolute(-2147483647), 2147483647);
    printf("Abs(%d) = %d. Solution should be: %d.\n", 0x80000000, absolute(0x80000000), 0x80000000);		//Overflow test
    printf("Abs(%d) = %d. Solution should be: %d.\n", 0, absolute(0), 0);
    
    printf("\n\n");
    
    printf("Add:\n");
    printf("%d + %d = %d. Solution should be: %d.\n", 1, 2, add(1, 2), 3);
    printf("%d + %d = %d. Solution should be: %d.\n", 2, 1, add(2, 1), 3);
    printf("%d + %d = %d. Solution should be: %d.\n", 10, 0, add(10, 0), 10);
    printf("%d + %d = %d. Solution should be: %d.\n", 0, 10, add(0, 10), 10);
    printf("%d + %d = %d. Solution should be: %d.\n", -5, 55, add(-5, 55), 50);
    printf("%d + %d = %d. Solution should be: %d.\n", 55, -5, add(55, -5), 50);
    printf("%d + %d = %d. Solution should be: %d.\n", -1, 1, add(-1, 1), 0);
    printf("%d + %d = %d. Solution should be: %d.\n", 1, -1, add(1, -1), 0);
    printf("%d + %d = %d. Solution should be: %d.\n", 0x7fffffff, 2, add(0x7fffffff, 2),  0x80000000);		//Overflow test
    printf("%d + %d = %d. Solution should be: %d.\n", 2, 0x7fffffff, add(2, 0x7fffffff),  0x80000000);		//Overflow test
    
    printf("\n\n");
    
    printf("Subtract:\n");
    printf("%d - %d = %d. Solution should be: %d.\n", 1, 2, sub(1, 2), -1);
    printf("%d - %d = %d. Solution should be: %d.\n", 2, 1, sub(2, 1), 1);
    printf("%d - %d = %d. Solution should be: %d.\n", 10, 0, sub(10, 0), 10);
    printf("%d - %d = %d. Solution should be: %d.\n", 0, 10, sub(0, 10), -10);
    printf("%d - %d = %d. Solution should be: %d.\n", -5, 55, sub(-5, 55), -60);
    printf("%d - %d = %d. Solution should be: %d.\n", 55, -5, sub(55, -5), 60);
    printf("%d - %d = %d. Solution should be: %d.\n", -1, 1, sub(-1, 1), -2);
    printf("%d - %d = %d. Solution should be: %d.\n", 1, -1, sub(1, -1), 2);
    printf("%d - %d = %d. Solution should be: %d.\n", 0x7fffffff, -100, sub(0x7fffffff, -100), 0x80000000);	//Overflow test
    printf("%d - %d = %d. Solution should be: %d.\n", 0x80000000, 2, sub(0x80000000, 2),  0x80000000);		//Overflow test
    
	printf("\n\n");
	
	printf("Multiply:\n");
	printf("%d * %d = %d. Solution should be: %d.\n", 5, 2, mul(5,2), 10);
	printf("%d * %d = %d. Solution should be: %d.\n", 2, 5, mul(2,5), 10);
	printf("%d * %d = %d. Solution should be: %d.\n", 0, 50, mul(0,50), 0);
	printf("%d * %d = %d. Solution should be: %d.\n", 50, 0, mul(50,0), 0);
	printf("%d * %d = %d. Solution should be: %d.\n", 3, -4, mul(3,-4), -12);
	printf("%d * %d = %d. Solution should be: %d.\n", -4, 3, mul(-4,3), -12);
	printf("%d * %d = %d. Solution should be: %d.\n", -12, -2, mul(-12,-2), 24);
	printf("%d * %d = %d. Solution should be: %d.\n", -2, -12, mul(-2,-12), 24);
	printf("%d * %d = %d. Solution should be: %d.\n", 0x7fffffff, 100000, mul(0x7fffffff,100000), 0x80000000);
	printf("%d * %d = %d. Solution should be: %d.\n", 100000, 0x7fffffff, mul(100000,0x7fffffff), 0x80000000);
	printf("%d * %d = %d. Solution should be: %d.\n", 0x7fffffff, 2, mul(0x7fffffff,2), 0x80000000);
	printf("%d * %d = %d. Solution should be: %d.\n", 2, 0x7fffffff, mul(2,0x7fffffff), 0x80000000);
	
	printf("\n\n");
	
	printf("Divide:\n");
	printf("%d / %d = %d. Solution should be: %d.\n", 10, 5, divide(10, 5), 2);
	printf("%d / %d = %d. Solution should be: %d.\n", 10, 2, divide(10, 2), 5);
	printf("%d / %d = %d. Solution should be: %d.\n", -20, 2, divide(-20, 2), -10);
	printf("%d / %d = %d. Solution should be: %d.\n", 20, -4, divide(20, -4), -5);
	printf("%d / %d = %d. Solution should be: %d.\n", 0, 20, divide(0, 20), 0);
	printf("%d / %d = %d. Solution should be: %d.\n", 0, 0, divide(0, 0), 0x80000000);
	printf("%d / %d = %d. Solution should be: %d.\n", 20, 0, divide(20, 0), 0x80000000);					//Divide by 0 test
	printf("%d / %d = %d. Solution should be: %d.\n", 0x80000000, -1, divide(0x80000000, -1), 0x80000000);
	
	printf("\n\n");
	
	printf("Power:\n");
	printf("%d^%d = %d. Solution should be: %d.\n", 2, 2, power(2,2), 4);
	printf("%d^%d = %d. Solution should be: %d.\n", 5, 3, power(5,3), 125);
	printf("%d^%d = %d. Solution should be: %d.\n", 6, 7, power(6,7), 279936);
	printf("%d^%d = %d. Solution should be: %d.\n", -2, 4, power(-2,4), 16);
	printf("%d^%d = %d. Solution should be: %d.\n", 5, 1, power(5,1), 5);				//x^1 test
	printf("%d^%d = %d. Solution should be: %d.\n", 8, 0, power(8,0), 1);				//x^0 test
	printf("%d^%d = %d. Solution should be: %d.\n", 0, 7, power(0,7), 0);				//0^x test
	printf("%d^%d = %d. Solution should be: %d.\n", 0, 1, power(0,1), 0);				//0^1 test
	printf("%d^%d = %d. Solution should be: %d.\n", 2, -2, power(2,-2), 0x80000000);	//Negative exponent test
	printf("%d^%d = %d. Solution should be: %d.\n", 25, 25, power(25,25), 0x80000000);	//Overflow test
	
	printf("\n\n");
	
	printf("Factorial:\n");
	printf("%d! = %d. Solution should be: %d.\n", 5, factorial(5), 120);
	printf("%d! = %d. Solution should be: %d.\n", 4, factorial(4), 24);
	printf("%d! = %d. Solution should be: %d.\n", 7, factorial(7), 5040);
	printf("%d! = %d. Solution should be: %d.\n", 0, factorial(0), 1);					//Zero test
	printf("%d! = %d. Solution should be: %d.\n", -5, factorial(-5), 0x80000000);		//Negative test
	printf("%d! = %d. Solution should be: %d.\n", 100, factorial(100), 0x80000000);		//Overflow test
	printf("%d! = %d. Solution should be: %d.\n", 3, factorial(3), 6);
	
    return 0;
}
