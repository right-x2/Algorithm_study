#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <vector>
using namespace std;

int arr[16][16];
int temp[16][16];
int ans;
vector<int> v;
int d;
int n,m;

int solve()
{
    int alcnt = 0;
    while(1)
    {
        int zcnt = 0;
        int cnt = 0;
        for(int i = 0; i < 3; i++)
        {
            int mn = 0;
            int ty = -1;
            int tx = -1;
            for (int j = n-1; j >= 0; --j)
            {
                for (int k = 0; k <m; ++k)
                {
                    if(arr[j][k]!=0&&abs(n-j)+abs(v[i]-k)<=d&&(mn==0||abs(n-j)+abs(v[i]-k)<=mn))
                    {
                        if(abs(n-j)+abs(v[i]-k)==mn)
                        {
                            if(k>tx) continue;
                        }
                        mn = abs(n-j)+abs(v[i]-k);
                        ty = j;
                        tx = k;
                    }
                }
            }
            if(ty!=-1)arr[ty][tx] = 2;
        }
        for (int i = 0; i < m; ++i)
        {
            if(arr[n-1][i]!=0) zcnt++;
            if(arr[n-1][i]==2) cnt++;
        }        
        for (int i = n-1; i > 0; i--)
        {
            for (int j = 0; j < m; ++j)
            {
                if(arr[i-1][j]!=0) zcnt++;
                if(arr[i-1][j]==2)
                {   
                    arr[i-1][j] = 0;
                    cnt++;
                }
                arr[i][j] = arr[i-1][j];
            }
        }
        for (int i = 0; i < m; ++i)arr[0][i] = 0;
        if(zcnt==0)
        {
            if(ans<alcnt) ans = alcnt;
            return 0;
        }
        else alcnt = alcnt + cnt;
    }
}

int dfs(int idx)
{
    if(v.size()==3)
    {
        solve();
        for (int i = 0; i < n; ++i)
        {
           for (int j = 0; j < m; ++j)
           {
               arr[i][j] = temp[i][j];
           }
        }
        return 0;
    }
    for (int i = idx+1; i <=14 ; ++i)
    {
        v.push_back(i);
        dfs(i);
        v.pop_back();        
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m>>d;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i <= 14; ++i)
    {
        v.push_back(i);
        dfs(i);
        v.pop_back();
    }
    cout<<ans<<"\n";
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}