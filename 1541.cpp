#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
 
using namespace std;

int cal(string str)
{
    int sum = 0;
    int len = 0;
    int num = 0;
    int to = 0;
    char opr = ' ';
    string ans = "";

    while(len<str.length())
    {
        //cout<<str[len]<<" ";
        if(str[len]=='-')
        {
            if(opr=='-') sum = sum - to;
            else sum = sum + to;
            len++;
            while(str[len]>='0'&&str[len]<='9')
            {
                ans = ans + str[len];
                len++;
            }
            num = atoi(ans.c_str());
            to = num;
            ans = "";
            opr = '-';
        }
        else if(str[len]=='+')
        {
            len++;
            while(str[len]>='0'&&str[len]<='9')
            {
                ans = ans + str[len];
                len++;
            }
            num = atoi(ans.c_str());
            to = to + num;
            ans = "";            
        }
        else
        {
            while(str[len]>='0'&&str[len]<='9')
            {
                ans = ans + str[len];
                len++;
            }
            num = atoi(ans.c_str());
            sum = num;
            ans = "";   
        }
    }
    if(opr!='-') sum = sum + to;
    else sum = sum - to;
    return sum;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string ans;
    cin>>ans;
    cout<<cal(ans)<<"\n";
    return 0;
}