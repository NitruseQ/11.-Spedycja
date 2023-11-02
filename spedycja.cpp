#include <iostream>
#include <fstream>
#include <vector>
#include <array>

struct route {
    std::string first;
    std::vector<std::string> between;
    std::string last;
    int distance;
};

void whatsNext(std::vector<route> & routes, std::vector<std::array<std::string, 2>> connections, std::vector<int> distances, std::vector<std::string> beenAt, std::string now, int dist) {
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

int main()
{
    std::ifstream file("example.txt");
    std::string startAt = "Koszalin";
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

        for (int i = 0; i < connections.size(); i++) {
            if (connections[i][0] != startAt && !(std::find(allTowns.begin(), allTowns.end(), connections[i][0]) != allTowns.end())) {
                allTowns.push_back(connections[i][0]);
            }
            if (connections[i][1] != startAt && !(std::find(allTowns.begin(), allTowns.end(), connections[i][1]) != allTowns.end())) {
                allTowns.push_back(connections[i][1]);
            }
        }

        std::vector<std::string> beenAt = {};
        whatsNext(routes, connections, distances, {}, startAt, 0);

        for (int i = 0; i < routes.size(); i++) {
            std::string between = "";
            for (int j = 0; j < routes[i].between.size(); j++) {
                between += routes[i].between[j] + " -> ";
            }
            std::cout << routes[i].first << " -> " << between << routes[i].last << ": " << routes[i].distance << std::endl;
        }
    }
    else {
        std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    }

    return 0;
}
