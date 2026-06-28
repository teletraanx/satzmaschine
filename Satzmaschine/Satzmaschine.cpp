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
    vector<Verb> verbs = parseVerbs("verbs.txt");
    vector<Noun> nouns = parseNouns("nouns.txt");
    vector<PersonNoun> personnouns = parsePersonNouns("personnouns.txt");
    vector<Adjective> adjectives = parseAdjectives("adjectives.txt");
    vector<Adverb> adverbs = parseAdverbs("adverbs.txt");

    if (pronouns.empty() || verbs.empty() || nouns.empty() || personnouns.empty() || adjectives.empty() || adverbs.empty()) {
        cout << "Failed to load words." << endl;
        return 1;
    }

    string answer;
    cout << "Press Enter for another sentence or q to quit: " << endl;
    cout << "Say the sentence: " << endl;
    do {
        // generatePronounSimpleSentence(pronouns, verbs, personnouns, nouns, adjectives, adverbs);
        generateNounSimpleSentence(pronouns, verbs, personnouns, nouns, adjectives, adverbs);
        getline(cin, answer);
    }
    while (answer != "q");
}


