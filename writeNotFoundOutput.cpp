#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include "struct.h"

/// Wypisuje i zapisuje do pliku nieznalezione polaczenia miedzy miastami.
/// @param startAt Miasto centrali.
/// @param connections Vector dwuelementowych arrayow wszystkich polaczen miedzy miastami.
/// @param routes Wszystkie trasy miedzy miastami.
/// @param allTowns Vector wszystkich miast.
/// @param outputFile plik wyjsciowy.
void writeNotFoundOutput(
    std::string& startAt,
    std::vector<std::array<std::string, 2>>& connections,
    std::vector<route>& routes,
    std::vector<std::string>& allTowns,
    std::ofstream& outputFile
) {
    if (!outputFile) std::cout << "Nie udalo sie zapisac znalezionych polaczen do pliku!" << std::endl;
    for (int k = 0; k <= 1; k++) {
        for (int i = 0; i < connections.size(); i++) {
            bool townInAllTowns = (std::find(allTowns.begin(), allTowns.end(), connections[i][k]) != allTowns.end());
            if (connections[i][k] != startAt && !townInAllTowns) {
                allTowns.push_back(connections[i][k]);
                bool foundRoute = false;
                for (int j = 0; j < routes.size(); j++) {
                    if (connections[i][k] == routes[j].last) {
                        foundRoute = true;
                        break;
                    }
                }
                if (!foundRoute) {
                    std::string output = "Nie znaleziono polaczenia: " + startAt + " -> " + connections[i][k] + "\n";
                    std::cout << output;
                    if (outputFile) outputFile << output;
                }
            }
        }
    }
}