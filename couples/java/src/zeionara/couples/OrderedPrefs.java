package zeionara.couples;

import java.util.concurrent.ThreadLocalRandom;

public class OrderedPrefs extends Prefs implements DataStore, IntMatrix{
	
	public OrderedPrefs(int quantity){
		super(quantity);	
	}

	public OrderedPrefs(Prefs prefs){
		super(prefs.get_quantity());
		int quantity = prefs.get_quantity();
		int counter = 0;
		for (int i = 0; i < quantity; i++){
			counter = 0;
			for (int j = 0; j < quantity; j++){
				set_value(i, prefs.get_value(i, j), counter);
				counter++;
			}
			
		}	
	}	
}

