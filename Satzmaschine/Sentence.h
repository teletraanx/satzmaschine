#pragma once
#include "Pronoun.h"
#include "Noun.h"
#include "Verb.h"
#include "PersonNoun.h"
#include "Utility.h"
#include "Adjective.h"
#include "Adverb.h"
#include "NounStartingVerb.h"
#include "StartNoun.h"
#include <random>
using namespace std;

Pronoun getRandomPronoun(const vector<Pronoun>& pronouns);

vector<Noun> getValidNouns(const vector<Noun>& nouns, Verb& verb);

vector<StartNoun> getValidStartNouns(const vector<StartNoun>& nouns, NounStartingVerb& verb);
vector<StartNoun> getValidSecondStartNouns(const vector<StartNoun>& nouns, NounStartingVerb& verb);

vector<Adjective> getValidAdjectives(const vector<Adjective>& adjectives, StartNoun& noun);

Noun getRandomNoun(const vector<Noun>& nouns);

Verb getRandomVerb(const vector<Verb>& verbs);

PersonNoun getRandomPersonNoun(const vector<PersonNoun>& personnouns);

Adjective getRandomAdjective(const vector<Adjective>& adjectives);

Adverb getRandomAdverb(const vector<Adverb>& adverbs);

void genPronounLVerbPNoun(const Pronoun& pronoun, const Verb& verb, const PersonNoun& personNoun);
void genPronounLVerbAdjective(const Pronoun& pronoun, const Verb& verb, const Adjective& adjective);
void genNounLVerbAdjective(const StartNoun& noun, const NounStartingVerb& verb, const Adjective& adjective);
void genPronounVerbNoun(const Pronoun& pronoun, const Verb& verb, const Noun& noun);
void genNounVerbNoun(const StartNoun& startNoun, const NounStartingVerb& verb, const StartNoun& secondNoun);
void genPronounVerbAdverb(const Pronoun& pronoun, const Verb& verb, const Adverb& adverb);
void genNounVerbAdverb(const StartNoun& noun, const NounStartingVerb& verb, const Adverb& adverb);

void generatePronounSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs);
void generateNounSimpleSentence(const vector<StartNoun>& nouns, const vector<NounStartingVerb>& verbs, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs);