#include <iostream>
#include <fstream> // for files
#include <sstream> // for files
#include <vector>
#include "Subject.h"
#include "Verb.h"
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
    cout << "Successfully loaded list of subjects." << endl;

    // Load Verbs: vector of Verb(string stem, string infinitive) objects
    //  verbs.txt:
    //  geh,gehen
    vector<Verb> verbs;
    ifstream verbsFile("verbs.txt");
    string verbLine;

    while (getline(verbsFile, verbLine)) {
        stringstream ss(verbLine);
        string stem;
        string infinitive;

        getline(ss, stem, ',');
        getline(ss, infinitive, ',');

        verbs.emplace_back(stem, infinitive);
    }
    verbsFile.close();
    cout << "Successfully loaded list of verbs." << endl;

    // Generate a random sentence
    //  Choose random Subject
    //  Choose random Verb
    //  Print Subject and correct verb conjugate
    cout << "Hello World!\n";
}


