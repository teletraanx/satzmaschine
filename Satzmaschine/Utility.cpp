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