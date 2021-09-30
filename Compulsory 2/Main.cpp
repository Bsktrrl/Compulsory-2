#include "Includes.h"
#include "Login.h"
#include "DeckOfCards.h"
#include "Rng.h"
#include "AiName.h"

void blackJack();
void scoreboard(int, int, int, int, int, int, int, int, int, string, string, string, string, bool, bool);
int rng();


int main() {
	login();
	
	for (size_t i = 0; i < 1;)
	{
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
		cout << "Do you want to play some Black Jack?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No, I want to leave" << endl;

		char menuSelect = _getch();
		switch (menuSelect)
		{
		case '1':
			blackJack();
			break;
		case '2':
		#pragma region Leave the Casino
			system("cls");
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << endl;
			cout << "    As you please " << endl;
			cout << endl;
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			Sleep(1000);
			system("cls");
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << endl;
			cout << "       Goodbye " << endl;
			cout << endl;
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			Sleep(1000);
			system("cls");
			i++;
		#pragma endregion
		default:
			system("cls");
			break;
		}
	}
	return 0;
}

void blackJack() {
	system("cls");
	#pragma region Variables
	bool newRound{};
	bool player{};
	bool playerInGame{};
	bool AiInGame{};

	int maxAmount{};
	int chosenCard{};

	int round{};
	int roundsOfPlayers{};
	int savedScorePlayer{};
	int savedScoreAi{};
	int numberToReach{21};

	int RngMax{};

	int gold{100};
	int goldPlayer{gold};
	int goldAi{gold};
	int goldPlayerGamble{};
	int goldAiGamble{};

	char decition{};

	string type{};
	string pictureCards{};
	string namePlayer{};
	string nameAi{};
	#pragma endregion
	#pragma region Introduction
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	cout << "First of all, what's your name? ";
	cin >> namePlayer;

	nameAi = aiName();
	cout << endl << "Great!" << endl;
	cout << "You will be playing alongside \"" << nameAi << "\"" << endl;
	cout << "You will each get $" << gold << " to use during play" << endl;
	cout << "The first player that looses all its $, loses the game" << endl << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Before we begin, you have to gamble some of your $" << endl;
	#pragma endregion

	//The system for the course of the game
	for (size_t i = 0; i < 1; )
	{
		for (size_t u = 0; u < 1;)
		{
			if (goldPlayer == 0)
			{
				cout << nameAi << " is the Black Jack Champion!!!" << endl;
				Sleep(1000);
				cout << "Please return to the lobby";
				Sleep(2000);
				system("cls");
				u++;
				i++;
			}
			else if (goldAi == 0)
			{
				cout << namePlayer << " is the Black Jack Champion!!!" << endl;
				Sleep(1000);
				cout << "Please return to the lobby";
				Sleep(2000);
				system("cls");
				u++;
				i++;
			}
			else
			{
				cout << "Your account: \t\t$" << goldPlayer << endl;
				cout << nameAi << "'s account: \t$" << goldAi << endl;
				cout << "How much $ do you want to gamble? $";
				cin >> goldPlayerGamble;

				if (goldPlayerGamble <= 0)
				{
					system("cls");
					cout << "You cannot gamble nothing";
					Sleep(2000);
				}
				else if (goldPlayerGamble > goldAi)
				{
					system("cls");
					cout << "You can only gamble more than " << nameAi << " owns, which are: $" << goldAi;
					Sleep(2000);
				}
				else if (goldPlayerGamble > goldPlayer)
				{
					system("cls");
					cout << "You cannot gamble more $ than you own";
					Sleep(2000);
				}
				else {
					goldAiGamble = goldPlayerGamble;
					u++;
				}
				system("cls");
			}
		}

		if (goldAi == 0 || goldPlayer == 0){}
		else
		{
			for (size_t roundCounter = 0; roundCounter < 2; roundCounter++)
			{
				#pragma region Setup for each new Round
				newRound = true;
				round = 0;
				maxAmount = 0;

				//Setup for each new Round (when the active player changes) -----------------------------------------------------------
				if (roundCounter == 0)
				{
					playerInGame = true;
					AiInGame = false;
				}
				else if (roundCounter == 1)
				{
					AiInGame = true;
					playerInGame = false;
				}
				else
				{
					playerInGame = false;
					AiInGame = false;
				}
				#pragma endregion
				#pragma region Players draw cards on their turn
				for (size_t gettingCards = 0; gettingCards < 1;)
				{
					round += 1;
					chosenCard = cards(newRound);
					maxAmount += chosenCard;
					newRound = false;

					//Generate random numbers from 1 to 4
					#pragma region Rng to 4 card types
					int numberMin{ 1 };
					int numberMax{ 4 };
					int randomNumber{};

					random_device rd;
					mt19937_64 gen(rd());
					uniform_int_distribution<int> RNG(numberMin, numberMax);
					randomNumber = RNG(gen);

					if (randomNumber == 1)
						type = "Heart";
					else if (randomNumber == 2)
						type = "Clubs";
					else if (randomNumber == 3)
						type = "Spades";
					else if (randomNumber == 4)
						type = "Diamond";
					else
						type = "Blank";
					#pragma endregion

					//When you draw a "A", give it either a score fo 1 or a score of 11
					//The Ai chooses for itself
					if (playerInGame == true)
					{
						if (chosenCard == 1 || chosenCard == 14)
						{
							cout << "You're about to draw a \"A\"" << endl;
							cout << "What score do you want it to count as?" << endl;
							cout << "1. Score 1" << endl;
							cout << "2. Score 11" << endl;
							char menuSelect = _getch();
							switch (menuSelect)
							{
							case '1':
								chosenCard = 1;
								break;
							case '2':
								chosenCard = 20;
								break;
							default:
								break;
							}
							system("cls");
						}
					}
					else
					{
						if (chosenCard == 1 || chosenCard == 14)
						{
							if (savedScoreAi < numberToReach - 11)
								chosenCard = 1;
							else
								chosenCard = 20;
						}
					}

					//Giving names, so the player knows what picture card that gave core 10
					if (chosenCard == 11)
					{
						pictureCards = "Jack";
						chosenCard = 10;
					}
					else if (chosenCard == 12)
					{
						pictureCards = "Queen";
						chosenCard = 10;
					}
					else if (chosenCard == 13)
					{
						pictureCards = "King";
						chosenCard = 10;
					}
					else if (chosenCard == 14)
					{
						pictureCards = "Ace";
						chosenCard = 10;
					}
					else if (chosenCard == 20)
					{
						pictureCards = "Ace";
						chosenCard = 11;
					}

					scoreboard(round, chosenCard, maxAmount, numberToReach, savedScorePlayer, goldPlayer, goldAi, goldPlayerGamble, goldAiGamble, type, pictureCards, namePlayer, nameAi, playerInGame, AiInGame);

					if (maxAmount < numberToReach)
					{
						if (playerInGame == true)
						{
							cout << "Do you want to draw another card or save your score?" << endl;
							cout << "1. Draw" << endl;
							cout << "2. Save" << endl;

							char menuSelect = _getch();
							switch (menuSelect)
							{
							case '1':
								break;
							case '2':
								savedScorePlayer = maxAmount;
								gettingCards++;
								cout << endl << "Well ...then there's time for " << nameAi << endl;
								Sleep(2000);
								break;
							default:
								break;
							}
						}
						else
						{
							RngMax = 10;
							randomNumberGenerator(RngMax);

							for (size_t i = 0; i < randomNumberGenerator(RngMax); i++)
							{
								cout << ".";
								Sleep(400);
							}
							cout << endl;

							if (maxAmount < savedScorePlayer)
							{
								cout << nameAi << " draws another card" << endl;
							}
							else if (maxAmount == savedScorePlayer)
							{
								if (maxAmount < numberToReach - 5)
								{
									cout << nameAi << " gambles and goes for yet another card" << endl;
								}
								else
								{
									cout << nameAi << " saves the score equal to you" << endl;
									Sleep(1000);
									cout << "What a twist!!" << endl;
									savedScoreAi = maxAmount;
									gettingCards++;
								}
							}
							else
							{
								cout << "Well, only an idiot would risk loosing..." << endl;
								Sleep(1000);
								cout << "And " << nameAi << " is not an idiot" << endl;;
								savedScoreAi = maxAmount;
								gettingCards++;
							}
							cout << endl;
							system("pause");
							system("cls");
						}
					}
					else if (maxAmount == numberToReach)
					{
						cout << "It's exactly " << maxAmount << " points!!!" << endl;
						Sleep(1000);
						cout << "Saving this score" << endl;
						Sleep(400);
						cout << "."; Sleep(400);
						cout << "."; Sleep(400);
						cout << "."; Sleep(400);

						if (playerInGame == true)
						{
							savedScorePlayer = maxAmount;
						}
						else
						{
							savedScoreAi = maxAmount;
						}
						gettingCards++;
					}
					else
					{
						//When your score exceeds the number to reach, you don't get a score this round
						if (playerInGame == true)
						{
							cout << namePlayer << ", your score is higher than " << numberToReach << endl;
							cout << "Sorry... " << endl;
							Sleep(2000);
							cout << endl << "Well ...then there's time for " << nameAi << endl;
							Sleep(2000);
							savedScorePlayer = maxAmount;
						}
						else
						{
							cout << nameAi << "'s score is higher than " << numberToReach << endl;
							cout << "Sorry... " << endl;
							Sleep(2000);
							savedScoreAi = maxAmount;
							system("cls");
						}
						gettingCards++;
					}
				}
				#pragma endregion
			}
			#pragma region Win conditions
			if (savedScorePlayer > numberToReach)
			{
				savedScorePlayer = 0;
			}
			if (savedScoreAi > numberToReach)
			{
				savedScoreAi = 0;
			}

			if (savedScorePlayer > savedScoreAi) {
				cout << namePlayer << " wins this round";
				goldPlayer += goldPlayerGamble;
				goldAi -= goldAiGamble;
			}
			else if (savedScorePlayer == savedScoreAi) {
				cout << "It's a tie!!!";
			}
			else {
				cout << nameAi << " wins this round";
				goldPlayer -= goldPlayerGamble;
				goldAi += goldAiGamble;
			}
			cout << endl;

			savedScorePlayer = 0;
			savedScoreAi = 0;
			system("pause");
			system("cls");
			#pragma endregion
		}
	}
}

