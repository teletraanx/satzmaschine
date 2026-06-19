#include "Verb.h"

Verb::Verb(string s, string i) : stem(s), infinitive(i) {}; // constructor 

string Verb::conjugate(const Subject& subject) const {
    if (subject.person == "first" && subject.number == "singular") {
        return stem + "e";
    }

    if (subject.person == "third" && subject.number == "singular") {
        return stem + "t";
    }

    return infinitive;
}