#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct plant 
{
    int plant_id;
    char plant_name[20];
    struct machine *mlink; 
    struct plant *plink;   
};

struct machine 
{
    int machine_id;
    float start_time;
    float stop_time;
    float cycle_time;
    int machine_production;
    struct machine *mlink; 
};

int plant_machine_list_created(struct plant* start);
struct plant* insert_plant_at_position(struct plant* start, struct plant* new_plant, int position);
void insert_machine_at_position(struct plant* current_plant, struct machine* new_machine, int position);
struct plant* add_plants_machines(struct plant* start);


struct plant* update_plant(struct plant* start, struct plant* new_plant);
void update_machine(struct plant* current_plant, struct machine* new_machine);
struct plant* create_plants_machines(struct plant* start);

void cycle_time_calculation(struct machine *m);

void delete_plant_at_position(struct plant **start, int plant_id);
struct plant* delete_plants_machines(struct plant* start);
void delete_machine_at_position(struct plant* current_plant, int position);

void display_plants_machines(struct plant* start);

void display_total_cycle_time_and_production(struct plant* start);

struct machine* allocate_machine();

struct plant* allocate_plant();

void entry_screen();

void menu_screen();

struct plant* reverse_machines(struct plant* start);
struct plant* search_plant_by_id(struct plant* start, int plant_id);
struct machine* search_machine_by_id(struct plant* current_plant, int machine_id);
struct plant* search_plants_machines(struct plant* start);

void swap_machines(struct machine* a, struct machine* b);
void sort_machines_by_cycle_time(struct plant* current_plant);
struct plant* sort_machines(struct plant* start);

int valid_integer(const char* str);
int valid_float(const char* str);
int validate_int_input(const char* data);
float validate_float_input(const char* data);
int validate_time_format(float time);
int plant_id_exists(struct plant* start, int plant_id);
int machine_id_exists(struct plant* current_plant, int machine_id); 

int plant_machine_list_created(struct plant* start);
struct plant* insert_plant_at_position(struct plant* start, struct plant* new_plant, int position);
void insert_machine_at_position(struct plant* current_plant, struct machine* new_machine, int position);


