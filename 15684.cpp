#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int mn = 3;
int arr[13][13];
int ans[13];
int n,m,h;

int chk(int k,int i, int j)
{
    while(i<m+2)
    {
        int flag = 0;
        if(flag ==0)
        {
             if(j>1&&j<n)
            {
                 if(arr[i][j]==0&&arr[i][j+1]==0)
                {
                    j = j + 1;
                    flag = 1;
                } 
                else if(arr[i][j]==0&&arr[i][j-1]==0)
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
                 if(arr[i][j]==0&&arr[i][j+1]==0)
                {
                    j = j + 1;
                    flag = 1;
                } 
                else
                {
                    i = i + 1;
                } 
            }
            else if(j==n)
            {
                if(arr[i][j]==0&&arr[i][j-1]==0)
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
        else j++;        
    }
    ans[k] = j;
    return 0;

}

int dfs(int cnt)
{
    
    cout<<""<<"\n";
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<""<<"\n";
    }
    
    int flag = 0;
    
    if(cnt>mn) return 0;
    /*
    if(cnt==3)
    {
        chk(1,1,1);
        chk(2,2,2);
        chk(3,3,3);
        chk(4,4,4);
        chk(5,5,5);
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i]!=i)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            if(mn>cnt) mn = cnt;
        }
        for (int i = 1; i <=n; ++i)
        {
             ans[i] = 0;
        }  
        return 0;
    }
    else
    {
        chk(1,1,1);
        chk(2,2,2);
        chk(3,3,3);
        chk(4,4,4);
        chk(5,5,5);
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i]!=i)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            if(mn>cnt) mn = cnt;
        }
        for (int i = 1; i <=n; ++i)
        {
             ans[i] = 0;
        }        
    }
    */
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if(arr[i][j]==0&&arr[i][j+1]==0)
            {
                arr[i][j] = 1;
                arr[i][j+1] = 1;
                dfs(cnt+1);
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
    int a,b;
    cin>>n>>h>>m;

    for (int i = 0; i < h; ++i)
    {
        cin>>a>>b;
        arr[a][b] = 1;
        arr[a][b+1] = 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<""<<"\n";
    }
    
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if(arr[i][j]==0&&arr[i][j+1]==0)
            {
                arr[i][j] = 1;
                arr[i][j+1] = 1;
                dfs(1);
                arr[i][j] = 0;
                arr[i][j+1] = 0;
            }
        }
    }
    
    if(mn==5) cout<<-1<<"\n";
    else cout<<mn<<"\n";
}  