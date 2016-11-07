/* a7b.cpp
 *
 * Aleck Zhao
 * 5 November, 2016
 *
 * Driver for generating random sentences from model.
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::pair;
using std::sort;

vector<pair<string, int>> readIntoVector();
string randomWord(vector<pair<string, int>> words, string last);
string randomSentence(vector<pair<string, int>> words);

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cerr << "Must specify valid arguments.\n";
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

	// random seed with system time
	srand(time(NULL));

	vector<pair<string, int>> words = readIntoVector();

	// generates random sentences
	for (int i = 0; i < reps; i++) {
		cout << randomSentence(words) << "\n";
	}

	return 0;

}

// reads a properly formatted bigram model into a vector
vector<pair<string, int>> readIntoVector() {

	vector<pair<string, int>> vec;

	string temp1, temp2;
	int temp3;

	// assumes bigram is properly formatted
	while (cin >> temp1 >> temp2 >> temp3 && !cin.eof()) {
		string combine = temp1 + " " + temp2;

		pair<string, int> p(combine, temp3);
		vec.push_back(p);
	}

	sort(vec.begin(), vec.end());
	return vec;

}

// generates a random sentence
string randomSentence(vector<pair<string, int>> words) {

	// words is sorted, so <START> is at beginning
	string sentence = words.at(0).first;

	string context = sentence.substr(sentence.find(' ') + 1, sentence.length());

	// while we haven't reached the end yet	
	while (context.compare("<END>") != 0) {
		// set new context
		context = randomWord(words, context);

		// concatenate with sentence
		sentence += " " + context;
	}

	return sentence;

}

// generates a random word based on bigram and context
string randomWord(vector<pair<string, int>> words, string last) {

	vector<pair<string, int>>::const_iterator iter = words.begin();

	// vector of key-value pairs that start with the last string generated
	vector<pair<string, int>> sample;

	size_t len = last.length();

	while (iter != words.end()) {

		string key = (*iter).first;

		if (len <= key.length() && key.substr(0, len) == last && key.at(len) == ' ') {	
			// current entry starts with last string generated

			sample.push_back(*iter);
		}

		iter++;
	}

	// calculates total number of occurrences
	int total = 0;
	for (size_t i = 0; i < sample.size(); i++) {

		total += sample.at(i).second;
	}

	// generate a random number from 1 to total inclusive
	int random = rand() % total + 1 ;

	string ret;

	int sum = 0;
	for (size_t i = 0; i < sample.size(); i++) {

		// increment by current count
		sum += sample.at(i).second;

		if (sum >= random) {
			// if sum is greater than count, we are done, use this word
	
			string combined = sample.at(i).first;

			// gets the second part of the string
			ret = combined.substr(combined.find(' ') + 1, combined.length());

			break;

		}		

	}

	return ret;

}
