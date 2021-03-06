/* a7a.cpp
 *
 * Aleck Zhao
 * 7 November, 2016
 * 
 * Driver for reading input and generating bigrams.
 */

#include <iostream>
#include <algorithm>

#include <string>
#include <map>
#include <list>
#include <vector>

using std::cerr;
using std::cout;
using std::cin;
using std::string;
using std::map;
using std::list;
using std::pair;
using std::vector;
using std::sort;

list<string> readIntoList();
map<string, int> readIntoMap(list<string> words);
vector<pair<string, int>> readIntoVector(map<string, int> bigram);

bool alphabetical(pair<string, int> s1, pair<string, int> s2);
bool reverseAlphabet(pair<string, int> s1, pair<string, int> s2);
bool countComp(pair<string, int> s1, pair<string, int> s2);

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cerr << "Must specify valid arguments.\n";
		return 1;
	}

	string option = argv[1];

	list<string> words = readIntoList();
	if (words.size() == 0) {
		// empty list

		cerr << "Word list was empty.\n";
		return 1;
	}

	map<string, int> bigram = readIntoMap(words);
	vector<pair<string, int>> vec = readIntoVector(bigram);

	if (option.compare("a") == 0) {
		// forward alphabetical

		sort(vec.begin(), vec.end(), alphabetical);
		
	} else if (option.compare("r") == 0) {
		// reverse alphabetical
		
		sort(vec.begin(), vec.end(), reverseAlphabet);
	
	} else if (option.compare("c") == 0) {
		// count

		sort(vec.begin(), vec.end(), countComp);
	} else {
		// doesn't match
		cerr << "Sort option does not match.\n";
		return 1;
	}		

	// prints out bigram after sorting
	for (pair<string, int> e : vec) {
		cout << e.first << " " << e.second << "\n";
	}

	return 0;

}

// reads text from cin into an ordered list
list<string> readIntoList() {
	list<string> words;

	string temp;

	while (cin >> temp && !cin.eof()) {
		words.push_back(temp);
	}

	return words;
}

// reads text from an ordered list, creates bigram
map<string, int> readIntoMap(list<string> words) {

	map<string, int> bigram;

	list<string>::const_iterator iter = words.begin();

	// first word
	bigram["<START> " + *iter] = 1;

	string temp1, temp2;
	string key;

	// until last pair<string, int> of words in file
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


// reads key-value pairs from map into vector
vector<pair<string, int>> readIntoVector(map<string, int> bigram) {
	
	vector<pair<string, int>> vec;

	for (pair<string, int> element : bigram) {
		vec.push_back(element);
	}

	return vec;

}

// alphabetical comparator
bool alphabetical(pair<string, int> s1, pair<string, int> s2) {
	return s1 < s2;
}

// reverse alphabetical comparator
bool reverseAlphabet(pair<string, int> s1, pair<string, int> s2) {
	return s2 < s1;
}

// comparator by count
bool countComp(pair<string, int> s1, pair<string, int> s2) {
	if ((s1.second) < (s2.second)) {
		return true;
	} else if ((s1.second) == (s2.second)) {
		// if equal counts, sort alphabetically
		return alphabetical(s1, s2);
	} else {
		return false;
	}
}
