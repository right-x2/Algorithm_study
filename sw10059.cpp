#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
string a,b;

int conv(string str)
{
    int sum = 0;
    int mul = 1;

    sum = (str[0]-'0')*10 + (str[1] - '0');

    return sum;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>str;

        a = str.substr(0,2);
        b = str.substr(2,3);

        int c = conv(a);
        int d = conv(b);

        if(c==0&&d==0)
        {
            cout<<"NA"<<"\n";
        }
        else if(c==0&&d!=0&&d<13)
        {
            cout<<"YYMM"<<"\n";
        }
        else if(c!=0&&d==0&&c<13)
        {
            cout<<"MMYY"<<"\n";
        }
        else if(c>12&&d<13&&d>0)
        {
            cout<<"YYMM"<<"\n";
        }
        else if(c<13&&d>12&&c>0)
        {
            cout<<"MMYY"<<"\n";
        }
        else if(c<13&&d<13)
        {
            cout<<"AMBIGUOUS"<<"\n";
        }
        else
        {
            cout<<"NA"<<"\n";
        }

    }
    return 0;
}