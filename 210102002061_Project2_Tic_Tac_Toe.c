#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "210102002061_Project2_Tic_Tac_Toe.h"


char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


void initialize_Game_Board() {
    printf("%c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("--------------\n");
    printf("%c  |  %c  |  %c \n", board[3], board[4], board[5]);
    printf("--------------\n");
    printf("%c  |  %c  |  %c \n", board[6], board[7], board[8]);
}

void update_Game_Board(int cell_number, char symbol) {
    board[cell_number-1] = symbol;   
}

void show_Game_Board() {
    int cell_number;
    char symbol;
    printf("Please choose a cell number (1-9): ");
    scanf("%d", &cell_number);
    printf("Please enter a symbol (X or O): ");
    scanf(" %c", &symbol); 
    if(cell_number < 1 || cell_number > 9 || (symbol != 'O' && symbol != 'X')){
        printf("WARNINGS : Please enter a valid number (1-9) and symbol (O or X)\n");
        show_Game_Board(); 
    } 
    else if (board[cell_number-1]==88 || board[cell_number-1]==79){
        printf("cell is not empty.please enter again  new number of cell .\n ");
        show_Game_Board();
    }
    else{
        update_Game_Board(cell_number,symbol);
    }

}

int check_for_Win(){

    int wins=0 ;
    for(int i=0;i<7; i+=3 ){
        if (board[i] == board[i+1] && board[i+1] == board[i+2]) {
        wins=board[i];
    }   
    }
    for(int i=0;i<3; i++ ){
        if (board[i] == board[i+3] && board[i+3] == board[i+6]) {
        wins=board[i];
    }   
    }

    if((board[0]==board[4] && board[4]==board[8]) || (board[2]==board[4] && board[4]==board[6])){
        wins=board[4];

    }
    

    return wins;
}

void start_Game(){
    char yes_no[5];
    printf("Do you want to play Tic Tac Toe game again ?\n");
    scanf("%s", yes_no);
    
    if(strcmp(yes_no, "yes") == 0){
        printf("Starting....\n \nWelcome to Tic Tac Toe game!\n\n");
        char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        initialize_Game_Board();
    }
    else if (strcmp(yes_no, "no") == 0){
        printf("Goodbye!");
    }
    else {
        printf("Please enter 'yes' or 'no'\n");
        start_Game();
    }
}


