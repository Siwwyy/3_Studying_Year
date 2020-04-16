import locale
import calendar
from sortedcontainers import SortedList
from datetime import date

#Zadanie 1

#locale.setlocale(locale.LC_ALL, 'pl_PL')
#c = calendar.TextCalendar(calendar.MONDAY);

#print("Podaj rok $ ")
#year = input()
#print("Podaj miesiac $ ")
#month = input()

#str = c.formatmonth(int(year, base = 10),int(month, base = 10))

#print(str)

###########################################################################

#Zadanie2

#class Record(object):
#    def __init__(self, character, occurence):
#        self.character = character
#        self.occurence = occurence

#    def __lt__(self, other):
#        return self.occurence < other.occurence

#    def __eq__(self,other):
#        return self.character != other.character
    
#    def Get_Character(self):
#        return self.character

#    def Get_Occurence(self):
#        return self.occurence

#print("Podaj zdanie $ ")
#str = input()

#sorted_list = SortedList()

#condition = False
#for char in str:
#   occurence = str.count(char)
#   for elem in sorted_list:
#       if char == elem.Get_Character():
#           condition = True
#   if condition == False:
#       sorted_list.add(Record(char,occurence))
#   condition = False


#for list_elem in sorted_list:
#    print(list_elem.Get_Character(),list_elem.Get_Occurence(), sep = " | ")

###########################################################################

#Zadanie3

#print("Podaj zdanie $ ")
#str = input()

#number_length = int()
#number = ""

#for char in str:
#    temp_str = ord(char)
#    if (temp_str >= 48 and temp_str <= 57):
#        number_length += 1
#        number += char
#    elif char == '-':
#        number += char
#    else:
#        number_length = 0
#        number = ""
#    if number_length == 9:
#        print(number)


###########################################################################

#Zadanie4

#def int_to_roman(number):
#    numerals={1:"I", 4:"IV", 5:"V", 9: "IX", 10:"X", 40:"XL", 50:"L",
#              90:"XC", 100:"C", 400:"CD", 500:"D", 900:"CM", 1000:"M"}
#    result=""
#    number = int(number,base=10)
#    for value, numeral in sorted(numerals.items(), reverse=True):
#        while number >= value:
#            result += numeral
#            number -= value
#    return result
    
#print("W systemie rzymskim to:", int_to_roman(input("Wpisz calkowita liczbe: ")))


###########################################################################

#Zadanie5

#def Get_Decimal(str):
#    day = int()
#    month = int()
#    year = int()
#    counter = 0
#    temp_str = ""
#    for char in str:
#        if char == '.':
#            if counter == 0:
#                day = int(temp_str,base=10)
#            elif counter == 1:
#                month = int(temp_str,base=10)
#            counter += 1
#            temp_str = ""
#        else:
#            temp_str += char
#    year = int(temp_str,base=10)

#    return date(year, month, day)


#print("Podaj pierwsza date $ ")
#str_date_1 = input()

#print("Podaj druga date $ ")
#str_date_2 = input()


#f_date = Get_Decimal(str_date_1)
#l_date = Get_Decimal(str_date_2)
#delta = l_date - f_date
#print("Te dwie daty dzieli: " , delta.days , " Dni")


###########################################################################

#Zadanie6

