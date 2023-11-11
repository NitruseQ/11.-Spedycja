#include <iostream>
#include <vector>
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
	for (int i = 1; i < argc - 1; i++) {
		if (!strcmp(argv[i], "-s") && strcmp(argv[i+1], "-c")) {
			param.source = argv[i+1];
			break;
		}
		if (i + 1 == argc - 1) wrongParams();
	}

	for (int i = 1; i < argc - 1; i++) {
		if (!strcmp(argv[i], "-c") && strcmp(argv[i + 1], "-s")) {
			param.startAt = argv[i+1];
			break;
		}
		if (i + 1 == argc - 1) wrongParams();
	}

	return param;
}