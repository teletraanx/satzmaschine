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
void genNounLVerbAdjective(const Noun& Noun, const Verb& verb, const Adjective& adjective) {
	cout << "Noun + Linking Verb + Adjective" << endl; // DEBUG 
	// Pronoun will always use singular adjective at the end 
	cout << capitalizeFirst(Noun.noun) << " " << verb.thirdSingularForm << " " << adjective.singular << "." << endl;
}

// 2: Pronoun + Verb + Noun
void genPronounVerbNoun(const Pronoun& pronoun, const Verb& verb, const Noun& noun) {
	cout << "Pronoun + Verb + Noun" << endl; // DEBUG 
	cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << noun.noun << "." << endl;
}

// 0: Noun + Verb + Noun
void genNounVerbNoun(const Noun& startNoun, const Verb& verb, const Noun& noun) {
	cout << "Pronoun + Verb + Noun" << endl; // DEBUG 
	cout << capitalizeFirst(startNoun.noun) << " " << verb.thirdSingularForm << " " << noun.noun << "." << endl;
}

// 3: Pronoun + Verb + Adverb
void genPronounVerbAdverb(const Pronoun& pronoun, const Verb& verb, const Adverb& adverb) {
	cout << "Pronoun + Verb + Adverb" << endl;// DEBUG
	cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adverb.adverb << "." << endl;
}

// 1: Noun + Verb + Adverb
void genNounVerbAdverb(const Noun& noun, const Verb& verb, const Adverb& adverb) {
	cout << "Noun + Verb + Adverb" << endl;// DEBUG
	cout << capitalizeFirst(noun.noun) << " " << verb.thirdSingularForm << " " << adverb.adverb << "." << endl;
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

void generateNounSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
	Noun startNoun = getRandomNoun(nouns);
	Verb verb = getRandomVerb(verbs);

	if (verb.hasTag("linking")) {
			// Noun + Linking Verb + Adjective
			Adjective adjective = getRandomAdjective(adjectives);
			genNounLVerbAdjective(startNoun, verb, adjective);		
	}
	else {
		if (verb.hasTag("adverb"))
		{
			switch (coinFlip()) {
			case 0:// Noun + Verb + Noun
			{
				vector<Noun> validNouns = getValidNouns(nouns, verb);
				if (validNouns.empty()) {
					Adverb adverb = getRandomAdverb(adverbs);
					genNounVerbAdverb(startNoun, verb, adverb);
				}
				else {
					Noun noun = getRandomNoun(validNouns);
					genNounVerbNoun(startNoun, verb, noun);
				}
				break;
			}
			case 1:
			{
				// Noun + Verb + Adverb
				Adverb adverb = getRandomAdverb(adverbs);
				genNounVerbAdverb(startNoun, verb, adverb);
				break;
			}
			}
		}
		else {
			vector<Noun> validNouns = getValidNouns(nouns, verb);
			if (validNouns.empty()) {
				cout << "No valid nouns found for this verb: " << verb.thirdSingularForm << endl;
			}
			else {
				Noun noun = getRandomNoun(validNouns);
				genNounVerbNoun(startNoun, verb, noun);
			}
		}
	}
	return;
}
