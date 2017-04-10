#include"LinkedStack.h"
#include"LinkedQueue.h"
#include"QueueInterface.h"
#include"StackInterface.h"

#include<string>
#include<iostream>

using namespace std;


bool isPalindrome(string word)
{
	LinkedQueue<char> aQueue;
	LinkedStack<char> aStack;

	int length = word.length();
	for (int i = 0; i<length; i++)
	{
		char nextChar = word[i];
		nextChar = toupper(nextChar);
		if (nextChar >= 65 && nextChar <= 90)
		{
			aQueue.enqueue(nextChar);
			aStack.push(nextChar);
		}
	}

	bool charactersAreEqual = true;
	while (!aQueue.isEmpty() && charactersAreEqual)
	{
		char queueFront = aQueue.peekFront();
		char stackTop = aStack.peek();
		if (queueFront == stackTop)
		{
			aQueue.dequeue();
			aStack.pop();
		}

		else
			charactersAreEqual = false;


	}
	return charactersAreEqual;
}


void main()
{
	string wordToCheck;
	cout << "Please enter a word to check if it is a Palindrome: ";
	getline(cin, wordToCheck);
	if (isPalindrome(wordToCheck))
		cout << "PALINDROME!" << endl;
	else
		cout << "NOT PALINDROME!" << endl;
}