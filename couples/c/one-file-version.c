#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

int get_pref(int* prefs, int first_index, int second_index, int quantity){
	return prefs[first_index * quantity + second_index];
}

int set_pref(int* prefs, int first_index, int second_index, int quantity, int value){
	prefs[first_index * quantity + second_index] = value;
	return 0;
}

int is_unique(int* prefs, int first_index, int second_index, int quantity, int value){
	int i = 0;

	for (i = 0; i < second_index; i++){
		if (prefs[first_index * quantity + i] == value){
			return 0;
		}
	}

	return 1;
}

int set_random_pref(int* prefs, int first_index, int second_index, int quantity){
	int value = 0;
	
	do {
		value = rand() % quantity;
	} while (0 == is_unique(prefs, first_index, second_index, quantity, value));
	
	prefs[first_index * quantity + second_index] = value;
}

int* get_prefs(int quantity){
	int i = 0;
	int j = 0;
	int *prefs = malloc(quantity * quantity * sizeof(int));
	
	for (i = 0; i < quantity; i++){
	       for (j = 0; j < quantity; j++){
			set_random_pref(prefs, i, j, quantity);
			printf("%d ", get_pref(prefs, i, j, quantity));	
		}
	        printf("\n");
	}

	return prefs;	
}

int* get_man_prefs(int quantity){
	return get_prefs(quantity);
}

int* prefs_to_sorted_matrix(int* prefs, int quantity){
	int i = 0;
	int j = 0;
	int counter = 0;
	int* sorted_matrix = malloc(quantity * quantity * sizeof(int));

	printf("Generating sorted matrix...\n");

	for (i = 0; i < quantity; i++){
		counter = 0;
		for (j = 0; j < quantity; j++){
			sorted_matrix[i * quantity + prefs[i * quantity + j]] = counter;
			counter++;
		}
	}

	return sorted_matrix;

}

int* get_woman_prefs(int quantity){
	int *prefs = get_prefs(quantity);
	return prefs_to_sorted_matrix(prefs, quantity);
}

int* initialize_int_array(int size, int value){
	int i = 0;
	
	int* array = malloc(size * sizeof(int));
	for (i = 0; i < size; i++){
		array[i] = value;
	}

	return array;
}

int* get_zeros_array(int size){
	return initialize_int_array(size, 0);
}

int show_int_array(int* array, int size){
	int i = 0;

	for (i = 0; i < size; i++){
		printf("array[%d] = %d;\n", i, array[i]);
	}

	return 0;
}

free_man* engage(int* woman_partners, int woman_id, int man_id, free_man *free_men){
	woman_partners[woman_id] = man_id;
	return free_men->next;
}

int main(){

	int quantity = 15;
	
	srand(time(NULL));
	
	free_man *free_men = get_free_men_list(quantity);
	
	printf("Generating prefs for men\n");
	
	int* man_prefs = get_man_prefs(quantity);

	int* man_currents = get_zeros_array(quantity);

	printf("Generating prefs for women\n");

	int* woman_prefs = get_woman_prefs(quantity);

	//show_int_array(woman_prefs, quantity);

	int* woman_partners = initialize_int_array(quantity, quantity);

	//show_int_array(man_currents, quantity);

	//check_free_men_list(free_men);
	//----
	//----
	//----
	//----
	//
	
	int man_id;
	int woman_id;
	int groom_id;
	
	while (free_men){
		man_id = free_men->id;
		woman_id = get_pref(man_prefs, man_id, man_currents[man_id], quantity);
		man_currents[man_id]++;
		groom_id = woman_partners[woman_id];

		show_int_array(woman_partners, quantity);

		printf("Act: man_id = %d, woman_id = %d, groom_id = %d\n", man_id, woman_id, groom_id);

		if (groom_id >= quantity){
			free_men = engage(woman_partners, woman_id, man_id, free_men);
			continue;
		} else if (get_pref(woman_prefs, woman_id, man_id, quantity) < 
				get_pref(woman_prefs, woman_id, groom_id, quantity)){
			free_men = engage(woman_partners, woman_id, man_id, free_men);
			free_men = add_free_man(free_men, groom_id);
			continue;
		}
	}

	printf("Result:\n");

	show_int_array(woman_partners, quantity);
	
	return 0;
}

