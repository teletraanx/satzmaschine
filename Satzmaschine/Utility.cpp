#include "Utility.h"

vector<string> splitTags(const string& text) {
	vector<string> tags;
	stringstream ss(text);
	string tag;

	while (getline(ss, tag, '|')) {
		tags.push_back(tag);
	}
	return tags;
}

string capitalizeFirst(const string& text) {
	string capitalizeFirst = text;
	capitalizeFirst[0] = toupper(capitalizeFirst[0]);
	return capitalizeFirst;
}

vector<Pronoun> parsePronouns(string fileName) {
	vector<Pronoun> words;
	ifstream file(fileName);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string word;
		string person;
		string number;

		getline(ss, word, ','); // from string stream parse field 1, store in word, deliminated by ','
		getline(ss, person, ',');
		getline(ss, number, ',');

		words.emplace_back(word, person, number);
	}
	file.close();
	return words;
}

vector<Verb> parseVerbs(string fileName) {
	vector<Verb> words;
	ifstream file(fileName);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string infinitive;
		string ichForm;
		string duForm;
		string thirdSingularForm;
		string wirForm;
		string ihrForm;
		string sieForm;
		string tagText;

		getline(ss, infinitive, ',');
		getline(ss, ichForm, ',');
		getline(ss, duForm, ',');
		getline(ss, thirdSingularForm, ',');
		getline(ss, wirForm, ',');
		getline(ss, ihrForm, ',');
		getline(ss, sieForm, ',');
		getline(ss, tagText, ',');

		words.emplace_back(infinitive, ichForm, duForm, thirdSingularForm, wirForm, ihrForm, sieForm, splitTags(tagText));
	}
	file.close();
	return words;
}

vector<Noun> parseNouns(string fileName) {
	vector<Noun> words;
	ifstream file(fileName);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string gender;
		string word;
		string objTagText;

		getline(ss, gender, ',');
		getline(ss, word, ',');
		getline(ss, objTagText, ',');

		words.emplace_back(gender, word, splitTags(objTagText));
	}
	file.close();
	return words;
}

vector<PersonNoun> parsePersonNouns(string fileName) {
	vector<PersonNoun> words;
	ifstream file(fileName);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string masculine;
		string feminine;
		string plural;
		string personnounTagText;

		getline(ss, masculine, ',');
		getline(ss, feminine, ',');
		getline(ss, plural, ',');
		getline(ss, personnounTagText, ',');

		words.emplace_back(masculine, feminine, plural, splitTags(personnounTagText));
	}
	file.close();
	return words;
}