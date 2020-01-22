#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define print printf
const int CALLOCSIZE = 200;  // 동적 할당시 임시로 사용할 사이즈. 코드 완성 후엔 각 선언마다 적절한 lenth로 계산해서 사용할 것
void find_operator(char*);
int find_dot(char*);
char* fill_zero_int(char*, char*);
char* fill_zero_dic(char*, char*);
char* cal_plus(char*, char*);
char* cal_minus(char*, char*);
int abs_compare(char*, char*);
char* minus_exception(char*, char*);
char *result, *X, *Y;
char* find_first_negative(char*);
char* cal_multiply(char*, char*);
char* remove_dot(char*, char*);
char* multiply_onebyone(char*, int, int);
char* fill_zero_multi(char*, int);
int cal_decimal_length(char*, char*);
char* addDot(char*,int);
char* mullAdd(char*, char*);
char* removeDot(char *str);
int first_negative = 0;  // 첫 숫자가 음수일 경우 1, default 0
//int A_bigger_abs = 0;  // 첫 숫자 A가 음수이며 덧셈할 B보다 값이 더 클 경우 1, default 0
int multiply_decimal = 0;  // 소수가 있는 수의 곱셈시 1, default 0
// end definition

int main() {
//    char input[] = "";
    char* TEST_S = (char*)calloc(sizeof(char) , CALLOCSIZE);
    X = (char*)calloc(sizeof(char) , CALLOCSIZE);
    Y = (char*)calloc(sizeof(char) , CALLOCSIZE);
    result = (char*)calloc(sizeof(char) , CALLOCSIZE);
//    scanf("%s", X);
//    scanf("%s", Y);
    X = "12.454";
    Y = "12.795";
//    remove_dot(TEST_S, X);
//    X = TEST_S;
//    X = find_first_negative(X);
//    X = fill_zero_int(Y, X);
//    Y = fill_zero_int(X, Y);
//    X = fill_zero_dic(Y, X);
//    Y = fill_zero_dic(X, Y);
//
   //result = cal_plus(X, Y);  // result에 덧셈 결과 저장
//    result = cal_minus(X, Y);  // result에 뺄셈 결과 저장
    result = cal_multiply(X, Y);
//    find_operator(input);
    printf("-------------------\n");
    printf("X : %s \nY : %s \n", X, Y);  // 현재 A, B값 (자리수까지 맞추어져있음)
    printf("result : %s\n", result);
    return 0;
}  // end main()

