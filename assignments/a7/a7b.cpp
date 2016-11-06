/* a7b.cpp
 *
 * Aleck Zhao
 * 5 November, 2016
 *
 * Driver for generating random sentences from model.
 */

#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::pair;

vector<pair<string, int>> readIntoVector();

int main(int argc, char* argv[]) {

	if (argc == 1) {
		cerr << "Need to specify number of lines.\n";
		return 1;
	}

	string num = argv[1];
	int reps;

	try {
		reps = std::stoi(num);
	} catch (std::invalid_argument) {
		cerr << "Invalid number of lines.\n";
		return 1;
	}

	vector<pair<string, int>> vec = readIntoVector();

	for (auto v : vec) {
		cout << v.first << " " << v.second << "\n";
	}

	return 0;

}

// reads a properly formatted bigram model into a vector
vector<pair<string, int>> readIntoVector() {

	vector<pair<string, int>> vec;

	string temp1, temp2;
	int temp3;

	while (cin >> temp1 >> temp2 >> temp3 && !cin.eof()) {
		string combine = temp1 + " " + temp2;

		pair<string, int> p(combine, temp3);
		vec.push_back(p);
	}

	return vec;

}
