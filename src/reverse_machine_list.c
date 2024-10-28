#include "main.h"

struct plant* reverse_machines(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available to reverse machines.\n");
		printf("----------------------------------------------------\n");
		return start;
	}

	int plant_id = validate_int_input("Enter Plant ID to reverse machines: ");
	struct plant* current_plant = search_plant_by_id(start, plant_id);

	if (current_plant == NULL) 
	{

		printf("Plant with ID %d not found. Reversal not done.\n", plant_id);
		printf("----------------------------------------------------\n");
		return start;
	}

	struct machine* current_machine = current_plant->mlink;

	if (current_machine == NULL || current_machine->mlink == current_machine) 
	{
		printf("Reverse Not Necessary\n");
		printf("----------------------------------------------------\n");
		return start; 
	}

	struct machine* first_machine = current_machine;
	struct machine* prev = NULL;
	struct machine* next = NULL;

	do 
	{
		next = current_machine->mlink;
		current_machine->mlink = prev;  
		prev = current_machine;          
		current_machine = next;          
	} 
	while (current_machine != first_machine); 

	first_machine->mlink = prev; 
	current_plant->mlink = prev;  

	printf("Machines reversed successfully for Plant ID %d.\n", plant_id);
	printf("----------------------------------------------------\n");
	return start;
}

