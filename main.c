
#include <stdio.h>
#include <stdlib.h>




int ** createMatrice(int rows,int cols){
    int ** matrice = malloc(rows*sizeof(int *));
    
    for (int i = 0; i < rows; i++)
    {
        *(matrice+i) = malloc(cols*sizeof(int));
    }

    return matrice;
    
}

void freeMatrice(int rows, int ** matrice){

    for (int i = 0; i < rows; i++)
    {
        free(*(matrice + i));
    }
    free(matrice);
    
}


int main() {

    int ** matrice = createMatrice(2,1);

    matrice[0][0] = 100;
    matrice[1][0] = 200;

    printf("%d\n",matrice[0][0]);
    printf("%d\n",matrice[1][0]);

    freeMatrice(2,matrice);

    return 0;
     
}


