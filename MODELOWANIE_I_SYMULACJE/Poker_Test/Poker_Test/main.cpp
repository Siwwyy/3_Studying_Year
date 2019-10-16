#include <iostream>
#include <windows.h>
#include <string>

#define NEW_LINE '\n'


class Gen
{
public:
	Gen();
	Gen(int seed);

public:
	const float Generate();

private:
	long long a;
	long long c;
	long long m;
	long long xi;
};


class Cards_Generator
{
private:
	size_t amount_of_cards;
	int N;	//ilosc graczy
	int M;	//ilosc kart dla graczy
	int Ilosc_Figur;	//ilosc kart
	int** player_matrix;	//gracze z ich kartami
	int* dostepne_karty;

	Gen Rand;
public:

	Cards_Generator():
		N(50),
		M(5),
		Ilosc_Figur(10)
	{
		this->player_matrix = new int* [this->N];
		this->dostepne_karty = new int[this->N * this->M];

		for (size_t i = 0; i < this->N; ++i)
		{
			this->player_matrix[i] = new int[this->M];
			for (size_t j = 0; j < this->M; ++j)
			{
				player_matrix[i][j] = -1;
			}
		}
	}

	void Print_Player_Matrix() const
	{
		
		for (size_t i = 0; i < this->N; ++i)
		{
			_STD cout << "Gracz nr" << (i+1) << ": ";
			for (size_t j = 0; j < this->M; ++j)
			{
				_STD cout << player_matrix[i][j] << ' ';
			}
			_STD cout << NEW_LINE;
		}
	}
	void Print_Cards() const
	{
		_STD cout << "Karty: ";
		for (size_t i = 0; i < (this->N* this->M); ++i)
		{
			_STD cout << dostepne_karty[i] << ' ';
		}
		_STD cout << NEW_LINE;
	}

	void Rozdaj()
	{
		for (size_t i = 0; i < N * M; ++i)
		{
			float temporary = Rand.Generate();
			dostepne_karty[i] = (int)(temporary/ (1.0f/Ilosc_Figur));
		}

		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < M; ++j)
			{
				player_matrix[i][j] = dostepne_karty[(j+(i*M))];
			}
		}

		Print_Cards();
		Print_Player_Matrix();
		
	}

	void Count_Unique_Occurences()
	{
		int ilosc_wystopien[7]{};
		/*
			Index:
			0 -> brak par itp
			1 -> 1 para
			2 -> 2 pary
			3 -> trojka
			4 -> full
			5 -> kareta
			6 -> piatka
		*/

		for(size_t i = 0; i < N; ++i)
		{
			size_t occurences{1};
			for (size_t j = 0; j < M; ++j)
			{
				//player_matrix[i][j]
				int current_value{ 0 };
				bool if_bool{false};
				for (size_t k = 0; k < M; ++k)
				{
					if ((player_matrix[i][j] == player_matrix[i][k]) && j != k)
					{
						current_value = player_matrix[i][j];
						break;
					}
				}
				
				for (size_t k = 0; k < M; ++k)
				{
					if (player_matrix[i][k] == current_value)
					{
						//player_matrix[i][k] = (-1);
						++occurences;
					}
				}
				for (size_t k = 0; k < M; ++k)
				{
					if (player_matrix[i][k] == current_value)
					{
						player_matrix[i][k] = (-1);
					}
				}
				if (occurences == 1)
				{
					occurences = 0;
				}
			}
			if (occurences == 0)
			{
				++ilosc_wystopien[0];
			}
			else if (occurences % 2 == 0)
			{
				++ilosc_wystopien[1];
			}
			else if (occurences % 3 == 0)
			{
				++ilosc_wystopien[2];
			}
			else if (occurences % 4 == 0)
			{
				++ilosc_wystopien[3];
			}
			else if (occurences % 5 == 0)
			{
				++ilosc_wystopien[5];
			}
			else if (occurences % 6 == 0)
			{
				++ilosc_wystopien[6];
			}
			else if (occurences % 7 == 0)
			{
				++ilosc_wystopien[6];
			}
		}

		for (size_t i = 0; i < 7; ++i)
		{
			_STD cout << ilosc_wystopien[i] << ' ';
		}
		_STD cout << NEW_LINE;
		float brak = float(float(ilosc_wystopien[0] / N) * 100);
		float para = float(float(ilosc_wystopien[1] / N) * 100);
		float pary_dwie = float(float(ilosc_wystopien[2] / N) * 100);
		float trojka = float(float(ilosc_wystopien[3] / N) * 100);
		float full = float(float(ilosc_wystopien[4] / N) * 100);
		float czworka = float(float(ilosc_wystopien[5] / N) * 100);
		float poker = float(float(ilosc_wystopien[6] / N) * 100);
		//Print_Player_Matrix();
		_STD cout << brak << ' ' << para << ' ' << pary_dwie << ' ' << trojka << ' ' << full << ' ' << czworka << ' ' << poker << NEW_LINE;
	}

	~Cards_Generator() 
	{
		for (size_t i = 0; i < this->N; ++i)
		{
			delete[] this->player_matrix[i];
		}
		delete[] player_matrix;
		delete[] dostepne_karty;
	};
};




int main(int argc, char* argv[])
{
	Cards_Generator Obj;

	Obj.Rozdaj();
	Obj.Count_Unique_Occurences();

	system("pause");
	return 0;
}

///////////////////////////////////////

Gen::Gen()
	:
	xi(0)
	, a(22695477)
	, c(1)
	, m(4294967296)
{

}

Gen::Gen(int seed)
	:
	xi(seed)
{

}

const float Gen::Generate()
{
	xi = (a * xi + c) % m;
	return (float)xi / (m - 1);
}

///////////////////////////////////////