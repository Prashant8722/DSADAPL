import numpy as np
class Square_Pattern:
    def __init__(self) -> None:
        pass
    
    def get_dimension(self, array):
        row_length = len(array)
        col_length = len(array[0])
        return row_length, col_length
    
    def display_position(self, positions):
            largest = 0
            for position in positions:
                print("Found Square at {} ofsize {}".format(position['position'], position['size']))
                if int(position['size']) > largest:
                    largest = position['size']
                    # print("Largest Square size is : {}".format(largest))
            return largest
        
    def show_largest(self, positions, largest):
        for position in positions:
            if position['size'] == largest:
                print("Found Largest Square at {} ofsize {}".format(position['position'], position['size']))
    
    def check_square(self, array):
        # print(array)
        all_one = True
        length = len(array)
        for m in range(length):
            for n in range(length):
                if array[m][n] != "1":
                    all_one = False
                    break
            if not all_one:
                break
        return all_one
    
    def find_square(self, array, rows, cols):
        position = []
        for i in range(rows):
            for j in range(cols):
                e = 2
                if array[i][j] == "1":
                    while (i+e <= rows) and (j+e <= cols):
                         # print("{} <= {} and {} <= {}".format(i+e,rows,j+e,cols)) 
                         if self.check_square(array[i:i+e,j:j+e]): 
                             position.append({'position' : "({}, {})".format(i, j), 'size' : e}) 
                             e = e + 1 
                         else:
                             break
                    e = 2 
                else: 
                     continue
                 
                return position 
     
if __name__ == ' __main__': 
    array = [] 
    with open('square_input.txt','r') as file: 
        lines = file.readlines()
        print(lines)
        for line in lines: 
            col = [] 
            for c in line.strip(): 
                col.append(c) 
                array.append(col)  
                array=np.array(array) 
                matcher = Square_Pattern() 
                
                rows, cols = matcher.get_dimension(array) 
                if rows == cols: 
                    positions = matcher.find_square(array, rows, cols) 
                    largest = matcher.display_position(positions) 
                    matcher.show_largest(positions, largest)