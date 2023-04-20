
#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2




/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {
        int i,j;
      for(j=0;j<6;j++){
      for(i=0;i<7;i++){
        gameBoard[j][i] = EMPTY;
        }
        }
    // TODO : Complete this part

}



/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {
          int i,j;
      for(j=0;j<6;j++){
      for(i=0;i<7;i++){
        if(gameBoard[j][i]==CIRCLE){
          printf("|O");






        }
        if(gameBoard[j][i]==EMPTY){
          printf("| ");

        }
        if(gameBoard[j][i]==CROSS){
          printf("|X");

        }

        }
        printf("|\n");


    // TODO : Complete this part

}
printf(" 1 2 3 4 5 6 7 ");
printf("\n");
}


/* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {
    int x,i;
    scanf("%d", &x);
    if(x<1||x>7){
        printf("Input out of range. Please input again:\n");
        placeMarkByHumanPlayer(gameBoard, mark);
    }

    else if(gameBoard[0][x-1]!=EMPTY){
      printf("Column is full. Please input again:\n");
      placeMarkByHumanPlayer(gameBoard, mark);

    }
    else {
      x= x-1;


  if(mark==CIRCLE){
    for(i=5;i>=0;i--){
        if (gameBoard[i][x]==EMPTY){
             gameBoard[i][x]=CIRCLE;
             break;

            }
}
  }
  if(mark==CROSS){
        for(i=5;i>=0;i--){
        if (gameBoard[i][x]==EMPTY){
             gameBoard[i][x]=CROSS;
             break;

            }}



}
      }

  }


    // TODO : Complete this part





/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){
    int i,j;
  for(i=0;i<6;i++){
    for(j=0;j<4;j++){
        if(gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2]&&gameBoard[i][j+2]==gameBoard[i][j+3]&&gameBoard[i][j]!=EMPTY){
            return 1;
        }

    }
  }
  for(i=0;i<3;i++){
    for(j=0;j<7;j++){
          if((gameBoard[i][j]==gameBoard[i+1][j]&&gameBoard[i+1][j]==gameBoard[i+2][j]&&gameBoard[i+2][j]==gameBoard[i+3][j])&&gameBoard[i][j]!=EMPTY){
            return 1;
        }

    }
  }
  for(i=0;i<3;i++){
    for(j=0;j<4;j++){
    if(gameBoard[i][j]==gameBoard[i+1][j+1]&&gameBoard[i+1][j+1]==gameBoard[i+2][j+2]&&gameBoard[i+2][j+2]==gameBoard[i+3][j+3]&&gameBoard[i][j]!=EMPTY){
        return 1;
    }
        }

    }


    for(i=0;i<3;i++){
        for(j=6;j>=3;j--){
            if(gameBoard[i][j]==gameBoard[i+1][j-1]&&gameBoard[i+1][j-1]==gameBoard[i+2][j-2]&&gameBoard[i+2][j-2]==gameBoard[i+3][j-3]&&gameBoard[i][j]!=EMPTY){
               return 1;
               }
        }
    }
    return 0;
  }
    // TODO : Complete this part





/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {
     int i,j, full=0;
     for(i=0;i<6;i++){
       for(j=0;j<7;j++){
         if(gameBoard[i][j]!= EMPTY){
             full++;
         }

     }
     if(full==42){
         return 1;
     }
     else return 0;


 }
    // TODO : Complete this part

}



/* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */

// TODO : Write the placeMarkByComputerPlayer(...) function here
void placeMarkByComputerPlayer(int gameBoard[6][7], int mark){
  int i,j;
 for(i=5;i>=0;i--){
 for(j=0;j<7;j++){
          if(gameBoard[i][j]==EMPTY){
           gameBoard[i][j]=CROSS;
        if(hasWinner(gameBoard)==1){
            return;

        }
        else{
          gameBoard[i][j]=EMPTY;
        }
          }

       }}
for(j=0;j<7;j++){
for(i=5;i>=0;i--){
  if(gameBoard[i][j]==EMPTY){
  gameBoard[i][j]=CIRCLE;
  if(hasWinner(gameBoard)==1){
    gameBoard[i][j]=CROSS;
    return;
  }
  else{
    gameBoard[i][j]=EMPTY;
    break;
  }
  }
}
}
for(i=5;i>=0;i--){
for(j=6;j>=0;j--){

if(gameBoard[i][j]==EMPTY){
  gameBoard[i][j]=CROSS;
return;
}

}


}

}


/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */


    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid

    printGameBoard(gameBoard);
    if(numOfHumanPlayers==1){
     while(gameContinue==1){

     printf("Player 1's turn:\n");

    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    printGameBoard(gameBoard);
    hasWinner(gameBoard);
    if(hasWinner(gameBoard)==1){
        printf("Congratulations! Player 1 wins!");
        gameContinue=0;
        break;

    }
    if(isFull(gameBoard)==1){
      printf("Draw game.");
      gameContinue=0;
      break;
    }
    printf("Computer's turn:\n");
     placeMarkByComputerPlayer(gameBoard, CROSS);

    printGameBoard(gameBoard);
    hasWinner(gameBoard);
    if(hasWinner(gameBoard)==1){
        printf("Computer wins!");
    gameContinue=0;
    break;
    }
     if(isFull(gameBoard)==1){
      printf("Draw game.");
      gameContinue=0;
      break;




     }
     }
    }
    if(numOfHumanPlayers==2){
   while(gameContinue==1){

    printf("Player 1's turn:\n");

    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    printGameBoard(gameBoard);

    hasWinner(gameBoard);
    if(hasWinner(gameBoard)==1){
        printf("Congratulations! Player 1 wins!");
        gameContinue=0;
        break;

    }
    if(isFull(gameBoard)==1){
      printf("Draw game.");
      gameContinue=0;
      break;
    }

    printf("Player 2's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CROSS);
    printGameBoard(gameBoard);
    hasWinner(gameBoard);
    if(hasWinner(gameBoard)==1){
        printf("Congratulations! Player 2 wins!");
    gameContinue=0;
    break;
    }
     if(isFull(gameBoard)==1){
      printf("Draw game.");
      gameContinue=0;
      break;
    }
   }
   }








    /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    //printGameBoard(gameBoard);
    //printf("Player 1's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CIRCLE);
    //printGameBoard(gameBoard);
    //printf("Player 2's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CROSS);
    //printGameBoard(gameBoard);

    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part

    return 0;

}
