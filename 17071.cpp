#include <iostream>
#include <cstdlib>

using namespace std;
int mn = 500000;
int ck[500000];

int move(int n, int k, int cnt)
{
    cout<<n<<" "<<k<<"\n";
    if(cnt>mn) return 0;
    if(n<0||n>50||k>50) return 0;
    if(n==k)
    {
        if(cnt<mn) mn = cnt;
        return 0;
    }

    cnt++;
    if(ck[k]==0)
    {
        ck[n] = cnt;
    }
    else 
    {
        if(ck[n]>cnt) ck[n] = cnt;
        else return 0;
    }
    
    move(n*2,k+cnt,cnt);
    move(n+1,k+cnt,cnt);
    move(n-1,k+cnt,cnt);
    
    
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    move(n,k,0);
    cout<<mn<<"\n";
    return 0;
}  