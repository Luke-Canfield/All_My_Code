#3.2 Lists and Condtional Statements
a = [1, 3, 12, 40, 100, 350, 990, 1200, 2000, 5000]
print("a =", a)
number = int(input("Enter number:"))
filter_num = [x for x in a if x < number]
print("The new list is", filter_num)
