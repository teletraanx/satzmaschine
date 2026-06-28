#include "Sentence.h"

Pronoun getRandomPronoun(const vector<Pronoun>& pronouns) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, pronouns.size() - 1);
	return pronouns[dist(gen)];
}

// Valid noun depends on verb's tags
vector<Noun> getValidNouns(const vector<Noun>& nouns, Verb& verb) {
	vector<Noun> validNouns;
	for (const Noun& noun : nouns) {
		if (verb.acceptsNoun(noun)) {
			validNouns.push_back(noun);
		}
	}
	return validNouns;
}

vector<StartNoun> getValidStartNouns(const vector<StartNoun>& nouns, NounStartingVerb& verb) {
	vector<StartNoun> validStartNouns;
	for (const StartNoun& noun : nouns) {
		if (verb.acceptsStartNoun(noun)) {
			validStartNouns.push_back(noun);
		}
	}
	return validStartNouns;
}

vector<StartNoun> getValidSecondStartNouns(const vector<StartNoun>& nouns, NounStartingVerb& verb) {
	vector<StartNoun> validStartNouns;
	for (const StartNoun& noun : nouns) {
		if (verb.acceptsSecondStartNoun(noun)) {
			validStartNouns.push_back(noun);
		}
	}
	return validStartNouns;
}

// Valid adjective depends on startNoun's second tags
vector<Adjective> getValidAdjectives(const vector<Adjective>& adjectives, StartNoun& noun) {
	vector<Adjective> validAdjectives;
	for (const Adjective& adjective : adjectives) {
		if (noun.acceptsAdjective(adjective)) {
			validAdjectives.push_back(adjective);
		}
	}
	return validAdjectives;
}

Noun getRandomNoun(const vector<Noun>& nouns) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, nouns.size() - 1);
	return nouns[dist(gen)];
}

Verb getRandomVerb(const vector<Verb>& verbs) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, verbs.size() - 1);
	return verbs[dist(gen)];
}

PersonNoun getRandomPersonNoun(const vector<PersonNoun>& personNouns) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, personNouns.size() - 1);
	return personNouns[dist(gen)];
}

Adjective getRandomAdjective(const vector<Adjective>& adjectives) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, adjectives.size() - 1);
	return adjectives[dist(gen)];
}

Adverb getRandomAdverb(const vector<Adverb>& adverbs) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, adverbs.size() - 1);
	return adverbs[dist(gen)];
}

StartNoun getRandomStartNoun(const vector<StartNoun>& startNouns) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, startNouns.size() - 1);
	return startNouns[dist(gen)];
}

NounStartingVerb getRandomNounStartingVerb(const vector<NounStartingVerb> verbs) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> dist(0, verbs.size() - 1);
	return verbs[dist(gen)];
}

// A Simple Sentence can be:
// 0: Noun + Verb + Noun
// 1: Noun + Verb + Adverb
// 2: Pronoun + Verb + Noun
// 3: Pronoun + Verb + Adverb
// 4: Pronoun + Linking Verb + Adjective
// 5: Pronoun + Linking Verb + PersonNoun
// 6: Noun + Linking Verb + Adjective

// 5: Pronoun + Linking Verb + PersonNoun
void genPronounLVerbPNoun(const Pronoun& pronoun, const Verb& verb, const PersonNoun& personNoun) {
	cout << "Pronoun + Linking Verb + PersonNoun" << endl; // DEBUG
	if (pronoun.number == "plural") {
		cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.plural << "." << endl;
	}
	else if (pronoun.word == "sie") { // she/her
		cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.feminine << "." << endl;
	}
	else
		cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.masculine << "." << endl;
}

// 4: Pronoun + Linking Verb + Adjective
void genPronounLVerbAdjective(const Pronoun& pronoun, const Verb& verb, const Adjective& adjective) {
	cout << "Pronoun + Linking Verb + Adjective" << endl; // DEBUG 
	// Pronoun will always use singular adjective at the end 
	cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adjective.singular << "." << endl;
}

// 6: Noun + Linking Verb + Adjective
void genNounLVerbAdjective(const StartNoun& noun, const NounStartingVerb& verb, const Adjective& adjective) {
	cout << "Noun + Linking Verb + Adjective" << endl; // DEBUG 
	if (noun.otherGender != "neuter") {
		// flip for Masc, Fem, or Plural Noun
		switch (threeSideDice()) {
		case 0: // noun is masculine
		{
			cout << "Der" << " " << noun.masc << " " << verb.singular << " " << adjective.singular << "." << endl;
			break;
		}
		case 1: // noun is feminine
		{
			cout << "Die" << " " << noun.fem << " " << verb.singular << " " << adjective.singular << "." << endl;
			break;
		}
		case 2: // noun is plural
		{
			cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adjective.singular << "." << endl;
			break;
		}
		}
	}
	else {
		cout << "Das" << " " << noun.plural << " " << verb.singular << " " << adjective.singular << "." << endl;
	}
}

// 2: Pronoun + Verb + Noun
void genPronounVerbNoun(const Pronoun& pronoun, const Verb& verb, const Noun& noun) {
	cout << "Pronoun + Verb + Noun" << endl; // DEBUG 
	cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << noun.noun << "." << endl;
}

