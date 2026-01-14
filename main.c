
#include <stdio.h>
#include "src/matrix.h"
int main() {

    int ** matrice1 = createMatrice(3,3);
    int ** matrice2 = createMatrice(3,3);
                                    
    matrice1[0][0] = 100;
    matrice1[1][0] = 200;
    matrice1[2][0] = 300;

    matrice1[0][1] = 10;
    matrice1[1][1] = 20;
    matrice1[2][1] = 30;

    matrice1[0][2] = 1;
    matrice1[1][2] = 2;
    matrice1[2][2] = 3;

    matrice2[0][0] = 100;
    matrice2[1][0] = 200;
    matrice2[2][0] = 300;

    matrice2[0][1] = 10;
    matrice2[1][1] = 20;
    matrice2[2][1] = 30;

    matrice2[0][2] = 1;
    matrice2[1][2] = 2;
    matrice2[2][2] = 3;

    int ** matrice3 = dotMatrices(matrice1,matrice2,3,3,3);

    prettyMatrice(3,3,matrice3);

    freeMatrice(3,matrice3);

    freeMatrice(3,matrice1);
    freeMatrice(3,matrice2);


    return 0;
     
}


