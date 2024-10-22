#include "main.h"

int plant_exist(struct plant* start, int plant_id) 
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

int machine_exist(struct machine* mlink, int machine_id) 
{
    	if (mlink == NULL) 
    	{
        	return 0;
    	}

    	struct machine* current_machine = mlink;
    	do 
    	{
        	if (current_machine->machine_id == machine_id) 
        	{
            		return 1;
        	}
        current_machine = current_machine->mlink;
    	} 
	
	while (current_machine != mlink);

    	return 0;
}

int plant_machine_list_created(struct plant* start)
{
    	return (start != NULL); 
}

struct plant* insert_plant_at_position(struct plant* start, struct plant* new_plant, int position) 
{
    	if (position < 1) 
    	{
        	printf("Position out of range.\n");
        	free(new_plant);
        	return start;
    	}

    
    	if (position == 1) 
    	{
        	new_plant->plink = start;
        	return new_plant;  
    	}

    	struct plant* current = start;
    
    
    	for (int i = 1; current != NULL && i < position - 1; i++) 
    	{
        	current = current->plink;
    	}

    	if (current == NULL) 
    	{
        	printf("Position out of range.\n");
        	free(new_plant);
        	return start;
    	}

    
    	new_plant->plink = current->plink;
    	current->plink = new_plant;

    	return start;
}

void insert_machine_at_position(struct plant* current_plant, struct machine* new_machine, int position) 
{
    	if (position < 1) 
    	{
        	printf("Position out of range.\n");
        	free(new_machine);
        	return;
    	}

    	if (current_plant->mlink == NULL) 
    	{
        	if (position != 1) 
        	{
            		printf("Position out of range.\n");
            		free(new_machine);
           		 return;
        	}
        
	
		current_plant->mlink = new_machine;
        	new_machine->mlink = new_machine;  
        	return;
    	}

    	struct machine* current_machine = current_plant->mlink;
    
    	if (position == 1) 
    	{
        	while (current_machine->mlink != current_plant->mlink) 
        	{
            		current_machine = current_machine->mlink;
        	}
        
		new_machine->mlink = current_plant->mlink;
        	current_machine->mlink = new_machine;
        	current_plant->mlink = new_machine; 
        	return;
    	}

    	for (int i = 1; current_machine->mlink != current_plant->mlink && i < position - 1; i++) 
    	{
        	current_machine = current_machine->mlink;
    	}

    	if (current_machine->mlink == current_plant->mlink && position > 1) 
    	{
        	printf("Position out of range.\n");
        	free(new_machine);
        	return;
    	}

    	new_machine->mlink = current_machine->mlink;
    	current_machine->mlink = new_machine;
}

struct plant* add_plants_machines(struct plant* start) 
{
    	if (!plant_machine_list_created(start)) 
    	{
        	printf("Please create the plant and machine list before adding.\n");
        	return start;
    	}	

    	int choice = validate_int_input("1. Add Plant\n2. Add Machine\n3.Back\nChoose: ");

    	if (choice == 1) 
    	{
        	struct plant* new_plant = allocate_plant();
	
        	new_plant->plant_id = validate_int_input("Enter Plant ID: ");
        
        	while (plant_exist(start, new_plant->plant_id)) 
        	{
            		printf("Plant with ID %d already exists.\n", new_plant->plant_id);
            		free(new_plant);
            		return start;
        	}	

        	printf("Enter Plant Name: ");
        	scanf("%s", new_plant->plant_name);

        	int position = validate_int_input("Enter the position to insert the plant: ");
        	struct plant* result = insert_plant_at_position(start, new_plant, position);


        	if (result != start) 
        	{
            		start = result; 
        	}

        	if (result == start && new_plant->plink == NULL) 
        	{
           		 printf("Plant not added due to invalid position.\n");
        	} 
        	else 
        	{
            		printf("Plant added successfully at position %d.\n", position);
        	}
    	} 
    	
	else if (choice == 2) 
    	{
        	int plant_id = validate_int_input("Enter Plant ID to add machine to: ");
      
        	struct plant* current = start;
        	while (current != NULL && current->plant_id != plant_id) 
        	{
            		current = current->plink;
        	}

        	if (current == NULL) 
        	{
            		printf("Plant not found!\n");
            		return start;
        	}

        	struct machine* new_machine = allocate_machine();
        
        	new_machine->machine_id = validate_int_input("Enter Machine ID: ");
        
        	if (machine_exist(current->mlink, new_machine->machine_id)) 
        	{
            		printf("Machine with ID %d already exists in this plant.\n", new_machine->machine_id);
            		free(new_machine);
            		return start;
        	}

       		 while (1)
        	{
            		new_machine->start_time = validate_float_input("Enter Machine Start Time (hh.mm): ");
            		if (validate_time_format(new_machine->start_time))
            		{
                		break;
            		}
            		else
            		{
                		printf("Invalid Time Format. Re-enter\n");
            		}
        	}
        
        	while (1)
        	{
            		new_machine->stop_time = validate_float_input("Enter Machine Stop Time (hh.mm): ");
            		if (validate_time_format(new_machine->stop_time))
            		{
                		break;
            		}
            
			else
            		{		
                		printf("Invalid Time Format. Re-Enter\n");
            		}
        	}

        
		cycle_time_calculation(new_machine);
        	new_machine->machine_production = 1;

        	int position = validate_int_input("Enter the position to insert the machine: ");
        	insert_machine_at_position(current, new_machine, position);

        	if (new_machine->mlink == NULL) 
        	{
            		printf("Machine not added due to invalid position.\n");
        	}	 
        	
		else 
        	{
            		printf("Machine added successfully at position %d.\n", position);
        	}
  
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
