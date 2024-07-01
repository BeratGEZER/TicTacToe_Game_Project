#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "210102002061_Project2_Tic_Tac_Toe.h"
#include "210102002061_Project2_Tic_Tac_Toe.c"

char roll_board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


int main() {
	int cell_number;
	char symbol;
	int control=1;

	printf("Welcome to Tic Tac Toe game!\n\n");
	
	initialize_Game_Board();

	while (control) {
		show_Game_Board();
		initialize_Game_Board();    
		check_for_Win();
		if(check_for_Win()!=0){
			control=0;
		}        
	}

	printf("Player %c wins!\n", check_for_Win());

	start_Game();


	return 0;
}
