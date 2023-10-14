#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <set>

#include "struktury.h"
#include "funkcje.h"
		
int main (int ile, char * params[])
{

	//-----------------URUCHAMIANIE BEZ PARAMETRÓW-----------------//
	/*
	std::string input = "input5.txt";
	std::string output = "output.txt";5
	int n = 5;
	int w = 3;
	*/
	//-----------------URUCHAMIANIE Z PARAMETRAMI-----------------//
	
	std::map<std::string, std::string> mapa_parametry = parametry(ile, params);
	if(mapa_parametry.empty()){
		return 0;
	}
	std::string input = mapa_parametry.at("-i");
	std::string output = mapa_parametry.at("-o");
	int n;
	int w;
	try 
	{
		std::string n_string = mapa_parametry.at("-n");
		n = std::stoi(n_string);   // throw std::expection();
		std::string w_string = mapa_parametry.at("-w");
		w = std::stoi(w_string);
	}
	catch(std::exception & error)
	{   
		poradnik();
		return 0;
	}
	
	//------------------------------------------------------------//
	std::vector<punkt> punkty = wczytywanie(input);
	if (punkty.empty()) {
		poradnik_wejscie();
		return 0;
	}
	przypisz_sasiadow(punkty, n);

	przypisz_klase(punkty, n, w);

	zapisz_do_pliku(punkty, output);

	return 0;
}
