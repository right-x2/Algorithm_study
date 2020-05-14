#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    long long mod = 1234567891;
    long long n;
    long long mul = 1;
    long long sum = 0;
    cin>>n;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
        sum = sum + ((mul*(str[i]-'`'))%mod);
        mul = mul*31;
        mul = mul%mod;
    }
    cout<<sum%mod<<"\n";
    return 0;
}  