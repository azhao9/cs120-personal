#include <iostream>
#include <fstream>

#include <string>
#include <map>

using std::cerr;
using std::cout;
using std::string;
using std::map;

map<string, int> read(string filename);

int main(int argc, char* argv[]) {

	if (argc == 1) {
		cerr << "Need to specify ordering.\n";
		return 1;
	}

	string option = argv[1];
	string filename = argv[2];

	read(filename);

	if (option.compare("a") == 0) {
		// forward alphabetical
		
	} else if (option.compare("r") == 0) {
		// reverse alphabetical
	
	} else if (option.compare("c") == 0) {
		// count

	} else {
		// doesn't match
		cerr << "Sort option does not match.\n";
		return 1;
	}
			

	return 0;


}

// reads text from a file, creates bigram map
map<string, int> read(string filename) {

	map<string, int> bigram;

	std::fstream file;
	file.open(filename);

	string temp;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> temp;
			cout << temp;
		}
	}

	file.close();

	return bigram;

}


