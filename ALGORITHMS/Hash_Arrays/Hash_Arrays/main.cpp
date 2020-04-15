#include <iostream>
#include <string>
#include <cmath>

#define STOPWATCH_ON

#include "StopWatch.h"

const int ARRAY_SIZE = 100;

int ktora_funkcja = 0;

struct Elem
{
	int32_t key{};
	std::string value{};
	bool deleted = true;
};

void Wstaw(Elem* Tab, int32_t key, const std::string& value);
void Znajdz(Elem* Tab/*, const int32_t key*/);
void Usun(Elem* Tab, const std::string& value);


const int32_t H(const int32_t key);
const int32_t H_Prim(const int32_t key);


const int32_t Hash_Linear(const int32_t key, const size_t i);
const int32_t Hash_Quadratic(const int32_t key, const size_t i);
const int32_t Hash_Double(const int32_t key, const size_t i);


std::string Get_Chain(std::string& value);


//METODA BERNSTEINA

//unsigned long hash(const std::string & value)
//{
//	unsigned long hash = 5381;
//	size_t i{};
//
//	while (i < value.size())
//	{
//		//hash = ((hash << 5) + hash) + value[i]; /* hash * 33 + c */
//		hash = hash * 33 ^ value[i];
//		++i;
//	}
//
//	return hash % ARRAY_SIZE;
//}
unsigned long int hash_djb2(const std::string& value)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	for (auto x : value)
	{
		c = x;
		hash = ((hash << 5) + hash) + c;
	}
	return (hash % ARRAY_SIZE);
}
//////////////////////////////////////////////////////////////////



int main(int argc, char* argv[])
{
	Elem Tab[ARRAY_SIZE]{};
	
	std::cout << "1. Liniowa\n";
	std::cout << "2. Kwadratowa\n";
	std::cout << "3. Podwojna\n";
	std::cout << "4. Bernsteina\n";
	std::cout << "5. Zakoncz\n";
	std::cin >> ktora_funkcja;
	std::cin.get();

	int wybor{};
	int32_t key{};
	std::string value{};
	while (wybor != 4)
	{
		std::cout << "1. Dodaj\n";
		std::cout << "2. Usun\n";
		std::cout << "3. Wyswietl\n";
		std::cout << "4. Zakoncz\n";
		std::cin >> wybor;
		std::cin.get();

		if (wybor == 1)
		{
			std::cout << "Podaj wartosc: ";
			std::getline(std::cin, value);
			START_STOPWATCH
			while (value.size() > 0)
			{
				std::string temp = Get_Chain(value);
				Wstaw(Tab, key, temp);
			}
			STOP_STOPWATCH
			std::cout << '\n';
			std::cin.get();
		}
		else if (wybor == 2)
		{
			Znajdz(Tab);
			std::cout << "Podaj klucz\n";
			std::cin >> value;
			//Znajdz(Tab, key);
			Usun(Tab, value);
			std::cout << '\n';
		}
		else if (wybor == 3)
		{
			//std::cout << "Podaj klucz\n";
			//std::cin >> key;
			//Znajdz(Tab, key);
			Znajdz(Tab);
			std::cout << '\n';
			std::cin.get();
		}
		else if (wybor == 4)
		{
			//exit(0);
		}
		else
		{
			std::cout << "Brak opcji w menu\n";
		}
		//std::cin.get();
		key = 0;
		value = {};
		system("cls");
	}

	std::cin.get();
	return EXIT_SUCCESS;
}

