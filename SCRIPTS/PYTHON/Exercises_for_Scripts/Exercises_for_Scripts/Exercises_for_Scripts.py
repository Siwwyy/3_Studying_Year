import locale
import calendar
import numpy
import itertools
from sortedcontainers import SortedList
from datetime import date
import os 
import sys


#Zadanie 1

#months = ["styczen","luty","marzec","kwiecien","maj","czerwiec","lipiec","sierpien","wrzesien","pazdziernik","listopad","grudzien"]

#locale.setlocale(locale.LC_ALL, 'pl_PL')
#c = calendar.TextCalendar(calendar.MONDAY);

#print("Podaj rok $ ")
#year = input()
#print("Podaj miesiac $ ")
#month = input()

#month_pos = months.index(month);
#month_pos += 1

#str = c.formatmonth(int(year, base = 10),int(str(month_pos), base = 10))

#print(str)

###########################################################################

#Zadanie2   #ok

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
#    if list_elem.Get_Occurence() > 1:
#        print(list_elem.Get_Character(),list_elem.Get_Occurence(), sep = " | ")

###########################################################################

#Zadanie3   #ok

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

#Zadanie4   #ok

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

#Zadanie5   #ok

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

#Zadanie6   #ok

#file_name = "main.cpp"
#file_data = str()
#output_data = []


#with open(file_name, "r") as file:
#    file_data = file.readlines()


#long_comment = False
#for line in file_data:
#    if "/*" in line:
#        long_comment = True
#    if long_comment == False and not "//" in line:
#        output_data.append(line)
#    if "*/" in line:
#        long_comment = False
#    if "//" in line:
#        index = line.find('/')
#        line = line[0: index]
#        output_data.append(line)


#f = open("main_commentary_deleted.cpp", 'w')
#f.writelines(output_data)
#f.close()

###############################################
#SAMPLE FILE
#include <iostream>
#include <string>
#include <cstdint>


#int main(int argc, char * argv[])
#{
#	int32_t val{};
#	/*
#		DDDDD
#	*/
	
#	/////DDDDDDD
	
#	std::cin.get();
#	return EXIT_SUCCESS;
#}

###############################################


###########################################################################

#Zadanie7  #ok

#operator for sorting
#def sort_by_Second(val): 
#    return val[0][1]

#data=""
#file = 0
#if len(sys.argv) == 1:
#    data = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."


#    Occurences = []

#    for char in data:
#        occurence = data.count(char, 0, len(data))
#        pair = [(char,int(occurence))]
#        if pair not in Occurences:
#            Occurences.append(pair)


#    Occurences.sort(key = sort_by_Second, reverse = True) 
#    counter = int()
#    for pairs in Occurences:
#        print(pairs)
#        counter += 1
#        if counter == 10:
#            break
#else:
#    file = open(str(sys.argv[1]), "r") 
#    data = file.read()
    
#    file.close()

#    Occurences = []

#    for char in data:
#        occurence = data.count(char, 0, len(data))
#        pair = [(char,int(occurence))]
#        if pair not in Occurences:
#            Occurences.append(pair)


#    Occurences.sort(key = sort_by_Second, reverse = True)

#    file = open(str(sys.argv[1]), "a+") 
#    counter = int()
#    for pairs in Occurences:
#        file.write(' '.join('\n %s %s' % x for x in pairs))
#        counter += 1
#        if counter == 10:
#            break


###########################################################################

#Zadanie8 #ok

##string_to_find = input()
#string_to_find = "marcin"
##file_path = input()

##dir_path = os.path.dirname(os.path.realpath(file_path))
#dir_path = "Test"
##cwd = os.getcwd()

#entries = os.listdir(dir_path)

#for file_paths in entries:
#    with open(file_paths) as file:
#        if string_to_find in file.read():
#            print(file_paths, " => contains " , string_to_find)



###########################################################################

#Zadanie9   #ok

#Unique_File_Names = []

#for dirpath, dirnames, file in os.walk(os.path.dirname(os.path.realpath(__file__))):
#    for single_file in file:
#        if single_file not in Unique_File_Names:
#            Unique_File_Names.append(single_file)

#for file_names in Unique_File_Names:
#    print(file_names, sep = '\n')[('a', 7)][('a', 7)][('m', 4)][('d', 3)][('i', 3)][('n', 3)][('\n', 3)][('r', 1)][('c', 1)][('a', 7)][('m', 4)][('d', 3)][('i', 3)][('n', 3)][('\n', 3)][('r', 1)][('c', 1)]