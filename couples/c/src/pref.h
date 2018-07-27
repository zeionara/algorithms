#ifndef FUNCTIONS_FOR_PREFS
#define FUNCTIONS_FOR_PREFS

int get_pref(int* prefs, int first_index, int second_index, int quantity);
int set_pref(int* prefs, int first_index, int second_index, int quantity, int value);

int is_unique(int* prefs, int first_index, int second_index, int quantity, int value);
int set_random_pref(int* prefs, int first_index, int second_index, int quantity);
int* get_prefs(int quantity);
int* get_man_prefs(int quantity);
int* get_woman_prefs(int quantity);
int* prefs_to_sorted_matrix(int* prefs, int quantity);
void show_prefs(int* prefs, int quantity);

#endif
