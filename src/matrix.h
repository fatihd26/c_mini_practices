#include <stdlib.h>
#include <stdio.h>

int ** createMatrice(int rows,int cols);

void freeMatrice(int rows, int ** matrice);

void prettyMatrice(int rows, int cols,int ** matrice);

int ** dotMatrices(int ** matrice1, int ** matrice2,int matrice1_cols,int matrice1_rows,int matrice2_cols);

void setMatriceValue(int ** matrice, int row, int col, int value);

