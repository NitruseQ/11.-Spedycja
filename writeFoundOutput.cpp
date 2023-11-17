#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include "struct.h"

/// Wypisuje i zapisuje do pliku znalezione polaczenia miedzy miastami.
/// @param routes Wszystkie trasy miedzy miastami.
/// @param outputFile Plik wyjsciowy.
void writeFoundOutput(
    std::vector<route>& routes,
    std::ofstream& outputFile
) {
    if (!outputFile) std::cout << "Nie udalo sie zapisac znalezionych polaczen do pliku!" << std::endl;
    for (int i = 0; i < routes.size(); i++) {
        std::string between = "";
        for (int j = 0; j < routes[i].between.size(); j++) {
            between += routes[i].between[j] + " -> ";
        }
        std::string output = routes[i].first + " -> " + between + routes[i].last + ": " + std::to_string(routes[i].distance) + "km" + "\n";
        std::cout << output;
        if (outputFile) outputFile << output;
    }
}