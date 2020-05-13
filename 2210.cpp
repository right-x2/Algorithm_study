#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> v;
char arr[6][6];


int dfs(int a, int b,string str,int cnt)
{
    if(cnt==6)
    {
        int flag = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i]==str)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)v.push_back(str);
        return 0;
    }

    if(a+1<5)
    {
        dfs(a+1,b,str+arr[a+1][b],cnt+1);
    }
    if(b+1<5)
    {
        dfs(a,b+1,str+arr[a][b+1],cnt+1);
    }
    if(a-1>=0)
    {
        dfs(a-1,b,str+arr[a-1][b],cnt+1);

    }
    if(b-1>=0)
    {
        dfs(a,b-1,str+arr[a][b-1],cnt+1);
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            string st = "";
            dfs(i,j,st+arr[i][j],1);
        }
    }
    cout<<v.size()<<"\n";
    return 0;
}  