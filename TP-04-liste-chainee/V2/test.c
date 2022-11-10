#include <stdio.h>
#include <string.h>

int main(void)
{
    char *string, *chunk;
    string = strdup("ceci est un,test");
    chunk = strsep(&string, ",");
    if(chunk!=NULL)
    {
        printf("%s", chunk);
    }
    return 0;
}