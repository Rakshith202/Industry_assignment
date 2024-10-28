#include "main.h"

void cycle_time_calculation(struct machine* machine)
{
	float start_time = machine->start_time;
	float stop_time = machine->stop_time;

	if (start_time == stop_time) 
	{
		machine->cycle_time = 24.0;  
	} 
	else if (stop_time > start_time) 
	{
		machine->cycle_time = stop_time - start_time;
	} 
	else 
	{
		machine->cycle_time = (24.0 - start_time) + stop_time;
	}


	int full_hours = (int)(machine->cycle_time);  
	machine->machine_production += full_hours;  
}
