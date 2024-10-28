#include "main.h"

int plants_created = 0;  

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
	if (plants_created && start != NULL) 
	{
		printf("Plants and machines created already. Please use the Add Plant or Machine option.\n");
		printf("------------------------------------------------------------------------------------\n");
		return start;
	}

	int num_plants = validate_int_input("Enter the number of plants to create (1–100): ");
	while (num_plants < 1 || num_plants > 100) 
	{
		printf("Invalid number of plants. Please enter a value between 1 and 100.\n");
		num_plants = validate_int_input("Enter the number of plants to create (1–100): ");
	}

	for (int i = 0; i < num_plants; i++) 
	{
		struct plant* new_plant = allocate_plant();

		printf("_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");

		int plant_id = validate_int_input("Enter Plant ID (1–100): ");
		while (plant_id < 1 || plant_id > 100 || plant_id_exists(start, plant_id)) 
		{
			printf("Invalid or used Plant ID. Please enter a value between 1 and 100.\n");
			plant_id = validate_int_input("Enter Plant ID (1–100): ");
		}
		new_plant->plant_id = plant_id;

		printf("Enter Plant Name (alphabets): ");
		scanf("%s", new_plant->plant_name);
		while (!validate_plant_name(new_plant->plant_name)) 
		{
			printf("Invalid plant name.Use alphabets only.\n");
			printf("Enter Plant Name: ");
			scanf("%s", new_plant->plant_name);
		}

		start = update_plant(start, new_plant);

		int num_machines = validate_int_input("\nEnter the number of machines for this plant (0–1000): ");
		while (num_machines < 0 || num_machines > 1000) 
		{
			printf("Invalid number of machines. Please enter a value between 0 and 1000.\n");
			num_machines = validate_int_input("\nEnter the number of machines for this plant (0–1000): ");
		}

		for (int j = 0; j < num_machines; j++) 
		{
			struct machine* new_machine = allocate_machine();

			int machine_id = validate_int_input("Enter Machine ID (1–1000): ");
			while (machine_id < 1 || machine_id > 1000 || machine_id_exists(new_plant, machine_id)) 
			{
				printf("Invalid or used Machine ID. Please enter a value between 1 and 1000.\n");
				machine_id = validate_int_input("Enter Machine ID (1–1000): ");
			}
			new_machine->machine_id = machine_id;

			update_machine(new_plant, new_machine);
		}
	}

	plants_created = 1;  
	printf("Successfully created %d plants and their respective machines.\n", num_plants);
	printf("---------------------------------------------------------------------------\n");
	return start;
}
