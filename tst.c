#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int cnt = 0;
    int i;
	char *answer = malloc(sizeof(char)*20);
    char *temp = malloc(sizeof(char)*20);
    memset(answer,'X',sizeof(char)*20);
    memset(temp,'X',sizeof(char)*20);
    int dot=4;
    strcpy(answer,"4254644");
    int len = strlen(answer);
    temp[len] = '\0';
    for (i = 0; i < len+1; ++i,answer++)
    {
        if(i+dot+1==len) temp[i] = '.';
        else temp[i] = *answer;

    }
    
    printf( "%s\n" , temp);
    return 0; 
}