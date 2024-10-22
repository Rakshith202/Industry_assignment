#include "main.h"

int plant_id_exists(struct plant* start, int plant_id) 
{
	struct plant* current = start;
	while (current != NULL) 
	{
		if (current->plant_id == plant_id) 
		{
			return 1;
		}
		current = current->plink;
	}
	return 0;
}

int machine_id_exists(struct plant* current_plant, int machine_id) 
{
	struct machine* first_machine = current_plant->mlink;
	if (first_machine == NULL) 
	{
		return 0;
	}

	struct machine* current_machine = first_machine;
	while (current_machine->mlink != first_machine) 
	{
		if (current_machine->machine_id == machine_id) 
		{
			return 1;
		}
		current_machine = current_machine->mlink;
	}
	if (current_machine->machine_id == machine_id) 
	{
		return 1;
	}
	return 0;
}

struct plant* update_plant(struct plant* start, struct plant* new_plant) 
{
	if (start == NULL) 
	{
		return new_plant;
	}

	struct plant* current = start;
	while (current->plink != NULL) 
	{
		current = current->plink;
	}

	current->plink = new_plant;
	return start;
}

void update_machine(struct plant* current_plant, struct machine* new_machine) 
{
	if (current_plant->mlink == NULL) 
	{
		current_plant->mlink = new_machine;
		new_machine->mlink = new_machine;
	} 
	else 
	{
		struct machine* first_machine = current_plant->mlink;
		struct machine* current_machine = first_machine;

		while (current_machine->mlink != first_machine) 
		{
			current_machine = current_machine->mlink;
		}

		current_machine->mlink = new_machine;
		new_machine->mlink = first_machine;
	}
}

struct plant* create_plants_machines(struct plant* start) 
{
	int num_plants = validate_int_input("Enter the number of plants to create: ");

	for (int i = 0; i < num_plants; i++) 
	{
		struct plant* new_plant = allocate_plant();

		printf("_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");

		int plant_id = validate_int_input("Enter Plant ID: ");
		while (plant_id_exists(start, plant_id)) 
		{
			printf("Plant ID used.\n");
			plant_id = validate_int_input("Enter Plant ID: ");
		}
		new_plant->plant_id = plant_id;

		printf("Enter Plant Name: ");
		scanf("%s", new_plant->plant_name);

		start = update_plant(start, new_plant);

		int num_machines = validate_int_input("\nEnter the number of machines for this plant: ");

		for (int j = 0; j < num_machines; j++) 
		{
			struct machine* new_machine = allocate_machine();

			int machine_id = validate_int_input("Enter Machine ID: ");
			while (machine_id_exists(new_plant, machine_id)) 
			{
				printf("Machine ID used.\n ");
				machine_id = validate_int_input("Enter Machine ID: ");
			}
			new_machine->machine_id = machine_id;

			while (1) 
			{
				new_machine->start_time = validate_float_input("Enter Machine Start Time in 24hr clk (hh.mm): ");
				if (validate_time_format(new_machine->start_time)) 
				{
					break; 
				} 
				else 
				{
					printf("Invalid time format. Please re-enter the start time.\n");
				}
			}


			while (1) 
			{
				new_machine->stop_time = validate_float_input("Enter Machine Stop Time in 24hr clk (hh.mm): ");
				if (validate_time_format(new_machine->stop_time)) 
				{
					break; 
				} 
				else 
				{
					printf("Invalid time format. Please re-enter the stop time.\n");
				}
			}

			cycle_time_calculation(new_machine);
			new_machine->machine_production = 1;

			update_machine(new_plant, new_machine);
		}
	}

	printf("Successfully created %d plants and their respective machines.\n", num_plants);
	return start;
}