void Wstaw(Elem* Tab, int32_t key, const std::string& value)
{
	size_t i{};
	for (size_t j = 0; j < value.size(); ++j)
	{
		key += static_cast<int32_t>(value[i]);
	}
	while (i < static_cast<size_t>(ARRAY_SIZE))
	{
		int32_t j{};
		if (ktora_funkcja == 1)
		{
			j = Hash_Linear(key, i);
		}
		else if (ktora_funkcja == 2)
		{
			j = Hash_Quadratic(key, i);
		}
		else if (ktora_funkcja == 3)
		{
			j = Hash_Double(key, i);
		}
		else if (ktora_funkcja == 4)
		{
			j = hash_djb2(value);
		}
		if (Tab[j].deleted == true)
		{
			Tab[j].key = key;
			Tab[j].value = value;
			Tab[j].deleted = false;
			break;
		}
		if (Tab[j].deleted == false)
		{
			for (size_t k = 0; k < static_cast<size_t>(ARRAY_SIZE); ++k)
			{
				if (Tab[k].deleted == true)
				{
					Tab[k].key = key;
					Tab[k].value = value;
					Tab[k].deleted = false;
					break;
				}
			}
			break;
		}
		i++;
	}
}

void Znajdz(Elem* Tab/*, const int32_t key*/)
{
	size_t i{};
	while (i < static_cast<size_t>(ARRAY_SIZE))
	{
		//int32_t j{};
		//if (ktora_funkcja == 1)
		//{
		//	j = Hash_Linear(key, i);
		//}
		//else if (ktora_funkcja == 2)
		//{
		//	j = Hash_Quadratic(key, i);
		//}
		//else if (ktora_funkcja == 3)
		//{
		//	j = Hash_Double(key, i);
		//}
		//if (Tab[j].key == key)
		//{
		//	std::cout << "T[" << j << "] " << Tab[j].key << ' ' << Tab[j].value << '\n';
		//}
		std::cout << "T[" << i << "] " << Tab[i].key << ' ' << Tab[i].value << '\n';
		//std::cout << "T[" << i << "] " << Tab[i].value << '\n';
		i++;
	}
}

//void Usun(Elem* Tab, const int32_t key)
void Usun(Elem* Tab, const std::string& value)
{
	size_t i{};
	int32_t key{};
	for (size_t j = 0; j < value.size(); ++j)
	{
		key += static_cast<int32_t>(value[i]);
	}
	while (i < static_cast<size_t>(ARRAY_SIZE))
	{
		int32_t j{};
		if (ktora_funkcja == 1)
		{
			j = Hash_Linear(key, i);
		}
		else if (ktora_funkcja == 2)
		{
			j = Hash_Quadratic(key, i);
		}
		else if (ktora_funkcja == 3)
		{
			j = Hash_Double(key, i);
		}
		else if (ktora_funkcja == 4)
		{
			j = hash_djb2(value);
		}
		if (Tab[j].deleted == false)
		{
			Tab[j].key = NULL;
			Tab[j].value = "";
			Tab[j].deleted = true;
			break;
		}
		i++;
	}
}

const int32_t H(const int32_t key)
{
	return static_cast<int32_t>((key) % ARRAY_SIZE);
}

const int32_t H_Prim(const int32_t key)
{
	return static_cast<int32_t>(1 + (key % (ARRAY_SIZE - 2)));
}

const int32_t Hash_Linear(const int32_t key, const size_t i)
{
	return static_cast<int32_t>((H(key) + i) % ARRAY_SIZE);
}

const int32_t Hash_Quadratic(const int32_t key, const size_t i)
{
	return static_cast<int32_t>((H(key) + 2 * i + 3 * pow(i, 2))) % ARRAY_SIZE;
}

const int32_t Hash_Double(const int32_t key, const size_t i)
{
	return static_cast<int32_t>((H(key) + i * H_Prim(key)) % ARRAY_SIZE);
}

std::string Get_Chain(std::string& value)
{
	std::string temp{};
	int32_t key{};
	bool erased = false;
	for (size_t i = 0; i < value.size(); ++i)
	{
		if (value[i] == ' ')
		{
			value.erase(value.begin(), value.begin() + i + 1);
			erased = true;
			break;
		}
		else
		{
			temp += value[i];
		}
	}
	if (erased == false)
	{
		value.erase(value.begin(), value.end());
	}
	return temp;
}