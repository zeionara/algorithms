#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pref.h"
#include "free_men.h"
#include "arrays.h"

static const char INVALID_QUANTITY_MESSAGE[] = "Please, provide a valid positive integer\n"; 

int string_to_positive_int(char *string, int *result){
	int temporary_result = 0, i = 0;
	while (string[i] != '\0'){
		char current_char = string[i];

		if ((current_char < '0') || (current_char > '9')){
			return 1;
		}

		temporary_result = temporary_result * 10 + (current_char - '0');
		i++;
	}

	*result = temporary_result;
       	return 0;	
}


int main(int argc, char *argv[]){

	int quantity = 0;

	if (argc >= 2){
		if (string_to_positive_int(argv[1], &quantity) != 0){
			printf(INVALID_QUANTITY_MESSAGE);
			return 1;		
		}
	} else {
		printf(INVALID_QUANTITY_MESSAGE);
		return 1;
	}

	//initialize data

	srand(time(NULL));

	
	free_man *free_men = get_free_men_list(quantity);
	
	int* man_prefs = get_man_prefs(quantity);	
	printf("Prefs for men:\n");
	show_prefs(man_prefs, quantity);

	int* man_currents = get_zeros_array(quantity);


	int* woman_prefs = get_woman_prefs(quantity);
	printf("Prefs for women:\n");
	show_prefs(woman_prefs, quantity);
	
	int* woman_partners = initialize_int_array(quantity, quantity);

	//show_int_array(man_currents, quantity);

	//start algorithm
	
	int man_id;
	int woman_id;
	int groom_id;
	
	while (free_men){
		man_id = free_men->id;
		woman_id = get_pref(man_prefs, man_id, man_currents[man_id], quantity);
		man_currents[man_id]++;
		groom_id = woman_partners[woman_id];

		//show_int_array(woman_partners, quantity);

		//printf("Act: man_id = %d, woman_id = %d, groom_id = %d\n", man_id, woman_id, groom_id);

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

