#ifndef FUNCTIONS
#define FUNCTIONS

params readParams(
	int& argc,
	char* argv[]
);
void wrongParams();
void writeFoundOutput(
	std::vector<route>& routes,
	std::ofstream& outputFile
);
void writeNotFoundOutput(
	std::string& startAt,
	std::vector<std::array<std::string, 2>>& connections,
	std::vector<route>& routes,
	std::vector<std::string>& allTowns,
	std::ofstream& outputFile
);
void whatsNext(
	std::vector<route>& routes,
	std::vector<std::array<std::string, 2>>& connections,
	std::vector<int>& distances,
	std::vector<std::string> beenAt,
	std::string now,
	int dist
);

#endif