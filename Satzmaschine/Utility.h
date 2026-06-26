#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream> // for files
#include <sstream> // for files
#include "Pronoun.h"
#include "Verb.h"
#include "Noun.h"
#include "PersonNoun.h"
using namespace std;

vector<string> splitTags(const string& text);

string capitalizeFirst(const string& text);

vector<Pronoun> parsePronouns(string fileName);

vector<Verb> parseVerbs(string fileName);

vector<Noun> parseNouns(string fileName);

vector<PersonNoun> parsePersonNouns(string fileName);