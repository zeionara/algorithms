package zeionara.couples;

public class Main{

	public static final String INVALID_QUANTITY_MESSAGE = "Please, provide a valid positive integer";

	public static FreeMan marry(FreeMan free_man, IntArray woman_partners, int woman_id, int man_id){
		woman_partners.set_value(woman_id, man_id);
		return free_man.get_next();
	}

	public static void main(String[] args){
	
		//get quantity
		
		int quantity = 0;
	       
		try {
			quantity = Integer.parseInt(args[0]);
		} catch (NumberFormatException e){
			System.out.println(INVALID_QUANTITY_MESSAGE);
			return;
		} catch (ArrayIndexOutOfBoundsException e){
			System.out.println(INVALID_QUANTITY_MESSAGE);
			return;
		}

		if (quantity <= 0){
			System.out.println(INVALID_QUANTITY_MESSAGE);
			return;
		}

		//initialize data structures
	
		FreeMan freeMen = FreeMan.getFreeMenList(quantity);

		Prefs man_prefs = new Prefs(quantity);
		man_prefs.init_with_random_values();
		System.out.println("Men prefs:");
		man_prefs.show();	
		
		IntArray man_currents = new IntArray(quantity);
		man_currents.init_with_zeros();

		OrderedPrefs woman_prefs = new OrderedPrefs(quantity);
		woman_prefs.init_with_random_values();
		System.out.println("Women prefs:");
		woman_prefs.show();

		IntArray woman_partners = new IntArray(quantity);
		woman_partners.init_with_value(quantity);
		
		while (freeMen != null){
			int man_id = freeMen.get_id();
			int woman_id = man_prefs.get_value(man_id, man_currents.get_value(man_id));
			man_currents.set_value(man_id, man_currents.get_value(man_id) + 1);
			int groom_id = woman_partners.get_value(woman_id);

			//System.out.println("Woman partners:");
			//woman_partners.show();
			

			if (groom_id >= quantity){
				freeMen = marry(freeMen, woman_partners, woman_id, man_id);
				continue;	
			} else if (woman_prefs.get_value(woman_id, man_id) < woman_prefs.get_value(woman_id, groom_id)){
				freeMen = marry(freeMen, woman_partners, woman_id, man_id);
				if (freeMen == null){
					freeMen = new FreeMan(groom_id, null);
				} else {
					freeMen.add(groom_id);
				}
				continue;
			}
		}
		
		System.out.println("Result:");
		woman_partners.show();
	}
}

