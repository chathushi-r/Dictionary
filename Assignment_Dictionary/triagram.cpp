#include "triagram.h"

void triagram::readFile(string filename)
{
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		string temp;
		while (!(myfile.eof()))
		{
			getline(myfile, temp, ' ');											//read file
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);		//convert all letters to lower case

			arr.push_back(temp);												//store in a vector
		}
		myfile.close();															//close the file
	}
	else
	{
		cout << "Unable to open file";											//display message if the file is unavailable
	}


}

int triagram::findCombinations(string letter1, string letter2)
{
	string search, combo = "none", letter;												//declare variables
	int searchFound = 0, searchSpace;
	letter = letter1 + letter2;

	search = letter;
	totalCount = 0;
	char ch = ' ';
	searchSpace = 0;

	for (string w1 : arr)
	{
		searchFound = w1.find(search, 0);
		//cout << searchFound << endl;
		if (searchFound >= 0)									//if condition to check whether the two characters are found in the string
		{
			//int sizeTotalCombo = search.length() + 1;
			combo = search + w1[searchFound + 2];				//create combination

			//cout << combo << endl;
			searchSpace = combo.find(ch);
			//cout << searchSpace << endl;
			if (searchSpace < 0)
			{
				//cout << combo << endl;
				comboArray.push_back(combo);					//store combination in vector
				totalCount++;									//total count of combinations occured
			}

		}
	}
	if (combo == "none")
	{
		return -1;											//if no combination is found
	}
	else
	{
		checkLastLetter();									//else call function
	}
}

void triagram::checkLastLetter()
{
	char lastLetter;
	int i = 0;
	for (string w1 : comboArray)
	{
		lastLetter = w1[w1.size() - 1];						//last letter of the combinations in the vector

		for (i = 0; i < 27; i++)
		{
			if (lastLetter == characterArray[i])			//compare last letter with a-z letters in character array
			{
				countArray(i);								//call count function to co
			}

		}

	}
	calculateProbability();									//call function
}

void triagram::countArray(int index)
{
	int i;
	for (i = 0; i < 26; i++)
	{
		if (i == index)
		{
			countArr[i]++;								//increment count array
		}
	}

}

void triagram::calculateProbability()
{
	float probability;
	int i;

	for (i = 0; i < 26; i++)
	{
		probability = countArr[i] / totalCount;				//calculate probability
		countArr[i] = probability;							//copy the proabability to count array
		//cout << countArr[i] << endl;
	}
	getThreeLetters();										//call function
}

void triagram::getThreeLetters()
{
	int i;
	int first = 0, second = 0, third = 0;

	for (i = 0; i < 26; i++)
	{
		if (countArr[i] > countArr[first])				//if condition to get the 1st largest probability
		{
			third = second;
			second = first;
			first = i;
		}
		else if (countArr[i] > countArr[second])		//if condition to get the 2nd largest probability
		{
			third = second;
			second = i;
		}

		else if (countArr[i] > countArr[third])			//if condition to get the 3rd largest probability
		{
			third = i;
		}

	}

	ThreeLetters(first, second, third);			//call function
}


void triagram::ThreeLetters(int first, int second, int third)
{
	firstLetter = characterArray[first];					//retrieve the letters
	secondLetter = characterArray[second];
	thirdLetter = characterArray[third];
}

void triagram::printThreeLetters()
{
	cout << "\nFirst letter: " << firstLetter << endl;			//print
	cout << "Second letter: " << secondLetter << endl;
	cout << "Third letter: " << thirdLetter << endl;
}

char triagram::pickRandomLetter()
{
	srand(time(NULL));
	char letter[3] = { firstLetter,secondLetter,thirdLetter };
	int randIndex = rand() % 3;

	char randomLetter = letter[randIndex];
	//cout << randomLetter << endl;
	//string word = word.append(1, randomLetter);

	return randomLetter;
}

void triagram::clearContents()
{
	//clear all vectors and initiate total count to 0
	comboArray.clear();
	fill(begin(countArr), end(countArr), 0);
	totalCount = 0;

}

int triagram::searchTrigram(string triagram)
{
	string currentName;

	for (Word w1 : words)														//for loop to run through the vector
	{
		currentName = w1.getName();												//stores the name of the current word in a temporary variable called currentName

		if (triagram == currentName)										//if condition to find the searched word in the dictionary
		{
			return 0;															//return 0 if the word is found
		}
	}
	return -1;
}

