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
    // Load Subjects: vector of Subject(string text, string person, string number) objects
    //  subjects.txt: 
    //  ich,first,singular
    //  er,third,singular
    //  ...
    vector<Pronoun> pronouns;
    ifstream pronounsFile("pronouns.txt"); // open file in read mode
    string pronounLine;

    while (getline(pronounsFile, pronounLine)) { // until EOF
        stringstream ss(pronounLine); // treat string like an input string
        string word;
        string person;
        string number;

        getline(ss, word, ','); // from string stream parse field 1, store in word, deliminated by ','
        getline(ss, person, ',');
        getline(ss, number, ',');

        pronouns.emplace_back(word, person, number); // construct Subject(word, person, number) and append new element to end of vector
    }
    pronounsFile.close();
    // cout << "Successfully loaded list of subjects." << endl;

    // Load Verbs: vector of Verb(string stem, string infinitive) objects
    //  verbs.txt: infinitive,ichForm,duForm,thirdSingularForm,wirForm,ihrForm,sieForm
    vector<Verb> verbs;
    ifstream verbsFile("verbs.txt");
    string verbLine;

    while (getline(verbsFile, verbLine)) {
        stringstream ss(verbLine);
        string infinitive;
        string ichForm;
        string duForm;
        string thirdSingularForm;
        string wirForm;
        string ihrForm;
        string sieForm;
        string tagText;

        getline(ss, infinitive, ',');
        getline(ss, ichForm, ',');
        getline(ss, duForm, ',');
        getline(ss, thirdSingularForm, ',');
        getline(ss, wirForm, ',');
        getline(ss, ihrForm, ',');
        getline(ss, sieForm, ',');
        getline(ss, tagText, ',');

        verbs.emplace_back(infinitive, ichForm, duForm, thirdSingularForm, wirForm, ihrForm, sieForm, splitTags(tagText));
    }
    verbsFile.close();
    // cout << "Successfully loaded list of verbs." << endl;

    // Load objects(the,word,tags)
    vector<Noun> nouns;
    ifstream nounsFile("nouns.txt");
    string nounsLine;

    while (getline(nounsFile, nounsLine)) {
        stringstream ss(nounsLine);
        string gender;
        string word;
        string objTagText;

        getline(ss, gender, ',');
        getline(ss, word, ',');
        getline(ss, objTagText, ',');

        nouns.emplace_back(gender, word, splitTags(objTagText));
    }
    nounsFile.close();

    // Load PersonNouns
    vector<PersonNoun> personnouns;
    ifstream personnounsFile("personnouns.txt");
    string personnounsLine;

    while (getline(personnounsFile, personnounsLine)) {
        stringstream ss(personnounsLine);
        string masculine;
        string feminine;
        string personnounTagText;

        getline(ss, masculine, ',');
        getline(ss, feminine, ',');
        getline(ss, personnounTagText, ',');

        personnouns.emplace_back(masculine, feminine, splitTags(personnounTagText));
    }
    personnounsFile.close();

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


