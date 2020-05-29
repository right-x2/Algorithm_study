#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int chk[30];

int con(string str)
{
    int sum = 0;
    int mul = 1;
    for (int i = str.length()-1; i >=0 ; --i)
    {
        sum = sum + (str[i]-'0')*mul;
        mul = mul * 10;
    }
    return sum;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string a,b,c="",d="",x="",y="";
    cin>>a>>b;
    for (int i = 0; i < a.length(); ++i)
    {
        if(a[i]=='6'||a[i]=='5')
        {
            c = c + '6';
            x = x + '5';
        }
        else
        {
            c = c + a[i];
            x = x + a[i];
        }
    }
    for (int i = 0; i < b.length(); ++i)
    {
        if(b[i]=='6'||b[i]=='5')
        {
            d = d + '6';
            y = y + '5';
        }
        else
        {
            d = d + b[i];
            y = y + b[i];
        }
    }
    cout<<con(x)+con(y)<<" ";
    cout<<con(c)+con(d)<<"\n";
    
    return 0;
}   