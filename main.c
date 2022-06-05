#include "demineur1.h"
#include "demineur2.h"

int main(){

	int board1[SIZE1][SIZE1];
	int board2[SIZE2][SIZE2];
	int boardstock1[SIZE1][SIZE1];
	int boardstock2[SIZE2][SIZE2];
	int boardnei1[SIZE1][SIZE1];
	int boardnei2[SIZE2][SIZE2];
	int diff, choice;
	int i, j, col, lig;
	
	diff = 0;
	
	srand(time(NULL));
	
	printf("Appuyez sur Entrée\n");
	time_t start = time (NULL);//TO START THE STOPWATCH
	getchar ();		    
	
	while(diff != 1 && diff != 2){
		printf("Quel niveau de difficulté voulez vous ? Tapez 1 pour débutant, tapez 2 pour intermédiaire : ");//CHOICE OF DIFFICULTY
		scanf("%d", &diff);
	}
	
	if (diff == 1){ 
		printf("Vous avez choisi la difficulté débutant.\n");
		for (i = 0; i < SIZE1; i++){
			for (j = 0; j < SIZE1; j++){
				board1[i][j] = 9;
				boardnei1[i][j] = 9;//INITIALIZE BOARD
				boardstock1[i][j] = 0;
			}
		}
		i = 0;
		while (i != 10){
			col = rand()%8;
			lig = rand()%8;//INITIALIZE THE MINES
			if (board1[lig][col] != 10){
				board1[lig][col] = 10;
				i++;
			}
		}
		
		nbminesnext1(board1, boardnei1, SIZE1);
		displayboard1(board1, SIZE1);
		
		while(verificationgame1(board1, SIZE1) != 0){
			printf("Tapez 1 si vous voulez placer un marqueur, 2 si vous voulez découvrir une case : ");//CHOICE OF ACTION
			scanf("%d", &choice);
			printf("Choisissez la ligne : ");
			scanf("%d", &lig);
			printf("Choisissez la colonne : ");//CHOICE OF CASE
			scanf("%d", &col);
			if(choice == 1){
				placemark1(board1, lig, col);
			}
			if(choice == 2){
				discocase1(board1, boardnei1, boardstock1, SIZE1, lig, col);
			}
			displayboard1(board1, SIZE1);
			if(verificationgame1(board1, SIZE1) == 2){
				printf ("Vous avez perdu, durée de la partie = %ds\n", (int) (time (NULL) - start));
				return 0;
			}
		}
		
		if(verificationgame1(board1, SIZE1) == 0){
			printf ("Vous avez gagné, durée de la partie = %ds\n", (int) (time (NULL) - start));
		}
	}
	
	if (diff == 2){ 
		printf("Vous avez choisi la difficulté débutant.\n");
		for (i = 0; i < SIZE2; i++){
			for (j = 0; j < SIZE2; j++){
				board2[i][j] = 9;
				boardnei2[i][j] = 9;//INITIALIZE BOARD
				boardstock2[i][j] = 0;
			}
		}
		i = 0;
		while (i != 40){
			col = rand()%15;
			lig = rand()%15;//INITIALIZE THE MINES
			if (board2[lig][col] != 10){
				board2[lig][col] = 10;
				i++;
			}
		}
		
		nbminesnext2(board2, boardnei2, SIZE2);
		displayboard2(board2, SIZE2);
		
		while(verificationgame2(board2, SIZE2) != 0){
			printf("Tapez 1 si vous voulez placer un marqueur, 2 si vous voulez découvrir une case : ");//CHOICE OF ACTION
			scanf("%d", &choice);
			printf("Choisissez la ligne : ");
			scanf("%d", &lig);
			printf("Choisissez la colonne : ");//CHOICE OF CASE
			scanf("%d", &col);
			if(choice == 1){
				placemark2(board2, lig, col);
			}
			if(choice == 2){
				discocase2(board2, boardnei2, boardstock2, SIZE2, lig, col);
			}
			displayboard2(board2, SIZE2);
			if(verificationgame2(board2, SIZE2) == 2){
				printf ("Vous avez perdu, durée de la partie = %ds\n", (int) (time (NULL) - start));
				return 0;
			}
		}
		
		if(verificationgame2(board2, SIZE2) == 0){
			printf ("Vous avez gagné, durée de la partie = %ds\n", (int) (time (NULL) - start));
		}
	}
}
