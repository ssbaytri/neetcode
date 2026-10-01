class DynamicArray:
    def __init__(self, capacity):
        self.arr = [None] * capacity
        self.size = 0
        self.capacity = capacity

    def get(self, i):
        return self.arr[i]

    def set(self, i, n):
        self.arr[i] = n

    def pushback(self, n):
        if self.size == self.capacity:
            self.resize()

        self.arr[self.size] = n
        self.size += 1

    def popback(self):
        self.size -= 1
        value = self.arr[self.size]
        self.arr[self.size] = None
        return value

    def resize(self):
        new_capacity = self.capacity * 2
        new_arr = [None] * new_capacity

        for i in range(self.size):
            new_arr[i] = self.arr[i]

        self.arr = new_arr
        self.capacity = new_capacity

    def getSize(self):
        return self.size

    def getCapacity(self):
        return self.capacity