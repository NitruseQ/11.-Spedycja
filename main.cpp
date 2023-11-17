#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "struct.h"
#include "functions.h"

/// Program do wyszukiwania najkrotszych mozliwych tras do wszystkich podanych miast, zaczynajac od centrali.
int main(int argc, char* argv[])
{
    std::pair<std::string, std::string> param = readParams(argc, argv); //first = source, second = center
    std::ifstream file(param.first);
    if (file) {
        //zainicjowanie zmiennych
        std::vector<link> links;
        std::vector<route> routes;
        std::string town1, town2;
        int dist;

        //wczytanie danych z pliku
        while (file >> town1 >> town2 >> dist) links.push_back({{ town1, town2 }, dist});

        //znalezienie najkrotszych tras
        whatsNext(routes, links, {}, param.second, 0);

        //wypisanie ich na ekran
        std::ofstream outputFile("output.txt");
        writeFoundOutput(routes, outputFile);
        writeNotFoundOutput(param.second, links, routes, outputFile);
        outputFile.close();
    }
    else std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    return 0;
}