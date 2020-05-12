#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long cnt;
long long ac; 
long long a;
long long b;
long long divide(long long y, long long x, long long ans, long long mul)
{
    if(ans<16)
    {
        if(a==y&&b==x) 
        {
            ac = cnt;
            return 0;
        }
        cnt++;
        if(a==y&&b==x+1) 
        {
            ac = cnt;
            return 0;
        }
        cnt++;
        if(a==y+1&&b==x)
        {
            ac = cnt;
            return 0;
        }
        cnt++;
        if(a==y+1&&b==x+1) 
        {
            ac = cnt;
            return 0;
        }
        cnt++;
        return 0;
    }
    if(x+mul>b&&y+mul>a) 
    {
        divide(y,x,ans/4,mul/2);
    }
    else if(x+mul<=b&&y+mul>a) 
    {
        cnt = cnt + ans/4;
        divide(y,x+mul,ans/4,mul/2);
    }
    else if(x+mul>b&&y+mul<=a)
    {
        cnt = cnt + (ans/4)*2;
        divide(y+mul,x,ans/4,mul/2);
    }
    else if(x+mul<=b&&y+mul<=a)
    {
        cnt = cnt + (ans/4)*3;
        divide(y+mul,x+mul,ans/4,mul/2);
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long ans = 1;
    int num;
    cin>>num>>a>>b;
    for(int i = 1; i <=num; i++ )
    {
        ans = ans *2;
    }
    long long mul = ans/2;
    ans = ans *ans;
    divide(0,0,ans,mul);
    cout<<ac<<"\n";
    return 0;
}  