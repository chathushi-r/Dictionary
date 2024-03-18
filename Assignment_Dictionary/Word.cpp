#include "Word.h"
#include<string>

//constructor to intialize the word class
Word::Word(string type, string name, string definition)
{
	Word::type = type;
	Word::name = name;
	Word::definition = definition;
}

//getter methods
string Word::getType()
{
	return type;
}

string Word::getName()
{
	return name;
}

string Word::getDefinition()
{
	return definition;
}

//method to print definitions
void Word::printDefinition(string name, string type, string definition)
{
	char chara = ';';
	char chara1 = ' ';
	int  i, size;
	//print
	cout << name << " ";
	cout << type << ". ";
	size = definition.size();
	for (i = 0; i < size; i++)
	{
		cout << definition[i];
		if (definition[i] == chara)
		{
			if (definition[i + 1] == chara1)
			{
				if (definition[i + 2] == chara1)
				{
					cout << endl;
				}
			}
		}
	}

}