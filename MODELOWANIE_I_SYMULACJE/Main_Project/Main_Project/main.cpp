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

std::mt19937 generator(time(nullptr));

class _Project
{
private:
	double time;
	const double start_time;

	const double Simulate_Ride_Time(const double time_from, const double time_to);
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
	using std::cout;
	using std::endl;
	using std::cin;
	using std::cerr;

	_Project Obj;

	Obj.Symulacja_Monte_Carlo();

	system("pause");
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

const double _Project::Simulate_Ride_Time(const double time_from, const double time_to)
{
	std::normal_distribution<> waiting_time(time_from, time_to);
	return waiting_time(generator);
}

_Project::_Project():
	start_time(0),
	time(0)
{

}

void _Project::Etap_1()
{
	//losowanie zielonego, czerwonego swiatla badz wypadku(objazd)
	std::discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	int number = static_cast<int>(x(generator));
	//rozklad quassona zeby zmienic czestotliwosc wypadkow
	if (number == 0)
	{
		//losowanie czasu przejazdu z rozkladu normalnego
		time += Simulate_Ride_Time(3,1);
	}
	else if (number == 1)
	{
		time += Simulate_Ride_Time(5, 1);
	}
	else if (number == 2)
	{
		time += Simulate_Ride_Time(10, 3);
		//5 mozliwosci objazdu
		std::discrete_distribution<> x2({ 40.0f, 20.0f, 10.0f, 20.0f, 10.0f });

		int number_2 = static_cast<int>(x2(generator));

		if (number_2 == 0)
		{
			time += Simulate_Ride_Time(5, 2);
		}
		else if (number_2 == 1)
		{
			time += Simulate_Ride_Time(5, 1);
		}
		else if (number_2 == 2)
		{
			time += Simulate_Ride_Time(8, 3);
		}
		else if (number_2 == 3)
		{
			time += Simulate_Ride_Time(12, 5);
		}
		else if (number_2 == 4)
		{
			time += Simulate_Ride_Time(4, 1);
		}
		else if (number_2 == 5)
		{
			time += Simulate_Ride_Time(15, 6);
		}
	}
}

void _Project::Etap_2()
{
	//losowanie zielonego, czerwonego swiatla badz zepsuta sygnalizacja
	std::discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	int number = static_cast<int>(x(generator));

	if (number == 0)
	{
		time += Simulate_Ride_Time(5, 1);
	}
	else if (number == 1)
	{
		time += Simulate_Ride_Time(6, 2);
	}
	else if (number == 2)
	{
		time += Simulate_Ride_Time(3, 1);
	}
}

void _Project::Etap_3()
{
	std::bernoulli_distribution probability(0.5);
	bool temp = probability(generator);
	if (!temp)
	{
		std::normal_distribution<> waiting_time(4,1);//ujemny czas, popraw
		time += waiting_time(generator);
	}
}

void _Project::Etap_4()
{
	//losowanie zielonego, czerwonego swiatla badz jedzie pojazd uprzywilejowany
	std::discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	int number = static_cast<int>(x(generator));

	if (number == 0)
	{
		time += Simulate_Ride_Time(10, 4);
	}
	else if (number == 1)
	{
		time += Simulate_Ride_Time(5, 1);
	}
	else if (number == 2)
	{
		time += Simulate_Ride_Time(7, 3);
	}
}

void _Project::Etap_5()
{
	//losowanie zielonego, czerwonego swiatla badz wypadku(objazd)
	std::discrete_distribution<> x({ 40.0f, 40.0f, 20.0f });

	int number = static_cast<int>(x(generator));

	if (number == 0)
	{
		time += Simulate_Ride_Time(3, 1);
	}
	else if (number == 1)
	{
		time += Simulate_Ride_Time(5, 2);
	}
	else if (number == 2)
	{
		time += Simulate_Ride_Time(15, 4);
		//3 mozliwosci objazdu
		std::discrete_distribution<> x2({ 30.0f, 30.0f, 40.0f });

		int number_2 = static_cast<int>(x2(generator));

		if (number_2 == 0)
		{
			time += Simulate_Ride_Time(6, 2);
		}
		else if (number_2 == 1)
		{
			time += Simulate_Ride_Time(3, 1);
		}
		else if (number_2 == 2)
		{
			time += Simulate_Ride_Time(5, 1);
		}
	}
}

void _Project::Symulacja_Monte_Carlo()
{
	std::fstream file_out("file.out", std::ios_base::out);
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