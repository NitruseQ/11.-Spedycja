#include <iostream>

/// Wyswietla instrukcje wprowadzania parametrow do programu. Program jest wylaczany po jej wykonaniu.
void wrongParams() {
    std::cout << "Nalezy podac 2 parametry:" << std::endl;
    std::cout << "\t\"-s\": zrodlo pliku z polaczeniami miast (np: -s input.txt), format pliku:" << std::endl;
    std::cout << "\t\t[miasto 1-1] [miasto 1-2] [odleglosc 1]" << std::endl;
    std::cout << "\t\t[miasto 2-1] [miasto 2-2] [odleglosc 2]" << std::endl;
    std::cout << "\t\"-c\": miasto, w ktorym ma znajdowac sie centrala (np: -c Koszalin)" << std::endl;
    exit(0);
}