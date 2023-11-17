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
	std::vector<link>& links,
	std::vector<route>& routes,
	std::ofstream& outputFile
);
void whatsNext(
	std::vector<route>& routes,
	std::vector<link>& links,
	std::vector<std::string> beenAt,
	std::string now,
	int dist
);

#endif