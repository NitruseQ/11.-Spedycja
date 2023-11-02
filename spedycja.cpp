#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>

struct route {
    std::string first;
    std::vector<std::string> between;
    std::string last;
    int distance;
};

void whatsNext(std::vector<route> & routes, std::vector<std::array<std::string, 2>> & connections, std::vector<int> & distances, std::vector<std::string> beenAt, std::string now, int dist) {
    beenAt.push_back(now);
    for (int i = 0; i < connections.size(); i++) {
        if (connections[i][0] == now && !(std::find(beenAt.begin(), beenAt.end(), connections[i][1]) != beenAt.end())) {
            whatsNext(routes, connections, distances, beenAt, connections[i][1], dist + distances[i]);
        }
        else if (connections[i][1] == now && !(std::find(beenAt.begin(), beenAt.end(), connections[i][0]) != beenAt.end())) {
            whatsNext(routes, connections, distances, beenAt, connections[i][0], dist + distances[i]);
        }
    }

    if (beenAt.size() > 1) {
        bool New = true;
        for (int i = 0; i < routes.size(); i++) {
            if (routes[i].first == beenAt[0] && routes[i].last == beenAt[beenAt.size() - 1]) {
                if (routes[i].distance > dist) {
                    routes[i].between.clear();
                    for (int j = 1; j < beenAt.size() - 1; j++) {
                        routes[i].between.push_back(beenAt[j]);
                    }
                    routes[i].distance = dist;
                }
                New = false;
                break;
            }
        }
        if (New) {
            route newRoute;
            newRoute.first = beenAt[0];
            newRoute.last = beenAt[beenAt.size() - 1];
            newRoute.distance = dist;
            for (int i = 1; i < beenAt.size() - 1; i++) {
                newRoute.between.push_back(beenAt[i]);
            }
            routes.push_back(newRoute);
        }
    }
}

void inst() {
    std::cout << "Nalezy podac 2 parametry:" << std::endl;
    std::cout << "\t1. nazwa pliku z polaczeniami miast (np \"input.txt\"), format pliku:" << std::endl;
    std::cout << "\t\t[miasto 1-1] [miasto 1-2] [odleglosc 1]" << std::endl;
    std::cout << "\t\t[miasto 2-1] [miasto 2-2] [odleglosc 2]" << std::endl;
    std::cout << "\t2. miasto, od ktorego rozpoczniemy trase (np \"Koszalin\")" << std::endl;
    exit(0);
}

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3) inst();
    std::ifstream file(argv[1]);
    std::string startAt = argv[2];
    if (file) {
        std::vector<std::array<std::string, 2>> connections;
        std::vector<int> distances;
        std::vector<std::string> allTowns;
        std::string town1, town2;
        std::vector<route> routes;
        int dist;

        while (file >> town1 >> town2 >> dist) {
            connections.push_back({town1, town2});
            distances.push_back(dist);
        }

        whatsNext(routes, connections, distances, {}, startAt, 0);

        std::ofstream outputFile("output.txt");

        for (int i = 0; i < routes.size(); i++) {
            std::string between = "";
            for (int j = 0; j < routes[i].between.size(); j++) {
                between += routes[i].between[j] + " -> ";
            }
            std::string output = routes[i].first + " -> " + between + routes[i].last + ": " + std::to_string(routes[i].distance) + "km" + "\n";
            std::cout << output;
            outputFile << output;
        }

        for (int i = 0; i < connections.size(); i++) {
            bool townInAllTowns = (std::find(allTowns.begin(), allTowns.end(), connections[i][0]) != allTowns.end());
            for (int k = 0; k <= 1; k++) {
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
                        std::string output = "Nie znaleziono polaczenia: " + startAt + " -> " + connections[i][0] + "\n";
                        std::cout << output;
                        outputFile << output;
                    }
                }
            }
        }

        outputFile.close();
    }
    else {
        std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    }

    return 0;
}
