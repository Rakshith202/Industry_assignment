#include "main.h"


void delete_plant_at_position(struct plant **start, int plant_id) 
{
	struct plant *current_plant = *start;
	struct plant *prev_plant = NULL;

	while (current_plant != NULL) 
	{
		if (current_plant->plant_id == plant_id) 
		{
			if (prev_plant == NULL) 
			{
				*start = current_plant->plink;  
			} 
			else 
			{
				prev_plant->plink = current_plant->plink;
			}


			struct machine *temp_m = current_plant->mlink;
			if (temp_m != NULL) 
			{
				struct machine *first_machine = temp_m;
				struct machine *next_m = NULL;
				while (temp_m->mlink != first_machine)
				{
					next_m = temp_m->mlink;
					free(temp_m);  
					temp_m = next_m;
				}
				free(temp_m); 
			}

			free(current_plant);  
			printf("Plant ID %d deleted.\n", plant_id);
			printf("----------------------------------------------------\n");
			return;
		}
		prev_plant = current_plant;
		current_plant = current_plant->plink;  
	}

	printf("Plant ID %d not found.\n", plant_id);
	printf("----------------------------------------------------\n");
}


void delete_machine_by_id(struct plant* current_plant, int machine_id) 
{
	if (current_plant->mlink == NULL) 
	{
		printf("No machines available to delete.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	struct machine* temp = current_plant->mlink;
	struct machine* prev = NULL;


	if (temp->machine_id == machine_id) 
	{
		if (temp->mlink == current_plant->mlink) 
		{
			free(temp);
			current_plant->mlink = NULL;
			printf("Machine ID %d deleted.\n", machine_id);
			printf("----------------------------------------------------\n");
			return;
		} 
		else 
		{
			struct machine* last = current_plant->mlink;
			while (last->mlink != current_plant->mlink) 
			{
				last = last->mlink;
			}
			last->mlink = temp->mlink;
			current_plant->mlink = temp->mlink;
			free(temp);
			printf("Machine ID %d deleted.\n", machine_id);
			printf("----------------------------------------------------\n");
			return;
		}
	}

	struct machine* start_machine = temp;
	temp = temp->mlink;
	while (temp != start_machine) 
	{
		if (temp->machine_id == machine_id) 
		{
			prev->mlink = temp->mlink;
			free(temp);
			printf("Machine ID %d deleted.\n", machine_id);
		 	printf("----------------------------------------------------\n");	
			return;
		}

		prev = temp;
		temp = temp->mlink;
	}

	printf("Machine ID %d not found.\n", machine_id);
	printf("----------------------------------------------------\n");
}


struct plant* delete_plants_machines(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("Create the plant and machine before deleting.\n");
		printf("----------------------------------------------------\n");
		return start;
	}

	int choice = validate_int_input("1. Delete Plant\n2. Delete Machine\n3.Back\nChoose: ");

	if (choice == 1) 
	{
		int plant_id = validate_int_input("Enter the Plant ID to delete: ");
		delete_plant_at_position(&start, plant_id);
	} 
	else if (choice == 2) 
	{
		int plant_id = validate_int_input("Enter Plant ID to delete machine from: ");
		struct plant* current = start;

		while (current != NULL && current->plant_id != plant_id) 
		{
			current = current->plink;
		}

		if (current == NULL) 
		{
			printf("Plant not found!\n");
			printf("----------------------------------------------------\n");
			return start;
		}

		int machine_id = validate_int_input("Enter the Machine ID to delete: ");
		delete_machine_by_id(current, machine_id);
	} 
	else if (choice == 3) 
	{
		return start;
	} 
	else 
	{
		printf("Invalid choice.\n");
	}

	return start;
}
