/*
Atif Ahmad
Lab 3
*/

#include <iostream>
#include <random>
using namespace std;

int main()
{
	cout << "Pokemon: Mewtowo vs. Clefairy Battle" << endl;
	cout << "This is a game of Pokemon. This is a Pokemon battle. You are a Level 70 Mewtwo\nfighting against your opponent,"
		<< " a Level 80 Clefairy. The object of of the game is\neither defeat your opponent or catach your opponent. At each part of the game, \n"
		<< "you\'ll get to choose your action from a list of actions. The game ends if you\nfainted or you chose to quit the game." << endl;
	cout << endl;
	cout << "HP stands for hit points. It works the same way as a health meter. If an\nindividual\'s HP reaches zero (HP = 0), the"
		<< " individual has fainted." << endl;
	cout << endl;
	cout << "If you choose to attack, choose a a particular attack move (such as Psychic) to\ndamage your opponent. When the opponent is "
		<< "damaged, the opponent\'s HP goes down.\nThe opponent will try to attack you and lower your HP. If you defeat the\nopponent,"
		<< " you win the battle. Similarly, if the opponent defeats you, you lose\nthe battle." << endl;
	cout << endl;
	cout << "If you choose to use a Poke Ball, you will be given 2 types of Poke Balls. The\nnormal Poke Ball will try to capture your"
		<< " opponent with a low probability. The\nlower the opponent\'s HP is, the higher the probability of catching the opponent.\n"
		<< "You have unlimited Poke Balls. The other type of Poke Ball available is the\nMaster Ball. The Master Ball is a kind of Poke"
		<< " Ball that has a 100% chance of\ncapturing the opponent. This is to be used if you are in a terrible situation\nand want to"
		<< " capture the opponent. To get the most fun out of capturing the\nopponent, try to catch using Poke Balls and use the Master"
		<< " Ball in a terrible\nsituation." << endl;
	cout << endl;
	cout << "Have fun with the game!" << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	const int YOUR_ORIGINAL_HP = 239;
	const int OPPONENTS_ORIGINAL_HP = 214;
	int yourHP = YOUR_ORIGINAL_HP;
	int yourOpponentsHP = OPPONENTS_ORIGINAL_HP;
	int input;
	int attackInput;
	int usePokeBallInput;
	bool errorOccurred;
	do {
		cout << "Character                                                                             Current HP/Orignal HP" << endl;
		cout << "---------                                                                             ---------------------" << endl;
		cout << "Mewtwo                                                                                              "
			<< yourHP << "/" << YOUR_ORIGINAL_HP << endl;
		cout << "Clefairy                                                                                            "
			<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;

		cout << endl;
		cout << "1) Attack." << endl;
		cout << "2) Use Poke Ball." << endl;
		cout << "3) Quit the battle." << endl;
		cout << endl;

		do{
			cout << "Choose the number of the action you would like: ";
			cin >> input;
			errorOccurred = input < 1 || (input > 1 && input < 2) || (input > 2 && input < 3) || input > 3 || cin.fail();

			if (errorOccurred)
			{
				cout << "You have to choose a valid number." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (errorOccurred);

			switch (input)
			{
			case 1:
			{
				cout << endl;
				cout << "1) Psychic" << endl;
				cout << "2) Blizzard" << endl;
				cout << "3) Thunderbolt" << endl;
				cout << "4) Fire Blast" << endl;
				cout << endl;

				do{
					cout << "Choose the number of the attack you would like: ";
					cin >> attackInput;
					errorOccurred = attackInput < 1 || (attackInput > 1 && attackInput < 2) || (attackInput > 2 && attackInput < 3)
						|| (attackInput >3 && attackInput < 4) || attackInput > 4 || cin.fail();

					if (errorOccurred)
					{
						cout << "You have to choose a valid number." << endl;
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
				} while (errorOccurred);

				if (attackInput == 1)
				{
					yourOpponentsHP -= 60;
					cout << "Mewtwo used Physic on Clefairy!" << endl;
					if (yourOpponentsHP <= 0)
					{
						cout << endl;
						cout << "Character                                                                             Current HP/Orignal HP" << endl;
						cout << "---------                                                                             ---------------------" << endl;
						cout << "Mewtwo                                                                                              "
							<< yourHP << "/" << YOUR_ORIGINAL_HP << endl;
						cout << "Clefairy                                                                                            "
							<< 0 << "/" << OPPONENTS_ORIGINAL_HP << endl;
						cout << endl;
						cout << "Clefairy has fainted! You have won the battle!" << endl;
						cout << endl;
						system("pause");
						return 0;
					}

					random_device rd;
					mt19937 gen(rd()); // Mersenne Twister
					// 2 ^ 19937 prime number
					uniform_int_distribution<int> dist(1, 4);
					int randomNumber = dist(gen);

					if (randomNumber == 1)
					{
						yourHP -= 40;
						cout << "Clefairy used Body Slam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 2)
					{
						yourHP -= 30;
						cout << "Clefairy used Thunder on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 3)
					{
						yourHP -= 20;
						cout << "Clefairy used Strength on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
					else if (randomNumber == 4)
					{
						yourHP -= 25;
						cout << "Clefairy used Ice Beam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
				}

				if (attackInput == 2)
				{
					yourOpponentsHP -= 35;
					cout << "Mewtwo used Blizzard on Clefairy!" << endl;
					if (yourOpponentsHP <= 0)
					{
						cout << endl;
						cout << "Character                                                                             Current HP/Orignal HP" << endl;
						cout << "---------                                                                             ---------------------" << endl;
						cout << "Mewtwo                                                                                              "
							<< yourHP << "/" << YOUR_ORIGINAL_HP << endl;
						cout << "Clefairy                                                                                            "
							<< 0 << "/" << OPPONENTS_ORIGINAL_HP << endl;
						cout << endl;
						cout << "Clefairy has fainted! You have won the battle!" << endl;
						cout << endl;
						system("pause");
						return 0;
					}

					random_device rd;
					mt19937 gen(rd()); // Mersenne Twister
					// 2 ^ 19937 prime number
					uniform_int_distribution<int> dist(1, 4);
					int randomNumber = dist(gen);

					if (randomNumber == 1)
					{
						yourHP -= 40;
						cout << "Clefairy used Body Slam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 2)
					{
						yourHP -= 30;
						cout << "Clefairy used Thunder on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 3)
					{
						yourHP -= 20;
						cout << "Clefairy used Strength on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
					else if (randomNumber == 4)
					{
						yourHP -= 25;
						cout << "Clefairy used Ice Beam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
				}

				if (attackInput == 3)
				{
					yourOpponentsHP -= 40;
					cout << "Mewtwo used Thunderbolt on Clefairy!" << endl;
					if (yourOpponentsHP <= 0)
					{
						cout << endl;
						cout << "Character                                                                             Current HP/Orignal HP" << endl;
						cout << "---------                                                                             ---------------------" << endl;
						cout << "Mewtwo                                                                                              "
							<< yourHP << "/" << YOUR_ORIGINAL_HP << endl;
						cout << "Clefairy                                                                                            "
							<< 0 << "/" << OPPONENTS_ORIGINAL_HP << endl;
						cout << endl;
						cout << "Clefairy has fainted! You have won the battle!" << endl;
						cout << endl;
						system("pause");
						return 0;
					}

					random_device rd;
					mt19937 gen(rd()); // Mersenne Twister
					// 2 ^ 19937 prime number
					uniform_int_distribution<int> dist(1, 4);
					int randomNumber = dist(gen);

					if (randomNumber == 1)
					{
						yourHP -= 40;
						cout << "Clefairy used Body Slam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 2)
					{
						yourHP -= 30;
						cout << "Clefairy used Thunder on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 3)
					{
						yourHP -= 20;
						cout << "Clefairy used Strength on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
					else if (randomNumber == 4)
					{
						yourHP -= 25;
						cout << "Clefairy used Ice Beam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
				}

				if (attackInput == 4)
				{
					yourOpponentsHP -= 30;
					cout << "Mewtwo used Fire Blast on Clefairy!" << endl;
					if (yourOpponentsHP <= 0)
					{
						cout << endl;
						cout << "Character                                                                             Current HP/Orignal HP" << endl;
						cout << "---------                                                                             ---------------------" << endl;
						cout << "Mewtwo                                                                                              "
							<< yourHP << "/" << YOUR_ORIGINAL_HP << endl;
						cout << "Clefairy                                                                                            "
							<< 0 << "/" << OPPONENTS_ORIGINAL_HP << endl;
						cout << endl;
						cout << "Clefairy has fainted! You have won the battle!" << endl;
						cout << endl;
						system("pause");
						return 0;
					}

					random_device rd;
					mt19937 gen(rd()); // Mersenne Twister
					// 2 ^ 19937 prime number
					uniform_int_distribution<int> dist(1, 4);
					int randomNumber = dist(gen);

					if (randomNumber == 1)
					{
						yourHP -= 40;
						cout << "Clefairy used Body Slam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 2)
					{
						yourHP -= 30;
						cout << "Clefairy used Thunder on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber == 3)
					{
						yourHP -= 20;
						cout << "Clefairy used Strength on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
					else if (randomNumber == 4)
					{
						yourHP -= 25;
						cout << "Clefairy used Ice Beam on Mewtwo!" << endl;
						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;
					}
				}

				break;
			}

			case 2:
			{
				cout << endl;
				cout << "1) Use Poke Ball." << endl;
				cout << "2) Use Master Ball." << endl;
				cout << endl;

				do{
					cout << "Choose the number of the action you would like: ";
					cin >> usePokeBallInput;
					errorOccurred = usePokeBallInput < 1 || (usePokeBallInput > 1 && usePokeBallInput < 2) || usePokeBallInput > 2
						|| cin.fail();

					if (errorOccurred)
					{
						cout << "You have to choose a valid number." << endl;
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
				} while (errorOccurred);

				if (usePokeBallInput == 1)
				{
					random_device rd;
					mt19937 gen(rd()); // Mersenne Twister
					// 2^ 19937 prime number
					uniform_int_distribution<int> dist(1, OPPONENTS_ORIGINAL_HP);
					uniform_int_distribution<int> dist2(1, 4);
					int randomNumber = dist(gen);
					int randomNumber2 = dist2(gen);

					cout << "You threw a Poke Ball at Clefairy! Clefairy is striggling to get free!" << endl;
					if (randomNumber >= yourOpponentsHP)
					{
						cout << "Clefairy couldn't get out of the Poke Ball." << endl;
						cout << "COngratulations! You have caught Clefairy!" << endl;
						cout << endl;
						system("pause");
						return 0;
					}
					else
					{
						cout << "Oh no! Clefairy broke free from the Poke Ball." << endl;
						cout << endl;
					}

					if (randomNumber2 == 1)
					{
						yourHP -= 40;
						cout << "Clefairy used Body Slam on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber2 == 2)
					{
						yourHP -= 30;
						cout << "Clefairy used Thunder on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber2 == 3)
					{
						yourHP -= 20;
						cout << "Clefairy used Strength on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}
					else if (randomNumber2 == 4)
					{
						yourHP -= 25;
						cout << "Clefairy used Ice Beam on Mewtwo!" << endl;

						if (yourHP <= 0)
						{
							cout << endl;
							cout << "Character                                                                             Current HP/Orignal HP" << endl;
							cout << "---------                                                                             ---------------------" << endl;
							cout << "Mewtwo                                                                                              "
								<< 0 << "/" << YOUR_ORIGINAL_HP << endl;
							cout << "Clefairy                                                                                            "
								<< yourOpponentsHP << "/" << OPPONENTS_ORIGINAL_HP << endl;
							cout << endl;
							cout << "Mewtwo have fainted! You have lost the battle!" << endl;
							cout << endl;
							system("pause");
							return 0;
						}

						cout << endl;

					}

				}

				if (usePokeBallInput == 2)
				{
					cout << endl;
					cout << "You threw a Master Ball at Clefairy! Clefairy is struggling to get free!" << endl;
					cout << "Clefairy couldn\'t get out of the Master Ball." << endl;
					cout << "Congratulations! You have caught Clefairy!" << endl;
					cout << endl;
					system("pause");
					return 0;
				}

				break;
			}

			case 3:
			{
				cout << endl;
				cout << "You have quit the battle!" << endl;
				break;
			}

		}

				
			
	} while (input != 3);

	cout << endl;
	system("pause");
	return 0;
}