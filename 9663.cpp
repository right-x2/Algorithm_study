#include <iostream>

using namespace std;

int arr[16][16];
int mn=100000;
int n;
int alcnt = 0;

int chk(int y, int x)
{
    int a = y;
    int b = x;
    // x축에 퀸 있는지 확인
    for (int i = 0; i < x; ++i)
    {
        if(arr[y][i]==1) return 0;   
    }
    // 왼쪽 위 대각선에 있는지 확인
    while(a>=0&&b>=0)
    {
        if(arr[a][b]==1) return 0;
        a--;
        b--;
    }
    a = y;
    b = x;
    // 왼쪽 아래 대각선에 있는지 확인
    while(a<n&&b>=0)
    {
        if(arr[a][b]==1) return 0;
        a++;
        b--;
    }
    return 1;
}

int dfs(int y, int x, int cnt)
{
    for (int i = 0; i < n; ++i)
    {
        if(i!=y)
        {
            if(chk(i,x+1))
            {
                if(cnt==n-1)
                {
                    alcnt++;
                    return 0;
                }
                arr[i][x+1] = 1;
                dfs(i,x+1,cnt+1);
                arr[i][x+1] = 0;
            }
        }
    }
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        arr[i][0] = 1;
        dfs(i,0,1);
        arr[i][0] = 0;
    }
    if(n==1) alcnt = 1;
    cout<<alcnt<<"\n";
    return 0;
}  