#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m,k;
int arr[1001][3];
int chk[1001][3][31];

int solve(int y, int x, int cnt)
{
    if(cnt>m) return 0;
    if(chk[y][x][cnt]!=0) return chk[y][x][cnt];
    int tmp = 0;
    if(arr[y][x]==1) tmp = 1;
    if(y==n-1) return tmp;
    if(arr[y+1][x]==1||cnt==m)chk[y][x][cnt] = tmp+solve(y+1,x,cnt);
    else
    {
        int a,b;
        if(x==1)
        {
            b = tmp+solve(y+1,x+1,cnt+1);
        }
        else
        {
            b = tmp+solve(y+1,x-1,cnt+1);
        }
        a = tmp+solve(y+1,x,cnt);
        chk[y][x][cnt] = max(a,b);
    }

    return chk[y][x][cnt];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        cin>>num;
        arr[i][num] = 1;
    }

    cout<<max(solve(0,2,1),solve(0,1,0))<<"\n";
    
    
    return 0;
}