#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include "struct.h"

/// Wypisuje i zapisuje do pliku nieznalezione polaczenia miedzy miastami.
/// @param startAt Miasto centrali.
/// @param links Vector polaczen miast i dystansow miedzy nimi.
/// @param routes Wszystkie trasy miedzy miastami.
/// @param outputFile plik wyjsciowy.
void writeNotFoundOutput(
    std::string& startAt,
    std::vector<link>& links,
    std::vector<route>& routes,
    std::ofstream& outputFile
) {
    std::vector<std::string> allCities;
    if (!outputFile) std::cout << "Nie udalo sie zapisac znalezionych polaczen do pliku!" << std::endl;
    for (int i = 0; i < links.size(); i++) {
        for (int k = 0; k <= 1; k++) {
            bool townInAllTowns = (std::find(allCities.begin(), allCities.end(), links[i].cities[k]) != allCities.end());
            if (links[i].cities[k] != startAt && !townInAllTowns) {
                allCities.push_back(links[i].cities[k]);

                bool foundRoute = false;
                for (int j = 0; j < routes.size(); j++) {
                    if (links[i].cities[k] == routes[j].last) {
                        foundRoute = true;
                        break;
                    }
                }
                if (!foundRoute) {
                    std::string output = "Nie znaleziono polaczenia: " + startAt + " -> " + links[i].cities[k] + "\n";
                    std::cout << output;
                    if (outputFile) outputFile << output;
                }
            }
        }
    }
}