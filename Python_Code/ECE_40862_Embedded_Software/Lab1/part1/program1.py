import datetime

#3.1 Character Input
name = input("What is your name: ")
age = int(input("How old are you: "))
curr_year = datetime.datetime.now().year
time_til_100 = 100 - age
year_when_100 = curr_year + time_til_100
print(name,"will be 100 years old in the year",year_when_100)
          