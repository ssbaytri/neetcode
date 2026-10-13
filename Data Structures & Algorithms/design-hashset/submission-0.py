class MyHashSet:

    def __init__(self):
        self.B = 10007
        self.buckets =[[] for _ in range(self.B)]

    def add(self, key: int) -> None:
        i = key % self.B
        if key not in self.buckets[i]:
            self.buckets[i].append(key)

    def remove(self, key: int) -> None:
        i = key % self.B
        if key in self.buckets[i]:
            self.buckets[i].remove(key)

    def contains(self, key: int) -> bool:
        i = key % self.B
        if key in self.buckets[i]:
            return True
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)