#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Element
{
private:
	int pionowy;
	int koszt;
	int krawedz;
	std::vector<int> polaczenia;
	size_t polaczenia_rozmiar;
public:
	Element();
	Element(const int pionowy, const int koszt, const int krawedz);
	Element(const Element & Obiekt);
	virtual ~Element();

	int get_pionowy() const;
	int get_koszt() const;
	int get_krawedz() const;
	size_t get_polaczenia_rozmiar() const;
	int get_polaczenia_szyk(const size_t licznik) const;

	void set_polaczenia_rozmiar(const size_t polaczenia_rozmiar);
	void set_polaczenie(const int wartosc, const size_t licznik);
	void set_way(const int cel, const int waga_drogi);
	void set_pionowy(const int pionowy);
	void set_koszt(const int koszt);
	void set_krawedz(const int krawedz);
};

Element::Element() :
	polaczenia_rozmiar(0),
	pionowy(0),
	koszt(0),
	krawedz(0)
{
	polaczenia.resize(polaczenia_rozmiar);
	for (size_t i = 0; i < this->polaczenia_rozmiar; ++i)
	{
		polaczenia[i] = 0;
	}
}

Element::Element(const int pionowy, const int koszt, const int krawedz) :
	polaczenia_rozmiar(0),
	pionowy(pionowy),
	koszt(koszt),
	krawedz(krawedz)
{
	polaczenia.resize(polaczenia_rozmiar);
	for (size_t i = 0; i < this->polaczenia_rozmiar; ++i)
	{
		polaczenia[i] = 0;
	}
}

Element::Element(const Element & Obiekt) :
	polaczenia_rozmiar(Obiekt.polaczenia_rozmiar),
	pionowy(Obiekt.pionowy),
	koszt(Obiekt.koszt),
	krawedz(Obiekt.krawedz)
{
	polaczenia.resize(polaczenia_rozmiar);
	for (size_t i = 0; i < this->polaczenia_rozmiar; ++i)
	{
		polaczenia[i] = 0;
	}
}

Element::~Element()
{
	polaczenia_rozmiar = 0;
	krawedz = 0;
	koszt = 0;
	pionowy = 0;
}

int Element::get_pionowy() const
{
	return this->pionowy;
}

int Element::get_koszt() const
{
	return this->koszt;
}

int Element::get_krawedz() const
{
	return this->krawedz;
}

size_t Element::get_polaczenia_rozmiar() const
{
	return this->polaczenia_rozmiar;
}

int Element::get_polaczenia_szyk(const size_t licznik) const
{
	return polaczenia[licznik];
}

void Element::set_polaczenia_rozmiar(const size_t polaczenia_rozmiar)
{
	this->polaczenia_rozmiar = polaczenia_rozmiar;
	polaczenia.clear();
	polaczenia.resize(polaczenia_rozmiar);
	for (size_t i = 0; i < this->polaczenia_rozmiar; ++i)
	{
		polaczenia[i] = 0;
	}
}

void Element::set_polaczenie(const int wartosc, const size_t licznik)
{
	this->polaczenia[licznik] = wartosc;
}

void Element::set_way(const int cel, const int waga_drogi)
{
	this->polaczenia[(cel - 1)] = waga_drogi;
}

void Element::set_pionowy(const int pionowy)
{
	this->pionowy = pionowy;
}

void Element::set_koszt(const int koszt)
{
	this->koszt = koszt;
}

void Element::set_krawedz(const int krawedz)
{
	this->krawedz = krawedz;
}

class MST
{
private:
	std::vector<Element> graf;
	size_t graf_dlugosc;
	
	std::vector<Element> macierz;
	size_t macierz_dlugosc;

	std::vector<int> Q;
	size_t Q_dlugosc;
	int Q_licznik;
	
	vector<Element> F;
	
	vector<pair<pair<int, int>, int>> cel;
	
