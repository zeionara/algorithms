import sys, random

from free_man import FreeMan
from prefs import Prefs
from ordered_prefs import OrderedPrefs

INVALID_QUANTITY_MSG = "Please, type a valid positive integer"

def create_plain_array(size, value):
    return [value for i in range(size)]

def main(): 
    
    quantity = 0
    
    try:
        quantity = int(sys.argv[1])
    except IndexError:
        print(INVALID_QUANTITY_MSG)
        return
    except ValueError:
        print(INVALID_QUANTITY_MSG)
        return


    free_men = FreeMan.get_free_men_list(quantity)
    free_men.check()

    man_prefs = Prefs(quantity)
    man_prefs.init_with_random_values()
    
    print("Man prefs:")
    man_prefs.show()

    #print()

    #ordered_prefs = OrderedPrefs.from_prefs(man_prefs)
    #ordered_prefs.show()

    man_currents = create_plain_array(quantity, 0)

    woman_prefs = OrderedPrefs(quantity)
    woman_prefs.init_with_random_values()

    print("Woman prefs:")
    woman_prefs.show()

    woman_partners = create_plain_array(quantity, quantity)
    
    while (free_men):
        man_id = free_men.id
        woman_id = man_prefs.get_value(man_id, man_currents[man_id]);
        man_currents[man_id]+=1
        groom_id = woman_partners[woman_id]
        
        if (groom_id >= quantity):
            woman_partners[woman_id] = man_id
            free_men = free_men.next
            continue
        elif (woman_prefs.get_value(woman_id, man_id) < woman_prefs.get_value(woman_id, groom_id)):
            woman_partners[woman_id] = man_id
            free_men = free_men.next
            if free_men:
                free_men.add(groom_id)
            else:
                free_men = FreeMan(groom_id, None)

    print("Result:")
    print(woman_partners)
    
    #first_free_man = FreeMan(1488, None)
    #second_free_man = FreeMan(6255, first_free_man)

    #print(second_free_man.next.id)


if __name__ == '__main__':
    main()
