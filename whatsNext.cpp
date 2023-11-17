#include <iostream>
#include <vector>
#include <array>
#include "struct.h"

/// Funckja rekurencyjna, ktora szuka wszystkie najkrotsze mozliwe trasy do podanych miast z miasta centrali.
/// @param routes Gotowe, znalezione przez funkcje trasy.
/// @param links Vector polaczen miast i dystansow miedzy nimi.
/// @param beenAt Miasta, ktore funkcja juz sprawdzila w danym jej wykonaniu rekurencyjnym.
/// @param now Miasto, ktore funkcja aktualnie sprawdza.
/// @param distance Odleglosc od poprzednio sprawdzanego miasta, do sprawdzanego obecnie.
void whatsNext(
    std::vector<route>& routes,
    std::vector<link>& links,
    std::vector<std::string> beenAt,
    std::string now,
    int distance
) {
    beenAt.push_back(now);
    for (int i = 0; i < links.size(); i++) {
        for (int j = 0; j <= 1; j++) {
            if (links[i].cities[j] == now && !(std::find(beenAt.begin(), beenAt.end(), links[i].cities[j ? 0 : 1]) != beenAt.end())) {
                whatsNext(routes, links, beenAt, links[i].cities[(j ? 0 : 1)], distance + links[i].distance);
                break;
            }
        }
    }

    if (beenAt.size() < 2) return;
    bool New = true;
    for (int i = 0; i < routes.size(); i++) {
        if (routes[i].first == beenAt[0] && routes[i].last == beenAt[beenAt.size() - 1]) {
            if (routes[i].distance > distance) {
                beenAt.erase(beenAt.begin());
                beenAt.erase(beenAt.end() - 1);
                routes[i].between = beenAt;
                routes[i].distance = distance;
            }
            New = false;
            break;
        }
    }
    if (New) {
        std::string first = beenAt[0];
        beenAt.erase(beenAt.begin());
        beenAt.erase(beenAt.end() - 1);
        routes.push_back({ first, beenAt, now, distance });
    }
}