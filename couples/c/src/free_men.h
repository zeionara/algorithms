#ifndef FREE_MEN_FUNCTIONS
#define FREE_MEN_FUNCTIONS

typedef struct free_man free_man;

struct free_man{
	int id;
	free_man *next;
};

free_man* add_free_man(free_man *free_men, int man_id);
free_man* get_free_men_list(int quantity);
int check_free_men_list(free_man *next_free_man);
free_man* engage(int* woman_partners, int woman_id, int man_id, free_man *free_men);

#endif
