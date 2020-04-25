#include <iostream>
#include <queue>
using namespace std;

int n,m;
int dp[10001];
vector<int> v;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    string tg;

    getline(cin, str);
    getline(cin, tg);
    int cnt = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]==tg[0])
        {
            if(str.substr(i,tg.length())==tg)
            {
                cnt++;
                i = i + tg.length()-1;
            }
        }
    }

    cout<<cnt<<"\n";

    return 0;
}