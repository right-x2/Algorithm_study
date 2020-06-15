#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int arr[11][11];
int chk[11][11];
int ans = -1;
int card[6];
int search(int y, int x, int cnt)
{
    for (int i = 0; i <= cnt; ++i)
    {
        for (int j = 0; j <= cnt; ++j)
        {
            if(y+i>9||x+j>9||arr[y+i][x+j]==0||chk[y+i][x+j]==1) return 0;
        }
    }

    return 1;
}

int clean(int y, int x, int cnt)
{
    for (int i = 0; i <= cnt; ++i)
    {
        for (int j = 0; j <= cnt; ++j)
        {
            chk[y+i][x+j] = 0;
        }
    }
    return 1;    
}

int spray(int y, int x, int cnt)
{
    for (int i = 0; i <= cnt; ++i)
    {
        for (int j = 0; j <= cnt; ++j)
        {
            chk[y+i][x+j] = 1;
        }
    }
    return 1;    
}
int dfs(int y, int x, int cnt)
{
    if(ans!=-1&&cnt>ans) return 0;
    if(y<10)
    {
        int flag = 0;
        for (int i = y; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if(arr[i][j]==1&&chk[i][j]==0)
                {   
                    flag=1;
                    for (int k = 4; k >= 0; --k)
                    {
                        if(card[k]<5&&search(i,j,k)==1)
                        {
                            card[k]++;
                            spray(i,j,k);
                            if(j+k<9) dfs(i,j+k+1,cnt+1);
                            else dfs(i+1,0,cnt+1);
                            clean(i,j,k);
                            card[k]--;
                        }
                    }
                    break;
                }
            }
            if(flag==1) break;
        }
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if(chk[i][j]!=arr[i][j])
                {
                    return 0;
                }
            }
        }
    }
    if(ans==-1||ans>cnt) ans = cnt;
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int zcnt = 0;
    int flag = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)zcnt++;
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if(arr[i][j]==1)
            {
                flag=1;
                for (int k = 4; k >= 0; --k)
                {
                    if(card[k]<5&&search(i,j,k)==1)
                    {
                        card[k]++;
                        spray(i,j,k);
                        if(j+k<9) dfs(i,j+k+1,1);
                        else dfs(i+1,0,1);
                        clean(i,j,k);
                        card[k]--;
                    }
                }
                break;
            }
        }
        if(flag==1) break;
    }
    if(zcnt==0)cout<<0<<"\n";
    else cout<<ans<<"\n";
    return 0;
}