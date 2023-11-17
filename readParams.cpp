#include <iostream>
#include <vector>
#include <array>
#include "struct.h"
#include "functions.h"

/// Czyta parametry podane przez uzytkownika.
/// @param argc Ilosc parametrow.
/// @param argv Tablica parametrow.
/// @return Zwraca zrodlo podanego pliku oraz miasto centrali (first = source, second = center).
std::pair<std::string, std::string> readParams(
	int& argc,
	char *argv[]
) {
	std::pair<std::string, std::string> param;
	bool center = false, source = false;

	for (int i = 1; i < argc - 1 && !(source && center); i++) {
		if (!strcmp(argv[i], "-s")) {
			param.first = argv[i + 1];
			source = true;
		} else if (!strcmp(argv[i], "-c")) {
			param.second = argv[i + 1];
			center = true;
		}
	}

	return param;
}