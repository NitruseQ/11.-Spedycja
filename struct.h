#ifndef ROUTE
#define ROUTE

/// Przechowuje trasy do poszczegolnych miast.
/// @param first Pierwsze miasto trasy.
/// @param between Miasta miedzy pierwszym, a ostatnim.
/// @param last Ostatnie miasto.
struct route {
    std::string first;
    std::vector<std::string> between;
    std::string last;
    int distance;
};

/// Przechowuje parametry uzytkownika.
/// @param source Zrodlo pliku.
/// @param startAt Miasto centrali.
struct params {
    std::string source;
    std::string startAt;
};

#endif