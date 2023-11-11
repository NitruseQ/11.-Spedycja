#include <iostream>
#include <vector>
#include <array>
#include "struct.h"

/// Funckja rekurencyjna, ktora szuka wszystkie najkrotsze mozliwe trasy do podanych miast z miasta centrali.
/// @param routes Gotowe, znalezione przez funkcje trasy.
/// @param connections Vector wszystkich polaczen miedzy miastami.
/// @param distances Vector wszystkich odleglosci miedzy miastami.
/// @param beenAt Miasta, ktore funkcja juz sprawdzila w danym jej wykonaniu rekurencyjnym.
/// @param now Miasto, ktore funkcja aktualnie sprawdza.
/// @param dist Odleglosc od poprzednio sprawdzanego miasta, do sprawdzanego obecnie.
void whatsNext(
    std::vector<route>& routes,
    std::vector<std::array<std::string, 2>>& connections,
    std::vector<int>& distances,
    std::vector<std::string> beenAt,
    std::string now,
    int dist
) {
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