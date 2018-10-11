// Lab01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

void beginGame();
void gameLoop();
int randomNumber();
bool passNumber(int iChosenNumber, int iRandomNumber);
void endGame(bool bGameState);

int main()
{
	
	gameLoop();

	system("pause");
    return 0;
}

void beginGame()
{
	std::cout << "Guess the number computer chose from 1 to 100" << std::endl;
	std::cout << "Your number:" << std::endl;
};
void gameLoop()
{
	int iNumber;
	int iCounter = 1;

	beginGame();
	int iRandomNumber = randomNumber();
	std::cout << "iRandomNumber = " << iRandomNumber << std::endl;
	std::cin >> iNumber;
	bool bWin = passNumber(iNumber, iRandomNumber);
	while (!bWin && iCounter < 5)
	{
		std::cin >> iNumber;
		bWin = passNumber(iNumber, iRandomNumber);
		iCounter++;
	}

	endGame(bWin);
};
int randomNumber()
{
	srand(time(0));
	int iRandom = rand() % 100 + 1;
	return iRandom;
};
bool passNumber(int iChosenNumber, int iRandomNumber)
{
	if (iChosenNumber < iRandomNumber)
	{
		std::cout << "Higher" << std::endl;
		return false;
	}
	else if (iChosenNumber > iRandomNumber)
	{
		std::cout << "Lower" << std::endl;
		return false;
	}
	else return true;
};
void endGame(bool bGameState)
{
	if (bGameState)
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "You lost" << std::endl;
	}
};

