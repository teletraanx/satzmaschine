#include "Sentence.h"

// pick random Simple Sentence template
// 0. Pronoun + Verb + Noun : I need water
//		Noun + Verb + Noun : The dog needs water.
// 1. Pronoun + Linking Verb + Noun : I am a Doctor
// 2. Pronoun + Linking Verb + Adjective : I am tired
//		Noun + Linking Verb + Adjective : The dog is tired
// 3. Pronoun + Verb + Adverb : I sleep peacefully.
//		Noun + Verb + Adverb : The dog sleeps peacefully
// 1b. Noun + Linking Verb + Noun <-- Ignore for now


Pronoun getRandomPronoun(vector<Pronoun> pronouns) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> pronounDist(0, pronouns.size() - 1);
	Pronoun pronoun = pronouns[pronounDist(gen)];
	return pronoun;
}

// Valid noun depends on verb's tags
vector<Noun> getValidNouns(vector<Noun> nouns, Verb verb) {
	vector<Noun> validNouns;
	for (const Noun& noun : nouns) {
		if (verb.acceptsNoun(noun)) {
			validNouns.push_back(noun);
		}
	}
	return validNouns;
}

Noun getRandomNoun(vector<Noun> nouns) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> nounDist(0, nouns.size() - 1);
	Noun noun = nouns[nounDist(gen)];
	return noun;
}

Verb getRandomVerb(vector<Verb> verbs) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 

	uniform_int_distribution<> verbDist(0, verbs.size() - 1);
	Verb verb = verbs[verbDist(gen)];
	return verb;
}
