import re

def problem1(searchstring):
    first_p = re.findall("\+1\s\(\d{3}\)\s\d{3}[-]\d{4}", searchstring)
    second_p = re.findall("\+1\s\d{3}[-]\d{3}[-]\d{4}",searchstring)
    third_p = re.findall("\+52\s\(\d{3}\)\s\d{3}[-]\d{4}", searchstring)
    fourth_p = re.findall("\+52\s\d{3}[-]\d{3}[-]\d{4}",searchstring)
    fifth_p = re.findall("\d{3}[-]\d{4}", searchstring)
  
    if len(searchstring) == 17 and first_p != []:
        return "True"
    elif len(searchstring) == 15 and second_p != []:
        return "True"  
    elif len(searchstring) == 18 and third_p != []:
        return "True"
    elif len(searchstring) == 16 and fourth_p != []:
        return "True"
    elif len(searchstring) == 8 and fifth_p != []:
        return "True"
    else:
        return "False"
        
def problem2(searchstring):
    p = r'([0-9]+) (([A-Z]{1}[a-z]* )+)(Rd\.|Dr\.|Ave\.|St\.)'
    street = re.search(p, searchstring)
    if street != []:
      return street.group(2)[:-1]
    else:
      return "None"
    
def problem3(searchstring):
    p = '([0-9]+) (([A-Z]{1}[a-z]* )+)(Rd\.|Dr\.|Ave\.|St\.)'
    match = re.search(p, searchstring)
    street = match.group(2)[:-1]
    reversedS = street[::-1]  
    reversedS = " " + reversedS + " "
    x = re.compile(r' (([A-Z]{1}[a-z]* )+)')
    y = x.sub (reversedS,searchstring)
    return(y)


if __name__ == '__main__' :
    print(problem1('+1 765-494-4600')) #True
    print(problem1('+52 765-494-4600 ')) #False
    print(problem1('+1 (765) 494 4600')) #False
    print(problem1('+52 (765) 494-4600')) #True    
    print(problem1('494-4600')) #True

    print(problem2('The EE building is at 465 Northwestern Ave.')) #Northwestern
    print(problem2('Meet me at 201 South First St. at noon')) #South First
    
    print(problem3('The EE building is at 465 Northwestern Ave.'))
    print(problem3('Meet me at 201 South First St. at noon'))
