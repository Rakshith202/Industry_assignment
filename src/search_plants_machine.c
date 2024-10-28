#include "main.h"

struct plant* search_plant_by_id(struct plant* start, int plant_id) 
{
	if (start == NULL) 
	{
		printf("Please create the plant and machine before searching.\n");
		printf("----------------------------------------------------------------\n");
		return NULL;
	}

	struct plant* current = start;

	while (current != NULL) 
	{
		if (current->plant_id == plant_id) 
		{
			printf("Plant found: ID = %d, Name = %s\n", current->plant_id, current->plant_name);
			printf("----------------------------------------------------\n");
			return current;  
		}
		current = current->plink;
	}

	printf("Plant with ID %d not found.\n", plant_id);
	printf("----------------------------------------------------\n");
	return NULL;  
}

struct machine* search_machine_by_id(struct plant* current_plant, int machine_id) 
{
	if (current_plant->mlink == NULL) 
	{
		printf("No machines available for this plant.\n");
		printf("----------------------------------------------------\n");
		return NULL;
	}

	struct machine* current_machine = current_plant->mlink;
	struct machine* first_machine = current_machine;  

	do 
	{
		if (current_machine->machine_id == machine_id) 
		{
			printf("Machine found: ID = %d, Start Time = %.2f, Stop Time = %.2f, Production = %d\n",
					current_machine->machine_id, current_machine->start_time, 
					current_machine->stop_time, current_machine->machine_production);
			printf("------------------------------------------------------------------------\n");
			return current_machine;
		}
		current_machine = current_machine->mlink;
	} 
	while (current_machine != first_machine);  

	printf("Machine with ID %d not found.\n", machine_id);
	printf("----------------------------------------------------\n");
	return NULL;
}

struct plant* search_plants_machines(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("Please create the plant and machine to search.\n");
		printf("----------------------------------------------------\n");
		return NULL;
	}

	int choice = validate_int_input("1. Search by Plant ID\n2. Search by Machine ID\n3.Back\nChoose: ");

	if (choice == 1) 
	{
		int plant_id = validate_int_input("Enter Plant ID to search: ");
		return search_plant_by_id(start, plant_id);
	} 
	else if (choice == 2) 
	{
		int plant_id = validate_int_input("Enter Plant ID of the machine : ");
		struct plant* current_plant = search_plant_by_id(start, plant_id);

		if (current_plant == NULL) 
		{
			printf("Plant with ID %d not found. Machine search terminated.\n", plant_id);
			printf("----------------------------------------------------\n");
			return NULL;
		}

		int machine_id = validate_int_input("Enter Machine ID to search: ");
		search_machine_by_id(current_plant, machine_id);
	}
	else if (choice == 3)
	{
		return start;
	} 
	else 
	{
		printf("Invalid choice.\n");
	}

	return NULL;
}

