/*
	Czas przejazdu przez trase WZ

	Etapy:
	1) Skrzyzowanie przy Atlas Arenie
		- mam zielone swiatlo
		- mam czerwone swiatlo
		- wypadek (jade objazdem)
	Prawdopodobienstwo 0.4,0.4,0.2; rozklad dyskretny

	2) Skrzyzowanie przy Dworcu Kaliskim
		- mam zielone swiatlo
		- mam czerwone swiatlo
		- zepsuta sygnalizacja swietlna
	Prawdopodobienstwo 0.4,0.4,0.2; rozklad dyskretny

	3) Skrzyzowanie przy Galerii Lodzkiej
		- mam zielone swiatlo
		- mam czerwone swiatlo
	Prawdopodobienstwo 0.5, rozklad normalny

	4) Skrzyzowanie Marszalkow
		- mam zielone swiatlo
		- mam czerwone swiatlo
		- mam zielone swiatlo, ale jedzie pojazd uprzywilejowany
	Prawdopodobienstwo 0.4,0.4,0.2; rozklad dyskretny

	5) Rondo Inwalidow
		- mam zielone swiatlo
		- mam czerwone swiatlo
		- wypadek
	Prawdopodobienstwo 0.4,0.4,0.2; rozklad dyskretny


	Liczba symulacji Monte Carlo: 3000
	Nazwa pliku wyjsciowego "file.out"

*/

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <time.h>
#include <iterator>
#include <string>
#include <math.h>

#define NEW_LINE '\n'

_STD mt19937 generator(time(nullptr));

class _Project
{
private:
	double time;
	const double start_time;
public:
	_Project();

	void Etap_1();
	void Etap_2();
	void Etap_3();
	void Etap_4();
	void Etap_5();

	void Symulacja_Monte_Carlo();

	~_Project();
};

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	using _STD cerr;

	_Project Obj;

	Obj.Symulacja_Monte_Carlo();

	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

_Project::_Project():
	start_time(0),
	time(0)
{

}

void _Project::Etap_1()
{
	//losowanie zielonego, czerwonego swiatla badz wypadku(objazd)
	_STD discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	__int32 number = static_cast<__int32>(x(generator));

	if (number == 0)
	{
		time += 5;
	}
	else if (number == 1)
	{
		time += 6;
	}
	else if (number == 2)
	{
		time += 10;
		//3 mozliwosci objazdu
		_STD discrete_distribution<> x2({ 30.0f, 30.0f, 40.0f });

		__int32 number_2 = static_cast<__int32>(x2(generator));

		if (number_2 == 0)
		{
			time += 4;
		}
		else if (number_2 == 1)
		{
			time += 5;
		}
		else if (number_2 == 2)
		{
			time += 8;
		}
	}
}

void _Project::Etap_2()
{
	//losowanie zielonego, czerwonego swiatla badz zepsuta sygnalizacja
	_STD discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	__int32 number = static_cast<__int32>(x(generator));

	if (number == 0)
	{
		time += 5;
	}
	else if (number == 1)
	{
		time += 6;
	}
	else if (number == 2)
	{
		time += 2;
	}
}

void _Project::Etap_3()
{
	_STD bernoulli_distribution probability(0.5);
	bool temp = probability(generator);
	if (!temp)
	{
		_STD normal_distribution<> waiting_time(2,1);
		time += waiting_time(generator);
	}
}

void _Project::Etap_4()
{
	//losowanie zielonego, czerwonego swiatla badz jedzie pojazd uprzywilejowany
	_STD discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	__int32 number = static_cast<__int32>(x(generator));

	if (number == 0)
	{
		time += 10;
	}
	else if (number == 1)
	{
		time += 12;
	}
	else if (number == 2)
	{
		time += 14;
	}
}

void _Project::Etap_5()
{
	//losowanie zielonego, czerwonego swiatla badz wypadku(objazd)
	_STD discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	__int32 number = static_cast<__int32>(x(generator));

	if (number == 0)
	{
		time += 3;
	}
	else if (number == 1)
	{
		time += 4;
	}
	else if (number == 2)
	{
		time += 15;
		//3 mozliwosci objazdu
		_STD discrete_distribution<> x2({ 30.0f, 30.0f, 40.0f });

		__int32 number_2 = static_cast<__int32>(x2(generator));

		if (number_2 == 0)
		{
			time += 2;
		}
		else if (number_2 == 1)
		{
			time += 3;
		}
		else if (number_2 == 2)
		{
			time += 5;
		}
	}
}

void _Project::Symulacja_Monte_Carlo()
{
	_STD fstream file_out("file.out", _STD ios_base::out);
	for (size_t i = 0; i < 3000; i++)
	{
		time = this->start_time;
		Etap_1();
		Etap_2();
		Etap_3();
		Etap_4();
		Etap_5();
		file_out << time << NEW_LINE;
	}

	file_out.close();
}

_Project::~_Project()
{
	this->time = NULL;
}