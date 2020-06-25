#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char arr[11][11];
char temp[11][11];
vector<int> v;
vector<int> av;
int ans = 0;
int bx,by,rx,ry;
int n,m;
int run(int idx,int cnt)
{
   // cout<<cnt<<"\n";
    arr[ry][rx] = '.';
    arr[by][bx] = '.';
    int flag = 0;
    if(idx==0)
    {
        if(ry>by)
        {

            for (int i = ry; i <n ; ++i)
            {
                if(arr[i][rx]=='#')
                {
                    arr[i-1][rx] = 'R';
                    break;
                }
                else if(arr[i][rx]=='O')
                {
                    flag = 1;
                    break;
                    
                }
            }
            for (int i = by; i <n ; ++i)
            {
                if(arr[i][bx]=='#'||arr[i][bx]=='R')
                {
                    if(flag==1)
                    {
                        if(ans==0||ans>cnt) 
                        {
                            ans = cnt;
                            av.clear();
                            for (int j = 0; j < v.size(); ++j)
                            {
                                av.push_back(v[j]);
                            }                            
                        }
                        return 0;
                    }
                    arr[i-1][bx] = 'B';
                    return 1;
                }
                else if(arr[i][bx]=='O')
                {
                    return 0;
                }
            }
        }
        else
        {
            for (int i = by; i <n ; ++i)
            {
                if(arr[i][bx]=='#')
                {
                    arr[i-1][bx] = 'B';
                    break;
                }
                else if(arr[i][bx]=='O')
                {
                    return 0;
                }
            }
            for (int i = ry; i <n ; ++i)
            {
                if(arr[i][rx]=='#'||arr[i][rx]=='B')
                {
                    arr[i-1][rx] = 'R';
                    return 1;
                }
                else if(arr[i][rx]=='O')
                {
                    if(ans==0||ans>cnt) 
                    {
                        ans = cnt;
                        av.clear();
                        for (int j = 0; j < v.size(); ++j)
                        {
                            av.push_back(v[j]);
                        }
                    }
                    return 0;
                }
            }
        }            
    }
    if(idx==1)
    {
        
        if(rx>bx)
        {
            for (int i = rx; i <m ; ++i)
            {
                if(arr[ry][i]=='#')
                {
                    arr[ry][i-1] = 'R';
                    break;
                }
                else if(arr[ry][i]=='O')
                {
                    flag = 1;
                    break;
                }
            }
            for (int i = bx; i <m ; ++i)
            {
                if(arr[by][i]=='#'||arr[by][i]=='R')
                {
                    if(flag==1)
                    {
                        if(ans==0||ans>cnt) 
                        {
                            ans = cnt;
                            av.clear();
                            for (int j = 0; j < v.size(); ++j)
                            {
                                av.push_back(v[j]);
                            }
                        }
                        return 0;
                    }
                    arr[by][i-1] = 'B';
                    return 1;
                }
                else if(arr[by][i]=='O')
                {
                    return 0;
                }
            }
        }
        else
        {
            for (int i = bx; i <m ; ++i)
            {
                if(arr[by][i]=='#')
                {
                    arr[by][i-1] = 'B';
                    break;
                }
                else if(arr[by][i]=='O')
                {
                    return 0;
                }
            }
            for (int i = rx; i <m ; ++i)
            {
                if(arr[ry][i]=='#'||arr[ry][i]=='B')
                {
                    arr[ry][i-1] = 'R';
                    return 1;
                }
                else if(arr[ry][i]=='O')
                {
                    if(ans==0||ans>cnt) 
                    {
                        ans = cnt;
                        av.clear();
                        for (int j = 0; j < v.size(); ++j)
                        {
                            av.push_back(v[j]);
                        }
                    }
                    return 0;
                }
            }
        } 
    }
    if(idx==2)
    {
        
        if(ry<by)
        {
            for (int i = ry; i >=0 ; --i)
            {
                if(arr[i][rx]=='#')
                {
                    arr[i+1][rx] = 'R';
                    break;
                }
                else if(arr[i][rx]=='O')
                {
                    flag = 1;
                    break;
                }
            }
            for (int i = by; i >=0 ; --i)
            {
                if(arr[i][bx]=='#'||arr[i][bx]=='R')
                {
                    if(flag==1)
                    {
                        if(ans==0||ans>cnt) 
                        {
                            ans = cnt;
                            av.clear();
                            for (int j = 0; j < v.size(); ++j)
                            {
                                av.push_back(v[j]);
                            }
                        }
                        return 0;
                    }
                    arr[i+1][bx] = 'B';
                    return 1;
                }
                else if(arr[i][bx]=='O')
                {
                    return 0;
                }
            }
        }
        else
        {
            for (int i = by; i >=0 ; --i)
            {
                if(arr[i][bx]=='#')
                {
                    arr[i+1][bx] = 'B';
                    break;
                }
                else if(arr[i][bx]=='O')
                {
                    return 0;
                }
            }
            for (int i = ry; i >=0 ; --i)
            {
                if(arr[i][rx]=='#'||arr[i][rx]=='B')
                {
                    arr[i+1][rx] = 'R';
                    return 1;
                }
                else if(arr[i][rx]=='O')
                {
                    if(ans==0||ans>cnt) 
                    {
                        ans = cnt;
                        av.clear();
                        for (int j = 0; j < v.size(); ++j)
                        {
                            av.push_back(v[j]);
                        }
                    }
                    return 0;
                }
            }
        }  
    }
    if(idx==3)
    {
        
        if(rx<bx)
        {
            for (int i = rx; i >=0 ; --i)
            {
                if(arr[ry][i]=='#')
                {
                    arr[ry][i+1] = 'R';
                    break;
                }
                else if(arr[ry][i]=='O')
                {
                    flag = 1;
                    break;
                }
            }
            for (int i = bx; i >=0 ; --i)
            {
                if(arr[by][i]=='#'||arr[by][i]=='R')
                {   
                    if(flag==1)
                    {
                        if(ans==0||ans>cnt) 
                        {
                            ans = cnt;
                            av.clear();
                            for (int j = 0; j < v.size(); ++j)
                            {
                                av.push_back(v[j]);
                            }
                        }
                        return 0;
                    }
                    arr[by][i+1] = 'B';
                    return 1;
                }
                else if(arr[by][i]=='O')
                {
                    return 0;
                }
            }
        }
        else
        {
            for (int i = bx; i >=0 ; --i)
            {
                if(arr[by][i]=='#')
                {
                    arr[by][i+1] = 'B';
                    break;
                }
                else if(arr[by][i]=='O')
                {
                    return 0;
                }
            }
            for (int i = rx; i >=0 ; --i)
            {
                if(arr[ry][i]=='#'||arr[ry][i]=='B')
                {
                    arr[ry][i+1] = 'R';
                    return 1;
                }
                else if(arr[ry][i]=='O')
                {
                    if(ans==0||ans>cnt) 
                    {
                        ans = cnt;
                        av.clear();
                        for (int j = 0; j < v.size(); ++j)
                        {
                            av.push_back(v[j]);
                        }
                    }
                    return 0;
                }
            }
        } 
    }
    return 1;
}

