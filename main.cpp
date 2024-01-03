#include <iostream> 
#include <random> 
#include <chrono>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include "utils.h"

int MAIN_NUMBERS[4] = {2,2,2,4} ;

//LB = Leaderboard
struct LB {
	std::string name ;
	int score ;
} ;


int Score(int Board[4][4]) {
	int Sum = 0 ; 
	for (int i = 0 ; i < 4 ; i++) {
		for (int j = 0 ; j < 4 ; j++) {
			Sum += Board[i][j] ; 
		}
	}

	return Sum ; 
}


void LeaderboardAdd(LB Data) {
	std::ofstream Leaderboard("Leaderboard.txt" , std::ios::app) ;

	if (!Leaderboard){
        std::cerr << "FILE ERROR !";
        return ;
    } 

	Leaderboard << Data.score << " " << Data.name << '\n'; 

	return ;  
}

bool Compare(const LB& a, const LB& b) {
    return a.score > b.score; // sort in descending order of score
}


void LeaderboardRead() {
	// Assume that the name of the file is Leaderboard.txt
	int size = 0 ; 
	LB *Scores = nullptr ; 

	std::ifstream Leaderboard("Leaderboard.txt") ;

	if (!Leaderboard){
        std::cerr << "FILE ERROR !";
        return ;
    } 


	LB Data ;

	while (Leaderboard >> Data.score >> Data.name ) {
		LB *Temp = new LB[size + 1] ; 

		for (int i = 0 ; i < size ; i++) {
			Temp[i] = Scores[i] ; 
		}
		
		Temp[size] = Data ; 

		delete[] Scores ; 

		size++ ; 

		Scores = new LB[size] ; 

		for (int i = 0 ; i < size ; i++) {
			Scores[i] = Temp[i] ; 
		}

		delete[] Temp ; 
	}

	if (size == 0) {
		std::cout << "There isn't any saved match for you !" << std::endl ; 	
		return ; 

	}

	std::sort(&Scores[0] , &Scores[size] , Compare) ; 

	for (int i = 1 ; i <= size ; i++) {
		std::cout << i << ") " <<  Scores[i - 1].name << " " << Scores[i - 1].score  << std::endl ; 

	}


	Leaderboard.close() ; 
	delete[] Scores ; 

	return ; 

}


int RandomNumber() {
	std::mt19937 Generate(static_cast<std::mt19937::result_type>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count()
		));

	std::uniform_int_distribution<int> Index(0 , 3);	
	int RandomIndex = Index(Generate) ; 

	return MAIN_NUMBERS[RandomIndex] ; 

}

void RandomBoard(int Board[4][4], int Times = 2) {
    int size = 0;
    int** EmptyLocs = nullptr;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Board[i][j] == 0) {
                int** Temp = new int*[size + 1];

                for (int x = 0; x < size; x++) {
                    Temp[x] = new int[2];
                    for (int y = 0; y < 2; y++) {
                        Temp[x][y] = EmptyLocs[x][y];
                    }
                    delete[] EmptyLocs[x];
                }
                Temp[size] = new int[2];
                Temp[size][0] = i;
                Temp[size][1] = j;

                delete[] EmptyLocs;

                size++;

                EmptyLocs = new int*[size];
                for (int x = 0; x < size; x++) {
                    EmptyLocs[x] = new int[2];
                    for (int y = 0; y < 2; y++) {
                        EmptyLocs[x][y] = Temp[x][y];
                    }
                    delete[] Temp[x];
                }

                delete[] Temp;
            }
        }
    }


	for (int time = 0 ; time < Times ; time++) {
		std::mt19937 Generate(static_cast<std::mt19937::result_type>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count()
		));

		std::uniform_int_distribution<int> Index(0 , size - 1);
		int RandomIndex = Index(Generate) ;

		int* RandomLoc = new int[2];
		RandomLoc[0] = EmptyLocs[RandomIndex][0];
		RandomLoc[1] = EmptyLocs[RandomIndex][1];

		Board[RandomLoc[0]][RandomLoc[1]] = RandomNumber();


	}


    for (int i = 0; i < size; i++) {
        delete[] EmptyLocs[i];
    }
    delete[] EmptyLocs;
}


