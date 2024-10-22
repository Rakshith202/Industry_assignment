#include "main.h"


void display_total_cycle_time_and_production(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available.\n");
		return;
	}

	float total_cycle_time = 0.0;
	int total_production = 0;

	struct plant* current_plant = start;

	while (current_plant != NULL) 
	{
		struct machine* current_machine = current_plant->mlink;

		if (current_machine == NULL) 
		{
			printf("No machines available for Plant ID %d.\n", current_plant->plant_id);
		} 
		else 
		{
			struct machine* first_machine = current_machine;

			do 
			{
				total_cycle_time += current_machine->cycle_time;
				total_production += current_machine->machine_production;

				current_machine = current_machine->mlink;


				if (current_machine == first_machine) 
				{
					break; 
				}
			} 
			while (current_machine != NULL); 


			printf("Machines for Plant ID %d:\n", current_plant->plant_id);
			current_machine = first_machine; // Reset to first machine
			do 
			{
				printf("\tMachine ID: %d, Cycle Time: %.2f, Production: %d\n",
						current_machine->machine_id,
						current_machine->cycle_time,
						current_machine->machine_production);
				current_machine = current_machine->mlink;
			} 
			while (current_machine != first_machine);
		}

		current_plant = current_plant->plink;
	}

	printf("Total Cycle Time: %.2f\n", total_cycle_time);
	printf("Total Production: %d\n", total_production);
}

