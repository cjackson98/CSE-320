#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

double add( double x, double y){	
		
	int test = 0;
		
	union double_precision x_union;
	union double_precision y_union;
	union double_precision final;
	
	x_union.drep = x;
	y_union.drep = y;
		
	if( ((x_union.irep >> 52) & 0x7ff) == 0x7ff || ((y_union.irep >> 52) & 0x7ff) == 0x7ff ){
		if(x_union.irep == 0x7ff0000000000000 || y_union.irep == 0x7ff0000000000000){
			return INFINITY;
		}
		return NAN;
	}	
	if( ((x_union.irep >> 52) & 0x7ff) == 0x000 || ((y_union.irep >> 52) & 0x7ff) == 0x000 ){
		if( ((x_union.irep >> 52) & 0x7ff) == 0x000 ){
			return y;
		}
		return x;
	}
			
	unsigned long long x_biased = (x_union.irep >> 52) & 0x7ff;
	unsigned long long y_biased = (y_union.irep >> 52) & 0x7ff;
	unsigned long long final_biased;
		
	unsigned long long x_fraction = x_union.irep & 0x000fffffffffffff;
	unsigned long long y_fraction = y_union.irep & 0x000fffffffffffff;
	unsigned long long final_fraction;
	
	unsigned long long x_sign = x_union.irep >> 63;
	unsigned long long y_sign = y_union.irep >> 63;
	unsigned long long final_sign = 0x0000000000000000;
	
	unsigned long long x_significand = x_fraction | 0x0010000000000000;
	unsigned long long y_significand = y_fraction | 0x0010000000000000;
	unsigned long long final_significand;
	
	if(test){
		printf("X -- Significand: %016llx\n", x_significand);
		printf("Y -- Significand: %016llx\n", y_significand);
		printf("X -- Exponent (biased): %016llx\n", x_biased);
		printf("Y -- Exponent (biased): %016llx\n", y_biased);
	}
	
	if(x_sign != y_sign && x_fraction == y_fraction && x_biased == y_biased){
		return 0;
	}
	/*
	if(x_sign == 1){
		x_significand = -x_significand;
		//x_significand = x_significand & 0x00ffffffffffffff;
		printf("Negated x_significand: %016llx\n", x_significand);
	}
	if(y_sign == 1){
		y_significand = -y_significand;
		//y_significand = y_significand & 0x00ffffffffffffff;
		printf("Negated y_significand: %016llx\n", y_significand);
	}
	*/
	unsigned long long shift;
	if(x_biased > y_biased){
		//printf("x > y\n");
		shift = x_biased - y_biased;
		//printf("Shift by: %016llx\n", shift);	
		y_significand = y_significand >> shift;	
		
		//negate if necessary
		if(x_sign == 1){
			x_significand = -x_significand;
			//x_significand = x_significand & 0x00ffffffffffffff;
			//printf("Negated x_significand: %016llx\n", x_significand);
		}
		if(y_sign == 1){
			y_significand = -y_significand;
			//y_significand = y_significand & 0x00ffffffffffffff;
			//printf("Negated y_significand: %016llx\n", y_significand);
		}		
		
		//printf("X: %016llx + Y: %016llx\n", x_significand, y_significand);	

		
		final_significand = x_significand + y_significand;		
		final_biased = x_biased;
		
	}
	else if(x_biased < y_biased){
		//printf("x < y\n");
		shift = y_biased - x_biased;		
		x_significand = x_significand >> shift;		
		
		//negate if necessary
		if(x_sign == 1){
			x_significand = -x_significand;
			//x_significand = x_significand & 0x00ffffffffffffff;
			//printf("Negated x_significand: %016llx\n", x_significand);
		}
		if(y_sign == 1){
			y_significand = -y_significand;
			//y_significand = y_significand & 0x00ffffffffffffff;
			//printf("Negated y_significand: %016llx\n", y_significand);
		}

		//printf("X: %016llx + Y: %016llx\n", x_significand, y_significand);	
		
		final_significand = x_significand + y_significand;				
		final_biased = y_biased;
		
	}
	else if(x_biased == y_biased){
		//printf("x = y\n");
		
		//negate if necessary
		if(x_sign == 1){
			x_significand = -x_significand;
			//x_significand = x_significand & 0x00ffffffffffffff;
			//printf("Negated x_significand: %016llx\n", x_significand);
		}
		if(y_sign == 1){
			y_significand = -y_significand;
			//y_significand = y_significand & 0x00ffffffffffffff;
			//printf("Negated y_significand: %016llx\n", y_significand);
		}		

		//printf("X: %016llx + Y: %016llx\n", x_significand, y_significand);	
		
		final_significand = x_significand + y_significand;				
		final_biased = x_biased;
		
	}
	
	//printf("Added significands before negated (if needed): %016llx\n", final_significand);

	//printf("Test: %016llx\n", final_significand >> 56);

	if((final_significand >> 63) == 0x0000000000000001){//if solution is negative
		final_significand = -final_significand;
		final_sign = 1;
	}
	/*
	00.xxxxxxxx  -- normalize by shifting left some number of digits
	01.xxxxxxxx  -- already normalized
	10.xxxxxxxx  -- normalize by shifting right exactly one digit
	11.xxxxxxxx  -- normalize by shifting right exactly one digit

	You can detect the last two cases using a mask such as 0000 0000 0010 (binary).  Note that the 1 will check the bit which is two positions to the left of the implied binary point.

	You can check the second case using a mask such as 0000 0000 0001 (binary) to get the bit immediately to the left of the implied binary point.
	 
	For the first case, repeatedly shift left by one position until it is normalized (a variation on the second case).
	*/	
	
	//printf("Final Significand before normalize %016llx\n", final_significand);
	//printf("Normalized check: %016llx\n", final_significand >> 52);
	
	if( (final_significand | 0x000fffffffffffff) != 0x001fffffffffffff){
		//printf("Needs to be normalized\n");
		
		if( (final_significand >> 53) == 0x0000000000000001){// DOUBLE CHECK/FIX
			//printf("Shift right by one and ?adding? 1 to exponent (pt1)\n");
			final_significand = final_significand >> 1;
			final_biased += 1;
		}
		else if( (final_significand >> 52) == 0x0000000000000002){
			//printf("Shift right by one and ?adding? 1 to exponent (pt2)\n");
			final_significand = final_significand >> 1;
			final_biased += 1;
		}
		else{
			//printf("shift left\n");
			while( (final_significand >> 52) != 0x0000000000000001){
				//printf("Shift left until happy and ?subtractinging? 1 to exponent\n");
				final_significand = final_significand << 1;
				final_biased -= 1;
			}
		}
	}
			
	final_fraction = final_significand & 0x000FFFFFFFFFFFFF;
	final_biased = final_biased << 52;
	
	if(test){
		printf("Final sign: %016llx\n", final_sign);
		printf("Final_biased: %016llx\n", final_biased);
		printf("Final_fraction: %016llx\n", final_fraction);
	}
	
	if(final_sign == 1){
		final.irep = 0x8000000000000000 | final_biased | final_fraction;
	}
	else{
		final.irep = 0x0000000000000000 | final_biased | final_fraction;
	}
	
	return final.drep;
}
