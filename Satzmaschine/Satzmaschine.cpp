#include <iostream>
#include <vector>
#include "Pronoun.h"
#include "Verb.h"
#include "Noun.h"
#include "Utility.h"
#include "Sentence.h"
#include "PersonNoun.h"
using namespace std;

int main()
{
    vector<Pronoun> pronouns = parsePronouns("pronouns.txt");
    vector<Verb> verbs = parseVerbs("lvl1verbs.txt");
    vector<Noun> nouns = parseNouns("lvl1nouns.txt");
    vector<PersonNoun> personnouns = parsePersonNouns("lvl1personnouns.txt");
    vector<Adjective> adjectives = parseAdjectives("lvl1adjectives.txt");
    vector<Adverb> adverbs = parseAdverbs("lvl1adverbs.txt");
    vector<StartNoun> startNouns = parseStartNouns("lvl1startnouns.txt");
    vector<NounStartingVerb> nounStartingVerbs = parseNounStartingVerbs("lvl1nounstartingverbs.txt");

    if (pronouns.empty() || verbs.empty() || nouns.empty() || personnouns.empty() || adjectives.empty() || adverbs.empty()) {
        cout << "Failed to load words." << endl;
        return 1;
    }

    string answer;
    cout << "Press Enter for another sentence or q to quit: " << endl;
    cout << "Say the sentence: " << endl;
    do {
        switch (coinFlip()) {
        case 0:
            cout << generatePronounSimpleSentence(pronouns, verbs, personnouns, nouns, adjectives, adverbs) << endl;
            break;
        case 1:
            cout << generateNounSimpleSentence(startNouns, nounStartingVerbs, adjectives, adverbs) << endl;
            break;
        }
        getline(cin, answer);
    }
    while (answer != "q");
}


