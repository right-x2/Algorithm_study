#include <iostream>
using namespace std;

int dp[4001][4001];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    string temp;
    int mx = 0;
    cin>>str;
    cin>>temp;

    for (int i = 1; i <= str.length(); ++i)
    {
        for (int j = 1; j <= temp.length(); ++j)
        {
            if(str[i-1]==temp[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            if(mx<dp[i][j]) mx = dp[i][j];
        }
    }
    cout<<mx<<"\n";
    return 0;
}