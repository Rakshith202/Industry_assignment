#include "main.h"

struct machine* allocate_machine() 

{
	struct machine* new_machine = (struct machine*)malloc(sizeof(struct machine));

	if (new_machine == NULL) 
	{
		printf("Memory allocation for machine failed\n");
		menu_screen();
	}
	new_machine->mlink = NULL;  
	return new_machine;
}
