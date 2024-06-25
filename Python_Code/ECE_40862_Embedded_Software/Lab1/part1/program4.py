#3.4 Dictionary

birthday_dict = {
    "Matthew": "01/20/2001",
    "Mark": "03/04/2002",
    "Luke": "05/10/2003",
    "John": "06/12/2004",
    "Ezekiel": "08/30/2005"
}
 
print("Welcome to the birthday dictionary. We know the birthdays of: \n Matthew\n Mark\n Luke\n John\n Ezekiel")
name = input("Whose birthday do you want to look up? ")
birthday = birthday_dict.get(name)
if birthday:
    print(f"{name}'s birthday is {birthday}")
else:
    print(f"Sorry,{name}'s birthday is not found in the dictionary")
