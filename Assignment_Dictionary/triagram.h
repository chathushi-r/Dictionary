#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<random>
#include "Dictionary_Part01.h"
#include "Word.h"

using namespace std;

class triagram : public Dictionary_Part01
{
private:
	int totalCount;
	vector<string> arr;
	vector<string> comboArray;
	char characterArray[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	float countArr[26] = { 0 };
	char firstLetter, secondLetter, thirdLetter;
public:
	void readFile(string filename);
	int findCombinations(string letter1, string letter2);
	void checkLastLetter();
	void countArray(int index);
	void calculateProbability();
	void getThreeLetters();
	void ThreeLetters(int first, int second, int third);
	void printThreeLetters();
	char pickRandomLetter();
	void clearContents();
	int searchTrigram(string triagram);
};