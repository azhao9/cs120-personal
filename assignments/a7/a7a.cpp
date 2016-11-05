#include <iostream>
#include <fstream>

#include <string>
#include <map>
#include <list>

using std::cerr;
using std::cout;
using std::cin;
using std::string;
using std::map;
using std::list;

list<string> readIntoList();

map<string, int> read(list<string> words);

int main(int argc, char* argv[]) {

	if (argc == 1) {
		cerr << "Need to specify ordering.\n";
		return 1;
	}

	string option = argv[1];

	list<string> words = readIntoList();
	map<string, int> bigram = read(words);

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

	for (auto elem : bigram) {
		cout << elem.first << " " << elem.second << "\n";
	}

	return 0;


}

// reads text from cin into an ordered list
list<string> readIntoList() {
	list<string> words;

	string temp;

	while(cin >> temp && !cin.eof()) {
		words.push_back(temp);
	}

	return words;
}

// reads text from an ordered list, creates bigram
map<string, int> read(list<string> words) {

	map<string, int> bigram;

	list<string>::const_iterator iter = words.begin();

	// first word
	bigram["<START> " + *iter] = 1;

	string temp1, temp2;
	string key;

	// until last pair of words in file
	while (std::next(iter, 1) != words.end()) {
		temp1 = *iter;		
		temp2 = *(++iter);

		key = temp1 + " " + temp2;

		if (bigram.find(key) == bigram.end()) {
			// key not currently in map
			bigram[key] = 1;
		} else {
			// key already in map, increment number of times it appears
			bigram.at(key)++;
		}
	}

	// last word
	bigram[*iter + " <END>"] = 1;

	return bigram;

}


