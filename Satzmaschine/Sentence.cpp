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

void generateSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
	Pronoun pronoun = getRandomPronoun(pronouns);
	Verb verb = getRandomVerb(verbs);

	if (verb.hasTag("linking")) {
		switch (coinFlip()) {
		case 0: // use PersonNoun
		{
			// 5: Pronoun + Linking Verb + PersonNoun
			PersonNoun personNoun = getRandomPersonNoun(personNouns);

			if (pronoun.number == "plural") {
				cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.plural << "." << endl;
			}
			else if (pronoun.word == "sie") { // she/her
				cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.feminine << "." << endl;
			}
			else
				cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.masculine << "." << endl;
			break;
		}
		case 1: // use Adjective
		{
			// 4: Pronoun + Linking Verb + Adjective
			Adjective adjective = getRandomAdjective(adjectives);
			// Pronoun will always use singular adjective at the end 
			cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adjective.singular << "." << endl;
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
					cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adverb.adverb << "." << endl;
					// cout << "No valid nouns found for this verb: " << verb.conjugate(pronoun) << endl;
				}
				else {
					Noun noun = getRandomNoun(validNouns);

					cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << noun.noun << "." << endl;
				}
				break;
			}
			case 1:
			{
				// 3: Pronoun + Verb + Adverb
				Adverb adverb = getRandomAdverb(adverbs);
				cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adverb.adverb << "." << endl;
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

				cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << noun.noun << "." << endl;
			}
		}

	}
	return;
}
