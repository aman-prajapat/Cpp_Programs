#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char  *argv[])
{
    char *A;
    A = argv[1]; 
    float total;
    
    if (strcmp(A,"add")==0)
    {
         total = atoi(argv[2]) + atoi(argv[3]);
    }
    else if(strcmp(A,"sub")==0) 
    {
        total = atoi(argv[2]) - atoi(argv[3]);
    }
     else if(strcmp(A,"mul")==0) 
    {
        total = atoi(argv[2]) * atoi(argv[3]);
    }
    else if(strcmp(A,"div")==0) 
    {
        total = atoi(argv[2]) / atoi(argv[3]);
    }
    else{
        printf("Enter Valid sign");
    }

    printf("Your answer is : %f",total);

}