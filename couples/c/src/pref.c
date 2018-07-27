#include <stdio.h>
#include <stdlib.h>


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
	
	return 0;

}

int* get_prefs(int quantity){
	int i = 0;
	int j = 0;
	int *prefs = malloc(quantity * quantity * sizeof(int));
	
	for (i = 0; i < quantity; i++){
	       for (j = 0; j < quantity; j++){
			set_random_pref(prefs, i, j, quantity);
			//printf("%d ", get_pref(prefs, i, j, quantity));	
		}
	        //printf("\n");
	}

	return prefs;	
}

void show_prefs(int* prefs, int quantity){
	int i = 0, j = 0;

	for (i = 0; i < quantity; i++){
		for (j = 0; j < quantity; j++){
			printf("%d ", get_pref(prefs, i, j, quantity));
		}
		printf("\n");
	}
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
	int *modified_prefs = prefs_to_sorted_matrix(prefs, quantity);
	return modified_prefs;
}

