#include <string.h>
#include<stdio.h>

int main()
{
    printf(__TIME__ "\n");
    printf(__DATE__ );
    printf("%s \n",__FILE__);
    printf("%d \n",__LINE__);
     printf("%d \n",__STDC__);


}