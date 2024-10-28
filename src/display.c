#include "main.h"

void display_menu(struct plant* start) 
{
	int choice;

	while (1) 
	{
		printf("------------------------------\n");
		printf("Display Details Menu:\n");
		printf("1. Display All Plants\n");
		printf("2. Display Machines by using Plant ID\n");
		printf("3. Display Cycle Time and Production of the Plant\n");
		printf("4. Display Cycle Time and Production of a Machine using Plant ID and Machine ID\n");
		printf("5. Display All Plants and Number of Machines with their IDs\n");
		printf("6. Back to Main Menu\n");
		choice = validate_int_input("Enter your choice: ");

		switch (choice) 
		{
			case 1:
				display_all_plants(start);
				break;
			case 2:
				display_machines_by_plant_id(start);
				break;
			case 3:
				display_cycle_time_production_by_plant(start);
				break;
			case 4:
				display_cycle_time_production_by_machine(start);
				break;
			case 5:
				display_plants_machines_summary(start);
				break;
			case 6:
				return;  
				 printf("----------------------------------------------------\n");
			default:
				printf("Invalid choice, please try again.\n");
				break;
		}
	}
}

void display_all_plants(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	struct plant* current_plant = start;
	while (current_plant != NULL) 
	{
		printf("Plant ID: %d, Plant Name: %s\n", current_plant->plant_id, current_plant->plant_name);
		current_plant = current_plant->plink;
	}
}

void display_machines_by_plant_id(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	int plant_id = validate_int_input("Enter the Plant ID: ");
	struct plant* current_plant = start;

	while (current_plant != NULL && current_plant->plant_id != plant_id) 
	{
		current_plant = current_plant->plink;
	}

	if (current_plant == NULL) 
	{
		printf("Plant with ID %d not found.\n", plant_id);
		printf("----------------------------------------------------\n");
	} 
	else 
	{
		printf("Machines for Plant ID: %d\n", plant_id);
		struct machine* current_machine = current_plant->mlink;
		if (current_machine == NULL) 
		{
			printf("No machines available for this plant.\n");
			printf("----------------------------------------------------\n");
		} 
		else 
		{
			struct machine* first_machine = current_machine;
			while (1) 
			{
				printf("Machine ID: %d\n", current_machine->machine_id);
				current_machine = current_machine->mlink;
				if (current_machine == first_machine) 
				{
					break;
				}
			}
		}
	}
}

void display_cycle_time_production_by_plant(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	struct plant* current_plant = start;
	while (current_plant != NULL) 
	{
		float total_cycle_time = 0;
		int total_production = 0;

		struct machine* current_machine = current_plant->mlink;
		if (current_machine != NULL) 
		{
			struct machine* first_machine = current_machine;
			while (1) 
			{
				total_cycle_time += current_machine->cycle_time;
				total_production += current_machine->machine_production;
				current_machine = current_machine->mlink;
				if (current_machine == first_machine) 
				{
					break;
				}
			}
		}

		printf("Plant ID: %d, Total Cycle Time: %.2f, Total Production: %d\n", current_plant->plant_id, total_cycle_time, total_production);
		printf("-------------------------------------------------------------------------------------------\n");
		current_plant = current_plant->plink;
	}
}

void display_cycle_time_production_by_machine(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	int plant_id = validate_int_input("Enter the Plant ID: ");
	int machine_id = validate_int_input("Enter the Machine ID: ");

	struct plant* current_plant = start;
	while (current_plant != NULL && current_plant->plant_id != plant_id) 
	{
		current_plant = current_plant->plink;
	}

	if (current_plant == NULL) 
	{
		printf("Plant with ID %d not found.\n", plant_id);
		printf("----------------------------------------------------\n");
		return;
	}

	struct machine* current_machine = current_plant->mlink;
	if (current_machine == NULL) 
	{
		printf("No machines available for this plant.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	struct machine* first_machine = current_machine;
	while (1) 
	{
		if (current_machine->machine_id == machine_id) 
		{
			printf("Machine ID: %d, Cycle Time: %.2f, Production: %d\n", current_machine->machine_id, current_machine->cycle_time, current_machine->machine_production);
			printf("------------------------------------------------------------------------------\n");
			return;
		}
		current_machine = current_machine->mlink;
		if (current_machine == first_machine) 
		{
			break;
		}
	}

	printf("Machine with ID %d not found in Plant ID %d.\n", machine_id, plant_id);
	printf("-----------------------------------------------------------------------\n");
}

void display_plants_machines_summary(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("No plants available.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	struct plant* current_plant = start;

	while (current_plant != NULL) 
	{
		printf("Plant ID: %d, Plant Name: %s\n", current_plant->plant_id, current_plant->plant_name);
		printf("--------------------------------------------------------------\n");

		struct machine* current_machine = current_plant->mlink;
		int machine_count = 0;

		if (current_machine == NULL) 
		{
			printf("\tNo machines available for this plant.\n");
			printf("----------------------------------------------------\n");
		} 
		else 
		{
			printf("\tMachine IDs: ");
			struct machine* first_machine = current_machine;

			while (1) 
			{
				printf("%d ", current_machine->machine_id);
				machine_count++;
				current_machine = current_machine->mlink;
				if (current_machine == first_machine) 
				{
					break;
				}
			}
			printf("\n\tTotal Machines: %d\n", machine_count);
			printf("----------------------------------------------------\n");
		}

		current_plant = current_plant->plink;
		printf("\n");
	}
}
