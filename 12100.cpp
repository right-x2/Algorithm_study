#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[21][21];
int ans = 0;
int n;



void run(int idx)
{
    queue<int> q;
    int dx = 0;
    if(idx==0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(arr[j][i]!=0) 
                {
                    q.push(arr[j][i]);
                    arr[j][i] = 0;
                }
            }
            dx = 0;
            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                arr[dx][i] = tp;
                dx++;
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n-1; ++j)
            {
                if(arr[j][i]==arr[j+1][i]&&arr[j][i]!=0)
                {
                    arr[j][i] = arr[j][i]*2;
                    arr[j+1][i] = 0;
                }
            }
            for (int j = 0; j < n; ++j)
            {
                if(arr[j][i]!=0) 
                {
                    q.push(arr[j][i]);
                    arr[j][i] = 0;
                }
            }
            dx = 0;
            while(!q.empty())
            {

                int tp = q.front();
                q.pop();
                arr[dx][i] = tp;
                dx++;
            }
        }
        
    }
    if(idx==1)
    {
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = n-1; j >= 0; --j)
            {
                if(arr[i][j]!=0) 
                {
                    q.push(arr[i][j]);
                    arr[i][j] = 0;
                }
            }
            dx = n-1;
            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                arr[i][dx] = tp;
                dx--;
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = n-1; j > 0; --j)
            {
                if(arr[i][j]==arr[i][j-1]&&arr[i][j]!=0)
                {
                    arr[i][j] = arr[i][j]*2;
                    arr[i][j-1] = 0;
                }
            }
            for (int j = n-1; j >= 0; --j)
            {
                if(arr[i][j]!=0) 
                {
                    q.push(arr[i][j]);
                    arr[i][j] = 0;
                }
            }
            dx = n-1;
            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                arr[i][dx] = tp;
                dx--;
            }
        }
    }
    if(idx==2)
    {
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = n-1; j >=0; --j)
            {
                if(arr[j][i]!=0) 
                {
                    q.push(arr[j][i]);
                    arr[j][i] = 0;
                }
            }
            dx = n-1;
            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                arr[dx][i] = tp;
                dx--;
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = n-1; j > 0; --j)
            {
                if(arr[j][i]==arr[j-1][i]&&arr[j][i]!=0)
                {
                    arr[j][i] = arr[j][i]*2;
                    arr[j-1][i] = 0;
                }
            }
            for (int j = n-1; j >=0; --j)
            {
                if(arr[j][i]!=0) 
                {
                    q.push(arr[j][i]);
                    arr[j][i] = 0;
                }
            }
            dx = n-1;
            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                arr[dx][i] = tp;
                dx--;
            }
        }
    }
    if(idx==3)
    {
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(arr[i][j]!=0) 
                {
                    q.push(arr[i][j]);
                    arr[i][j] = 0;
                }
            }
            dx = 0;
            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                arr[i][dx] = tp;
                dx++;
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n-1; ++j)
            {
                if(arr[i][j]==arr[i][j+1]&&arr[i][j]!=0)
                {
                    arr[i][j] = arr[i][j]*2;
                    arr[i][j+1] = 0;
                }
            }
            for (int j = 0; j < n; ++j)
            {
                if(arr[i][j]!=0) 
                {
                    q.push(arr[i][j]);
                    arr[i][j] = 0;
                }
            }
            dx = 0;
            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                arr[i][dx] = tp;
                dx++;
            }
        }
    }
}

int solve(int cnt)
{
    int tmp[21][21];
    if(cnt==5)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if(arr[j][k]>ans) ans = arr[j][k];
            }
        }
        return 0;        
    }
    for (int j = 0; j < n; ++j)
    {
        for (int k = 0; k < n; ++k)
        {
            tmp[j][k] = arr[j][k];
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                
                arr[j][k] = tmp[j][k];
            }
            
        }
        run(i);
        solve(cnt+1);
    }

    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int tmp[21][21];
    cin>>n;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }   
    for (int i = 0; i < 4; ++i)
    {
        
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                arr[j][k] = tmp[j][k];
            }
        }
        run(i);
        solve(1);
    }
    
    cout<<ans<<"\n";
    return 0;
}