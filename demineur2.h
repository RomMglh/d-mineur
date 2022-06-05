#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE2 16

void displayboard2(int tab[SIZE2][SIZE2], int size);

void nbminesnext2(int tab[SIZE2][SIZE2], int tab2[SIZE2][SIZE2], int size);

int casenext2(int tab1[SIZE2][SIZE2], int tab2[SIZE2][SIZE2], int tab3[SIZE2][SIZE2], int size, int lin, int col);

void discocase2(int tab1[SIZE2][SIZE2], int tab2[SIZE2][SIZE2], int tab3[SIZE2][SIZE2], int size, int lin, int col);

void placemark2(int tab[SIZE2][SIZE2], int lin, int col);

int verificationgame2(int tab[SIZE2][SIZE2], int size);
