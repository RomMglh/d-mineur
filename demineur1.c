#include "demineur1.h"

void displayboard1(int tab[SIZE1][SIZE1], int size){
//SHOW THE GAME BOARD
	int i, j;
	printf("	|0 |1 |2 |3 |4 |5 |6 |7 |8 |\n	____________________________");
	for(i = 0; i < size; i++){
		printf("\n      %d |", i);
		for(j = 0; j < size; j++){
			if(tab[i][j] == 9 || tab[i][j] == 10){
      				printf("~ |");
      			}
      			if(tab[i][j] == 11){
      				printf("💣️|");
      			}
      			if(tab[i][j] == 12){
      				printf("🚩️|");
      			}
      			if(tab[i][j] < 9){
      				printf("%d |", tab[i][j]);
      			}
    		}
  	}
  	printf("\n\n");
}

void nbminesnext1(int tab[SIZE1][SIZE1], int tab2[SIZE1][SIZE1], int size){
//CREATION OF A BOARD HAVING THE NUMBER OF NEIGHBORING MINES FOR EACH BOX
	int cnt;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cnt = 0;
			if (tab[i][j]!=10){
        	       	 if (tab[i-1][j-1]==10){
        	       	     	cnt++;
        	       	 }
        	       	 if (tab[i-1][j]==10){
        	       	     	cnt++;
        	       	 }
        	       	 if (tab[i-1][j+1]==10){
        	       	    	cnt++;
        	       	 }
        	       	 if (tab[i][j-1]==10){
        	       	     	cnt++;
        	       	 }
        	       	 if (tab[i][j+1]==10){
        	       	     	cnt++;
        	       	 }
        	       	 if (tab[i+1][j-1]==10){
        	       	     	cnt++;
        	       	 }
        	       	 if (tab[i+1][j]==10){
        	       	     	cnt++;
        	       	 }
        	       	 if (tab[i+1][j+1]==10){
        	       	     	cnt++;
        	       	 }
        	       	 tab2[i][j] = cnt;
			}	
		}
	}
}


int casenext1(int tab1[SIZE1][SIZE1], int tab2[SIZE1][SIZE1], int tab3[SIZE1][SIZE1], int size, int lig, int col){
//RECURSIVE FUNCTION DISPLAYING THE NUMBER OF MINES NEIGHBORING THE BOX, IF THERE ARE ANY. OTHERWISE, PERFORMS THE FUNCTION FOR THE BOXES NEIGHBORING THE ORIGIN BOX
	if(tab3[lig][col] == 0){
		tab3[lig][col] = 1;
		tab1[lig][col] = tab2[lig][col];
		if(tab1[lig][col] == 0){
			if(lig-1 >= 0){
				casenext1(tab1, tab2, tab3, size, lig-1, col);
			}
			if(col-1 >= 0){
				casenext1(tab1, tab2, tab3, size, lig, col-1);
			}
			if(col+1 <= 8){
				casenext1(tab1, tab2, tab3, size, lig, col+1);
			}
			if(lig+1 <= 8){
				casenext1(tab1, tab2, tab3, size, lig+1, col);
			}
			return 0;
		}
	}
	return 0;
}


void discocase1(int tab1[SIZE1][SIZE1], int tab2[SIZE1][SIZE1], int tab3[SIZE1][SIZE1], int size, int lig, int col){
//FUNCTION ALLOWING PLAYERS TO MAKE APPEAR SQUARES
	if(tab1[lig][col] == 9){
		casenext1(tab1, tab2, tab3, size, lig, col);
	}
	if(tab1[lig][col] == 10){
		tab1[lig][col] = 11;
	}
	else{
		tab1[lig][col] = tab1[lig][col];
	}
}



void placemark1(int tab[SIZE1][SIZE1], int lig, int col){
//FEATURE ALLOWING PLAYERS TO APPEAR MARKERS
	tab[lig][col] = 12;
}

int verificationgame1(int tab[SIZE1][SIZE1], int size){
//GAME STATUS CHECK, IE IF THE PLAYER HAS LOST, WON OR IF THE GAME CONTINUES
	int cnt;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(tab[i][j] < 9){
				cnt++;
			}
			if(tab[i][j] == 11){
				return 2;
			}
		}
	}
	if(cnt == 71){
		return 0;
	}
	return 1;
}
