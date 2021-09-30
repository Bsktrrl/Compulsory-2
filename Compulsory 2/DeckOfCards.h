#pragma once
#include "Includes.h"

vector<int> CardsAlreadyPlayed{};

int rng(int, int);

int cards(bool newRound) {
	vector<int> deckOfCards;

	int cardCheck{0};
	int deckSize{13};
	int cardTypes{4};
	int cardsInADeck{deckSize * cardTypes};
	int theChosenCard{};
	int theChosenNumber{};

	bool firstTime{};

	int numberMin{1};
	int numberMax{cardsInADeck};
	int randomNumber{};

	system("cls");

	//The first time the game runs, setup the "deckOfCards"-vector so it includes all possible cards in a deck (56 cards)
	if (firstTime == false)
	{
		for (size_t i = 0; i < deckSize + 1; i++)
		{
			for (size_t j = 0; j < cardTypes + 1; j++) {
				deckOfCards.push_back(i + 1);
			}
		}
		firstTime = true;
	}

	//If a new game has begun, the amount of positions in the "CardsAlreadyPlayed"-vector resets to 1 with the value 0
	if (newRound == true)
	{
		CardsAlreadyPlayed.clear();
		CardsAlreadyPlayed.push_back(0);
	}

	//See if the card that's about to be selected already has been played
	//If so, choose another card and check this one
	//If not, choose this card as the one to play
	for (size_t i = 0; i < 1;)
	{
		cardCheck = 0;
		theChosenCard = rng(numberMin, numberMax);

		for (size_t j = 0; j < CardsAlreadyPlayed.size(); j++)
		{
			if (theChosenCard != CardsAlreadyPlayed[j])
				cardCheck += 1;

			if (cardCheck == CardsAlreadyPlayed.size())
			{
				CardsAlreadyPlayed.push_back(theChosenCard);
				i++;
			}
		}
	}

	theChosenNumber = deckOfCards[theChosenCard];
	return theChosenNumber;
}

int rng(int numberMin, int numberMax) {
	int randomNumber{};

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> RNG(numberMin, numberMax);
	randomNumber = RNG(gen);

	return randomNumber;
}