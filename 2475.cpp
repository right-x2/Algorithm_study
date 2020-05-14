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
    long long sum = 0;
    long long num;
    for (int i = 0; i < 5; ++i)
    {
        cin>>num;
        sum = sum + (num*num);
    }
    cout<<sum%10<<"\n";
    return 0;
}  