#include "main.h"

void add_or_update_machine_cycle_time(struct plant* start) 
{
	if (start == NULL) 
	{
		printf("Please create plants and machines first.\n");
		printf("----------------------------------------------------\n");
		return;
	}

	int plant_id = validate_int_input("Enter the Plant ID to update machine cycle time: ");
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

	if (current_plant->mlink == NULL) 
	{
		printf("No machines available for plant %d.\n", plant_id);
		printf("----------------------------------------------------\n");
		return;
	}

	int machine_id = validate_int_input("Enter the Machine ID to update cycle time: ");
	struct machine* first_machine = current_plant->mlink;
	struct machine* current_machine = first_machine;

	while (current_machine->machine_id != machine_id && current_machine->mlink != first_machine) 
	{
		current_machine = current_machine->mlink;
	}

	if (current_machine->machine_id != machine_id) 
	{
		printf("Machine with ID %d not found.\n", machine_id);
		printf("----------------------------------------------------\n");
		return;
	}

	float new_start_time, new_stop_time;
	while (1) 
	{
		new_start_time = validate_float_input("Enter Machine Start Time in 24hr clock (hh.mm): ");
		if (validate_time_format(new_start_time)) 
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
		new_stop_time = validate_float_input("Enter Machine Stop Time in 24hr clock (hh.mm): ");
		if (validate_time_format(new_stop_time)) 
		{
			break;
		} 
		else 
		{
			printf("Invalid time format. Please re-enter the stop time.\n");
		}
	}

	if (current_machine->cycle_time == 0) 
	{
		printf("Initial cycle time and production added.\n");
		printf("----------------------------------------------------\n");
		current_machine->start_time = new_start_time;
		current_machine->stop_time = new_stop_time;
		cycle_time_calculation(current_machine);
	} 
	else 
	{
		printf("Cycle time and production updated.\n");
		printf("----------------------------------------------------\n");
		float additional_cycle_time = 0;
		if (new_start_time == new_stop_time) 
		{
			additional_cycle_time = 24.0;
		} 
		else if (new_stop_time > new_start_time) 
		{
			additional_cycle_time = new_stop_time - new_start_time;
		} 
		else 
		{
			additional_cycle_time = (24.0 - new_start_time) + new_stop_time;
		}


		current_machine->cycle_time += additional_cycle_time;


		int additional_production = (int)(additional_cycle_time);  
		current_machine->machine_production += additional_production;  
	}

	printf("Plant ID: %d, Machine ID: %d, ", plant_id, machine_id);
	display_time_in_hours_and_minutes(current_machine->cycle_time);  
	printf("Total Production: %d units\n", current_machine->machine_production);
}

