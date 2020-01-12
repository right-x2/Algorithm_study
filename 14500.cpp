#include <iostream>

using namespace std;

int n,m;
int arr[501][501];
int chk[501][501];
int mx = 0;

int play(int a, int b,int cnt, int sum)
{

    if(cnt==4)
    {
        if(sum>mx) mx = sum;
        return 0;
    }
    for (int i = 0; i < 4; ++i)
    {
            if(i==0)
            {
                if(b+1<m)
                {
                    if(chk[a][b+1]==0)
                    {
                        chk[a][b+1]=1;
                        play(a,b+1,cnt+1,sum + arr[a][b+1]);
                        chk[a][b+1]=0;
                    }
                    else if(chk[a][b+1]==1)
                    {
                        chk[a][b+1]=2;
                        play(a,b+1,cnt,sum);
                        chk[a][b+1]=1;
                    }
                }
            }
            else if(i==1)
            {
                if(b-1>=0)
                {
                    if(chk[a][b-1]==0)
                    {
                        chk[a][b-1]=1;
                        play(a,b-1,cnt+1,sum + arr[a][b-1]);
                        chk[a][b-1]=0;
                    }
                    else if(chk[a][b-1]==1)
                    {
                        chk[a][b-1]=2;
                        play(a,b-1,cnt,sum);
                        chk[a][b-1]=1;
                    }
                }
            }
            else if(i==2)
            {
                if(a-1>=0)
                {
                    if(chk[a-1][b]==0)
                    {
                        chk[a-1][b]=1;
                        play(a-1,b,cnt+1,sum + arr[a-1][b]);
                        chk[a-1][b]=0;
                    }
                    else if(chk[a-1][b]==1)
                    {
                        chk[a-1][b]=2;
                        play(a-1,b,cnt,sum);
                        chk[a-1][b]=1;
                    }
                }
            }
            else
            {
                if(a+1<n)
                {
                    if(chk[a+1][b]==0)
                    {
                        chk[a+1][b]=1;
                        play(a+1,b,cnt+1,sum + arr[a+1][b]);
                        chk[a+1][b]=0;
                    }
                    else if(chk[a+1][b]==1)
                    {
                        chk[a+1][b]=2;
                        play(a+1,b,cnt,sum);
                        chk[a+1][b]=1;
                    }
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
    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            chk[i][j]=1;
            play(i,j,1,arr[i][j]);
            chk[i][j]=0;
        }
    }
    cout<<mx<<"\n";
    return 0;
}  