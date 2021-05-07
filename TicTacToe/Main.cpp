#include <iostream>
#include <string_view>
#include <vector>
#include <algorithm>

struct Player {
	std::vector<int> playerMoves{};
	bool isPlayer1{};
	bool won{};
	int playerVictories{};
};

void greeting() {
	std::cout << "Welcome to Tic Tac Toe Game!\n";
	std::cout << "-----------------------------------------\n";
}

std::vector<std::vector<char>> createGrid() {
	std::vector<std::vector<char>> grid{ {{' '}, {'1'}, {' '}, {'|'}, {' '}, {'2'}, {' '}, {'|'}, {' '}, {'3'}, {' '}, {'\n'}},
										 {{'-'}, {'-'}, {'-'}, {'|'}, {'-'}, {'-'}, {'-'}, {'|'}, {'-'}, {'-'}, {'-'}, {'\n'}},
										 {{' '}, {'4'}, {' '}, {'|'}, {' '}, {'5'}, {' '}, {'|'}, {' '}, {'6'}, {' '}, {'\n'}},
										 {{'-'}, {'-'}, {'-'}, {'|'}, {'-'}, {'-'}, {'-'}, {'|'}, {'-'}, {'-'}, {'-'}, {'\n'}},
										 {{' '}, {'7'}, {' '}, {'|'}, {' '}, {'8'}, {' '}, {'|'}, {' '}, {'9'}, {' '}, {'\n'}}};
	return grid;
}

void printGrid(const std::vector<std::vector<char>> &grid) {
	for (const auto line: grid) {
		for (auto item : line) {
			std::cout << item;
		}
	}
}

void printChoices(const std::vector<int>& moves) {
	std::cout << "Player moves: ";
	for (auto i : moves) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}

bool isFree(int choice, std::vector<int> &spaces) {
	for (int i{ 0 }; i < choice; ++i) {
		if (choice == spaces.at(i)) {
			spaces.at(i) = 0;
			return true;
		}
	}
	return false;
}

void makeMove(std::vector<int>& moves, std::vector<int>& spaces) {
	
	int choice{};
	bool checkSpace{};

	while (choice < 1 || choice > 9 || checkSpace == false) {
		std::cout << "\nPick a tile: ";
		std::cin >> choice;
		
		if (choice >= 1 && choice <=9) {
			checkSpace = isFree(choice, spaces);
		}

		if (choice < 1 || choice > 9 || checkSpace == false) {
			std::cout << "Invalid choice pick again... \n";
		}

		if (checkSpace == true) {
			moves.push_back(choice);
		}
	}
}

void updateGrid(std::vector<std::vector<char>>& grid, Player &player) {
	
	//std::sort(player.playerMoves.begin(), player.playerMoves.end());

	for (auto choice : player.playerMoves) {
		if (choice >=1 && choice <=3) {
			if (choice == 1) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[0][i] == 49) {
						if (player.isPlayer1 == true) {
							grid[0][i] = 'X';
						}
						else { 
							grid[0][i] = 'O'; 
						};
						break;
					}
				}
			}

			if (choice == 2) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[0][i] == 50) {
						if (player.isPlayer1 == true) {
							grid[0][i] = 'X';
						}
						else {
							grid[0][i] = 'O';
						};
						break;
					}
				}
			}

			if (choice == 3) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[0][i] == 51) {
						if (player.isPlayer1 == true) {
							grid[0][i] = 'X';
						}
						else {
							grid[0][i] = 'O';
						};
						break;
					}
				}
			}
		}

		if (choice >= 4 && choice <= 6) {
			if (choice == 4) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[2][i] == 52) {
						if (player.isPlayer1 == true) {
							grid[2][i] = 'X';
						}
						else {
							grid[2][i] = 'O';
						};
						break;
					}
				}
			}

			if (choice == 5) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[2][i] == 53) {
						if (player.isPlayer1 == true) {
							grid[2][i] = 'X';
						}
						else {
							grid[2][i] = 'O';
						};
						break;
					}
				}
			}

			if (choice == 6) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[2][i] == 54) {
						if (player.isPlayer1 == true) {
							grid[2][i] = 'X';
						}
						else {
							grid[2][i] = 'O';
						};
						break;
					}
				}
			}
		}

		if (choice >= 7 && choice <= 9) {
			if (choice == 7) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[4][i] == 55) {
						if (player.isPlayer1 == true) {
							grid[4][i] = 'X';
						}
						else {
							grid[4][i] = 'O';
						};
						break;
					}
				}
			}

			if (choice == 8) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[4][i] == 56) {
						if (player.isPlayer1 == true) {
							grid[4][i] = 'X';
						}
						else {
							grid[4][i] = 'O';
						};
						break;
					}
				}
			}

			if (choice == 9) {
				for (int i{ 0 }; i <= 11; ++i) {
					if (grid[4][i] == 57) {
						if (player.isPlayer1 == true) {
							grid[4][i] = 'X';
						}
						else {
							grid[4][i] = 'O';
						};
						break;
					}
				}
			}
		}
	}
}

