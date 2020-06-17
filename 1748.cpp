#include <vector>
#include <iostream>
using namespace std;


int conv(long long num)
{
    int cnt = 0;
    while(num>0)
    {
        cnt++;
        num = num/10;
    }
    return cnt;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long n;
    long long sum = 0;
    cin>>n;
    long long i = 1;
    while(i<=n)
    {
        sum = sum + conv(i);
        i++;
    }
    cout<<sum<<"\n";
    return 0;
}