#ifndef ROUTE
#define ROUTE

/// Przechowuje trasy do poszczegolnych miast.
/// @param first Pierwsze miasto trasy.
/// @param between Miasta miedzy pierwszym, a ostatnim.
/// @param last Ostatnie miasto.
/// @param int Dystans pomiedzy miastami.
struct route {
    std::string first;
    std::vector<std::string> between;
    std::string last;
    int distance;
};

/// Przechowuje polaczenia miast i dystanse miedzy nimi.
/// @param cities Dwuelementowy array z nazwami polaczonych miast.
/// @param distance Dystans polaczenia.
struct link {
    std::array<std::string, 2> cities;
    int distance;
};

#endif