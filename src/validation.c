#include "main.h"
#include <ctype.h>
#include <math.h>

int valid_integer(const char* str) 
{
	for (int i = 0; i < strlen(str); i++) 
	{
		if (!isdigit(str[i])) 
		{
			return 0;  
		}
	}
	return 1;  
}


int valid_float(const char* str) 
{
	int decimal_count = 0; 
	for (int i = 0; i < strlen(str); i++) 
	{
		if (str[i] == '.') 
		{
			decimal_count++;  
			if (decimal_count > 1) 
			{
				return 0;  
			}
		} 
		else if (!isdigit(str[i])) 
		{
			return 0;  
		}
	}
	return 1;  
}


int validate_int_input(const char* data) 
{
	char input[100];  

	while (1) 
	{
		printf("%s", data);
		scanf("%s", input);  


		if (valid_integer(input)) 
		{
			return atoi(input);  
		} 
		else 
		{
			printf("Invalid input, please enter a valid integer.\n");
		}
	}
}


float validate_float_input(const char* data)
{
	char input[100];

	while (1) 
	{
		printf("%s", data);
		scanf("%s", input);  


		if (valid_float(input)) 
		{
			return atof(input);  
		} 

		else 
		{
			printf("Invalid input, please enter a valid floating-point number.\n");
		}
	}
}




int validate_time_format(float time) 
{
	int hours = (int)time;          
	int minutes = (int)((time - hours) * 100 + 0.5); 


	if (hours < 0 || hours > 23) 
	{
		// printf("Invalid hours. Please enter time in hh.mm format where hh is 00-23.\n");
		return 0;
	}

	if (minutes < 0 || minutes > 59) 
	{
		// printf("Invalid minutes. Please enter time in hh.mm format where mm is 00-59.\n");
		return 0;
	}

	return 1;
}
