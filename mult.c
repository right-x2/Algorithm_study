#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int findDot(char* num) {  // 소수점까지의 length(정수부 길이)를 찾아 return함
	int lenOfNumber = strcspn(num, ".");
	return lenOfNumber;
}
char* mullAdd(char *a, char *b)
{
  if(strlen(a)>strlen(b))
  {
    int i = 0;
    int sum = 0;
    int one = 0;
    int len = strlen(a)+1;
    int lenA = strlen(a);
    int lenB = strlen(b);
    char *temp = malloc(sizeof(char)*1000000);
    memset(temp,'X',sizeof(char)*len);
    temp[len] = '\0';
    len--;

    for (i = 0; i < lenA-1; ++i,a++) continue;
    for (i = 0; i < lenB-1; ++i,b++) continue;

    for (i = lenB; i > 0; i--,b--,a--,len--)
    {
      int oneA = *a-48;
      int oneB = *b-48;
      sum = oneA+oneB + sum;
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
      temp[len] = one;
    }
    
    while(len>0)
    {
      int oneA = *a-48;
      if(oneA+sum>9)
      {
        temp[len] = ((oneA+sum)%10)+48;
        sum = 1;
      }
      else if(sum>0)
      {
        temp[len] = (oneA+sum)+48;
        sum = 0;
      }
      else
      {
        temp[len] = oneA+48;
      }
      len--;
      a--;
    }
    if(sum>0) temp[0] = sum+48;
    else
    {
      strncpy(temp,temp+1,lenA);
      temp[lenA] = '\0';
    }
    return temp;
  }
  else if(strlen(a)<strlen(b))
  {
    int i = 0;
    int sum = 0;
    int one = 0;
    int len = strlen(b)+1;
    int lenA = strlen(a);
    int lenB = strlen(b);
    char *temp = malloc(sizeof(char)*1000000);
    memset(temp,'X',sizeof(char)*len);
    temp[len] = '\0';
    len--;
    for (i = 0; i < lenA-1; ++i,a++) continue;
    for (i = 0; i < lenB-1; ++i,b++) continue;

    for (i = lenA; i > 0; i--,b--,a--,len--)
    {
      int oneA = *a-48;
      int oneB = *b-48;
      sum = oneA+oneB + sum;
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
      temp[len] = one;
    }
    
    while(len>0)
    {
      int oneB = *b-48;
      if(oneB+sum>9)
      {
        temp[len] = ((oneB+sum)%10)+48;
        sum = 1;
      }
      else if(sum>0)
      {
        temp[len] = (oneB+sum)+48;
        sum = 0;
      }
      else
      {
        temp[len] = oneB+48;
      }
      len--;
      b--;
    }
    if(sum>0) temp[0] = sum+48;
    else
    {
      strncpy(temp,temp+1,lenB);
      temp[lenB] = '\0';
    }
    return temp;
  }
  else
  {
    int i = 0;
    int sum = 0;
    int one = 0;
    int len = strlen(a)+1;
    int lenA = strlen(a);
    int lenB = strlen(b);
    char *temp = malloc(sizeof(char)*1000000);
    memset(temp,'X',sizeof(char)*len);
    temp[len] = '\0';
    len--;
    for (i = 0; i < lenA-1; ++i,a++) continue;
    for (i = 0; i < lenB-1; ++i,b++) continue;

    for (i = lenB; i > 0; i--,b--,a--,len--)
    {
      int oneA = *a-48;
      int oneB = *b-48;
      sum = oneA+oneB + sum;
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
      temp[len] = one;
    }
    if(sum>0)
    {
      temp[0] = sum+48;
    }
    else
    {
      strncpy(temp,temp+1,lenA);
      temp[lenA] = '\0';
    }
    return temp;
  }
  
}
char* removeDot(char *str)
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
char* addDot(char *str,int dot)
{
	int i;
	char *answer = malloc(sizeof(char)*1000);
    char *temp = malloc(sizeof(char)*1000);
    memset(answer,'X',sizeof(char)*1000);
    memset(temp,'X',sizeof(char)*1000);
    strcpy(answer,str);
    int len = strlen(answer);
    temp[len] = '\0';
    for (i = 0; i <= len+1; ++i,answer++)
    {
        if(i+dot==len)
        {
          temp[i] = '.';
          answer--;
        }
        else temp[i] = *answer;
    }
    return temp;
} 
char* calMul(char *a, char *b)
{
   int i , j, sum,k,strlenA,strlenB,dot = 0;
   int count = 0;
   int cnt = 0;
   char one ;
   char *result = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *ptr;
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

   if(result != NULL)
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

   if(result != NULL)
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

   for(i = 0; i < strlenA-1; i++, c++) continue;
   for(j = 0; j < strlenB-1; j++, d++) continue;
   //for(j = 0; j < strlen(b); j++, d++) continue;
   sum = 0;
   for (i = strlenB ; i > 0 ; i--, d--)
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
      if(count==0)
      {
        strcpy(temp2,answer);
      }
      else
      {
        strcpy(temp2,mullAdd(temp2,answer));
      }
      cnt++;
      count++;
      sum = 0;
      memset(answer,'X',sizeof(char)*strlen(a)*strlen(b));
      for(k = 0; k < strlenA; k++, c++) continue;
  }
  if(dot==0) return temp2;
  
  else
  {
    
    strcpy(temp2,addDot(temp2,dot));
    int dotlen = strlen(temp2);
    int dotcnt = 0;
    strcpy(temp3,temp2);
    if(temp3[dotlen-1]=='0')
    {

      for (i = 0; i < dotlen-1; ++i,temp3++) continue;
      while(1)
      {
        if(*temp3=='.'||*temp3!='0')
        {
          if(*temp3=='.') dotcnt++;
          break;
        }
        else
        {
          *temp3--;
          dotcnt++;
        }
      }
      temp2[dotlen-dotcnt] = '\0';
      return temp2;
    }
    else
    {
      return temp2;
    }

  }
}

int main()
{
   char *a = malloc(sizeof(char)*1000);
   char *b = malloc(sizeof(char)*1000);
   char *c = malloc(sizeof(char)*10000000000);
   a ="426.26";
   b ="468.65";
   c = calMul(a,b);
   printf("%s",c);
   //calMul(a,b);
}   