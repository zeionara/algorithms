package zeionara.couples;

import java.util.concurrent.ThreadLocalRandom;

public class Prefs implements DataStore, IntMatrix{
	private int[] values;
	private int quantity;
	
	public Prefs(int quantity){
		this.quantity = quantity;
		values = new int[quantity * quantity];
		init_with_zeros();
	}

	public int get_quantity(){
		return quantity;
	}

	public int get_value(int first_index, int second_index){
		return values[first_index * quantity + second_index];
	}

	public void set_value(int first_index, int second_index, int value){
		values[first_index * quantity + second_index] = value;
	}

	public void init_with_value(int value){
		for (int i = 0; i < quantity * quantity; i++){
			values[i] = value;
		}
	}

	private boolean is_unique(int first_index, int second_index, int value){
		for (int i = 0; i < second_index; i++){
			if (get_value(first_index, i) == value){
				return false;
			}
		}
		return true;
	}


	public void init_with_random_values(){
		for (int i = 0; i < quantity; i++){
			for (int j = 0; j < quantity; j++){
				int random_value = 0;
				do {
					random_value = ThreadLocalRandom.current().nextInt(0, quantity);
				} while (! is_unique(i, j, random_value));
				set_value(i, j, random_value);
			}
		}
	}


	public void init_with_zeros(){
		init_with_value(0);
	}

	public void show(){
		for (int i = 0; i < quantity; i++){
			for (int j = 0; j < quantity; j++){
				System.out.print(get_value(i, j) + " ");
			}
			System.out.println();
		}
	}
}

