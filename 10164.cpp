#include <iostream>
using namespace std;

int n,m,a,b;
int arr[16][16];
int alcnt;

int solve(int y, int x,int flag)
{
    if(y==a&&x==b){
        flag = 1;
    }
    if(y==n-1&&x==m-1){
        if(flag==1)alcnt++;
        return 0;
    }
    if(y+1<n){
        solve(y+1,x,flag);
    }
    if(x+1<m){
        solve(y,x+1,flag);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int cnt = 0;
    cin>>n>>m>>num;
    if(num==0){
        a = 0;
        b = 0;
    }
    else{
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cnt++;
                if(num==cnt)
                {
                    a = i;
                    b = j;
                    break;
                }
            }
        }        
    }
    solve(0,0,0);
    cout<<alcnt<<"\n";
    return 0;
}