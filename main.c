
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




int main() {

    int ** matrice = malloc(5 * sizeof(int *));

    for(int i = 0;i<5;i++){
        *(matrice+i) = malloc(2*sizeof(int));
        
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


