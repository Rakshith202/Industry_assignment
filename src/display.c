#include "main.h"

void display_plants_machines(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available.\n");
		return;
	}

	struct plant* current_plant = start;

	while (current_plant != NULL) 
	{
		printf("Plant ID: %d, Plant Name: %s\n", current_plant->plant_id, current_plant->plant_name);

		struct machine* current_machine = current_plant->mlink;

		if (current_machine == NULL) 
		{
			printf("\tNo machines available for this plant.\n");
		} 
		else 
		{
			printf("\tMachines:\n");

			struct machine* first_machine = current_machine; 
			do 
			{
				printf("\t\tMachine ID: %d, Start Time: %.2f, Stop Time: %.2f, Cycle Time: %.2f, Production: %d\n",
						current_machine->machine_id, 
						current_machine->start_time, 
						current_machine->stop_time, 
						current_machine->cycle_time, 
						current_machine->machine_production);
				current_machine = current_machine->mlink;
			} 

			while (current_machine != first_machine);  
		}

		current_plant = current_plant->plink;
		printf("\n");
	}
}

