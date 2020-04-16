import locale
import calendar
from sortedcontainers import SortedList

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