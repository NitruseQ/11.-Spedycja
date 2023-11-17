#include <iostream>
#include <vector>
#include <array>
#include "struct.h"
#include "functions.h"

/// Czyta parametry podane przez uzytkownika.
/// @param argc Ilosc parametrow.
/// @param argv Tablica parametrow.
/// @return Zwraca zrodlo podanego pliku oraz miasto centrali.
params readParams(
	int& argc,
	char *argv[]
) {
	params param;
	bool startAt = false, source = false;

	for (int i = 1; i < argc - 1 && !(source && startAt); i++) {
		if (!strcmp(argv[i], "-c")) {
			param.startAt = argv[i + 1];
			startAt = true;
		} 
		if (!strcmp(argv[i], "-s")) {
			param.source = argv[i + 1];
			source = true;
		}
	}

	return param;
}