void scoreboard(int round, int chosenCard, int maxAmount, int numberToReach, int savedScorePlayer, int goldPlayer, int goldAi, int goldPlayerGamble, int goldAiGamble, string type, string pictureCards, string namePlayer, string nameAi, bool playerInGame, bool AiInGame) {
	

	if (playerInGame == true) {
		cout << namePlayer << " Round: " << round << " | Gold: $" << goldPlayer << " | Gambled: " << goldPlayerGamble << endl;
		cout << "-----------------------" << endl << endl;
		Sleep(600);
		if (chosenCard == 10)
			cout << "You got a: \t\"" << chosenCard << " (" << pictureCards << ")" << " of " << type << "\"" << endl;
		else
			cout << "You got a: \t\"" << chosenCard << " of " << type << "\"" << endl;
		
		cout << "Your score: \t " << maxAmount << " / " << numberToReach << endl << endl;
		cout << "-----------------------" << endl << endl;
	}
	else
	{
		cout << nameAi << " Round: " << round << " | Gold: $" << goldAi << " | Gambled: " << goldAiGamble << endl;
		cout << "-----------------------" << endl << endl;
		Sleep(600);
		cout << namePlayer << "'s score to beat: " << savedScorePlayer << endl << endl;
		cout << "-----------------------" << endl << endl;
		if (chosenCard == 10)
			cout << nameAi << " got a: \t\"" << chosenCard << " (" << pictureCards << ")" << " of " << type << "\"" << endl;
		else
			cout << nameAi << " got a: \t\"" << chosenCard << " of " << type << "\"" << endl;
		cout << nameAi << "'s score: \t " << maxAmount << " / " << numberToReach << endl << endl;
		cout << "-----------------------" << endl << endl;
	}
	Sleep(600);
}

int rng() {
	int numberMin{1};
	int numberMax{4};
	int randomNumber{};

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> RNG(numberMin, numberMax);
	randomNumber = RNG(gen);

	return randomNumber;
}