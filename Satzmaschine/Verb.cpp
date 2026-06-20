#include "Verb.h"

// verbs.txt: infinitive,ichForm,duForm,thirdSingularForm,wirForm,ihrForm,sieForm
Verb::Verb(string infinitive,
    string ichForm,
    string duForm,
    string thirdSingularForm,
    string wirForm,
    string ihrForm,
    string sieForm) 
    : infinitive(infinitive),
      ichForm(ichForm),
      duForm(duForm),
      thirdSingularForm(thirdSingularForm),
      wirForm(wirForm),
      ihrForm(ihrForm),
      sieForm(sieForm)
    {}; // constructor 

string Verb::conjugate(const Subject& subject) const {
    if (subject.person == "first" && subject.number == "singular") {
        return ichForm;
    }

    if (subject.person == "first" && subject.number == "plural") {
        return wirForm;
    }

    if (subject.person == "second" && subject.number == "singular") {
        return duForm;
    }

    if (subject.person == "second" && subject.number == "plural") {
        return ihrForm;
    }

    if (subject.person == "third" && subject.number == "singular") {
        return thirdSingularForm;
    }

    if (subject.person == "third" && subject.number == "plural") {
        return sieForm;
    }

    return infinitive;
}