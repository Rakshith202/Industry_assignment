
#include "main.h"

void entry_screen() 
{
	char option[2];

	printf("\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");   
	printf("\t\t\t Welcome to Loginware Industry\n");
	printf("\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");   
	printf("Press e to enter \nPress q to exit: ");


	while (1) 
	{
		scanf(" %s", option);
		//	while (getchar() != '\n');	
		if ((strlen(option)== 1) && (option[0] == 'e' || option[0] == 'E')) 
		{
			menu_screen(); 
		} 

		else if ((strlen(option) == 1) && (option[0] == 'q' || option[0] == 'Q')) 
		{
			printf("Thank you :)\n");
			exit(1);  
		} 

		else 
		{
			printf("Invalid input. Please press 'e' to enter or 'q' to exit: ");
		}
	}
}

void menu_screen()
{


	struct plant* start = NULL;
	int choice;

	while (1) 

	{
		printf("\n--- Main Menu ---\n");
		printf("1. Create Plants and Machines\n");
		printf("2. Add Plants or Machines\n");
		printf("3. Delete Plants or Machines\n");
		printf("4. Search Plants or Machines\n");
		printf("5. Reverse Machines\n");
		printf("6. Sort Machines\n");
		printf("7. Display All Plants and Machines\n");
		printf("8. Display Overall Cycle Time and Production\n");
		printf("9. Exit\n");
		choice = validate_int_input("Enter your choice: ");

		switch (choice) {
			case 1:
				start = create_plants_machines(start);
				// display_plants_machines(start); 
				break;
			case 2:
				start = add_plants_machines(start);
				// display_plants_machines(start); 
				break;
			case 3:
				start = delete_plants_machines(start);
				// display_plants_machines(start); 
				break;
			case 4:
				search_plants_machines(start);
				break;
			case 5:
				start = reverse_machines(start);
				// display_plants_machines(start); 
				break;
			case 6:
				start = sort_machines(start);
				// display_plants_machines(start); 
				break;
			case 7:
				display_plants_machines(start); 
				break;
			case 8:
				display_total_cycle_time_and_production(start);
				break;
			case 9:
				printf("THANK YOU!\n");
				exit(1);
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}

}

