#include "main.h"

void display_total_cycle_time_and_production(struct plant* start) 
{
    if (start == NULL) 
    {
        printf("No plants available.\n");
	printf("----------------------------------------------------\n");
        return;
    }

    int total_plants = 0;
    int total_machines = 0;
    float total_cycle_time = 0.0;
    int total_production = 0;

    struct plant* current_plant = start;

    while (current_plant != NULL) 
    {
        total_plants++;

        struct machine* current_machine = current_plant->mlink;

        if (current_machine != NULL) 
        {
            struct machine* first_machine = current_machine;

            while (1) 
            {
                total_cycle_time += current_machine->cycle_time;
                total_production += current_machine->machine_production;
                total_machines++;

                current_machine = current_machine->mlink;

                if (current_machine == first_machine) 
                {
                    break; 
                }
            }
        }

        current_plant = current_plant->plink; 
    }

    int total_hours = (int)total_cycle_time;  
    int total_minutes = (int)((total_cycle_time - total_hours) * 60); 

    printf("Total number of plants: %d\n", total_plants);
    printf("Total number of machines: %d\n", total_machines);
   // printf("Total cycle time of industry: %d hours and %d minutes\n", total_hours, total_minutes);
    printf("Total production of industry: %d units\n", total_production);
    printf("-------------------------------------------------------------------\n");
}
