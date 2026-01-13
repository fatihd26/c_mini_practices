
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void square(double * number){
    *number =  (*number)* (*number);
}

void len(char * str){
    int flag = 1;
    int length = 0;
    while(flag){
        if ((*str) == '\0') 
        {
            flag = 0;
        }
        else if ((*str) == ' ')
        {
            str++;
        }
        
        else{
            str++;
            length++;
        }
        
        
       
        
    }
    printf("%d",length);

}

void wordSize(char * str){
    int flag = 1;
    int word_length = 0;
    char * current_char = malloc(sizeof(char));

    while (flag)
    {   
        *current_char = *str;
        if ((*str)== '\0'){
            flag = 0;
        }
        else if ((*str)==' '){

            str++;

            if (*current_char != *str){
                word_length++;
            }
            

        }
        else{
            str++;
        }
    }
    printf("%d",word_length+1);
    
}

typedef struct{
    int * mat;
    int col;
    int row;
}Matrice;

int getValue(Matrice * matrice,int row, int col){
    return matrice->mat[row*matrice->col + col];
}

void setValue(Matrice * matrice, int row, int col,int value){
    matrice->mat[row*matrice->col + col] = value;
}

void dotMatrices(Matrice * matrice1, Matrice * matrice2){
    printf("girdi\n");

    if(matrice1->col != matrice2->row){

        printf("Boyutlar Uyumsuz");
        return;
    }

    Matrice * matrice3 = malloc(sizeof(Matrice));
    matrice3->row = matrice1->row;
    matrice3->col = matrice2->col;
    int * mat3 = malloc(matrice3->row*matrice3->col*sizeof(int));
    matrice3->mat = mat3;

    for (int i = 0; i < matrice1->row; i++)
    {   
        for (int j = 0; j < matrice2->col; j++)
        {   
            int sum = 0;
            for (int k = 0; k < matrice1->col; k++)
            {   
                sum = sum + getValue(matrice1,i,k) * getValue(matrice2,k,j);
                
            }   
            setValue(matrice3,i,j,sum); 
        }  
    }

    for (int k = 0; k < matrice3->row; k++)
    {
        for (int l= 0; l<matrice3->col; l++){
            printf("%d\n",getValue(matrice3,k,l));
        }
    }


    free(matrice3->mat);
    free(matrice3);
    
    
    


}

void main2(){
    int mat1[9] = {1,2,3,4,5,6,7,8,9}; //3x3
    int mat2[3] = {10,11,12};         // 3x1

    Matrice * matrice1 = malloc(sizeof(Matrice));
    Matrice *  matrice2 = malloc(sizeof(Matrice));

// 1 2 3  10    10+22+36  = 68
// 4 5 6  11    40+55+72  = 167
// 7 8 9  12    70+88+108 = 266

    matrice1->col=3;
    matrice1->row = 3;
    matrice1->mat = &mat1[0];

    matrice2->col=1;
    matrice2->row = 3;
    matrice2->mat=&mat2[0];

    dotMatrices(matrice1,matrice2);    

    free(matrice1);
    free(matrice2);
}




int main() {

    int ** matrice = malloc(5 * sizeof(int *));
    //matriceden 1 adet var yani sadece 5li bloğa işaret ediyor

    for(int i = 0;i<5;i++){
        *(matrice+i) = malloc(2*sizeof(int));
        //*(matrice+i) den 5 adet var her biri 2 adet inte işaret ediyor.
        
    }

    for (int i= 0; i<5;i++){
        for(int j = 0;j<2;j++){
            *(*(matrice+i)+j) = i+j*j;

            
            printf("%d ", *(*(matrice+i)+j));
            
        }
    }


    for (int i = 0;i<5;i++){
        free(*(matrice+i));
    }

    free(matrice);


    return 0;
     
}