// 0: Noun + Verb + Noun
void genNounVerbNoun(const StartNoun& noun, const NounStartingVerb& verb, const StartNoun& secondNoun) {
	cout << "Noun + Verb + Noun" << endl; // DEBUG 
	// flip for Masc, Fem, or Plural Noun
	switch (threeSideDice()) {
	case 0:
	{
		cout << "Der" << " " << noun.masc << " " << verb.singular << " " << secondNoun.masc << "." << endl;
		break;
	}
	case 1:
	{
		cout << "Die" << " " << noun.fem << " " << verb.singular << " " << secondNoun.masc << "." << endl;
		break;
	}
	case 2:
	{
		cout << "Die" << " " << noun.plural << " " << verb.plural << " " << secondNoun.masc << "." << endl;
		break;
	}
	}

}

// 3: Pronoun + Verb + Adverb
void genPronounVerbAdverb(const Pronoun& pronoun, const Verb& verb, const Adverb& adverb) {
	cout << "Pronoun + Verb + Adverb" << endl;// DEBUG
	cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adverb.adverb << "." << endl;
}

// 1: Noun + Verb + Adverb
void genNounVerbAdverb(const StartNoun& noun, const NounStartingVerb& verb, const Adverb& adverb) {
	cout << "Noun + Verb + Adverb" << endl;// DEBUG
	switch (threeSideDice()) {
	case 0: // masc
	{
		cout << "Der" << " " << noun.masc << " " << verb.singular << " " << adverb.adverb << "." << endl;
		break;
	}
	case 1: // fem
	{
		cout << "Die" << " " << noun.fem << " " << verb.singular << " " << adverb.adverb << "." << endl;
		break;
	}
	case 2: // plural
	{
		cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adverb.adverb << "." << endl;
		break;
	}
	}
}

void generatePronounSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
	Pronoun pronoun = getRandomPronoun(pronouns);
	Verb verb = getRandomVerb(verbs);

	if (verb.hasTag("linking")) {
		switch (coinFlip()) {
		case 0: // use PersonNoun
		{
			// 5: Pronoun + Linking Verb + PersonNoun
			PersonNoun personNoun = getRandomPersonNoun(personNouns);
			genPronounLVerbPNoun(pronoun, verb, personNoun);
			break;
		}
		case 1: // use Adjective
		{
			// 4: Pronoun + Linking Verb + Adjective
			Adjective adjective = getRandomAdjective(adjectives);
			genPronounLVerbAdjective(pronoun, verb, adjective);
			break;
		}
		}
	}
	else {
		if (verb.hasTag("adverb"))
		{
			switch (coinFlip()) {
			case 0:// 2: Pronoun + Verb + Noun
			{
				vector<Noun> validNouns = getValidNouns(nouns, verb);
				if (validNouns.empty()) {
					Adverb adverb = getRandomAdverb(adverbs);
					genPronounVerbAdverb(pronoun, verb, adverb);
				}
				else {
					Noun noun = getRandomNoun(validNouns);
					genPronounVerbNoun(pronoun, verb, noun);
				}
				break;
			}
			case 1:
			{
				// 3: Pronoun + Verb + Adverb
				Adverb adverb = getRandomAdverb(adverbs);
				genPronounVerbAdverb(pronoun, verb, adverb);
				break;
			}
			}
		}
		else {
			vector<Noun> validNouns = getValidNouns(nouns, verb);
			if (validNouns.empty()) {
				cout << "No valid nouns found for this verb: " << verb.conjugate(pronoun) << endl;
			}
			else {
				Noun noun = getRandomNoun(validNouns);
				genPronounVerbNoun(pronoun, verb, noun);
			}
		}
	}
	return;
}

void generateNounSimpleSentence(const vector<StartNoun>& nouns, const vector<NounStartingVerb>& verbs, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
	NounStartingVerb verb = getRandomNounStartingVerb(verbs);
	
	if (verb.hasFirstTag("linking")) { // can only be Noun+LVerb+Adjective
		// if linking verb, use any start noun
		StartNoun startNoun = getRandomStartNoun(nouns);
		// startNoun second tags must match adjective tags
		vector<Adjective> validAdjectives = getValidAdjectives(adjectives, startNoun);
		Adjective adjective = getRandomAdjective(adjectives);
		genNounLVerbAdjective(startNoun, verb, adjective);
	}
	else { // can be either Noun+Verb+Noun or Noun+Verb+Adverb
		// first tags of startNoun and verb must match to choose a valid startNoun
		vector<StartNoun> validNouns = getValidStartNouns(nouns, verb);

		if (validNouns.empty())
		{
			cout << "No valid nouns for the verb: " << verb.singular << endl;
			return;
		}

		StartNoun startNoun = getRandomStartNoun(validNouns);

		switch (coinFlip()) {
		case 0: // Noun + Verb + Noun
		{
			// second tags of verb and second startNoun must match to be valid
			vector<StartNoun> validSecondStartNouns = getValidSecondStartNouns(nouns, verb);
			StartNoun secondStartNoun = getRandomStartNoun(validSecondStartNouns);
			genNounVerbNoun(startNoun, verb, secondStartNoun);
			break;
		}
		case 1: // Noun + Verb + Adverb
		{
			Adverb adverb = getRandomAdverb(adverbs);
			genNounVerbAdverb(startNoun, verb, adverb);
			break;
		}
		}
	}
}
