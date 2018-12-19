#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

int main(){
	
	//Test Negatives
	printf("%f\n", add(-6.5,-1.5));			//-8.0
	printf("%f\n", add(6.5,-1.5));			//5.0
	printf("%f\n", add(-7.15,-0.15));		//-7.3
	printf("%f\n", add(-10.25,-2.25));		//-12.5
	printf("%f\n", add(7.25,-2.25));		//5.0
	printf("%f\n", add(3.0,2.25));			//5.25
	printf("%f\n", add(5.0,-2.5));			//2.5
	printf("%f\n", add(6.25, 4.75));		//11.0
	printf("%f\n", add(-2.5,5.0));			//2.5
	printf("%f\n", add(-1.5,-6.5));			//-8.0
	printf("%f\n", add(-1.5,6.5));			//5.0
	printf("%f\n", add(-0.15,-7.15));		//-7.3
	printf("%f\n", add(-2.25,-10.25));		//-12.5
	printf("%f\n", add(-6.5,-1.5));			//-8.0
	printf("%f\n", add(6.5,-1.5));			//5.0
	printf("%f\n", add(-7.15,-0.15));		//-7.3
	printf("%f\n", add(-10.25,-2.25));		//-12.
	printf("%f\n", add(7.25,-2.25));		//5.0
	printf("\n");//Test Positives
	printf("%f\n", add(0.25,1.0));			//1.25
	printf("%f\n", add(1.25,2.0));			//3.25
	printf("%f\n", add(2.25,3.0));			//5.25
	printf("%f\n", add(3.25,4.0));			//7.25
	printf("%f\n", add(4.25,5.0));			//9.25
	printf("%f\n", add(5.25,6.0));			//11.25
	printf("%f\n", add(6.25,7.0));			//13.25
	printf("%f\n", add(7.25,8.0));			//15.25
	printf("%f\n", add(8.25,9.0));			//17.25
	printf("%f\n", add(9.25,10.0));			//19.25
	printf("%f\n", add(10.25,11.0));		//21.25
	printf("%f\n", add(11.25,12.0));		//23.25
	printf("%f\n", add(12.25,13.0));		//25.25
	printf("%f\n", add(13.25,14.0));		//27.25
	printf("%f\n", add(14.25,15.0));		//29.25
	printf("\n");
	printf("%f\n", add(1.0,0.25));			//1.25
	printf("%f\n", add(2.0,1.25));			//3.25
	printf("%f\n", add(3.0,2.25));			//5.25
	printf("%f\n", add(4.0,3.25));			//7.25
	printf("%f\n", add(5.0,4.25));			//9.25
	printf("%f\n", add(6.0,5.25));			//11.25
	printf("%f\n", add(7.0,6.25));			//13.25
	printf("%f\n", add(8.0,7.25));			//15.25
	printf("%f\n", add(9.0,8.25));			//17.25
	printf("%f\n", add(10.0,9.25));			//19.25
	printf("%f\n", add(11.0,10.25));		//21.25
	printf("%f\n", add(12.0,11.25));		//23.25
	printf("%f\n", add(13.0,12.25));		//25.25
	printf("%f\n", add(14.0,13.25));		//27.25
	printf("%f\n", add(15.0,14.25));		//29.25
	printf("\n");
	printf("%f\n", add(6.5,0.5));			//7.0
	printf("%f\n", add(6.5,1.5));			//8.0	
	printf("%f\n", add(6.5,2.5));			//9.0	
	printf("%f\n", add(6.5,3.5));			//10.0
	printf("%f\n", add(6.5,4.5));			//11.0
	printf("%f\n", add(6.5,5.5));			//12.0
	printf("%f\n", add(6.5,6.5));			//13.0
	printf("%f\n", add(6.5,7.5));			//14.0
	printf("%f\n", add(6.5,8.5));			//15.0
	printf("\n");
	printf("%f\n", add(8.0,0.25));			//8.25
	printf("%f\n", add(8.0,1.25));			//9.25
	printf("%f\n", add(8.0,2.25));			//10.25
	printf("%f\n", add(8.0,3.25));			//11.25
	printf("%f\n", add(8.0,4.25));			//12.25
	printf("%f\n", add(8.0,5.25));			//13.25
	printf("%f\n", add(8.0,6.25));			//14.25
	printf("%f\n", add(8.0,7.25));			//15.25
	printf("%f\n", add(8.0,8.25));			//16.25
	printf("\n");
	printf("%f\n", add(25.0,0.25));			//25.25
	printf("%f\n", add(25.0,1.25));			//26.25
	printf("%f\n", add(25.0,2.25));			//27.25
	printf("%f\n", add(25.0,3.25));			//28.25
	printf("%f\n", add(25.0,4.25));			//29.25
	printf("%f\n", add(25.0,5.25));			//30.25
	printf("%f\n", add(25.0,6.25));			//31.25
	printf("%f\n", add(25.0,7.25));			//32.25
	printf("%f\n", add(25.0,8.25));			//33.25
	printf("\n");
	printf("%f\n", add(50.0,0.25));			//50.25
	printf("%f\n", add(50.0,1.25));			//51.25
	printf("%f\n", add(50.0,2.25));			//52.25
	printf("%f\n", add(50.0,3.25));			//53.25
	printf("%f\n", add(50.0,4.25));			//54.25
	printf("%f\n", add(50.0,5.25));			//55.25
	printf("%f\n", add(50.0,6.25));			//56.25
	printf("%f\n", add(50.0,7.25));			//57.25
	printf("%f\n", add(50.0,8.25));			//58.25
	//Test special
	printf("%f\n", add(INFINITY,2.5));		//inf
	printf("%f\n", add(7.5,INFINITY));		//inf

	printf("%f\n", add(NAN,8.25));			//nan
	printf("%f\n", add(8.25,NAN));			//nan

	return 0;
}
