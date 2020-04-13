#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

constexpr auto ARRAY_SIZE = 10;

struct Elem
{
	int32_t key;
	std::string value;
	bool deleted = true;

};

void Wstaw(Elem* Tab, const int32_t key, const std::string& value);
void Znajdz(Elem* Tab, const int32_t key);
void Usun(Elem* Tab, const int32_t key);
const int32_t H(const int32_t key);
const int32_t H_Prim(const int32_t key);
const int32_t Hash_Linear(const int32_t key, const size_t i);
const int32_t Hash_Quadratic(const int32_t key, const size_t i);
const int32_t Hash_Double(const int32_t key, const size_t i);


int main(int argc, char* argv[])
{
	Elem Tab[ARRAY_SIZE]{};

	Wstaw(Tab, 12, "ddd");
	Wstaw(Tab, 12, "ddd");
	Wstaw(Tab, 12, "ddd");
	Znajdz(Tab, 12);

	std::cin.get();
	return EXIT_SUCCESS;
}

void Wstaw(Elem* Tab, const int32_t key, const std::string& value)
{
	size_t i{};
	while (i < static_cast<size_t>(ARRAY_SIZE))
	{
		int32_t j = Hash_Linear(key, i);
		if (Tab[j].deleted == true)
		{
			Tab[j].key = key;
			Tab[j].value = value;
			Tab[j].deleted = false;
			break;
		}
		i++;
	}
}

void Znajdz(Elem* Tab, const int32_t key)
{
	size_t i{};
	while (i < static_cast<size_t>(ARRAY_SIZE))
	{
		int32_t j = Hash_Linear(key, i);
		if (Tab[j].key == key)
		{
			std::cout << Tab[j].value << '\n';
		}
		i++;
	}
}

void Usun(Elem* Tab, const int32_t key)
{
	size_t i{};
	while (i < static_cast<size_t>(ARRAY_SIZE))
	{
		int32_t j = Hash_Linear(key, i);
		if (Tab[j].key == key)
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
	return static_cast<int32_t>((key)%ARRAY_SIZE);
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
	return static_cast<int32_t>((H(key) + 2*i + 3 * pow(i,2))) % ARRAY_SIZE;
}

const int32_t Hash_Double(const int32_t key, const size_t i)
{
	return static_cast<int32_t>((H(key) + i * H_Prim(key)) % ARRAY_SIZE);
}
