#include "matrix.h"


int ** createMatrice(int rows,int cols){
    //int ** matrice = malloc(rows*sizeof(int *));
    // burada hem double pointer hem de calloc kullanmam performans olarak olumsuz etki yapar.
    // Double pointer cache friendly değildir. Ancak projenin ölçeği küçük olduğu için bu etki ihmal edilebilir.
    int ** matrice = calloc(rows,sizeof(int *)); 
    
    for (int i = 0; i < rows; i++)
    {
        //*(matrice+i) = malloc(cols*sizeof(int));
        *(matrice+i) = calloc(cols,sizeof(int));
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

void prettyMatrice(int rows, int cols,int ** matrice){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%4d ",matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}

int ** dotMatrices(int ** matrice1, int ** matrice2,int matrice1_cols,int matrice1_rows,int matrice2_cols){
    int ** matrice3 = createMatrice(matrice1_rows,matrice2_cols);
    int total = 0;
    for (int i = 0; i < matrice1_rows; i++)
    {
        for (int k = 0; k < matrice2_cols; k++)
        {
            for (int j = 0; j < matrice1_cols; j++)
            {
                total = total+ matrice1[i][j]*matrice2[j][k];
            }
            matrice3[i][k] = total;
            total = 0;
            
        }

        
        

    }

    return matrice3;
    
}

void setMatriceValue(int ** matrice, int row_index, int col_index, int value){
    matrice[row_index][col_index] = value;
}