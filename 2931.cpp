#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int flag = 0;
char arr[26][26];
int chk[26][26];
int dflag = 0;
char puz[7] ={'|','-','+','1','2','3','4'};
int n,m;
int sy,sx,ey,ex;

int ay=-1,ax=-1;
int answer;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int dfs(int py,int px,int y,int x)
{
    if(y>=n||y<0||x>=m||x<0) 
    {
        flag = 1;
        return 0;
    }
    chk[y][x]++;
    if(arr[y][x]=='.')
    {
        if(ay==-1&&ay==-1)
        {
            ay = y;
            ax = x;            
        }
        else
        {
            flag = 1;
        }
        return 0;
    }
    else if(arr[y][x]=='|')
    {
        if(!(px==x&&py==y-1)&&!(px==x&&py==y+1))
        {
            flag = 1;
            return 0;
        }
        if(py>y) 
        {
            dfs(y,x,y-1,x);
        }
        else 
        {
           dfs(y,x,y+1,x); 
        }
    }
    else if(arr[y][x]=='-')
    {
        if(!(px==x-1&&py==y)&&!(px==x+1&&py==y))
        {
            flag = 1;
            return 0;
        }
        if(px>x) 
        {
           dfs(y,x,y,x-1); 
        }
        else 
        {
            dfs(y,x,y,x+1);
        }
    }
    else if(arr[y][x]=='+')
    {
        if(y==py&&x>px)
        {
            dfs(y,x,y,x+1);
        }
        else if(y==py&&x<px)
        {
            dfs(y,x,y,x-1);         
        }
        else if(y>py&&x==px)
        {
            dfs(y,x,y+1,x);              
        }
        else if(y<py&&x==px)
        {
            dfs(y,x,y-1,x);             
        }
    }
    else if(arr[y][x]=='1')
    {
        if(!(px==x&&py==y+1)&&!(px==x+1&&py==y))
        {
            flag = 1;
            return 0;
        }
       if(x==px)
       {
          dfs(y,x,y,x+1);
       }
       else if(y==py)
       {
          dfs(y,x,y+1,x);
       }
    }
    else if(arr[y][x]=='2')
    {
        if(!(px==x&&py==y-1)&&!(px==x+1&&py==y))
        {
            flag = 1;
            return 0;
        }
       if(x==px)
       {
          dfs(y,x,y,x+1);
       }
       else if(y==py)
       {
          dfs(y,x,y-1,x);
       }
    }
    else if(arr[y][x]=='3')
    {
        if(!(px==x&&py==y-1)&&!(px==x-1&&py==y))
        {
            flag = 1;
            return 0;
        }
       if(x==px)
       {
          dfs(y,x,y,x-1);
       }
       else if(y==py)
       {
          dfs(y,x,y-1,x);
       }
    }
    else if(arr[y][x]=='4')
    {
        if(!(px==x&&py==y+1)&&!(px==x-1&&py==y))
        {
            flag = 1;
            return 0;
        }
       if(x==px)
       {
          dfs(y,x,y,x-1);
       }
       else if(y==py)
       {
          dfs(y,x,y+1,x);
       }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    char a;
    int ny,nx;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='M')
            {
                sy = i;
                sx = j;
            }
            else if(arr[i][j]=='Z')
            {
                ey = i;
                ex = j;
            }     
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if(sy+dy[i]<n&&sy+dy[i]>=0&&sx+dx[i]<m&&sx+dx[i]>=0)
        {
            if(i==0&&(arr[sy+1][sx]=='|'||arr[sy+1][sx]=='+'||arr[sy+1][sx]=='2'||arr[sy+1][sx]=='3'))
            {
                ny = sy+dy[i];
                nx = sx+dx[i];
                chk[sy][sx]++;
                dfs(sy,sx,sy+dy[i],sx+dx[i]);
                break;                
            }
            else if(i==1&&(arr[sy-1][sx]=='|'||arr[sy-1][sx]=='+'||arr[sy-1][sx]=='1'||arr[sy-1][sx]=='4'))
            {
                ny = sy+dy[i];
                nx = sx+dx[i];
                chk[sy][sx]++;
                dfs(sy,sx,sy+dy[i],sx+dx[i]);
                break;                     
            }
            else if(i==2&&(arr[sy][sx+1]=='-'||arr[sy][sx+1]=='+'||arr[sy][sx+1]=='3'||arr[sy][sx+1]=='4'))
            {
                ny = sy+dy[i];
                nx = sx+dx[i];
                chk[sy][sx]++;
                dfs(sy,sx,sy+dy[i],sx+dx[i]);
                break;                   
            }
            else if(i==3&&(arr[sy][sx-1]=='-'||arr[sy][sx-1]=='+'||arr[sy][sx-1]=='1'||arr[sy][sx-1]=='2'))
            {
                ny = sy+dy[i];
                nx = sx+dx[i];
                chk[sy][sx]++;
                dfs(sy,sx,sy+dy[i],sx+dx[i]);
                break;   
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            chk[i][j] = 0;   
        }
    }
    for (int i = 0; i < 7; ++i)
    {
        flag = 0;
        dflag = 0;
        arr[ay][ax] = puz[i];
        chk[sy][sx] = 1;
        dfs(sy,sx,ny,nx);
        answer = i;
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                if(chk[j][k]==0&&arr[j][k]!='.') flag = 1;
                chk[j][k] = 0;   
            }
        }
        if(flag==0) break;
    }
    
    cout<<ay+1<<" "<<ax+1<<" "<<puz[answer]<<"\n";
    return 0;
}