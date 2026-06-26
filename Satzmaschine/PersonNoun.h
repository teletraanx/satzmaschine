#pragma once
#include <iostream>
#include <vector>
using namespace std;

class PersonNoun {
public:
	string masculine;
	string feminine;
	vector<string> tags;

	PersonNoun(string m, string f, vector<string> t);
};