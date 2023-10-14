#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <set>
#include <cstring>

#include "struktury.h"
#include "funkcje.h"

std::map<std::string, std::string> parametry(const int & ile, char * params[]) 
{
	std::string input;
	std::string output;
	std::string n;
	std::string w;

	bool czy_i = false;
	bool czy_o = false;
	bool czy_n = false;
	bool czy_w = false;
	std::map<std::string, std::string> mapa;
	//std::cout << "Liczba parametrow: " << ile << std::endl;
	for (int i = 1; i < ile; i++) 
	{
		//std::cout << "Parametr" << "[" << i << "]: " << typeid(params[i]).name() << std::endl;
		if (strcmp(params[i], "-i") == 0)
		{
			if (i + 1 < ile)  // if (i + 1 < ile)
			{
				if ((strcmp(params[i + 1], "-n") != 0) && (strcmp(params[i + 1], "-w") != 0)) {
					input = params[i + 1];
					czy_i = true;
				}
			}
		}
		else if (strcmp(params[i], "-o") == 0) {
			if (i + 1 < ile) {
				if ((strcmp(params[i + 1], "-n") != 0) && (strcmp(params[i + 1], "-w") != 0)) {
					output = params[i + 1];
					czy_o = true;
				}
			}
		}
		else if (strcmp(params[i], "-n") == 0) {
			if (i + 1 < ile) {
				if ((strcmp(params[i + 1], "-n") != 0) && (strcmp(params[i + 1], "-w") != 0)) {
					n = params[i + 1];
					czy_n = true;
				}
			}
		}
		else if (strcmp(params[i], "-w") == 0) {
			if (i + 1 < ile) {
				if ((strcmp(params[i + 1], "-n") != 0) && (strcmp(params[i + 1], "-w") != 0)) {
					w = params[i + 1];
					czy_w = true;
				}
			}
		}
	}
	if ((ile != 9) || ((czy_i == false) || (czy_o == false) || (czy_n == false) || (czy_w == false))) 
	{
		std::cout << "Program uruchomiony z nieprawidlowymi parametrami." << std::endl;
		poradnik();
	}
	else {
		mapa.insert(std::make_pair("-i", input));
		mapa.insert(std::make_pair("-o", output));
		mapa.insert(std::make_pair("-n", n));
		mapa.insert(std::make_pair("-w", w));
	
		
	}
	return mapa;
}

void poradnik() {
	std::cout << "Program powinien zostac uruchomiony z linii polecen z wykorzystaniem nastepujacych przelacznikow: " << std::endl;
	std::cout << " -i	nazwa pliku wejsciowego z rozszerzeniem" << std::endl;
	std::cout << " -o	nazwa pliku wyjsciowego z rozszerzeniem" << std::endl;
	std::cout << " -n	liczba najblizszych sasiadow (liczba naturalna)" << std::endl;
	std::cout << " -w	liczba wspolnych najblizszych sasiadow (liczba naturalna) " << std::endl;
}

void poradnik_wejscie() {
	std::cout << "Program uruchomiony z nieprawidlowymi parametrami." << std::endl;
	std::cout << "Plik wejsciowy o podanej nazwie nie istnieje badz jest pusty! " << std::endl;
}

std::vector<punkt> wczytywanie(const std::string& input) {
	//wczytywanie wspolrzednych punktow
	std::ifstream plik(input);
	std::vector<punkt> punkty;
	int i = 1;
	std::string linia;
	// getline --> string, find_first_of,  substr
	// stringstream
	while (getline(plik, linia))
	{
		std::stringstream ss;
		std::size_t pozycja = linia.find_first_of("%"); // Co sie stanie, gdzy % nie b�dzie? Dlaczego to dziala?
		std::string ucieta = linia.substr(0, pozycja);
		ss << ucieta;
		double liczba;
		//std::istream_iterator<double> begin(ss);
		//std::istream_iterator<double> end;
		//std::vector<double> wspolrzedne(begin, end);
		std::vector<double> wspolrzedne;
		while (ss >> liczba) {
			wspolrzedne.push_back(liczba);
		}
		punkt punkt;
		punkt.id = i;
		punkt.wspolrzedne = wspolrzedne;
		punkty.push_back(punkt);
		i++;
	}
	return punkty;
}

void przypisz_sasiadow(std::vector<punkt>& punkty, const int& n) {
	for (punkt& i : punkty) 
	{
		std::vector<std::pair<int,      // nr punktu 
		                      double    // odleglosc
							 >> vec;

		//obliczanie odleglosci miedzy punktami
		for (punkt& j : punkty) {
			vec.push_back(std::make_pair(j.id, obl_odl(i,j)));
		}

		//sortowanie odleglosci miedzy punktami

		/*
		std::map<int,double> ::iterator it;
		for (it = odleglosci.begin(); it != odleglosci.end(); it++)
		{
			vec.push_back(std::make_pair(it->first, it->second));
		}
		*/

		std::sort(vec.begin(), vec.end(),
			//lambda
			[](const std::pair<int, double>& a, const std::pair<int, double>& b) {
				return (a.second < b.second);
			}
		);
		for (int a = 1; a < n + 1; a++)
		{
			i.sasiedzi.push_back(vec[a].first);
		}
	}
}

double obl_odl(const punkt& i, const punkt& j) {
	double odleglosc = 0;
	double roznica_wsp;
	for (int k = 0; k < i.wspolrzedne.size(); k++) {
		roznica_wsp = i.wspolrzedne[k] - j.wspolrzedne[k];
		odleglosc += pow(roznica_wsp, 2);
	}
	return sqrt(odleglosc);
}

void przypisz_klase(std::vector<punkt>& punkty, const int& n, const int& w) {
	klasa_temp(punkty);
	for (punkt& i : punkty) 
	{
		for (punkt& j : punkty) 
		{
			std::set<int> set_sasiedzi;
			for (int x = 0; x < j.sasiedzi.size(); x++) 
			{
				set_sasiedzi.insert(i.sasiedzi[x]);
				set_sasiedzi.insert(j.sasiedzi[x]);
			}
			if (set_sasiedzi.size() <= (2 * n) - w) 
			{
				int j_temp = j.klasa;
				int i_temp = i.klasa;
				j.klasa = i.klasa;
				for (punkt& k : punkty) {  // scalanie grup (struktrura danych rozłącznych)
					if ((k.klasa == j_temp)/*|| (k.klasa == i.klasa)*/) 
					{
						k.klasa = i_temp;
					}	
				}
			}
			set_sasiedzi.clear();
		}
	}
}

void klasa_temp(std::vector<punkt>& punkty) {
	int k = 1;
	for (punkt& i : punkty) {
		i.klasa = k++;
	}
}

void zapisz_do_pliku(const std::vector<punkt>& punkty, const std::string & output) {
	std::ofstream plik(output);
	std::stringstream ss;
	for (punkt i : punkty) {
		if (i.id > 1) {
			plik << "\n";
		}
		plik << std::setw(3) <<i.klasa;
		for (double j : i.wspolrzedne) {
			plik << std::fixed << std::setw(7) << std::setprecision(2) <<j;
		}
	}
}
