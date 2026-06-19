#pragma once
#include <iostream>
#include "Subject.h"
using namespace std;

class Verb {
private:
    string stem;
    string infinitive;
public:
    Verb(string s, string i); // constructor 

    string conjugate(const Subject& subject) const;
};