	void znajdz_droge(const int skad, const int dokad, const int waga_drogi);
	
public:
	MST();
	MST(const size_t graf_dlugosc);
	virtual ~MST();

	void pchaj(const int wartosc, const int cel, const int waga_drogi);
	void pchaj_kierunkowo(const int skad, const int dokad, const int waga_drogi);
	void MST_tworzenie(const int poczatek);
	void get_wynik();
};

MST::MST() :
	graf_dlugosc(0),
	Q_dlugosc(0),
	Q_licznik(0),
	macierz_dlugosc(0)
{
	graf.resize(graf_dlugosc);
	Q.resize(Q_dlugosc);
	macierz.resize(macierz_dlugosc);
}

MST::MST(const size_t graf_dlugosc) :
	graf_dlugosc(graf_dlugosc),
	Q_dlugosc(graf_dlugosc),
	Q_licznik(0),
	macierz_dlugosc(graf_dlugosc)
{
	graf.resize(graf_dlugosc);
	Q.resize(Q_dlugosc);
	macierz.resize(macierz_dlugosc);
	for (size_t i = 0; i < this->graf_dlugosc; ++i)
	{
		this->graf[i].set_polaczenia_rozmiar(this->graf_dlugosc);
		this->Q[i] = static_cast<int>((i + 1));
		this->macierz[i].set_pionowy(static_cast<int>((i + 1)));
		this->macierz[i].set_koszt(0);
		this->macierz[i].set_krawedz(0);
	}
}

MST::~MST()
{
	graf.clear();
	Q.clear();
	macierz.clear();
	F.clear();
	graf_dlugosc = 0;
	Q_licznik = 0;
	Q_dlugosc = 0;
	macierz_dlugosc = 0;
}

void MST::pchaj(const int wartosc, const int cel, const int waga_drogi)
{
	this->graf[(wartosc - 1)].set_way(cel, waga_drogi);
}

void MST::pchaj_kierunkowo(const int skad, const int dokad, const int waga_drogi)
{
	cel.emplace_back(make_pair(make_pair(skad, dokad), waga_drogi));
}

void MST::MST_tworzenie(const int poczatek)
{
	F.clear();
	for (size_t i = 0; i < macierz_dlugosc; ++i)
	{
		macierz[i].set_koszt(0);
		macierz[i].set_krawedz(0);
		Q[i] = static_cast<int>((i + 1));
	}
	Q_licznik = 0;
	int aktualny_pionowy = (poczatek - 1);
	int min_koszt = 0;
	int min_koszt_pozycja = 0;
	while (Q_licznik < static_cast<int>(Q_dlugosc))
	{
		Q[(aktualny_pionowy)] = 0;
		++Q_licznik;
		if (macierz[(aktualny_pionowy)].get_krawedz() != 0)
		{
			F.emplace_back(Element(macierz[aktualny_pionowy].get_pionowy(), 0, 0));
			F.emplace_back(Element(macierz[aktualny_pionowy].get_pionowy(), 0, macierz[aktualny_pionowy].get_krawedz()));
		}
		else
		{
			F.emplace_back(Element(macierz[aktualny_pionowy].get_pionowy(), 0, 0));
		}
		for (size_t j = 0; j < graf[aktualny_pionowy].get_polaczenia_rozmiar(); ++j)
		{
			if (graf[aktualny_pionowy].get_polaczenia_szyk(j) != 0 && Q[j] == macierz[j].get_pionowy())
			{
				if ((macierz[j].get_koszt() >= graf[aktualny_pionowy].get_polaczenia_szyk(j)) || (macierz[j].get_koszt() == 0))
				{
					macierz[j].set_koszt(graf[aktualny_pionowy].get_polaczenia_szyk(j));
					macierz[j].set_krawedz((aktualny_pionowy + 1));
				}
			}
			else
			{
				continue;
			}
		}
		for (size_t i = 0; i < macierz_dlugosc; ++i)
		{
			if (macierz[i].get_koszt() <= min_koszt && Q[i] == macierz[i].get_pionowy())
			{
				min_koszt = macierz[i].get_koszt();
				min_koszt_pozycja = static_cast<int>(i);
			}
		}
		aktualny_pionowy = min_koszt_pozycja;
		min_koszt = 0;
		min_koszt_pozycja = 0;
	}
}

