# Hashing Table
import random, math

class SymblTable:
    def init (self, table_size):
        self.table_size = table_size
        self.HashTable = [[] for _ in range(table_size)]

    def display_hash(self):
        for i in range(len(self.HashTable)):
            print(i, end = " ")
        
        for j in self.HashTable[i]:
            print("-->", end = " ")
            print(j, end = " ")

        print()
def Hashing(self, keyvalue):
    k = (math.sqrt(5)-1)/2
    fraction, _ = math.modf(k*keyvalue)
    hashvalue = math.floor(self.table_size * fraction)
    return hashvalue

def insert(self, keyvalue, value):
    hash_key = self.Hashing(keyvalue)
    self.HashTable[hash_key].append(value)

    if __name__ == '__main__':

        with open('hash_input.txt') as file:
            lines = file.readlines()
        text = ''.join(lines)
        tokens = text.split()

        size = input('Enter Size of Hash Table\n')
        hash = SymblTable(int(size))
        
        modified = []
        for token in tokens:
            if len(token)>10:
                modified.append(token[:10])
            elif len(token)<10:
                extra = ''.join(random.choices('*', k = 10-len(token)))
                modified.append(token + extra)

        for token in modified:
            ascii_sum = sum([ord(c) - 96 for c in token])
            hash.insert(ascii_sum, token)

        hash.display_hash()