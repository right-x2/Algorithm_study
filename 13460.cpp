#include <iostream>

using namespace std;

char arr[11][11];
int chk[11][11];
int min = 12;
int move(int j,int cnt,int ry,int rx,int by,int bx)
{
    if(cnt>10) return 0; 
    if(j==0)
    {
        else
        {
            if(rx>bx)
            {
                while(arr[ry][rx+1]=='.')
                {
                    rx++;
                }
                while(arr[by][bx+1]=='.')
                {
                    bx++;
                } 
                if(arr[ry][rx+1]=='O'&&arr[by][bx+2]=='O') return 0;              
            }
            else
            {
                while(arr[by][bx+1]=='.')
                {
                    bx++;
                }  
                while(arr[ry][rx+1]=='.')
                {
                    rx++;
                }
                if(arr[by][bx+1]=='O'&&arr[ry][rx+2]=='O') return 0;              
            }
            
            else if(arr[ry][rx+1]=='O')
            {
                if(min>cnt) mx = cnt;
            }
            else if(arr[by][bx+1]=='O')
            {
                return 0;
            }
            else
            {
                if(chk[ry][rx]==1) return 0;
                else chk[ry][rx] = 1;
            }  
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if(i==0&&arr[ry][rx+1]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
        else if(i==1&&arr[ry][rx-1]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
        else if(i==2&&arr[ry-1][rx]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
        else if(i==3&&arr[ry+1][rx]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,rx,ry,bx,by;
    cin>>a>>b;
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='R')
            {
                ry = i;
                rx = j;
            }
            else if(arr[i][j]=='B')
            {
                by = i;
                bx = j;
            }
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if(i==0&&arr[ry][rx+1]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
        else if(i==1&&arr[ry][rx-1]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
        else if(i==2&&arr[ry-1][rx]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
        else if(i==3&&arr[ry+1][rx]!='#')
        {
            move(i,1,ry,rx,by,bx);
        }
    }
    return 0;
}  