void MST::get_wynik()
{
	for (typename vector<pair<pair<int, int>, int>>::const_iterator iter = cel.begin(); iter != cel.end(); ++iter)
	{
		znajdz_droge(iter->first.first, iter->first.second, iter->second);
	}
}

void MST::znajdz_droge(const int skad, const int dokad, const int waga_drogi)
{
	if (skad == dokad)
	{
		cout << '0' << endl;
	}
	else
	{
		int * zwiedzone = new int[this->graf_dlugosc];
		for (size_t i = 0; i < graf_dlugosc; ++i)
		{
			zwiedzone[i] = 0;
		}

		double min_droga = -1000000000;
		int aktualny_pionowy = (skad - 1);
		int cel_pionowy = dokad;
		bool znaleziony_cel = false;
		int skad_he = 0;
		int dokad_he = 0;

		if (skad < dokad)
		{
			skad_he = dokad;
			dokad_he = skad;
		}
		else
		{
			skad_he = skad;
			dokad_he = dokad;
		}

		MST_tworzenie(dokad_he);

		aktualny_pionowy = macierz[(skad_he - 1)].get_krawedz();
		if (min_droga < macierz[(skad_he - 1)].get_koszt())
		{
			min_droga = macierz[(skad_he - 1)].get_koszt();
		}
		zwiedzone[(aktualny_pionowy)-1] = macierz[(skad_he - 1)].get_pionowy();
		while (znaleziony_cel == false)
		{
			for (int i = macierz_dlugosc - 1; i >= 0; --i)
			{
				if (macierz[i].get_pionowy() == (aktualny_pionowy))
				{
					zwiedzone[(aktualny_pionowy)-1] = aktualny_pionowy;
					aktualny_pionowy = macierz[i].get_krawedz();
					if (min_droga < macierz[i].get_koszt())
					{
						min_droga = macierz[i].get_koszt();
					}
					break;
				}
				if ((aktualny_pionowy) == macierz[(dokad_he - 1)].get_pionowy())
				{
					znaleziony_cel = true;
					break;
				}
			}

		}
		min_droga *= -1;
		min_droga -= 1;
		double wynik = ceil(static_cast<double>(((static_cast<double>(waga_drogi) / (min_droga)))));
		cout << wynik << endl;
		delete[] zwiedzone;
	}
}

void inserter();

int main(int argc, char* argv[])
{
	inserter();
	return EXIT_SUCCESS;
}

void inserter()
{
	int m = 0;			//liczba miast
	int d = 0;			//liczba drog
	int c1 = 0;			//liczba miast
	int c2 = 0;			//liczba miast
	int p = 0;			//max liczba pasazerow w jednym kursie
	int s = 0;			//poczatek drogi
	int e = 0;			//koniec drogi
	int t = 0;			//liczba pasazerwo do przejazdu
	while (true)
	{
		cin >> m;
		cin >> d;
		MST MST_Obiekt(m);
		while (d > 0)
		{
			cin >> c1;
			cin >> c2;
			cin >> p;
			MST_Obiekt.pchaj(c1, c2, (-1)*p);
			MST_Obiekt.pchaj(c2, c1, (-1)*p);
			--d;
			c1 = 0;
			c2 = 0;
			p = 0;
		}
		while (true)
		{
			cin >> s;
			cin >> e;
			if (s != 0 && e != 0)
			{
				cin >> t;
				MST_Obiekt.pchaj_kierunkowo(s, e, t);
			}
			else
			{
				MST_Obiekt.get_wynik();
				exit(0);
			}
			s = 0;
			e = 0;
			t = 0;
		}
		d = 0;
		m = 0;
	}
}