void RightShift(int Board[4][4]) {
	for (int Row = 0; Row < 4; Row++) {
		int Pos = 0;

		for (int i = 3; i >= 0; --i) {
			if (Board[Row][i] != 0 && i != 3) {
				Board[Row][3 - Pos] = Board[Row][i]; 

				if (3 - Pos != i) {
					Board[Row][i] = 0 ;
				}
				Pos++ ;
			}
			else if (Board[Row][i] != 0){
				Pos++ ;
			}
		}
	}
}


void RightSum(int Board[4][4]) {
	for (int i = 0 ; i < 4 ; i++) {
		for (int j = 3 ; j > 0 ; j--) {
			if (Board[i][j] == Board[i][j - 1] & Board[i][j] != 0) {
				Board[i][j] *= 2 ;
				Board[i][j - 1] = 0 ;
			}
		}
	}
}


void LeftShift(int Board[4][4]) {
    for (int Row = 0 ; Row < 4 ; Row++) {
        int Pos = 0; 

        for (int i = 0; i < 4; ++i) {
            if (Board[Row][i] != 0 && i != 0) {
                Board[Row][Pos] = Board[Row][i];
                if (Pos != i) {
                    Board[Row][i] = 0;
                }
                Pos++; 

            } else if (Board[Row][i] != 0) {
                Pos++;
            }
        }
    }
}

void (LeftSum(int Board[4][4])) {
	for (int i = 0 ; i < 4 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			if (Board[i][j] == Board[i][j + 1] & Board[i][j] != 0) {
				Board[i][j] *= 2 ; 
				Board[i][j + 1] = 0 ;
			}	
		}
	}
}



void UpShift(int Board[4][4]) {
    for (int j = 0 ; j < 4 ; j++) {
        int Column[4] ;
		
        for (int i = 0 ; i < 4 ; i++) {
            Column[i] = Board[i][j] ;
        }

        int Pos = 0 ;

        for (int i = 0 ; i < 4 ; i++) {
            if (Column[i] != 0 & i != 0) {
                Column[Pos] = Column[i] ;
                if (Pos != i) {
                    Column[i] = 0 ;
                }
                Pos++ ;
            } else if (Column[i] != 0) {
                Pos++ ;
            }
        }

        for (int x = 0; x < 4; ++x) {
            Board[x][j] = Column[x];
        }
    }

}


void UpSum(int Board[4][4]) {
	for (int Row = 0 ; Row < 4 ; Row++) {
		int Column[4] ; 

		for (int Col = 0 ; Col < 4 ; Col++) {
			Column[Col] = Board[Col][Row] ; 
		}

		for (int j = 0 ; j < 3 ; j++) {
			if (Column[j] == Column[j + 1] & Column[j] != 0 ) {
				Column[j] *= 2 ; 
				Column[j + 1] = 0 ;
			}
		}

		for (int i = 0 ; i < 4 ; i++) {
			Board[i][Row] = Column[i] ;  
		}
	}
}


void downShift(int Board[4][4]) {
    for (int j = 0 ; j < 4 ; j++) {
        int Column[4];

        for (int i = 0 ; i < 4 ; i++) {
            Column[i] = Board[i][j];
        }

        int Pos = 0;

        for (int i = 3 ; i >= 0 ; i--) {
            if (Column[i] != 0 && i != 3) {
                Column[3 - Pos] = Column[i] ;
                if (3 - Pos != i) {
                    Column[i] = 0 ;
                }
                Pos++ ;

            } else if (Column[i] != 0) {
                Pos++ ;
            }
        }

        for (int i = 0 ; i < 4 ; i++) {
            Board[i][j] = Column[i] ;
        }
    }
}

