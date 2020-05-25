#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int n,m;
vector<char> v;
int chk[16];

int dfs(int idx, int cnt, int a, int b)
{
    if(cnt==n)
    {
        string str = "";
        if(a>=1&&b>=2)
        {
            for (int i = 0; i < m; ++i)
            {
                if(chk[i]==1)
                {
                    str = str + v[i];
                }
            }
            cout<<str<<"\n";
            return 0;
        }

    }

    for (int i = idx+1; i < m; ++i)
    {
        if(v[i]=='a'||v[i]=='i'||v[i]=='e'||v[i]=='o'||v[i]=='u')
        {
            chk[i]= 1;
            dfs(i,cnt+1,a+1,b);
            chk[i] = 0;
        }
        else
        {
            chk[i]= 1;
            dfs(i,cnt+1,a,b+1);
            chk[i] = 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    char temp;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < m; ++i)
    {
        if(v[i]=='a'||v[i]=='i'||v[i]=='e'||v[i]=='o'||v[i]=='u')
        {
            chk[i]= 1;
            dfs(i,1,1,0);
            chk[i] = 0;
        }
        else
        {
            chk[i]= 1;
            dfs(i,1,0,1);
            chk[i] = 0;
        }
    }
    
}   