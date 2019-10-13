/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <vector>

using namespace std;

class _Single_Block		//block contains from which material to which, transformation is available and cost that transformation
{
private:
	/*
		VARIABLES PUBLIC
	*/
	__int32 cost;
	__int32 left_metal;
	__int32 right_metal;
	///////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Single_Block(void);
	_Single_Block(const __int32 left_metal, const __int32 right_metal, const __int32 cost);
	_Single_Block(const _Single_Block & Object);
	///////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	///////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_left_metal(const __int32 left_metal);
	void set_right_metal(const __int32 right_metal);
	///////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	const __int32 get_left_metal() const;
	const __int32 get_right_metal() const;
	const __int32 get_cost() const;
	///////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_Single_Block & operator=(const _Single_Block & Object);
	const bool operator==(const _Single_Block & Object) const;
	const bool operator<(const _Single_Block & Object) const;
	//DWUARGUMENTOWE
	///////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	///////////////////////////////////////////////
	virtual ~_Single_Block(void);
};


//CLASS OF HEAP SORT
class _Main_Class
{
private:
	/*
		VARIABLES PRIVATE
	*/
	__int64 * Prices;
	size_t prices_size;
	unsigned int prices_counter;
	///////////////////////////////////
	_Single_Block * Block;
	size_t block_size;
	unsigned int block_counter;
	///////////////////////////////////
	std::vector<std::vector<_Single_Block>> Pairs;
	///////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Main_Class(void);
	_Main_Class(const _Main_Class & Object);
	///////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void push_prices(const __int64 price);
	void push_blocks(const _Single_Block * _Ty_ptr);
	void Clear();
	void create_pairs();
	void show_pairs() const;
	void sort();
	__int32 solve() const;
	///////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_prices_size(const size_t size);
	void set_block_size(const size_t size);
	///////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	///////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	_Main_Class & operator=(const _Main_Class & Object);
	///////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Main_Class(void);
	///////////////////////////////////////////////
};

//FUNCTION FOR CREATE A LEVELS OF TEST FILES
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
	__int32 t = 0;
	__int32 n = 0;
	__int64 pk = 0;
	__int32 m = 0;
	__int32 a = 0;
	__int32 b = 0;
	__int32 c = 0;
	std::cin >> t;
	_Main_Class Object;
	for (__int32 i = 0; i < t; ++i)
	{
		std::cin >> n;
		Object.set_prices_size(n);
		while (n > 0)
		{
			std::cin >> pk;
			Object.push_prices(pk);
			pk = 0;
			n--;
		}
		std::cin >> m;
		Object.set_block_size(m);
		while (m > 0)
		{
			std::cin >> a;
			std::cin >> b;
			std::cin >> c;
			Object.push_blocks(new _Single_Block(a, b, c));
			a = 0;
			b = 0;
			c = 0;
			m--;
		}
		Object.create_pairs();
		std::cout << Object.solve() << '\n';
		n = 0;
		pk = 0;
		m = 0;
		a = 0;
		b = 0;
		c = 0;
		Object.Clear();
	}
	t = 0;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	SINGLE BLOCK CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Single_Block::_Single_Block(void) :
	left_metal(0),
	right_metal(0),
	cost(0)
{

}

_Single_Block::_Single_Block(const __int32 left_metal, const __int32 right_metal, const __int32 cost) :
	left_metal(left_metal),
	right_metal(right_metal),
	cost(cost)
{

}

_Single_Block::_Single_Block(const _Single_Block & Object) :
	left_metal(Object.left_metal),
	right_metal(Object.right_metal),
	cost(Object.cost)
{

}

void _Single_Block::set_left_metal(const __int32 left_metal)
{
	this->left_metal = left_metal;
}

void _Single_Block::set_right_metal(const __int32 right_metal)
{
	this->right_metal = right_metal;
}

const __int32 _Single_Block::get_left_metal() const
{
	return this->left_metal;
}

const __int32 _Single_Block::get_right_metal() const
{
	return this->right_metal;
}

const __int32 _Single_Block::get_cost() const
{
	return this->cost;
}

_Single_Block & _Single_Block::operator=(const _Single_Block & Object)
{
	if (this != &Object)
	{
		this->left_metal = Object.left_metal;
		this->right_metal = Object.right_metal;
		this->cost = Object.cost;
	}
	return *this;
}

const bool _Single_Block::operator==(const _Single_Block & Object) const
{
	if (this->left_metal == Object.left_metal && this->right_metal == Object.right_metal)
	{
		return true;
	}
	return false;
}

const bool _Single_Block::operator<(const _Single_Block & Object) const
{
	if (this->left_metal < Object.left_metal && this->right_metal < Object.right_metal)
	{
		return true;
	}
	return false;
}

