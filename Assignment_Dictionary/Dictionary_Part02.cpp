#include "Dictionary_Part02.h"

void Dictionary_Part02::palindrome()
{
	string revcurrentWord, copyCurrentWord;									//declare variables

	for (Word w1 : words)
	{
		revcurrentWord = w1.getName();										//current word stored in a temporary variable
		reverse(revcurrentWord.begin(), revcurrentWord.end());				//current word reversed using inbuilt reverse function

		if (revcurrentWord == w1.getName())									//comparing the reversed word and the word in the vector
		{
			cout << w1.getName() << endl;									//if condition is true - print the word
		}

	}
}

int Dictionary_Part02::findAnagram(string word)
{
	//int i = 0;
	string currentWord, wordCopy;
	//i <= words.size();

	wordCopy = word;
	sort(word.begin(), word.end());											//sort the word inputted by user

	for (Word w1 : words)													//for loop to iterate through the vector
	{
		currentWord = w1.getName();											//store the word in a temp variable for every iteration
		sort(currentWord.begin(), currentWord.end());						//sort the word

		if (currentWord == word)												//checking to see if the strings are equal after sorting
		{
			if (w1.getName() != wordCopy)
			{
				cout << w1.getName() << endl;									//print word name
			}

		}
	}
	return -1;

}

int Dictionary_Part02::findWord(string searchWordName)
{
	string currentName, currentType, currentDefinition;							//temporary variables

	transform(searchWordName.begin(), searchWordName.end(), searchWordName.begin(), ::tolower);				//convert the user input into lowercase
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
			if (currentType == "n_and_v")
			{
				currentType = "n.v";										//change the type format
			}
			if (currentType == "pn")
			{
				currentName[0] = toupper(currentName[0]);
			}
			w1.printDefinition(currentName, currentType, currentDefinition);	//call function
			return 0;															//return 0 if the word is found
		}

	}
	return -1;
}

string Dictionary_Part02::randomWord()
{
	string wordName, wordDefinition;
	int randomVectorElement = 0;
	srand(time(NULL));
	randomVectorElement = rand() % words.size();
	wordName = words[randomVectorElement].getName();
	wordDefinition = words[randomVectorElement].getDefinition();
	cout << "\nLength of word: " << wordName.size() << endl;
	cout << "Definition of word: " << wordDefinition << endl;
	return wordName;
}

int Dictionary_Part02::guessingGame(string wordName, string guessWord, int i)
{
	if (guessWord == wordName)
	{
		cout << "Congrats! You guessed it right!" << endl;					//display message if the guess is correct
		return 0;
	}
	else if (guessWord != wordName)
	{
		if (i == 1)
		{
			cout << "Try again. Let me show u a hint" << endl;					//display message if 1st guess is wrong
			cout << "First letter: " << wordName[0] << endl;					//print the first letter of the word as a hint
		}
		else if (i == 2)
		{
			cout << "Try again. Let me show u a hint" << endl;					//display message if 1st guess is wrong
			cout << "Second letter: " << wordName[1] << endl;					//print the second letter of the word as a hint
		}
		else if (i == 3)
		{
			cout << "\nYou lost!" << endl;										//display message if 3rd guess is wrong
			cout << "Correct Word: " << wordName << endl;						//print the correct word
		}
		return -1;
	}
}

