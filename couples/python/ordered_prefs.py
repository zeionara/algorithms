from prefs import Prefs

class OrderedPrefs(Prefs):
    def __init__(self, quantity):
        Prefs.__init__(self, quantity)
    
    @staticmethod
    def from_prefs(prefs):
        ordered_prefs = OrderedPrefs(prefs.quantity)
        counter = 0
        for i in range(prefs.quantity):
            counter = 0
            for j in range(prefs.quantity):
                ordered_prefs.set_value(i, prefs.get_value(i, j), counter)
                counter+=1
        return ordered_prefs

