import re

def problem3(searchstring):
    p = '([0-9]+) (([A-Z]{1}[a-z]* )+)(Rd\.|Dr\.|Ave\.|St\.)'
    match = re.search(p, searchstring)
    street = match.group(2)[:-1]
    reversedS = street[::-1]  
    reversedS = " " + reversedS + " "
    x = re.compile(r' (([A-Z]{1}[a-z]* )+)')
    y = x.sub (reversedS,searchstring)
    return(y)
      
print(problem3('The EE building is at 465 Northwestern Ave.')) 
print(problem3('Meet me at 201 South First St. at noon')) 