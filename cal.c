#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char* removeDot(char *str) // 곰셈할 때 .을 제거하는 함수.
{
    int cnt = 0;
    char *ptr;
    char *a = malloc(sizeof(char)*30);
    char *b = malloc(sizeof(char)*30);
    char *c = malloc(sizeof(char)*30);
    strcpy(a,str);
    ptr = strtok(a, ".");
    while(ptr != NULL ){
        if(cnt==0) b = ptr;
        else c = ptr;
        ptr = strtok(NULL, ".");
        cnt++;
    }
    strcat(b,c);
    return b;
}
char* addDot(char *str,int dot)  // 계산 후 .을 추가하는 함수.
{
    int i;
    char *answer = malloc(sizeof(char)*20);
    char *temp = malloc(sizeof(char)*20);
    memset(answer,'X',sizeof(char)*20);
    memset(temp,'X',sizeof(char)*20);
    strcpy(answer,str);
    int len = strlen(answer);
    temp[len] = '\0';
    for (i = 0; i < len+1; ++i,answer++)
    {
        if(i+dot+1==len) temp[i] = '.';
        else temp[i] = *answer;
    }
    return temp;
}
char* calMul(char *a, char *b)
{
   int i , j, sum,k,strlenA,strlenB,dot = 0,cnt = 0;
   char one ;
   char *ptr;
   char *result = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *answer = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *temp = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *temp2 = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *temp3 = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *c = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *d = malloc(sizeof(char)*strlen(a)*strlen(b));
   memset(answer,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(temp,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(temp2,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(temp3,'X',sizeof(char)*strlen(a)*strlen(b));
  

   result = strchr(a,'.');

   if(result != NULL)// a에 .이 있는지 검사 있으면 제거를 한다 
   {
        c = removeDot(a);
        strlenA = strlen(a)-1;
        dot = strlen(a)-findDot(a)-1 +dot;
   }
   else
   {
        c = a;
        strlenA = strlen(a);
        
   }
   cnt = 0;
   
   
   result = strchr(b,'.');

   if(result != NULL)// b에 .이 있는지 검사 있으면 제거를 한다 
   {
        d = removeDot(b);
        strlenB = strlen(b)-1;
        dot = strlen(b)-findDot(b)-1 +dot;
   }
   else
   {
        d = b;
        strlenB = strlen(b);
        
   }
   cnt = 0;

   for(i = 0; i < strlenA-1; i++, c++) continue;// 각 수의 포인터를 가장 끝으로 옮긴다.
   for(j = 0; j < strlenB-1; j++, d++) continue;
   //for(j = 0; j < strlen(b); j++, d++) continue;
    sum = 0;
   for (i = strlenB ; i > 0 ; i--, d--)// 곱하기를 한다.
   {
      answer[strlenA+cnt+1] = '\0';  
      for (j = strlenA+cnt; j > strlenA; j--)
      {
         answer[j] = '0';
      }
      for (j = strlenA; j > 0; j--,c--)
      {
         int oneA = *c-48;
         int oneB = *d-48;
         sum = oneA*oneB + sum;
         if(sum>9)
         {
            one = (sum%10)+48;
            sum = sum/10;
         }
         else
         {
            one = sum+48;
            sum = 0;
         }
         answer[j] = one;
      }
      if(sum>0)
      {
         answer[j] = sum+48;
      }
      
      if(answer[0] == 'X'){
        strncpy(temp,answer+1,strlenA+cnt+1);
        answer = temp;
      }
      
      if(cnt==0) // 가장 처음에 계산된 값을 빈 공간에 담는다.
      {
        strcpy(temp2,answer);
      }
      
      else
      {

        if(strlen(answer)==strlen(temp2))  // 합계에 계산된 값을 계속 넣는다.
        {
            strcpy(temp2,calPlus(answer,temp2));

        }
        else if(strlen(answer)>strlen(temp2))
        {
            strcpy(temp2,(fillZeroInt(answer, temp2)));
            strcpy(temp2,calPlus(answer,temp2));
        }
        else if(strlen(answer)<strlen(temp2))
        {
            strcpy(answer,(fillZeroInt(temp2, answer)));
            strcpy(temp2,calPlus(answer,temp2));
        }
      }
      cnt++;
      sum = 0;
      memset(answer,'X',sizeof(char)*strlen(a)*strlen(b));
      for(k = 0; k < strlenA; k++, c++) continue;
   }
   if(dot==0) return temp2; 
   else return addDot(temp2,dot); // .이 있었던 경우 계산후에 다시 추가한다.
}

int main()
{
   char *a = malloc(sizeof(char)*50);
   char *b = malloc(sizeof(char)*50);
   a = "1234";
   b = "5678";
   calMul(a,b);
}