package zeionara.couples;

public class FreeMan{
	private int id;
	private FreeMan next;

	public int get_id(){
		return id;
	}

	public FreeMan get_next(){
		return next;
	}

	public void set_next(FreeMan free_man){
		next = free_man;
	}
	
	public FreeMan(int id, FreeMan next){
		this.id = id;
		this.next = next;
	}

	public static FreeMan getFreeMenList(int quantity){
		FreeMan oldFreeMan = null;
		FreeMan newFreeMan = null;

		for (int i = 0; i < quantity; i++){
			oldFreeMan = newFreeMan;
			newFreeMan = new FreeMan(i, oldFreeMan);
		}
		
		return newFreeMan;
	}

	public void add(int man_id){
		FreeMan free_man = this;

		while (free_man.get_next() != null){
			free_man = free_man.get_next();
		}

		free_man.set_next(new FreeMan(man_id, null));
	}

	public void check(){
		FreeMan freeMan = this;

		while(freeMan != null){
			System.out.println(freeMan.id);
			freeMan = freeMan.next;
		}
	}
}

