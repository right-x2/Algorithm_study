#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str,ans;
    int a,b,sum = 0;
    int cnt = 1;
    char c,d;
    cin>>str;
    if(str.length()==1) str = "0"+str;
    ans = str;
    a = str[0]-'0';
    b = str[1]-'0';
    str[0] = b+'0';
    c = ((a+b)%10)+'0';
    str[1] = c;
    while(ans!=str)
    {
        a = str[0]-'0';
        b = str[1]-'0';
        str[0] = b+'0';
        c = ((a+b)%10)+'0';
        str[1] = c;
        cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}  