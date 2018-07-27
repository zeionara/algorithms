#include <stdio.h>
#include <stdlib.h>

typedef struct free_man free_man;

struct free_man{
	int id;
	free_man *next;
};

free_man* add_free_man(free_man *free_men, int man_id){
	struct free_man *new_free_man = malloc(sizeof *new_free_man);
	new_free_man->id = man_id;
	new_free_man->next = free_men;
	return new_free_man;
}

free_man* get_free_men_list(int quantity){

	int i;

	struct free_man *old_free_man = NULL;
	struct free_man *new_free_man = NULL;

	for (i = 0; i < quantity; i++){
		if (i > 0){
			old_free_man = new_free_man;
		}
		
		new_free_man = malloc(sizeof *new_free_man);
		new_free_man->id = i;

		new_free_man->next = old_free_man;
	}

	return new_free_man;
}

int check_free_men_list(free_man *next_free_man){
	do {
		printf("%d\n", next_free_man->id);
		next_free_man = next_free_man->next;
	} while (next_free_man);
}

free_man* engage(int* woman_partners, int woman_id, int man_id, free_man *free_men){
	woman_partners[woman_id] = man_id;
	return free_men->next;
}

