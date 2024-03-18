#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Word
{
private:
	//members of the word class made private so only can be accessed within the word class
	string name;
	string type;
	string definition;
public:
	//constructor to intialize the variables
	Word(string name, string type, string definition);

	//getter methods
	string getName();
	string getType();
	string getDefinition();
	//printDefinition method
	void printDefinition(string name, string type, string definition);
};


