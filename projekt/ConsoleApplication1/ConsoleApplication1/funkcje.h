/** @file  */

// DECLARATIONS (HEADERS) OF FUNCTIONS 

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include <vector>

#include "struktury.h"
#include "funkcje.h"


/** @brief Funkcja sprawdza poprawnosc parametrow wejsciowych
* @param ile Liczba parametrow wejsciowych programu
* @param params[] Tablica zawierajaca te parametry
* @return Zwraca mape parametrow
*/
std::map<std::string, std::string> parametry(const int& ile, char* params[]);

/** @brief Funkcja wypisujaca na ekran poradnik dotyczacy uzytkowania programu
*/
void poradnik();

/** @brief Funkcja informujaca o niepoprawnych typach danych wejsciowych
* @return Nie zwraca niczego
*/
void poradnik_wejscie();

/** @brief Funkcja wczytujaca punkty z pliku wejsciowego
* @param input Nazwa pliku wejsciowego przekazanego jako parametr i
* @return Zwraca wektor wczytanych punktow
*/
std::vector<punkt> wczytywanie(const std::string& input);

/** @brief Funkcja ustalajaca najblizszych sasiadow kazdego z punktow(modyfikuje istniejacy wektor)
* @param[out] punkty Wektor wszystkich pobranych punktow
* @param n Liczba najblizszych sasiadow przekazana jako parametr n
*/
void przypisz_sasiadow(std::vector<punkt>& punkty, const int& n);

/** @brief Funkcja obliczajaca odleglosc miedzy dwoma punktami
* @param i Pierwszy punkt
* @param n Drugi punkt
* @return Zwraca odleglosc euklidesowa
*/

double obl_odl(const punkt& i, const punkt& j);

/** @brief Funkcja przypisujaca klase kazdemu z punktow zgodnie z glownym zalozeniem algorytmu
* @param[out] punkty Wektor wszystkich pobranych punktow
* @param n Liczba najblizszych sasiadow przekazana jako parametr n   (int liczba; double ilosc;)
* @param w Liczba wspolnych sasiadow miedzy dowlonymi punktami przekazana jako parametr w
*/
void przypisz_klase(std::vector<punkt>& punkty, const int& n, const int& w);

/** @brief Funkcja przypisujaca tymczasowa klase kazdemu punktowi (modyfikuje istniejacy wektor)
* @param[out] punkty Wektor wszystkich pobranych punktow
*/

void klasa_temp(std::vector<punkt>& punkty);

/** @brief Funkcja wypisujaca klasy punktow oraz ich wspolrzedne do pliku wyjsciowego
* @param[out] punkty Wektor wszystkich pobranych punktow
* @param output Nazwa pliku wyjsciowego przekazana jako parametr o
*/
void zapisz_do_pliku(const std::vector<punkt>& punkty, const std::string& output);

#endif