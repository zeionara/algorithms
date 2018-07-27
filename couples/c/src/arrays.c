#include <stdio.h>
#include <stdlib.h>

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

