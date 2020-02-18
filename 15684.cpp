#include <iostream>

using namespace std;

int mn = 5;
int arr[301][301];
int ans[301];
int n,m,h;

int chk(int k,int i, int j)
{
    int flag = 0;
    while(i<n+2)
    {
        if(flag == 0)
        {
            
             if(j>1&&j<m)
            {
                if((arr[i][j]!=0&&arr[i][j+1]!=0)&&arr[i][j]==arr[i][j+1])
                {
                    j = j + 1;
                    flag = 1;
                }
                else if((arr[i][j]!=0&&arr[i][j-1]!=0)&&arr[i][j]==arr[i][j-1])
                {
                    j = j - 1;
                    flag = 1;
                }
                else
                {
                    i = i + 1;
                }    
            }
            else if(j==1)
            {
                 if((arr[i][j]!=0&&arr[i][j+1]!=0)&&arr[i][j]==arr[i][j+1])
                {
                    j = j + 1;
                    flag = 1;
                } 
                else
                {
                    i = i + 1;
                } 
            }
            else if(j==m)
            {
                if((arr[i][j]!=0&&arr[i][j-1]!=0)&&arr[i][j]==arr[i][j-1])
                {
                    j = j -1;
                    flag = 1;
                } 
                else
                {
                    i = i + 1;
                }            
            }       
        }
        else 
        {
            flag = 0;
            i++;
        }        
    }
    return j;
}

int dfs(int cnt, int tt)
{
    tt++;
    int flag = 0;
    if(cnt>3) return 0;
    
    if(cnt==3)
    {
        for (int i = 1; i <= m; ++i)
        {
            if(chk(i,1,i)!=i)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            if(mn>cnt) mn =  cnt;
        }
        return 0;
    }
    else
    {
        for (int i = 1; i <= m; ++i)
        {
            if(chk(i,1,i)!=i)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            if(mn>cnt) mn = cnt;
        }      
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if(arr[i][j]==0&&arr[i][j+1]==0)
            {
                arr[i][j] = tt;
                arr[i][j+1] = tt;
                dfs(cnt+1,tt);
                arr[i][j] = 0;
                arr[i][j+1] = 0;
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
    int a,b,cnt = 2,flag =0;
    cin>>m>>h>>n;

    for (int i = 0; i < h; ++i)
    {
        cin>>a>>b;
        arr[a][b] = cnt;
        arr[a][b+1] = cnt;
        cnt++;
    }
    for (int i = 1; i <= m; ++i)
    {
        if(chk(i,1,i)!=i)
        {
            flag = 1;
            break;
        }
    } 
    if(flag == 0) cout<<0<<"\n";
    else
    {    
       for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if(arr[i][j]==0&&arr[i][j+1]==0)
                {
                    arr[i][j] = cnt;
                    arr[i][j+1] = cnt;
                    dfs(1,cnt);
                    arr[i][j] = 0;
                    arr[i][j+1] = 0;
                }
            }
        }
    
        if(mn==5) cout<<-1<<"\n";
        else cout<<mn<<"\n";
    }
}  