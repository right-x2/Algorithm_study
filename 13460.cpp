#include <iostream>

using namespace std;
char cop[11][11];
char arr[11][11];
int chk[11][11];
int cb[11];
int mx = 12,a,b,ry,rx,by,bx,n,m,ary,arx,aby,abx;

int move(int j,int cnt)
{
    int a = ry,b = rx ,c = by,d = bx;

    if(cnt>10) return 0; 
    if(j==0)
    {
            if(arr[ry][rx+1]=='#') return 1;
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

            if(arr[ry][rx+1]=='O')
            {
                if(mx>cnt) mx = cnt;
                return 0;
            }
            else if(arr[by][bx+1]=='O')
            {
                return 0;
            }
            else
            {
                if(chk[ry][rx]==1) return 0;
                else 
                {
                    chk[ry][rx] = 1;
                    arr[a][b] ='.';
                    arr[c][d] ='.';
                    arr[ry][rx]='R';
                    arr[by][bx]='B';
                    return 1;
                }
            }  
    }
    if(j==1)
    {
        if(arr[ry][rx-1]=='#') return 1;
            if(rx<bx)
            {
                while(arr[ry][rx-1]=='.')
                {
                    rx--;
                }
                while(arr[by][bx-1]=='.')
                {
                    bx--;
                } 
                if(arr[ry][rx-1]=='O'&&arr[by][bx-2]=='O') return 0;              
            }
            else
            {
                while(arr[by][bx-1]=='.')
                {
                    bx--;
                }  
                while(arr[ry][rx-1]=='.')
                {
                    rx--;
                }
                if(arr[by][bx-1]=='O'&&arr[ry][rx-2]=='O') return 0;              
            }

            if(arr[ry][rx-1]=='O')
            {
                if(mx>cnt) mx = cnt;
                return 0;
            }
            else if(arr[by][bx-1]=='O')
            {
                return 0;
            }
            else
            {
                if(chk[ry][rx]==1) return 0;
                else 
                {
                    chk[ry][rx] = 1;
                    arr[a][b] ='.';
                    arr[c][d] ='.';
                    arr[ry][rx]='R';
                    arr[by][bx]='B';
                    return 1;
                }
            }  
    }
    if(j==2)
    {
        if(arr[ry-1][rx]=='#') return 1;
            if(ry<by)
            {
                while(arr[ry-1][rx]=='.')
                {
                    ry--;
                }
                while(arr[by-1][bx]=='.')
                {
                    by--;
                } 
                if(arr[ry-1][rx]=='O'&&arr[by-2][bx]=='O') return 0;              
            }
            else
            {
                while(arr[by-1][bx]=='.')
                {
                    by--;
                }  
                while(arr[ry-1][rx]=='.')
                {
                    rx--;
                }
                if(arr[by-1][bx]=='O'&&arr[ry-2][rx]=='O') return 0;              
            }

            if(arr[ry-1][rx]=='O')
            {
                if(mx>cnt) mx = cnt;
                return 0;
            }
            else if(arr[by-1][bx]=='O')
            {
                return 0;
            }
            else
            {
                if(chk[ry][rx]==1) return 0;
                else 
                {
                    chk[ry][rx] = 1;
                    arr[a][b] ='.';
                    arr[c][d] ='.';
                    arr[ry][rx]='R';
                    arr[by][bx]='B';
                    return 1;
                }
            }  
    }
    if(j==3)
    {
        if(arr[ry+1][rx]=='#') return 1;
            if(rx>bx)
            {
                while(arr[ry+1][rx]=='.')
                {
                    ry++;
                }
                while(arr[by+1][bx]=='.')
                {
                    by++;
                } 
                if(arr[ry+1][rx]=='O'&&arr[by+2][bx]=='O') return 0;              
            }
            else
            {
                while(arr[by+1][bx]=='.')
                {
                    by++;
                }  
                while(arr[ry+1][rx]=='.')
                {
                    ry++;
                }
                if(arr[by+1][bx]=='O'&&arr[ry+2][rx]=='O') return 0;              
            }

            if(arr[ry+1][rx]=='O')
            {
                if(mx>cnt) mx = cnt;
                return 0;
            }
            else if(arr[by+1][bx]=='O')
            {
                return 0;
            }
            else
            {
                if(chk[ry][rx]==1) return 0;
                else 
                {
                    chk[ry][rx] = 1;
                    arr[a][b] ='.';
                    arr[c][d] ='.';
                    arr[ry][rx]='R';
                    arr[by][bx]='B';
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < m; ++j)
                        {
                            cout<<arr[i][j]<<" ";
                        }
                        cout<<""<"\n";
                    }
                    return 1;
                }
            }  
    }
}

int play(int cnt)
{
    for (int i = 0; i < 10; ++i)
    {
        if(!move(cb[i],i+1))
        {
            for (int k = 0; k < a; ++k)
            {
                for (int j = 0; j < b; ++j)
                {
                    arr[k][j] = cop[k][j];
                }
            }
            ry = ary;
            rx = arx;
            by = aby;
            bx = abx;
            return 0;
        }
    }
    return 0;
}
int cbn(int j,int cnt)
{
    if(cnt==10) play(cnt);
    for (int i = 0; i < 4; ++i)
    {
        if(i!=j)
        {
            cb[cnt] = i;
            cbn(i,cnt+1);
            cb[cnt] = 0;
        }
    }
}



int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='R')
            {
                ry = i;
                rx = j;
                ary = i;
                arx = j;
            }
            else if(arr[i][j]=='B')
            {
                by = i;
                bx = j;
                aby = i;
                abx = j;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cop[i][j] = arr[i][j];
        }
    }
    cbn(-1,0);
    cout<<mx<<"\n";
    return 0;
}  