void printPlayerScore(Player &player1, Player &player2) {
	std::cout << "Player 1 wins: " << player1.playerVictories << "\n";
	std::cout << "Player 2 wins: " << player2.playerVictories << "\n";
}

bool victory(Player &player) {
	

	std::vector <int> plays{ {123}, {147}, {159}, {258}, {357}, {369}, {456}, {789}, 
							 {1234}, {1235}, {1236}, {1237}, {1238}, {1239}, {1247}, 
							 {1258}, {1259}, {1347}, {1357}, {1359}, {1369}, {1456}, 
							 {1457}, {1459}, {1467}, {1478}, {1479}, {1569}, {1579}, 
							 {1589}, {1789}, {2357}, {2358}, {2369}, {2456}, {2458}, 
							 {2568}, {2578}, {2589}, {2789}, {3456}, {3457}, {3469}, 
							 {3567}, {3569}, {3578}, {3579}, {3679}, {3689}, {3789}, 
							 {4567}, {4568}, {4569}, {4789}, {5789}, {6789}, {12345}, 
							 {12346}, {12348}, {12349}, {12356}, {12367}, {12368}, 
							 {12378}, {12379}, {12389}, {12457}, {12458}, {12459}, 
							 {12467}, {12478}, {12479}, {12568}, {12569}, {12578}, 
							 {12579}, {13459}, {13467}, {13469}, {13478}, {13479}, 
							 {13567}, {13578}, {13589}, {13679}, {13689}, {14568}, 
							 {14578}, {14589}, {14678}, {14679}, {15679}, {15689}, 
							 {16789}, {23457}, {23458}, {23469}, {23567}, {23568}, 
							 {23569}, {23579}, {23589}, {23679}, {23689}, {24567}, 
							 {24569}, {24578}, {24589}, {24789}, {25678}, {25689}, 
							 {26789}, {34568}, {34578}, {34579}, {35678}, {34679}, 
							 {34689}, {34789}, {35689} };
	
	unsigned int playlength{ plays.size() };
	bool draw{};

	if (player.playerMoves.size() >= 3) {
		std::sort(player.playerMoves.begin(), player.playerMoves.end());
		
		int playCode{};
		for (auto d : player.playerMoves) {
			playCode = playCode * 10 + d;
		}

		for (int i{ 0 }; i < playlength; i++) {
			if (playCode == plays[i]) {
				std::cout << "Congrats you won!\n";
				player.won = true;
				player.playerVictories += 1;
				return true;
			}

			if (playCode != plays[i] && player.playerMoves.size() >= 5) {
				draw = true;
			}
		}

		if (player.playerMoves.size() >= 5 && draw == true) {
			std::cout << "The Game was a draw!\n";
			return true;
		}
	}
	return false;
}

bool anotherGame() {
	char choice{};
	bool valid{};

	while (valid != true) {

		std::cin >> choice;

		switch (choice) {
		case 'Y':
		case 'y':
			valid = true;
			return true;
		case 'N':
		case 'n':
			valid = true;
			return false;
		default:
			valid = false;
			std::cout << "Invalid input, try again\n";
		}
	}
}

void resetPlayers(Player &player1, Player &player2) {
	player1.playerMoves.clear();
	player1.won = false;
	player2.playerMoves.clear();
	player2.won = false;
}

void gameStart() {

	Player player1{};
	player1.isPlayer1 = true;
	Player player2{};
	player2.isPlayer1 = false;
	bool gameContinue{true};

	while (gameContinue != false) {

		//Should reset grid and free spaces here
		std::vector<std::vector<char>> grid{ createGrid() };
		std::vector<int>spaces{ 1,2,3,4,5,6,7,8,9 };

		bool winner{};
		printGrid(grid);

		while (!winner) {

			if (!winner) {
				makeMove(player1.playerMoves, spaces);
				updateGrid(grid, player1);
				winner = victory(player1);
				printGrid(grid);
			}

			if (!winner) {
				makeMove(player2.playerMoves, spaces);
				updateGrid(grid, player2);
				winner = victory(player2);
				printGrid(grid);
			}
		}
		printPlayerScore(player1, player2);
		resetPlayers(player1, player2);
		std::cout << "Another Game? Y/N: ";
		gameContinue = anotherGame();
		std::cout << "\n----------------------------------------------\n";
	}
}

int main() {
	greeting();
	gameStart();
	return 0;
 }