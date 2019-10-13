/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <set>
#include <random>

//CLASS GRILLE

class _Grille
{
private:
	/*
		PRIVATE VARIABLES
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	__int32 N;		//width and height the same value
	__int32 which_row;
	std::string line_decoded;
	std::vector<std::vector<char>> Grille_Matrix;
	std::vector<std::vector<char>> To_Read_Message_Matrix;
	/////////////////////////////////////////////////////////////////////////////////////////////
protected:
	/////////////////////////////////////////////////////////////////////////////////////////////
	//currently nothing special
	/////////////////////////////////////////////////////////////////////////////////////////////
public:
	/*
		CONSTRUCTORS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	_Grille() :
		N(0),
		which_row(0),
		line_decoded("")
	{
		//to do something
		Grille_Matrix.resize(N);
		To_Read_Message_Matrix.resize(N);
		for (int i = 0; i < Grille_Matrix.size(); ++i)
		{
			Grille_Matrix[i].resize(N);
			To_Read_Message_Matrix[i].resize(N);
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////
	_Grille(const __int16 N) :
		N(N),
		which_row(0),
		line_decoded("")
	{
		Grille_Matrix.resize(N);
		To_Read_Message_Matrix.resize(N);
		for (int i = 0; i < Grille_Matrix.size(); ++i)
		{
			Grille_Matrix[i].resize(N);
			To_Read_Message_Matrix[i].resize(N);
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////
	_Grille(const _Grille & Object) :
		N(Object.N),
		which_row(Object.which_row),
		line_decoded(Object.line_decoded)
	{
		//to do something
	}

	/*
		FUNKCJE PUBLIC
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	void show_grille_matrix()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				std::cout << Grille_Matrix[i][j];
			}
			std::cout << std::endl;
		}
	}
	void show_to_read_message_matrix()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				std::cout << To_Read_Message_Matrix[i][j];
			}
			std::cout << std::endl;
		}
	}
	void rotate_90()
	{
		std::string temp_line = "";
		temp_line.resize(N);
		std::vector<std::vector<char>> temp_vector;
		temp_vector.resize(N);
		int row = (N-1);
		for (int i = 0; i < temp_vector.size(); ++i)
		{
			temp_vector[i].resize(N);
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				temp_line[j] = Grille_Matrix[i][j];
			}
			for (int k = row; k >= row; --k)
			{
				for (int l = 0; l < N; ++l)
				{
					temp_vector[l][k] = temp_line[l];
				}
			}
			row--;
		}
		Grille_Matrix = temp_vector;
	}
	void read_message()	//remember about it
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (Grille_Matrix[i][j] == 'O')
				{
					line_decoded += To_Read_Message_Matrix[i][j];
				}
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		SETTERS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	void set_N(const __int32 N)
	{
		this->N = N;
	}
	void set_Grille_Matrix(const std::string & line)
	{
		for (int i = which_row; i <= which_row; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				Grille_Matrix[i][j] = line[j];
			}
		}
		which_row++;
		if (which_row >= N)
		{
			which_row = 0;
		}
	}
	void set_line_decoded(const std::string & line_decoded)
	{
		this->line_decoded = line_decoded;
	}
	void set_To_Read_Message_Matrix(const std::string & line)
	{
		for (int i = which_row; i <= which_row; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				To_Read_Message_Matrix[i][j] = line[j];
			}
		}
		which_row++;
		if (which_row >= N)
		{
			which_row = 0;
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		GETTERS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	const __int32 get_N() const
	{
		return N;
	}
	const std::string & get_line_decoded() const
	{
		return line_decoded;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		OPERATORS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	_Grille & operator=(const _Grille & Object)
	{
		if (this != &Object)
		{
			this->N = Object.N;
			this->line_decoded = Object.line_decoded;
		}
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		DESTRUCTOR
	*/
	virtual ~_Grille()
	{
		line_decoded = "";
		N = 0;
		which_row = 0;
		To_Read_Message_Matrix.clear();
		Grille_Matrix.clear();
	}
	///////////////////////////////////////////////////////////////////////////
};

//FUNCTION FOR INSERTING VALUES
void foo();
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	foo();
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

void foo()
{
	std::string data_reader = "";		//czyta dane z pliku
	__int32 N = 0;
	while (true)
	{
		std::cin >> N;
		if (N != 0)
		{
			_Grille Grille_Object(N);
			for (int i = 0; i < N; ++i)
			{
				std::cin >> data_reader;
				Grille_Object.set_Grille_Matrix(data_reader);
				data_reader = "";
			}
			for (int i = 0; i < N; ++i)
			{
				std::cin >> data_reader;
				if (data_reader == "")
				{
					data_reader = "A";
				}
				Grille_Object.set_To_Read_Message_Matrix(data_reader);
				data_reader = "";
			}
			Grille_Object.read_message();
			Grille_Object.rotate_90();
			Grille_Object.read_message();
			Grille_Object.rotate_90();
			Grille_Object.read_message();
			Grille_Object.rotate_90();
			Grille_Object.read_message();
			std::cout << Grille_Object.get_line_decoded() << std::endl;
		}
		else
		{
			break;
		}
		data_reader = "";
		N = 0;
	}
}