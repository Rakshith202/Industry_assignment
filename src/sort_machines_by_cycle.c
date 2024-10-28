#include "main.h"

void swap_machines(struct machine* a, struct machine* b) 
{
	int temp_id = a->machine_id;
	float temp_start_time = a->start_time;
	float temp_stop_time = a->stop_time;
	float temp_cycle_time = a->cycle_time;
	int temp_production = a->machine_production;

	a->machine_id = b->machine_id;
	a->start_time = b->start_time;
	a->stop_time = b->stop_time;
	a->cycle_time = b->cycle_time;
	a->machine_production = b->machine_production;

	b->machine_id = temp_id;
	b->start_time = temp_start_time;
	b->stop_time = temp_stop_time;
	b->cycle_time = temp_cycle_time;
	b->machine_production = temp_production;
}

void sort_machines_by_cycle_time(struct plant* current_plant) 
{
	if (current_plant == NULL || current_plant->mlink == NULL) 
	{
		printf("No machines available to sort.\n");
		return;
	}

	int swapped;
	struct machine* current_machine;
	struct machine* next_machine;
	struct machine* first_machine = current_plant->mlink;

	while (1) 
	{
		swapped = 0;
		current_machine = current_plant->mlink;


		while (1) 
		{
			next_machine = current_machine->mlink;

			if (next_machine == first_machine) 
			{
				break; 
			}

			if (current_machine->cycle_time > next_machine->cycle_time) 
			{
				swap_machines(current_machine, next_machine);
				swapped = 1;
			}

			current_machine = next_machine;

			if (current_machine == first_machine) 
			{
				break; 
			}
		}


		if (!swapped) 
		{
			break;
		}
	}

	printf("Machines sorted by cycle time successfully.\n");
	printf("----------------------------------------------------\n");
}

struct plant* sort_machines(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("Please create plants and machines before sorting.\n");
		printf("----------------------------------------------------\n");
		return start;
	}

	int plant_id = validate_int_input("Enter Plant ID to sort machines: ");
	struct plant* current_plant = search_plant_by_id(start, plant_id);

	if (current_plant == NULL) 
	{
		printf("Plant with ID %d not found. Sorting not donw.\n", plant_id);
		printf("----------------------------------------------------\n");
		return start;
	}

	sort_machines_by_cycle_time(current_plant);
	return start;
}
