#include <iostream> 


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

int main() {

	return 0 ;
} 
