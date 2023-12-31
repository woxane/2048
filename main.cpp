#include <iostream> 
#include "utils.h"


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
	// XXX The final version has the random board game 
    int ExampleBoardGame[4][4] = {{0, 0, 0, 0}, {2, 0, 0, 2}, {16, 0, 0, 0}, {0, 0, 2, 16}};		

	while (true) {
		Cls() ; 
		DrawBoard(ExampleBoardGame) ; 
		char Input = Getch() ; 

		if (Input == 'w') {
			UpShift(ExampleBoardGame) ; 

		} else if (Input == 'a') {
			LeftShift(ExampleBoardGame) ; 

		} else if (Input == 's') {
			downShift(ExampleBoardGame) ; 

		} else if (Input == 'd') {
			RightShift(ExampleBoardGame) ; 

		} else {
			return ; 
		}

	}


} 


int main() {

	return 0 ;
} 
