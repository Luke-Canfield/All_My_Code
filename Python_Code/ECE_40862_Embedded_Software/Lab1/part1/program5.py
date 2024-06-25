#3.5 Class and Functions
class Sum:
    def __init__(self, numbers, target_num):
        self.numbers = numbers
        self.idx_map = {}
        
        for i, x in enumerate(numbers):
            complement = target_num - x
            if complement in self.idx_map:
                self.idx1 = self.idx_map[complement]
                self.idx2 = i
                break
            self.idx_map[x] = i
    def find_indices(self):
        return f"index1={self.idx1}, index2={self.idx2}"
    
list = [10, 20, 10, 40, 50, 60, 70]
target_num = int(input("What is your target number? "))
nums = Sum(list, target_num)
indices = nums.find_indices()
print(indices)
