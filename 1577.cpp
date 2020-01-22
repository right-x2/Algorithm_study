#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
long long cc = 0;
int dfs(int a , int b , int cnt,int x, int y)
{
    //cout<<a<<" : a \n";
    //cout<<b<<" : b \n";
    if(a==x&&b==y)
    {
        //cout<<cc<<" cc \n";
        cc++;
        return 0;
    }
    if(a<x&&b<y)
    {
        dfs(a+1,b,cnt+1,x,y);
        dfs(a,b+1,cnt+1,x,y);
    }
    else if(a>=x&&b>=y) return 0;
    else if(a>=x) dfs(a,b+1,cnt+1,x,y);
    else if(b>=y) dfs(a+1,b,cnt+1,x,y);
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int  n,m,k,a,b,c,d;
    cin>>n>>m;
    /*
    cin>>k;
    for (int i = 0; i < k; ++i)
    {
        cin>>a>>b>>c>>d;
    }  
    */
    dfs(0,0,0,n,m);
    cout<<cc<<"\n";
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}