void DownSum(int Board[4][4]) {
	for (int Row = 0 ; Row < 4 ; Row++) {
		int Column[4] ; 

		for (int Col = 0 ; Col < 4 ; Col++) {
			Column[Col] = Board[Col][Row] ; 
		}

		for (int j = 3 ; j > 0 ; j--) {
			if (Column[j] == Column[j - 1] & Column[j] != 0 ) {
				Column[j] *= 2 ; 
				Column[j - 1] = 0 ;  
			}
		}

		for (int i = 0 ; i < 4 ; i++) {
			Board[i][Row] = Column[i] ; 
		}
	} 	
}


void PrintMenu() {
	int WIDTH = 35 ;
	int LENGTH = 9 ; 

	for (int Col = 0 ; Col < LENGTH ; Col++) {
		// Horizontal Line Parts :
		if (Col == 0 | Col == LENGTH / 2 | Col == LENGTH - 1) {
			for (int Row = 0 ; Row < WIDTH ; Row++) {
				if ((WIDTH + 1) / 2 == Row ) { 
					if (Col == 0 ) {
						std::cout << "\u2531" ; 
						continue ; 
						
					} else if (Col == LENGTH / 2) {
						
						std::cout << "\u2538";
						continue ; 

					}

				// Corner Parts : 
				} else if (Row == 0 & Col == 0) { 
					std::cout << "\u250D" ; 
					continue ; 

				} else if (Row == 0 & Col == LENGTH - 1) {
					std::cout << "\u2515" ; 
					continue ; 

				} else if (Row == WIDTH - 1 & Col == 0) {
					std::cout << "\u2511" ;
					continue ; 

				} else if (Row == WIDTH - 1 & Col == LENGTH - 1) {
					std::cout << "\u251B" ; 
					continue ; 

				} else if (Row == WIDTH - 1 & Col == LENGTH / 2) {
					std::cout << "\u2521" ; 
					continue ;

				} else if (Row == 0 & Col ==  LENGTH / 2) {
					std::cout << "\u2529" ; 
					continue ;

				}
			
				if (Row )
				std::cout << "\u2501";
			}

		}

		if (!(Col == 0 | Col == LENGTH / 2 | Col == LENGTH - 1)) {
			//Vertical Line Parts : 

			for (int Row = 0 ; Row < WIDTH ; Row++) {
				if (Row == 0 | Row == (WIDTH + 1 ) / 2 | Row == WIDTH - 1) {
					if (!(Col > LENGTH / 2 & Row == (WIDTH + 1) / 2)) {
						std::cout << "\u2503" ; 
						continue ;
					}
		 		} 

				// Menu : 
				if (Col == 2  & Row < WIDTH / 2) {
					std::cout << "   " << "1. New Game" <<  "  " ; 
					Row += 16 ; 

				} else if (Col == 2 & Row > WIDTH / 2) {
					std::cout << "2. Leaderboard" ;
					Row += 14 ;

				} else if (Col == 6) {
					std::cout << "             " << "3. Exit" << "            " ;
					Row += 32 ;

				}

				std::cout << " " ;

			}
		}

		std::cout << std::endl ; 
	}


}

