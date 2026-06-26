#include <iostream>
#include <fstream> // for files
#include <sstream> // for files
#include <vector>
#include <random>
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

    if (pronouns.empty() || verbs.empty() || nouns.empty() || personnouns.empty()) {
        cout << "Failed to load words." << endl;
        return 1;
    }

    string answer;
    do {
        // Generate a random sentence
        //  Choose random Subject
        //  Choose random Verb
        //  Print Subject and correct verb conjugate
        Pronoun pronoun = getRandomPronoun(pronouns);
        Verb verb = getRandomVerb(verbs);

           // if verb is linking, use adjectives or PersonNouns
        if (verb.hasTag("linking")) {
            //
            PersonNoun personNoun = getRandomPersonNoun(personnouns);
            cout << "Say the sentence:" << endl;

            if (pronoun.number == "plural") {
                cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.plural << "." << endl;
            }
            else if (pronoun.word == "sie") { // she/her
                cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.feminine << "." << endl;
            }
            else
                cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.masculine << "." << endl;

        }
        else {
            vector<Noun> validNouns = getValidNouns(nouns, verb);
            if (validNouns.empty()) {
                cout << "No valid nouns found for this verb: " << verb.conjugate(pronoun) << endl;
            }
            else {
                Noun noun = getRandomNoun(validNouns);

                cout << "Say the sentence:" << endl;
                cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << noun.noun << "." << endl;

            }
        }
        cout << "Press Enter for another sentence or q to quit: ";
        getline(cin, answer);
    }
    while (answer != "q");
}


