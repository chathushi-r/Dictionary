#pragma once
#include "Dictionary_Part01.h"
#include "Word.h"
#include<vector>
#include<string>
#include<algorithm>
#include<random>


using namespace std;

class Dictionary_Part02 : public Dictionary_Part01
{
public:
	void palindrome();
	int findAnagram(string word);
	int findWord(string searchWordName);
	string randomWord();
	int guessingGame(string wordName, string guessWord, int i);
};