int solve(int cnt)
{

    int tmp[21][21];
    if(cnt>10) return 0;
    for (int j = 0; j < n; ++j)
    {
        for (int k = 0; k < m; ++k)
        {
            tmp[j][k] = arr[j][k];
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                arr[j][k] = tmp[j][k];
                if(tmp[j][k]=='R')
                {
                    ry = j;
                    rx = k;
                }
                if(tmp[j][k]=='B')
                {
                    by = j;
                    bx = k;
                }
            }
            
        }
        v.push_back(i);
        int bol = run(i,cnt);
        if(bol==1)solve(cnt+1);
        v.pop_back();
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int tmp[21][21];
    cin>>n>>m;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
            if(tmp[i][j]=='R')
            {
                ry = i;
                rx = j;
            }
            if(tmp[i][j]=='B')
            {
                by = i;
                bx = j;
            }
        }
    } 
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                arr[j][k] = tmp[j][k];
                if(tmp[j][k]=='R')
                {
                    ry = j;
                    rx = k;
                }
                if(tmp[j][k]=='B')
                {
                    by = j;
                    bx = k;
                }
            }
        }
        v.push_back(i);
        int bol = run(i,1);
        if(bol==1)solve(2);
        v.pop_back();
    }
    if(ans==0)cout<<-1<<"\n";
    else 
    {
      cout<<ans<<"\n"; 
      for (int i = 0; i < av.size(); ++i)
      {
        if(av[i]==0)cout<<'D'<<"";
        else if(av[i]==1)cout<<'R'<<"";
        else if(av[i]==2)cout<<'U'<<"";
        else if(av[i]==3)cout<<'L'<<"";
      } 
    }

    return 0;
}