/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <windows.h>
#include <math.h>
#include <fstream>

#define NEW_LINE '\n'


//////////////////////////////////////////////////////////////////////////////
const size_t Amout_Of_Connections(const __int16 & amount_of_verticles);
void Create_Graph(const __int16 amount_of_verticles, const __int16 amount_of_edges_per_verticle);
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	//2->1 , 3->3, 4->6, 5->10, 6->15, 7->21, 8->28
	Create_Graph(1000,10);
	system("pause");
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////


const size_t Amout_Of_Connections(const __int16& amount_of_verticles)
{
	size_t value{ 0 };
	for (size_t i = 0; i < amount_of_verticles; ++i)
	{
		for (size_t j = i; j < amount_of_verticles; ++j)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				++value;
			}
		}
	}
	return value;
}

void Create_Graph(const __int16 amount_of_verticles, const __int16 amount_of_edges_per_verticle)
{
	_STD string file_path = "example5.out";
	_STD fstream file_out;
	file_out.open(file_path.c_str(), _STD ios_base::out);

	//file_out << amount_of_verticles << ' ' << ((amount_of_verticles * amount_of_edges_per_verticle)/2) << NEW_LINE;
	//file_out << amount_of_verticles << ' ' << ((amount_of_verticles * 2)) << NEW_LINE;
	file_out << amount_of_verticles << ' ' << Amout_Of_Connections(amount_of_verticles) << NEW_LINE;
	//int a = Amout_Of_Connections(amount_of_verticles);

	/*for (size_t i = 0; i < amount_of_verticles; ++i)
	{
		if (amount_of_verticles >= amount_of_edges_per_verticle)
		{
			for (size_t j = 0; j < amount_of_edges_per_verticle; ++j)
			{
				if (i == j)
				{
					continue;
				}
				else if (i == 0 && j == 0)
				{
					continue;
				}
				else if ((i == 0 && j == amount_of_edges_per_verticle - 1) || (i == amount_of_edges_per_verticle - 1 && j == 0))
				{
					continue;
				}
				else
				{
					file_out << (i + 1) << ' ' << (j + 1) << ' ' << (i * j + 10) << NEW_LINE;
				}
			}
		}
	}*/


	for (size_t i = 0; i < amount_of_verticles; ++i)
	{
		for (size_t j = i; j < amount_of_verticles; ++j)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				file_out << (i + 1) << ' ' << (j + 1) << ' ' << (i * j + 10) << NEW_LINE;
			}
		}
	}
	
	file_out << (1) << ' ' << (amount_of_verticles) << ' ' << 50 << NEW_LINE;
	file_out << 0 << ' ' << 0;

	file_out.close();
}