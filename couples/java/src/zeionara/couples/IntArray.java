package zeionara.couples;

import java.util.concurrent.ThreadLocalRandom;

public class IntArray implements DataStore{
	
	private int[] values;
	private int size;

	public IntArray(int size){
		values = new int[size];
		this.size = size;
	}

	public void init_with_value(int value){
		for (int i = 0; i < size; i++){
			values[i] = value;
		}
	}

	public void init_with_zeros(){
		init_with_value(0);
	}

	public void init_with_random_values(){
		for (int i = 0; i < size; i++){
			values[i] = ThreadLocalRandom.current().nextInt(0, size);
		}
	}

	public void show(){
		for (int i = 0; i < size; i++){
			System.out.print(values[i] + " ");
		}
		System.out.println();
	}

	public int get_value(int i){
		return values[i];
	}

	public void set_value(int i, int value){
		values[i] = value;
	}
}

