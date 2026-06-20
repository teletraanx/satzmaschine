#pragma once
#include <string>
#include <vector>
using namespace std;

class Object {
public:
	string the;
	string object;
	vector<string> tags;

	// constructor
	Object(string the, string object, vector<string> tags);
};