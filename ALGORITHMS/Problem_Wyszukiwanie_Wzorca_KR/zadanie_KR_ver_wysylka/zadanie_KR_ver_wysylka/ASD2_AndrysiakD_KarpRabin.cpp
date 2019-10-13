/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//CLASS OF _Pattern_Seeking

class _Pattern_Seeking
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	std::string find_where;
	std::string find_what;
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PRIVATE
	*/
	int prime_generator(const int range);
	long long power(long long base, long long power);
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Pattern_Seeking();
	_Pattern_Seeking(const _Pattern_Seeking & Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void Clear();
	void Karp_Rabin_Algorithm();
	bool is_equal(const std::string & _Ty_left, const std::string & _Ty_Right, const size_t size) const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_find_what(const std::string & pattern);
	void set_find_where(const std::string & file_path);
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_Pattern_Seeking & operator=(const _Pattern_Seeking & Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Pattern_Seeking();
};

//////////////////////////////////////////////////////////////////////////////

//FUNCTION FOR INSERTING VALUES FROM file_in
void inserter();
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	inserter();
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////


void inserter()
{
	std::string file_name = "";
	std::string pattern = "";
	std::string str_N = "";
	size_t N = 0;
	char sign_from_file = ' ';
	_Pattern_Seeking Object;
	std::getline(std::cin, str_N);
	N = std::stoi(str_N);
	while (N > 0)
	{
		std::getline(std::cin, file_name);
		std::getline(std::cin, pattern);
		/*
			TO DO SOMETHING
		*/
		Object.set_find_where(file_name);
		Object.set_find_what(pattern);
		Object.Karp_Rabin_Algorithm();
		Object.Clear();
		////////////////////////////////////////
		file_name = "";
		pattern = "";
		N--;
	}
	N = 0;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Pattern_Seeking CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


int _Pattern_Seeking::prime_generator(const int range)
{
	int prime_number = 0;
	for (int i = 2; i <= range; i++)
	{
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime == true)
		{
			prime_number = i;
		}
	}
	return prime_number;
}

long long _Pattern_Seeking::power(long long base, long long power)
{
	long long result = 1;
	while (power > 0)
	{
		if (power % 2 == 1) 
		{ 
			result = (result*base) % 8355967;
		}
		base = (base * base) % 8355967;
		power = power / 2;
	}
	return result;
}

_Pattern_Seeking::_Pattern_Seeking():
	find_what(""),
	find_where("")
{
	
}

_Pattern_Seeking::_Pattern_Seeking(const _Pattern_Seeking & Object):
	find_what(Object.find_what),
	find_where(Object.find_where)
{

}

void _Pattern_Seeking::Clear()
{
	this->find_what = "";
	this->find_where = "";
}

void _Pattern_Seeking::Karp_Rabin_Algorithm()
{
	std::fstream file_source;
 	file_source.open(find_where.c_str(), std::ios_base::in | std::ios_base::binary);
	if (file_source.good() == false)
	{
		std::cerr << "[ ERROR(1) -> FILE IS NOT CREATED OR IS NOT IN SOLUTION FOLDER ] \n";
	}
	else
	{
		const size_t seeking_size = find_what.size();
		std::string word = "";
		//magic numbers
		const int power_base = 256;	//set the end of the prime's number
		const int modulo_divider = 8355967;	//set the end of the prime's number
		///////////////////////////////////////////////////////////////////////////////////
		long long cost_find_what = 0;
		long long current_cost = 0;
		long long raw_value = 0;

		long long temporary = 0;
		long long my_power_result = 1;
		for (size_t i = 0; i < seeking_size; ++i)
		{
			if (((int)find_what[i]) < 0)
			{
				temporary = (modulo_divider - (((((int)find_what[i]) * (power(power_base, seeking_size - i - 1))) * (-1)) % modulo_divider)) % modulo_divider;	//works
			}
			else
			{
				temporary = (((int)find_what[i]) * ((power(power_base, seeking_size - i - 1)) % modulo_divider)) % modulo_divider;	//works
			}
			cost_find_what += temporary;
			cost_find_what %= modulo_divider;
			temporary = 0;
			my_power_result = 1;
		}
		temporary = 0;
		my_power_result = 1;
		char sign_from_file = ' ';
		size_t counter = 0;
		size_t pointer_in_file = 0;

		size_t i = 0;
		while (file_source.eof() == false)
		{
			temporary = 0;
			if (pointer_in_file == 0)
			{
				bool raw_bolean = false;
				while (i < seeking_size)
				{
					file_source.read(&sign_from_file, sizeof(sign_from_file));
					word += sign_from_file;
					if (((int)sign_from_file) < 0)
					{
						temporary = (modulo_divider - (((((int)sign_from_file) * (power(power_base, seeking_size - i - 1))) * (-1)) % modulo_divider)) % modulo_divider;
						if (raw_bolean == false)
						{
							raw_value = temporary;
							raw_bolean = true;
						}
					}
					else
					{
						temporary = (((int)sign_from_file) * ((power(power_base, seeking_size - i - 1)) % modulo_divider)) % modulo_divider;
						if (raw_bolean == false)
						{
							raw_value = temporary;
							raw_bolean = true;
						}
					}
					current_cost += temporary;
					current_cost %= modulo_divider;
					temporary = 0;
					sign_from_file = ' ';
					++i;
				}
				i = 0;	
			}
			else
			{
				file_source.read(&sign_from_file, sizeof(sign_from_file));
				if (sign_from_file != '\n')
				{
					for (size_t j = 0; j < word.size() - 1; ++j)
					{
						std::swap(word[j], word[j + 1]);
					}
					word[word.size() - 1] = sign_from_file;
					if (((int)sign_from_file) < 0)
					{
						temporary = (modulo_divider - (((((int)sign_from_file)) * (-1)) % modulo_divider)) % modulo_divider;
					}
					else
					{
						temporary = (((int)sign_from_file) % modulo_divider) % modulo_divider;
					}
					if (current_cost < raw_value)
					{
						current_cost = ((modulo_divider - ((((current_cost - raw_value) * (-1)) * 256) % modulo_divider)) + temporary) % modulo_divider;
					}
					else
					{
						current_cost = (((((current_cost - raw_value) * 256) % modulo_divider)) + temporary) % modulo_divider;
					}
					current_cost %= modulo_divider;
					if (((int)word[0]) < 0)
					{
						raw_value = (modulo_divider - (((((int)word[0]) * (power(power_base, seeking_size - 1))) * (-1)) % modulo_divider)) % modulo_divider;	//works
					}
					else
					{
						raw_value = (((int)word[0]) * ((power(power_base, seeking_size - 1)) % modulo_divider)) % modulo_divider;	//works
					}
					sign_from_file = ' ';
				}
				else
				{
					--pointer_in_file;
				}
			}
			if (cost_find_what == current_cost)
			{
				if (is_equal(find_what, word, seeking_size) == true)
				{
					std::cout << pointer_in_file << ' ';
				}
			}
			++pointer_in_file;
		}
		std::cout << '\n';
	}
	file_source.close();
}

bool _Pattern_Seeking::is_equal(const std::string & _Ty_left, const std::string & _Ty_Right, const size_t size) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (_Ty_left[i] != _Ty_Right[i])
		{
			return false;
		}
	}
	return true;
}

void _Pattern_Seeking::set_find_what(const std::string & find_what)
{
	this->find_what = find_what;
}

void _Pattern_Seeking::set_find_where(const std::string & find_where)
{
	this->find_where = find_where;
}

_Pattern_Seeking & _Pattern_Seeking::operator=(const _Pattern_Seeking & Object)
{
	if (this != &Object)
	{
		this->find_what = Object.find_what;
		this->find_where = Object.find_where;
	}
	return *this;
}

_Pattern_Seeking::~_Pattern_Seeking()
{
	find_where = "";
	find_what = "";
}