import random

#3.3.2 For Loop
rand_num = random.randint(0, 10)
guesses = 3

for x in range(1, guesses + 1):
    guess = int(input("Enter your guess: "))
    if guess == rand_num:
        print("You win!")
        break
    elif x < guesses:
        print()
    else:
        print("You lose!")
        