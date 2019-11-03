#include <string>
#include <vector>
#include <iostream>

using namespace std;
int room[1000001]={0,};
long long dp(int k , int c)
{
    long long sum;
    if(k%c != 0) sum = k/c + 1;
    else
    {
        sum = k/c;
    }
    return sum;
}
long long solution(int b, int c, int n)
{
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        room[i] = room[i] - b;
        if(room[i] > 0)
        {

            sum = sum + dp(room[i] , c) + 1;
        }
        else
        {
            sum++;
        }
    }
    return sum;
}
int main()
{
    int n, a, b, c;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>room[i];
    }
    cin>>b>>c;
    cout<<solution(b,c,n)<<" ";
}