_Single_Block::~_Single_Block(void)
{
	left_metal = 0;
	right_metal = 0;
	cost = 0;
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	MAIN CLASS CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Main_Class::_Main_Class(void) :
	prices_size(0),
	prices_counter(0),
	block_size(0),
	block_counter(0)
{

}

_Main_Class::_Main_Class(const _Main_Class & Object) :
	prices_size(Object.prices_size),
	prices_counter(Object.prices_counter),
	block_size(Object.block_size),
	block_counter(Object.block_counter)
{

}

void _Main_Class::push_prices(const __int64 price)
{
	Prices[prices_counter] = price;
	prices_counter++;
}

void _Main_Class::push_blocks(const _Single_Block * _Ty_ptr)
{
	Block[block_counter] = (*_Ty_ptr);
	block_counter++;
}

void _Main_Class::Clear()
{
	//Deleting arrays
	delete[] Prices;
	delete[] Block;
	Pairs.clear();
	//Nulling variables
	prices_counter = 0;
	prices_size = 0;
	block_size = 0;
	block_counter = 0;
}

void _Main_Class::create_pairs()
{
	Pairs.clear();
	sort();
	for (size_t i = 0; i < block_size; ++i)
	{
		if (Block[i].get_left_metal() == 1)
		{
			std::vector<_Single_Block> vec_block;
			_Single_Block * temp = new _Single_Block[block_size];
			for (size_t k = 0; k < block_size; ++k)
			{
				temp[k] = Block[k];
			}
			vec_block.emplace_back(Block[i]);
			__int32 right_metal = temp[i].get_right_metal();
			while (true)
			{
				bool found_pair = false;
				for (size_t j = i; j < block_size; ++j)
				{
					if (right_metal == temp[j].get_left_metal())
					{
						vec_block.emplace_back(temp[j]);
						right_metal = temp[j].get_right_metal();
						temp[j].set_left_metal(0);
						temp[j].set_right_metal(0);
						found_pair = true;
					}
				}
				if (found_pair == false)
				{
					break;
				}
				Pairs.emplace_back(vec_block);
				vec_block.clear();
			}
			delete[] temp;
		}
		else
		{
			continue;
		}
	}
}

void _Main_Class::show_pairs() const
{
	for (typename std::vector<std::vector<_Single_Block>>::const_iterator vec_iterator_first = Pairs.begin(); vec_iterator_first != Pairs.end(); ++vec_iterator_first)
	{
		for (typename std::vector<_Single_Block>::const_iterator vec_iterator_second = vec_iterator_first->begin(); vec_iterator_second != vec_iterator_first->end(); ++vec_iterator_second)
		{
			std::cout << vec_iterator_second->get_left_metal() << " -> " << vec_iterator_second->get_right_metal() << " cost: " << vec_iterator_second->get_cost() << " | ";
		}
		std::cout << '\n';
	}
}

void _Main_Class::sort()
{
	for (size_t i = 0; i < block_size; ++i)
	{
		if (Block[i].get_left_metal() == 1)
		{
			for (size_t j = 0; j < i; ++j)
			{
				if (Block[j].get_left_metal() != Block[i].get_left_metal())
				{
					std::swap(Block[i], Block[j]);
					break;
				}
			}
		}
		else if (Block[i].get_right_metal() == 1)
		{
			for (size_t j = block_size - 1; j >= i; --j)
			{
				if (Block[j].get_right_metal() != Block[i].get_right_metal())
				{
					std::swap(Block[i], Block[j]);
					break;
				}
			}
		}
	}
}

__int32 _Main_Class::solve() const
{
	__int32 minimal_value = 999999999;
	__int32 value = 0;
	for (size_t i = 0; i < Pairs.size(); ++i)
	{
		for (size_t j = 0; j < Pairs[i].size() - 1; ++j)
		{
			__int32 border_cost = (Prices[(Pairs[i][j].get_right_metal() - 1)] / 2);
			value += border_cost;
			for (size_t k = 0; k < Pairs[i].size(); ++k)
			{
				value += Pairs[i][k].get_cost();
			}
			if (value <= minimal_value)
			{
				minimal_value = value;
			}
			value = 0;
		}
	}
	value = 0;
	__int32 gold_cost = ((Prices[0]) / 2);
	value += gold_cost;
	if (value <= minimal_value)
	{
		minimal_value = value;
	}
	return minimal_value;
}

void _Main_Class::set_prices_size(const size_t size)
{
	this->prices_size = size;
	Prices = new __int64[this->prices_size];
}

void _Main_Class::set_block_size(const size_t size)
{
	this->block_size = size;
	Block = new _Single_Block[this->block_size];
}

_Main_Class & _Main_Class::operator=(const _Main_Class & Object)
{
	if (this != &Object)
	{
		this->prices_size = Object.prices_size;
		this->prices_counter = Object.prices_counter;
		this->block_size = Object.block_size;
		this->block_counter = Object.block_counter;
	}
	return *this;
}

_Main_Class::~_Main_Class(void)
{
	prices_counter = 0;
	prices_size = 0;
	block_size = 0;
	block_counter = 0;
}