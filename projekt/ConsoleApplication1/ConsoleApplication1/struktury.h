/** @file  */

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <map>
#include <vector>
#include <string>
/**
 * @brief Typ zlozony przechowujacy informacje o kazdym wczytanym punkcie
*/
struct punkt
{
    /** Przechowuje wspolrzedne punktu*/
    std::vector<double> wspolrzedne;
    /** Przechowuje klase punktu*/
    int klasa;    
    /** Przechowuje id punktu*/
    int id;   
    /** Przechowuje id n najblizszych sasiadow, gdzie n wczytywane z parametrow wejsciowych*/
    std::vector<int> sasiedzi;

    // std::set  
    // struktura danych rozłącznych
    
};

#endif
