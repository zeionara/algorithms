class FreeMan:
    def __init__(self, id, next):
        self.id = id
        self.next = next

    def check(self):
        free_man = self
        while (free_man):
            #print(free_man.id)
            free_man = free_man.next
    
    def add(self, man_id):
        free_man = self
        while (free_man.next):
            free_man = free_man.next
        free_man.next = FreeMan(man_id, None)

    @staticmethod
    def get_free_men_list(quantity):
        old_free_man = None
        new_free_man = None
        
        for i in range(0, quantity):
            old_free_man = new_free_man
            new_free_man = FreeMan(i, old_free_man)

        return new_free_man

