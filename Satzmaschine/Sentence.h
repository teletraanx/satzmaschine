#pragma once
#include "Pronoun.h"
#include "Noun.h"
#include "Verb.h"
#include <random>
using namespace std;

Pronoun getRandomPronoun(vector<Pronoun> pronouns);

vector<Noun> getValidNouns(vector<Noun> nouns, Verb verb);

Noun getRandomNoun(vector<Noun> nouns);

Verb getRandomVerb(vector<Verb> verbs);