void DrawBoard(int Board[4][4]) {
	int CUBE_WIDTH = 9 ; 
	int CUBE_LENGTH = 5 ;

	int BOARD_WIDTH = 39 ; // 4 * CUBE_WIDTH + 4 - 1 ; 
	int BOARD_LENGTH = 23 ; // 4 * CUBE_LENGTH + 4 - 1 ;  


	std::cout << std::endl << "Score : " << Score(Board) << std::endl ; 


	for (int Col = 0 ; Col < BOARD_LENGTH ; Col++ ) {
		if (Col % 2 != 0) {
			std::cout << std::endl ; 
			continue ; 
		} 
		for (int Row = 0 ; Row < BOARD_WIDTH ; Row++ ) {

			// Up Part + 
			if (Col % 6 == 0 ) {
				// Left Part 
				if (Row % 10 == 0) {
					std::cout << "\u250F" ; 
				// Right Part 
				} else if (Row % 10 == 8) {
					std::cout << "\u2513" << " " ; 
					Row++ ; 
				// Middle Part 
				} else if (Row % 10 > 0 & Row % 10 < 8) {
					std::cout << "\u2501" ;
				}

			// Mid Part +
			} else if (Col % 6 == 2 ) {
				// Left Part 
				if (Row % 10 == 0) {
					std::cout << "\u2503" ;  
				// Right Part 
				} else if (Row % 10 == 8) {
					std::cout << "\u2503" << " " ;  
					Row++ ; 

				} else {
					int i = Col / 6 ; 
					int j = Row / 10 ; 
					int Num = Board[i][j] ; 
					int NumLength= (std::to_string(Board[i][j])).length() ; 
					
					// WS = White Space 
					int LeftWS = (CUBE_WIDTH - NumLength - 2) / 2 ; 
					int RightWS = CUBE_WIDTH - NumLength - 2 - LeftWS ; 

					for (int temp = 0 ; temp < LeftWS ; temp++) {
						std::cout << " " ; 
						Row++ ; 
					} 
					
					if (Num == 0) {
						std::cout << " " ; 
						Row++ ; 

					} else {
						std::cout << Num ; 
						Row += NumLength ; 
					}

					for (int temp = 0 ; temp < RightWS ; temp++) {
						std::cout << " " ; 
						Row++ ; 
					}

					Row-- ;
				}

			// Down Part +
			} else if (Col % 6 == 4) {
				// Left Part 
				if (Row % 10 == 0) {
					std::cout << "\u2517" ; 
				// Right Part 
				} else if (Row % 10 == 8) {
					std::cout << "\u251B" << " " ; 
					Row++ ;   

				} else if (Row % 10 > 0 & Row % 10 < 8) {
					std::cout << "\u2501" ;
				} 
			} 
			

		}
		std::cout << std::endl ;

	}




}


void NewGame() {
	int BoardGame[4][4] = {{0,0,0,0} , {0,0,0,0} , {0,0,0,0} , {0,0,0,0}} ; 
	RandomBoard(BoardGame) ; 


	while (true) {
		Cls() ; 
		DrawBoard(BoardGame) ; 
		char Input = Getch() ; 

		if (Input == 'w') {
			UpShift(BoardGame) ; 
			UpSum(BoardGame) ; 
			UpShift(BoardGame) ; 

		} else if (Input == 'a') {
			LeftShift(BoardGame) ; 
			LeftSum(BoardGame) ; 
			LeftShift(BoardGame) ; 

		} else if (Input == 's') {
			downShift(BoardGame) ; 
			DownSum(BoardGame) ; 
			downShift(BoardGame) ; 

		} else if (Input == 'd') {
			RightShift(BoardGame) ; 
			RightSum(BoardGame) ; 
			RightShift(BoardGame) ; 

		} else { 
			LB Data ; 
			Data.score = Score(BoardGame) ;  

			std::cout << "Enter your name for the save last update : " ; 
			std::cin >> Data.name ; 

			LeaderboardAdd(Data) ; 
			return ; 
		}

		RandomBoard(BoardGame , 1) ; 


	}


} 


int main() {
	Cls() ; 
	PrintMenu() ; 
	char Choose = Getch() ;

	if (Choose == '1') {
		NewGame() ; 

	} else if (Choose == '2') {
		Cls() ; 
		LeaderboardRead() ; 

	} else if (Choose == '3') {
		return 0 ; 
	} else {
		std::cout << "ERR !" ;
	}



	return 0 ;
} 
