#include "Dictionary_Part01.h"

void Dictionary_Part01::loadDictionary(string filename)
{

	ifstream myfile(filename);
	if (myfile.is_open())
	{
		string temp;															//temporary variable to hold each line
		string tempName = "none";												//temporary variable to hold word name
		string tempType = "none";												//temporary variable to hold word type
		string tempDefinition = "none";											//temporary variable to hold word definition
		string tempStar = "none";												//temporary variable to hold '**'

		while (!(myfile.eof()))													//while loop runs until it reaches end of file
		{
			// first line holds the word type
			getline(myfile, temp, '\n');										//reads the first line till it reached \n and stores it in the temp variable
			tempType = temp;													//assigns the temp value to tempType
			// second line holds the word name
			getline(myfile, temp, '\n');										//reads the second line till it reached \n and stores it in the temp variable
			tempName = temp;													//assigns the temp value to tempName
			// third line holds the word definition
			getline(myfile, temp, '\n');										//reads the third line till it reached \n and stores it in the temp variable
			tempDefinition = temp;												//assigns the temp value to tempDefinition
			//fourth line holds the characters **
			getline(myfile, temp, '\n');										//reads the fourth line till it reached \n and stores it in the temp variable
			tempStar = temp;													//assigns the temp value to tempStar

			if (temp == tempStar)												//when it reaches the characters "**" an if condition performed
			{
				Word newWord(tempType, tempName, tempDefinition);				//create a new word record

				words.push_back(newWord);										//add the new word into a vector

			}
		}
		myfile.close();															//close the file
	}
	else
	{
		cout << "Unable to open file";											//display message if the file is unavailable
	}
}

int Dictionary_Part01::findWord(string searchWordName)
{
	string currentName, currentType, currentDefinition;							//temporary variables

	/*vector<Word> ::iterator it;
	int end = distance(words.end(), it);
	find(words.at(0).getName(), words.at(end).getName(), searchWordName);*/

	for (Word w1 : words)														//for loop to run through the vector
	{
		currentName = w1.getName();												//stores the name of the current word in a temporary variable called currentName
		currentType = w1.getType();												//stores the type of the current word in a temporary variable called currentType
		currentDefinition = w1.getDefinition();;								//stores the definition of the current word in a temporary variable called currentDefinition
		if (searchWordName == currentName)										//if condition to find the searched word in the dictionary
		{
			{
				if (currentType == "n_and_v")
				{
					currentType = "n.v";										//change the type format
				}
			}
			w1.printDefinition(currentName, currentType, currentDefinition);	//call function
			return 0;															//return 0 if the word is found
		}

	}
	return -1;																	//return -1 if searched word is not found in the dictionary
}

void Dictionary_Part01::findWordWithGivenCharacter(char chara, int noOfTimes)
{
	//declare variables
	int count, characterFound;
	string currentWord;

	cout << endl << "Words that contain the character '" << chara << "' appearing more than " << noOfTimes << " times:" << endl;		//display messsage

	for (Word w1 : words)
	{
		currentWord = w1.getName();												//get the word name from the dictionary
		count = 0;																//set count to 0 for every iteration

		characterFound = currentWord.find(chara);								//search for the character and store the first occurence in the variable

		while (characterFound != string::npos)									//loop to run until it reaches end of string 
		{
			count++;															//increment count if the character is found
			characterFound = currentWord.find(chara, characterFound + 1);		//increment found for the next iteration
		}
		if (count >= noOfTimes)													//check if the character appeared more than or equal to the user's given number of times
		{
			cout << currentWord << endl;										//print the word name
		}
	}
}

void Dictionary_Part01::findSubstring()
{
	for (Word w1 : words)
	{
		string search = "qu";													//string that needs to be searched in a word
		char LetterQ = 'q';
		int searchFound, getLetterQ;											//a variable to store the integer that appears if the string was found or not

		string currentWord = w1.getName();										//storing the current word name into a temporary variable

		getLetterQ = currentWord.find(LetterQ);									//using the find function to find the character "q" in the current word
		searchFound = currentWord.find(search);									//using the find function to find the string "qu" in the current word

		if (getLetterQ != string::npos)
		{
			if (searchFound == string::npos)									//if condition to check whether the string was not found in the string
			{
				cout << currentWord << endl;									//print the word name;
			}
		}
	}
}