#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "struct.h"
#include "functions.h"

//blad

/// Program do wyszukiwania najkrotszych mozliwych tras do wszystkich podanych miast, zaczynajac od centrali.
int main(int argc, char* argv[])
{
    params param = readParams(argc, argv);
    std::ifstream file(param.source);
    std::string startAt = param.startAt;
    if (file) {
        std::vector<std::array<std::string, 2>> connections;
        std::vector<int> distances;
        std::vector<std::string> allTowns;
        std::string town1, town2;
        std::vector<route> routes;
        int dist;

        while (file >> town1 >> town2 >> dist) {
            connections.push_back({ town1, town2 });
            distances.push_back(dist);
        }

        whatsNext(routes, connections, distances, {}, startAt, 0);

        std::ofstream outputFile("output.txt");
        writeFoundOutput(routes, outputFile);
        writeNotFoundOutput(startAt, connections, routes, allTowns, outputFile);
        outputFile.close();
    }
    else std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    return 0;
}