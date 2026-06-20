#pragma once
#include <iostream>
#include <vector>
#include "Subject.h"
#include "Object.h"
using namespace std;

class Verb {
// verbs.txt: infinitive,ichForm,duForm,thirdSingularForm,wirForm,ihrForm,sieForm
private:
    string infinitive;
    string ichForm;
    string duForm;
    string thirdSingularForm;
    string wirForm;
    string ihrForm;
    string sieForm;
    vector<string> objectTags;
public:
    // constructor
    Verb(string infinitive, 
        string ichForm,
        string duForm,
        string thirdSingularForm,
        string wirForm,
        string ihrForm,
        string sieForm,
        vector<string> objectTags
    );

    string conjugate(const Subject& subject) const;
    
    bool acceptsObject(const Object& object) const;
};