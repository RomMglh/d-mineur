#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE1 9

void displayboard1(int tab[SIZE1][SIZE1], int size);

void nbminesnext1(int tab[SIZE1][SIZE1], int tab2[SIZE1][SIZE1], int size);

int casenext1(int tab1[SIZE1][SIZE1], int tab2[SIZE1][SIZE1], int tab3[SIZE1][SIZE1], int size, int lig, int col);

void discocase1(int tab1[SIZE1][SIZE1], int tab2[SIZE1][SIZE1], int tab3[SIZE1][SIZE1], int size, int lig, int col);

void placemark1(int tab[SIZE1][SIZE1], int lig, int col);

int verificationgame1(int tab[SIZE1][SIZE1], int size);

