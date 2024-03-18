#pragma once
#include<iostream>
#include "Word.h"
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

class Dictionary_Part01
{
protected:
	//vector created of type Word
	vector<Word> words;
public:
	//member functions
	void loadDictionary(string filename);
	int virtual findWord(string searchWordName);
	void findWordWithGivenCharacter(char chara, int noOfTimes);
	void findSubstring();
};