char* cal_multiply(char *a, char *b) {  // 곱셈
   int i , j, sum,k,strlenA,strlenB,dot = 0;
   int count = 0;
   int cnt = 0;
   int nflag = 0;
   char one ;
   char *result = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *ptr;
   char *answer = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *temp = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *temp2 = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *temp3 = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *temp4 = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *negative = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *c = malloc(sizeof(char)*strlen(a)*strlen(b));
   char *d = malloc(sizeof(char)*strlen(a)*strlen(b));
   memset(answer,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(temp,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(temp2,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(temp3,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(temp4,'X',sizeof(char)*strlen(a)*strlen(b));
   memset(negative,'X',sizeof(char)*strlen(a)*strlen(b));

   result = strchr(a,'.');

   if(result != NULL)
   {

        c = removeDot(a);
        strlenA = strlen(a)-1;
        dot = strlen(a)-find_dot(a)-1 +dot;
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
        dot = strlen(b)-find_dot(b)-1 +dot;
   }
   else
   {
        d = b;
        strlenB = strlen(b);
        
   }
   cnt = 0;

   if((*c=='-' && *d=='-')||(*c!='-' && *d!='-'))
   {
        if(*c=='-' && *d=='-')
        {
            strncpy(temp3,c+1,strlenA);
            c=temp3;
            strlenA--;

            strncpy(temp4,d+1,strlenB);
            d=temp4;
            strlenB--;
        }
   }
   else
   {

        nflag = 1;
        if(*c=='-')
        {
            strncpy(temp3,c+1,strlenA);
            c=temp3;
            strlenA--;
        }
        else if(*d=='-')
        {
            strncpy(temp3,d+1,strlenB);
            d=temp3;
            strlenB--;
        }
   }
   for(i = 0; i < strlenA-1; i++, c++) continue;
   for(j = 0; j < strlenB-1; j++, d++) continue;
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
  if(dot==0)
  {
    if(nflag==1)
    {
         negative[0] = '-';
        negative[1] = '\0';
        strcat(negative, temp2); 
        strcpy(temp2,negative);
    }
    return temp2;
  }
  
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
      if(nflag==1)
      {
        negative[0] = '-';
        negative[1] = '\0';
        strcat(negative, temp2); 
        strcpy(temp2,negative);
      }
      return temp2;
    }
    else
    {
      if(nflag==1)
      {
         negative[0] = '-';
        negative[1] = '\0';
        strcat(negative, temp2); 
        strcpy(temp2,negative);
      }
      return temp2;
    }
  }
  free(result);
  free(answer);
  free(temp);
  free(temp2);
  free(temp3);
  free(c);
  free(d);
}  // end cal_multiply()


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
    char *temp = malloc(sizeof(char)*lenA*lenB);
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
    free(temp);
  }
  else if(strlen(a)<strlen(b))
  {
    int i = 0;
    int sum = 0;
    int one = 0;
    int len = strlen(b)+1;
    int lenA = strlen(a);
    int lenB = strlen(b);
    char *temp = malloc(sizeof(char)*lenA*lenB);
    memset(temp,'X',sizeof(char)*lenA*lenB);
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
    free(temp);
  }
  else
  {
    int i = 0;
    int sum = 0;
    int one = 0;
    int len = strlen(a)+1;
    int lenA = strlen(a);
    int lenB = strlen(b);

    char *temp = malloc(sizeof(char)*lenA*lenB);
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
    free(temp);
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
    char *answer = malloc(sizeof(char)*100000);
    char *temp = malloc(sizeof(char)*100000);
    memset(answer,'X',sizeof(char)*100000);
    memset(temp,'X',sizeof(char)*100000);
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
    free(answer);
    free(temp);
}

int cal_decimal_length(char* X, char* Y) {  // 곱셈시 각 수의 소수부 길이를 계산하여 합 return
    int len=0, a, b;
    a = strlen(X) - find_dot(X);
    b = strlen(Y) - find_dot(Y);
    if(a > 0)
        len += a-1;
    if(b > 0)
        len += b-1;
    if(len>0)
        multiply_decimal = 1;
    return len;
}  // end cal_decimal_length()

char* cal_plus(char *X, char*Y) {  // 덧셈
    if(first_negative) return minus_exception(X, Y);
    int i, sum, oneA, oneB, carry=0;
    char *A = X, *B = Y;  // X,Y로 받아 A,B로 이름 바꿔서 사용
    char *return_result, doPlus, *temp;
    int length_A = strlen(A);
    temp = (char*)calloc(sizeof(char) , CALLOCSIZE);
    return_result = (char*)calloc(sizeof(char) , strlen(X));
    for(i = 0; i < length_A-1; i++, A++, B++) continue;  // A와 B의 포인터 위치를 맨 끝으로 이동하여 맨 뒤부터 계산하도록 함
    for(i = length_A-1 ; i >= 0 ; i--, A--, B--) {  // 맨 뒤부터 앞으로 한칸씩 수행
        if(*A == '.' || *B == '.') {  // 소수점을 만나게 되면 점을 찍고 다음 반복 수행
            return_result[i] = '.';
            continue;
        }
        oneA = *A - 48;  // ASCII 값 중 0~9로 위치하도록 보정
        oneB = *B - 48;
        sum = oneA + oneB;  // 덧셈 수행
        if(carry) {  // 지난 덧셈에서 carry가 있을 경우 sum에 carry를 더함
            sum += carry;
            carry = 0;  // carry 사용 후 0으로 초기화
        }
        doPlus = (sum % 10) + 48;  // ASCII 0~9값 설정
        if(sum >= 10) carry++;  // 만약 합이 10보다 클 경우 carry++
        return_result[i] = doPlus;  // 현재 위치에 덧셈 결과 넣음
//        printf("i : %d, return_result[i] : %c\n", i, return_result[i]);
    }
//    printf("len : %d\n", strlen(return_result));
//    printf("final return_result : %s\n", return_result);
    if(carry) {  // 맨 앞까지 덧셈을 끝낸 후 carry가 있다면 결과값 맨 앞에 1을 추가
        strcat(temp, "1");
        strcat(temp, return_result);
        return_result = temp;
    }
    return return_result;
}  // end cal_plus

char* find_first_negative(char* X) {  // 첫 숫자가 음수일 경우 global first_negative를 켜주고 음수를 뗀 숫자 return
    if(*X == '-') {
        X++;
        first_negative = 1;
    }
    return X;
}  // end find_first_negative()

int abs_compare(char* X, char* Y) {
    int length_A = find_dot(X);
    int length_B = find_dot(Y);
    char *A = X, *B = Y;
    if(length_A > length_B)
        return 1;
    else if(length_A == length_B) {
        if(*A > *B)
            return 1;
        else {
            A++; B++;
        }
    }
    return 0;
}  // end abs_compare()

char* minus_exception(char *X, char *Y) {
    // -5 + 11  -> (11-5) =  6 -> -A + B = +(B - A)
    // -5 +  2  -> -(5-2) = -3 -> -A + B = -(A - B)  -> ** 예외 처리 할 case **
    // 음수 + 양수 의 경우 음수, 양수간의 절대값 대수 비교가 필요.  abs_compare() returns absolute value compare
    // 계산은 절대값간의 뺄셈으로 이루어지나, 음수가 더 클 경우 최종 결과 음수 / 양수가 더 클 경우 최종 결과 양수.
    char *A=X, *B=Y;
    char *temp_return, *temp;
    int A_bigger_abs = 0;
    A_bigger_abs = abs_compare(X, Y);  // X의 절대값이 Y보다 클 경우 A_bigger_abs = 1
    first_negative = 0;
    temp_return = (char*)calloc(sizeof(char) , CALLOCSIZE);
    if(A_bigger_abs) {  // A<0 && abs(A) > abs(B)
        temp = (char*)calloc(sizeof(char) , CALLOCSIZE);
        temp_return = cal_minus(A, B);
        strcat(temp, "-");  // 마이너스 부호 붙임
        strcat(temp, temp_return);
        temp_return = temp;
    } else  // A<0 && abs(B) > abs(A)
        temp_return = cal_minus(B, A);
    // end if
    A_bigger_abs = 0;
    return temp_return;
}  // end minus_exception

char* cal_minus(char *X, char*Y) {  // 뺄셈
    int i, sum, oneA, oneB, carry=0;
    char *A, *B;  // A와 B를 바꿀 부분  <<----- B > A 라서 뺄셈시 음수가 될 때
    A = X; B = Y;  // X,Y로 받아 A,B로 이름 바꿔서 사용
    char *return_result, doMinus, *temp;
    int length_A = strlen(A);
    temp = (char*)calloc(sizeof(char) , CALLOCSIZE);
    return_result = (char*)calloc(sizeof(char) , strlen(X));
    for(i = 0; i < length_A-1; i++, A++, B++) continue;  // A와 B의 포인터 위치를 맨 끝으로 이동하여 맨 뒤부터 계산하도록 함
    for(i = length_A-1 ; i >= 0 ; i--, A--, B--) {
        if(*A == '.' || *B == '.') {  // 소수점을 만나게 되면 점을 찍고 다음 반복 수행
            return_result[i] = '.';
            continue;
        }
        oneA = *A - 48;  // ASCII 값 중 0~9로 위치하도록 보정
        oneB = *B - 48;
        sum = oneA - oneB;  // 뺄셈 수행
        if(carry) {  // 직전 반복 뺼셈에서 carry 발생했을 경우 -1
            sum--;
            carry = 0;  // carry 사용 후 0으로 초기화
        }
        if(sum < 0 && i == 0) {  // 맨 앞자리 뺄셈인데 음수일 경우
            sum *= -1;  // 양수화
            carry++;  // 캐리 ++
        } else if(sum < 0) {  // 뺄셈이 음수일 경우
            sum += 10;  // 10을 더하고 캐리 ++
            carry++;
        }
        doMinus = (sum % 10) + 48;  // ASCII 0~9값 설정
        return_result[i] = doMinus;
    }
    if(carry) {  // 계산을 끝까지 마치고도 캐리가 있는 경우 = 계산 결과가 음수가 된 경우
        strcat(temp, "-");  // 마이너스 부호 붙임
        strcat(temp, return_result);
        return_result = temp;
    }
    return return_result;
}  // end cal_minus

char* fill_zero_int(char* A, char* B) {  // 덧셈, 뺄셈시 정수부 자리수가 차이나는 만큼 0으로 채움
    int int_A = find_dot(A);  // A의 정수부 길이
    int int_B = find_dot(B);  // B의 정수부 길이
    int difference_int = int_A>int_B? int_A - int_B: int_B - int_A;
    char *temp_A = A;  // A를 temp_A에 복사
    char *temp_B = B;  // B를 temp_B에 복사
//    char *temp = (char*)calloc((strlen(A) + difference_int) , sizeof(char));  // 두 수의 자릿수가 차이나는 만큼 0으로 채울 공간
    char *temp = (char*)calloc(sizeof(char), CALLOCSIZE);
    char *temp2 = (char*)calloc(sizeof(char), CALLOCSIZE);

//    difference_int = int_A - int_B;
    if(int_A > int_B) {  // 정수부가 A가 B보다 긴 경우
        for( ; difference_int > 0; difference_int--)  // 차이나는 만큼 0으로 채움
            strcat(temp, "0");
//        strcat(tempInt, temp_B);
//        return tempInt;
    }
    strcat(temp2, temp);
    strcat(temp2, temp_B);
    return temp2;
}  // end plus

char* fill_zero_dic(char *A, char *B) {  // 덧셈, 뺄셈시 소수부 자리수가 차이나는 만큼 0으로 채움
    int int_A = find_dot(A);  // A의 정수부 길이
    int int_B = find_dot(B);  // B의 정수부 길이
    int dec_A = strlen(A) - int_A;  // A의 소수부 길이
    int dec_B = strlen(B) - int_B;  // B의 소수부 길이
    int difference_dec = dec_A - dec_B;
    if(difference_dec <= 0) return B;
    char *temp_A = A;  // A를 temp_A에 복사
    char *temp_B = B;  // B를 temp_B에 복사
    char *temp = (char*)calloc((strlen(A) + difference_dec) , sizeof(char));  // 두 수의 자릿수가 차이나는 만큼 0으로 채울 공간
    char *temp2 = (char*)calloc((strlen(A) + difference_dec) , sizeof(char));  // 두 수의 자릿수가 차이나는 만큼 0으로 채울 공간

    if(difference_dec > 0)   // A의 소수부가 더 긴 경우
        for( ; difference_dec > 0; difference_dec--)
            strcat(temp, "0");
    strcat(temp2, temp_B);
    strcat(temp2, temp);
    return temp2;
}

int find_dot(char* num) {  // 소수점까지의 length(정수부 길이)를 찾아 return함
    int len_of_number = strcspn(num, ".");
    return len_of_number;
}

void find_operator(char* input) {
    int i;
    int size = strlen(input);
    print("%d",size);
    for(i = 0; i < size; i++) {
        if(isdigit(input[i]) == 0) {  // 정수가 아닌 문자 탐지
            switch(input[i]) {
                case '+':  // 덧셈 +
                    break;
                case '-':  // 뺄셈 -
                    break;
                case '*':  // 곱셈 *
                    break;
                default:  // 잘못 입력된 경우
                    print("\n!! Unavailable input !!\n");
                    exit(0);
            }  // end switch
        }  // end if
    }  // end for
}  // end find_operator
