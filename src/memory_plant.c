#include "main.h"

struct plant* allocate_plant()

{
	struct plant* new_plant = (struct plant*)malloc(sizeof(struct plant));
	if (new_plant == NULL) 

	{
		printf("Memory allocation for plant failed\n");
		exit(1);
	}

	new_plant->mlink = NULL;
	new_plant->plink = NULL;
	return new_plant;
}



