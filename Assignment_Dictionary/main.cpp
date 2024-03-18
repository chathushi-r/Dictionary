#include<iostream>
#include "Dictionary_Part01.h"
#include "Dictionary_Part02.h"
#include "Word.h"
#include "triagram.h"
#include<string>
#include<vector>
#include<fstream>
#include<exception>

using namespace std;

int main()
{
	//new instance of the dictionary_part01 class
	Dictionary_Part01 allWords;
	Dictionary_Part02 words;
	triagram comboWords;

	//declare variables
	int menuChoice, returnSearchValue, characterLimit, i, guessedValue, returnValue, trigramChoice, wordSize, anagramValue, retSearchValue;
	string searchWord, searchAnagram, message, rightWord, guessWord, concatenatedString, randomWord, chara1, chara2;
	char character, letter;
	vector<string>randomWords;



	//call function to load the dictionary file to a container of dictionary_Part01 class
	allWords.loadDictionary("dictionary.txt");
	words.loadDictionary("dictionary.txt");

	comboWords.readFile("sample2.txt");

	//menu
	cout << "Please select the required task option (1-4): " << endl;
	cout << "(1) Search for a word" << endl;
	cout << "(2) Find words that contain a character more than the minimum number of times" << endl;
	cout << "(3) Print words that have a 'q' without a following 'u'" << endl;
	cout << "(4) Print words that are palindromes" << endl;
	cout << "(5) Print anagrams of a given word" << endl;
	cout << "(6) Search for a word with a nicer output" << endl;
	cout << "(7) Do you want to guess a word? " << endl;
	cout << "(8) Find triagrams " << endl;
	cout << "(9) Exit " << endl;
	cin >> menuChoice;													//read the user's input


	//while loop to check the user's choice
	while (menuChoice != 9)
	{
		switch (menuChoice)
		{
		case 1: cout << "Enter the word you would like to search: ";					//display message asking user input
			cin >> searchWord;															//read user input even with spaces
			cout << endl;
			returnSearchValue = allWords.findWord(searchWord);								//call the function and return the search value
			if (returnSearchValue == -1)												//if condition to see if the word is not found
			{
				cout << "Word not found" << endl;										//display message if word not found
			}
			break;

		case 2: cout << "Enter a character (a-z) you would like to search: ";			//user input character
			cin >> character;
			cout << "Enter the minimum number of times this character should occur: ";	//user input character limit
			cin >> characterLimit;
			allWords.findWordWithGivenCharacter(character, characterLimit);				//call the function
			break;

		case 3: cout << "Words that have a 'q' without a following 'u' are:" << endl;	//display message
			allWords.findSubstring();													//call the function
			break;

		case 4: cout << "\nPalindromes within the dictionary: " << endl;
			words.palindrome();														//call function from Dictionary_Part02 class
			break;

		case 5: cout << "Enter a word: ";
			cin >> searchAnagram;														//read user input even with spaces
			cout << "\nAnagrams: " << endl;
			try {																	//try block for exceptions
				anagramValue = words.findAnagram(searchAnagram);
				if (anagramValue < 0)
				{
					throw(anagramValue);											//throw value
				}
			}
			catch (int anagramVal) {													//catch value to print the error message
				//anagramVal = -1;
				cout << "No anagrams found";										//error message printed
			}
			break;

		case 6: cout << "Enter the word you would like to search: ";					//display message asking user input
			cin >> searchWord;															//read user input even with spaces
			cout << endl;
			try {																		//try block for exceptions
				returnSearchValue = words.findWord(searchWord);								//call the function and return the search value
				if (returnSearchValue < 0)												//if condition to see if the word is not found
				{
					throw(returnSearchValue);											//throw value

				}
			}
			catch (int searchValue) {													//catch value to print the error message
				//searchValue = -1;
				cout << "Word not found";												//error message printed
			}
			break;

		case 7: cout << "Welcome to the guessing game!" << endl;
			cout << "You got 3 tries to guess the correct word. Let's begin!" << endl;
			rightWord = words.randomWord();												//call random function to get a random word
			for (i = 1; i <= 3; i++)
			{
				cout << "\nEnter your guess: " << i << " :";							//get user input
				cin >> guessWord;
				guessedValue = words.guessingGame(rightWord, guessWord, i);				//call guessing game function to check the guesses
				if (guessedValue == 0)													//if the user guessed it right, end loop
				{
					break;
				}
			}
			break;

		case 8: cout << "(1) Do you want to get three most likely characters for any two characters?" << endl;				//two functions
			cout << "(2) Generate 10 random words?" << endl;
			cout << "Your preferred option:";
			cin >> trigramChoice;
			if (trigramChoice == 1)
			{
				cout << "\nInput 1st character: ";											//user input 1st character
				cin >> chara1;
				if (chara1.length() > 1)														//if condition to check if the user enters only one character
				{
					cout << "Incorrect input. You entered more than one character." << endl;
					break;
				}
				cout << "Input 2nd character: ";											//user input 2nd character
				cin >> chara2;
				if (chara2.length() > 1)														//if condition to check if the user enters only one character
				{
					cout << "Incorrect input. You entered more than one character." << endl;
					break;
				}

				returnValue = comboWords.findCombinations(chara1, chara2);				//call function
				if (returnValue < 0)
				{
					cout << "\nNo combination found" << endl;									//if no combination is found in the text file
					break;
				}
				comboWords.printThreeLetters();
				comboWords.clearContents();
			}
			else if (trigramChoice == 2)
			{
				int j, i, wordCount;
				chara1 = " ";
				chara2 = " ";
				cout << "Enter the number of words you would like to generate: ";					//user input number of words to generate
				cin >> wordCount;
				for (i = 0; i < wordCount; i++)
				{
					cout << "\nEnter the size of word " << i+1 << ": ";
					cin >> wordSize;

					for (j = 0; j < wordSize; j++)
					{
						cout << endl;
						cout << "\nInput 1st character: ";											//user input 1st character
						cin >> chara1;
						if (chara1.length() > 1)														//if condition to check if the user enters only one character
						{
							cout << "Incorrect input. You entered more than one character." << endl;
							break;
						}
						cout << "Input 2nd character: ";											//user input 2nd character
						cin >> chara2;
						if (chara2.length() > 1)														//if condition to check if the user enters only one character
						{
							cout << "Incorrect input. You entered more than one character." << endl;
							break;
						}
						returnValue = comboWords.findCombinations(chara1, chara2);				//call function
						if (returnValue < 0)
						{
							cout << "\nNo combination found" << endl;									//if no combination is found in the text file
							break;
						}

						letter = comboWords.pickRandomLetter();									//pick randomly from the three letters 
						randomWord += letter;													//add it to a word
						comboWords.clearContents();
					}
					if ((chara1.length() > 1) || (chara2.length() > 1) || returnValue == -1)
					{
						break;
					}

					retSearchValue = comboWords.searchTrigram(randomWord);					//call the function and return the search value
					if (retSearchValue < 0)													//if condition to see if the word is not found
					{
						randomWords.push_back(randomWord);									//display message if word not found
					}
					//cout << endl << randomWord << endl;
					randomWord.clear();														//clear word string
				}

				cout << "\nWords created: " << endl;										//print words
				for (string w1 : randomWords)
				{
					cout << w1 << endl;
				}
				randomWords.clear();														//clear vector

			}
			break;

		default: cout << "Invalid choice" << endl;								//if the user inputs another integer/character apart from 1-4
		}
		cout << endl;
		cout << "\nPlease select the required task option (1-4): " << endl;
		cout << "(1) Search for a word" << endl;
		cout << "(2) Find words that contain a character more than the minimum number of times" << endl;
		cout << "(3) Print words that have a 'q' without a following 'u'" << endl;
		cout << "(4) Print words that are palindromes" << endl;
		cout << "(5) Print anagrams of a given word" << endl;
		cout << "(6) Search for a word with a nicer output" << endl;
		cout << "(7) Do you want to guess a word? " << endl;
		cout << "(8) Find triagrams " << endl;
		cout << "(9) Exit " << endl;
		cin >> menuChoice;			//read the user's input
	}
	cout << "Program ended!" << endl;		//display message to end the program if the user enters choice (4)

	system("pause");
	return 0;
}