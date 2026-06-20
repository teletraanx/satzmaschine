#pragma once
#include <iostream>
#include "Subject.h"
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
public:
    // constructor
    Verb(string infinitive, 
        string ichForm,
        string duForm,
        string thirdSingularForm,
        string wirForm,
        string ihrForm,
        string sieForm
    );

    string conjugate(const Subject& subject) const;
};