#include <iostream>
#include <fstream> // for files
#include <sstream> // for files
#include <vector>
#include <random>
#include "Subject.h"
#include "Verb.h"
#include "Noun.h"
#include "Utility.h"
using namespace std;

int main()
{
    // Load Subjects: vector of Subject(string text, string person, string number) objects
    //  subjects.txt: 
    //  ich,first,singular
    //  er,third,singular
    //  ...
    vector<Subject> subjects;
    ifstream subjectsFile("subjects.txt"); // open file in read mode
    string subjectLine;

    while (getline(subjectsFile, subjectLine)) { // until EOF
        stringstream ss(subjectLine); // treat string like an input string
        string word;
        string person;
        string number;

        getline(ss, word, ','); // from string stream parse field 1, store in word, deliminated by ','
        getline(ss, person, ',');
        getline(ss, number, ',');

        subjects.emplace_back(word, person, number); // construct Subject(word, person, number) and append new element to end of vector
    }
    subjectsFile.close();
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

    if (subjects.empty() || verbs.empty() || nouns.empty()) {
        cout << "Failed to load words." << endl;
        return 1;
    }

    string answer;
    do {
        // Generate a random sentence
        //  Choose random Subject
        //  Choose random Verb
        //  Print Subject and correct verb conjugate
        random_device rd; // get randomness from system
        mt19937 gen(rd()); // random number generator 

        uniform_int_distribution<> subjectDist(0, subjects.size() - 1); // ability to give random ints between 0 and size of vector-1 with equal probability
        uniform_int_distribution<> verbDist(0, verbs.size() - 1);

        Subject subject = subjects[subjectDist(gen)]; // generate random number
        Verb verb = verbs[verbDist(gen)];

        // find valid object
        vector<Noun> validNouns;
        for (const Noun& noun : nouns) {
            if (verb.acceptsNoun(noun)) {
                validNouns.push_back(noun);
            }
        }
        if (!validNouns.empty()) {
            uniform_int_distribution<> objDist(0, validNouns.size() - 1);
            Noun noun = validNouns[objDist(gen)];

            cout << "Say the sentence:" << endl;
            cout << capitalizeFirst(subject.word) << " " << verb.conjugate(subject) << " " << noun.noun << "." << endl;

            cout << "Press Enter for another sentence or q to quit: ";
        }
        else {
            cout << "Say the sentence:" << endl;
            cout << capitalizeFirst(subject.word) << " " << verb.conjugate(subject) << "." << endl;

            cout << "Press Enter for another sentence or q to quit: ";
        }

        getline(cin, answer);
    }
    while (answer != "q");
}


