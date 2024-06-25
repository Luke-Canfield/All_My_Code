#3.3.1 While Loop
def gen_fibonacci(n):
    fib_series = []
    a, b = 0, 1
    c = 0
    while c < n:
        fib_series.append(b)
        a, b = b, a + b
        
        c+= 1
    return fib_series

number = int(input("How many Fibonacci numbers would you like to generate?"))
if number < 0:
    print("Please enter a positive number.")
else:
    fib_series = gen_fibonacci(number)
    print("The Fibonacci Sequence is", fib_series)