#include "main.h"


void cycle_time_calculation(struct machine *m) 
{
	if (m->stop_time >= m->start_time) 
	{
		m->cycle_time = m->stop_time - m->start_time;
	} 

	else 
	{
		m->cycle_time = (24.00 - m->start_time) + m->stop_time;
	}
}

