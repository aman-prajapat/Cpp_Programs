#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("count  %d \n",argc);
    for (int  i = 0; i < argc; i++)
    {
        printf("Value is %s \n",argv[i]);
    }
    return 0;
}
