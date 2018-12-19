#include <stdio.h>

int convert(const char string[], int base, int* result){
	
	if(base < 2 || base >36)//If invalid base, conversion fails
	{
		*result = NULL;
		return 0;
	}
	
	int size = 0;
	int x = 0;
	
	while(string[x] != NULL)//get size of character array (string)
	{
		size++;
		x = x + 1;
	}
		
	char pos_neg = 'p';	//Used to declare if number to be converted is +/-
	char holder;		//Used as a temporary holder when converting letters from lower case to upper case
	int total=0;		//Used as final, converted number
	int start = -100;	//Used as the starting position of the number to be converted in the character array (set to -100 to test for erroneous entries)
	int end = 0;		//Used as the ending position of the number to be converted in the charracter array
	int value = 0;		//Used as a holder value when converting a character to an int
	int y = 0;			//Used in formula when converting to two's compliment
	int temp = 0;		//Used as a temporary value for the return value of the power function
	
	for(x = 0 ; x < size ; x++)//finds the positive or negative if possible. if not, posneg is set to p
	{
		if(string[x] == '+')//if starting character is positive, set pos_neg = positive (p), set start = to current x value, and stop searching
		{
			pos_neg = 'p';
			start = x;
			break;
		}
		if(string[x] == '-')//if starting character is negative, set pos_neg = negative (n), set start = to current x value, and stop searching
		{
			pos_neg = 'n';
			start = x;
			break;
		}
		if(string[x] == '0' || string[x] == '1' || string[x] == '2' || string[x] == '3' || string[x] == '4' || string[x] == '5' || string[x] == '6' || string[x] == '7' || string[x] == '8' || string[x] == '9' )//if loop reaches here, there is no +/-. Set start = current x value and stop searching 
		{
			start = x-1;
			break;
		}
		continue;
	}
	
	for(x = start+1 ; x < size ; x++)//find ending position of value to be converted
	{
		if(string[x] == '0' || string[x] == '1' || string[x] == '2' || string[x] == '3' || string[x] == '4' || string[x] == '5' || string[x] == '6' || string[x] == '7' || string[x] == '8' || string[x] == '9' )//if current element is 0-9
		{			
			value = string[x] - '0';//convert to int
			if(value >= base)//If the value is more than the base, set end = x (base 3 = (1 to 2), base 4 = (1 to 3), base 5 = (1 to 4), etc so number should never be greater than or equal to the base)
			{
				end = x;
				break;
			}
		}
		else//if current element is a letter
		{
			holder = string[x];
			if (string[x] >= 'a' && string[x] <= 'z')//convert lower case letter to upper case
			{
				holder = string[x] - 32;
			}
			value = (holder - 'A') + 10;//convert to int
			if(value >= base)//If the value is more than the base, set end = x (base 3 = (1 to 2), base 4 = (1 to 3), base 5 = (1 to 4), etc so number should never be greater than or equal to the base)
			{
				end = x;
				break;
			}
		}
	}
	
	if(start == -100)//If there is no start value (if start is still equal to its inital value) conversion fails
	{
		*result = NULL;
		return 0;
	}
	
	if(end == 0)//if there is not ending character (aside from null at the end of the character array), set end = size (last value of character array)
	{
		end = size;
	}
	
	//printf("Start: %d. End: %d.\n", start, end);
	//printf("Start: %c. End: %c.\n", string[start], string[end]);
	
	if(start + 1 == end && (string[start] == '+' || string[start] == '-'))//if there are no numbers between starting and ending character conversion fails
	{
		*result = NULL;
		return 0;
	}
	
	size = 0;
	for(x = start+1 ; x < end ; x++)//get size of array only including the elements/characters we care about (the number to be converted)
	{
		size++;
	}
	y = size - 1;
	
	for(x = start+1 ; x < end ; x++)//convert to base 10
	{
		if(string[x] == '0' || string[x] == '1' || string[x] == '2' || string[x] == '3' || string[x] == '4' || string[x] == '5' || string[x] == '6' || string[x] == '7' || string[x] == '8' || string[x] == '9' )//if 0-9
		{
			value = string[x] - '0';//convert to int
			temp = power(base, y);
			total = total + (value * temp);
		}
		else//if letter
		{
			holder = string[x];
			
			if (string[x] >= 'a' && string[x] <= 'z')//convert to upper case
			{
				holder = string[x] - 32;
			}
			value = (holder - 'A') + 10;//convert to int
			temp = power(base, y);
			total = total + (value * temp);
		}
		y = y-1;
	}
	
	//printf("Number in base 10 form: %d\n", total);
		
	if(pos_neg == 'p')//if starting character was +, set result = the value found
	{
		*result = total;
	}
	
	if(pos_neg == 'n')//if starting character was -, set result = the negative of the value found
	{
		*result = total * -1;
	}
	
	return 1;
}

int power(int x,int n)//created to use exponents. Arguments x and n are equivilant to x^n
{
    int ctr;//ctr for the loop
    int val = 1;//solution

    for (ctr = 0; ctr < n; ++ctr)
    {
        val = val * x;
	}
    return val;
}

