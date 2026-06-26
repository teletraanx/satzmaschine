#pragma once
#include "Pronoun.h"
#include "Noun.h"
#include "Verb.h"
#include "PersonNoun.h"
#include "Utility.h"
#include <random>
using namespace std;

Pronoun getRandomPronoun(const vector<Pronoun>& pronouns);

vector<Noun> getValidNouns(const vector<Noun>& nouns, Verb& verb);

Noun getRandomNoun(const vector<Noun>& nouns);

Verb getRandomVerb(const vector<Verb>& verbs);

PersonNoun getRandomPersonNoun(const vector<PersonNoun>& personnouns);

void generateSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns);