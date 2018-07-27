import sys, random

class Prefs:
    def __init__(self, quantity):
        self.values = [0 for i in range(quantity ** 2)]
        self.quantity = quantity

    def get_value(self, first_index, second_index):
        return self.values[first_index * self.quantity + second_index]

    def set_value(self, first_index, second_index, value):
        self.values[first_index * self.quantity + second_index] = value

    def init_with_value(self, value):
        for i in range(self.quantity ** 2):
            self.quantity[i] = value

    def init_with_zeros(self):
        self.init_with_value(0)

    def is_unique(self, value, first_index, second_index):
        for i in range(0, second_index):
            if self.get_value(first_index, i) == value:
                return False
        return True

    def init_with_random_values(self):
        for i in range(self.quantity):
            for j in range(self.quantity):
                value = 0
                while (True):
                    value = random.randint(0, self.quantity - 1)
                    if self.is_unique(value, i, j):
                        break
                self.set_value(i, j, value)

    def show(self):
        for i in range(self.quantity):
            for j in range(self.quantity):
                print(self.get_value(i, j), end = " ")
            print()
