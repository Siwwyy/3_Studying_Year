
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <conio.h>

#define L_WIERSZY 4
#define L_KOLUMN  4


void wprowadz_dane(int tab[][L_KOLUMN])
{
	printf_s("wprowadz_dane\n");
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			std::cin >> tab[wiersze][kolumny];
		}
	}
}

void wprowadz_dane_losowo(int tab[][L_KOLUMN])
{
	printf_s("wprowadz_dane_losowo\n");
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			tab[wiersze][kolumny] = (rand() % 100) + 0;;
		}
	}
}

void wyswietl_dane(int tab[][L_KOLUMN])
{
	int temp = 0;
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			printf_s("%4d", tab[wiersze][kolumny]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}

void wyswietl_dane_posortowane(int tab[])
{
	printf_s("wyswietl_dane_posortowane\n");

}

float srednia(int tab[][L_KOLUMN])
{
	printf_s("srednia\n");
	int srednia{};
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			srednia += tab[wiersze][kolumny];
		}
	}
	return (float)((float)srednia/(float)( L_WIERSZY* L_KOLUMN));
}

float mediana(int tab[][L_KOLUMN], int tab_sort[])
{
	printf_s("mediana\n");
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			tab_sort[kolumny] = tab[wiersze][kolumny];
		}
		for (int kolumny = 0; kolumny < L_KOLUMN - 1; kolumny++)
		{
			if (tab_sort[kolumny] < tab_sort[kolumny + 1])
			{
				std::swap(tab_sort[kolumny], tab_sort[kolumny + 1]);
			}
		}
		printf("Mediana z kolumny %d: %d \n", wiersze, tab_sort[L_KOLUMN / 2]);
	}
	return 0;
}

void zapisz_dane(int tab[][L_KOLUMN])
{
	printf_s("zapisz_dane\n");
	std::fstream file;
	file.open("file.out", std::ios_base::out);
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			file << tab[wiersze][kolumny] << ' ';
		}
	}
	file.close();
}

void wczytaj_dane(int tab[][L_KOLUMN])
{
	printf_s("wczytaj_dane\n");
	std::fstream file;
	file.open("file.out", std::ios_base::in);
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			file >> tab[wiersze][kolumny];
		}
	}
	file.close();
}

void zamien_min_max(int tab[][L_KOLUMN])
{
	printf_s("zamien_min_max\n");
	int min{ INT_MAX };
	int max{ 0 };
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			if (tab[wiersze][kolumny] < min)
			{
				min = tab[wiersze][kolumny];
			}
			if (tab[wiersze][kolumny] > max)
			{
				max = tab[wiersze][kolumny];
			}
		}
	}
}

void menu(void)
{
	printf_s("\n");
	printf_s("1 - wprowadz dane\n");
	printf_s("2 - wyswietl dane\n");
	printf_s("3 - oblicz srednia i mediane\n");
	printf_s("4 - zamien wartosc minimalna z maksymalna\n");
	printf_s("5 - generuj dane losowo\n");
	printf_s("z - zapisz dane do pliku\n");
	printf_s("w - wczytaj dane z pliku\n");
	printf_s("k - koniec programu\n");
	printf_s("\n");
}

int main()
{
	srand(time(NULL));
	int tablica[L_WIERSZY][L_KOLUMN] = { 0 };
	int tab_sort_temp[L_WIERSZY * L_KOLUMN] = { 0 };
	char opcja = 0;

	while (opcja != 'k')
	{
		menu();
		opcja = _getch();

		switch (opcja)
		{
		case '1':
			wprowadz_dane(tablica);
			break;

		case '2':
			wyswietl_dane(tablica);
			break;

		case '3':

			printf_s("Srednia wartosci znajdujacych sie w tabeli wynosi: %f\n", srednia(tablica));
			printf_s("Mediana wartosci znajdujacych sie w tabeli wynosi: %f\n", mediana(tablica, tab_sort_temp));
			break;

		case '4':
			zamien_min_max(tablica);
			printf_s("Zamieniono wartosc minimalna z maksymalna.\n");
			break;

		case '5':
			wprowadz_dane_losowo(tablica);
			printf_s("Wygenerowano dane losowo.\n");
			break;

		case 'z':
			zapisz_dane(tablica);
			printf_s("Zapisano dane do pliku.\n");
			break;

		case 'w':
			wczytaj_dane(tablica);
			printf_s("Odczytano dane z pliku.\n");
			break;

		case 'k':
			//zakonczenie programu
			break;

		default:
			printf_s("Wybierz wlasciwa opcje.\n\n");
			break;
		}
	}

	std::cin.get();
	return 0;
}