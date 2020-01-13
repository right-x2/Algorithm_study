#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10][10];
int tmp[10][10];
int n,m;
int mn = 64;
vector< pair<int,int> > v;
int spay(int a, int b,int k,int idx)
{
    if(k==0)
    {
        for (int i = b+1; i < m; ++i)
        {
            if(arr[a][i]==0) arr[a][i]=idx;
            else if(arr[a][i]==6) break;
        }
    }
    else if(k==1)
    {
        for (int i = b-1; i >= 0; --i)
        {
            if(arr[a][i]==0) arr[a][i]=idx;
            else if(arr[a][i]==6) break;
        }
    }
    else if(k==2)
    {
        for (int i = a+1; i < n; ++i)
        {
            if(arr[i][b]==0) arr[i][b]=idx;
            else if(arr[i][b]==6) break;
        }
    }
    else if(k==3)
    {
        for (int i = a-1; i >= 0; --i)
        {
            if(arr[i][b]==0) arr[i][b]=idx;
            else if(arr[i][b]==6) break;
        }
    }
    return 0;
}
int ex(int a, int b,int k, int idx)
{
    if(k==0)
    {
        for (int i = b+1; i < m; ++i)
        {
            if(arr[a][i]==idx) arr[a][i]=0;
            else if(arr[a][i]==6) break;
        }
    }
    else if(k==1)
    {
        for (int i = b-1; i >= 0; --i)
        {
            if(arr[a][i]==idx) arr[a][i]=0;
            else if(arr[a][i]==6) break;
        }
    }
    else if(k==2)
    {
        for (int i = a+1; i < n; ++i)
        {
            if(arr[i][b]==idx) arr[i][b]=0;
            else if(arr[i][b]==6) break;
        }
    }
    else if(k==3)
    {
        for (int i = a-1; i >= 0; --i)
        {
            if(arr[i][b]==idx) arr[i][b]=0;
            else if(arr[i][b]==6) break;
        }
    }
    return 0;
}
int dfs(int a, int b,int k,int cnt)
{
    int count = 0;
    if(cnt==v.size())
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(arr[i][j]==0) count++;
            }
        }
        if(count<mn) mn = count;
        return 0;
    }
    if(k==1)
    {
        spay(a,b,0,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,0,cnt+7);

        spay(a,b,1,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,1,cnt+7);

        spay(a,b,2,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,2,cnt+7);

        spay(a,b,3,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,3,cnt+7);
    }
    if(k==2)
    {
        for (int i = 0; i < 3; ++i)
        {
            if(i!=1)
            {
                int x = i;
                spay(a,b,x,cnt+7);
                spay(a,b,x+1,cnt+7);
                if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
                else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
                ex(a,b,x,cnt+7);
                ex(a,b,x+1,cnt+7);
            }
        }
    }
    if(k==3)
    {
        spay(a,b,0,cnt+7);
        spay(a,b,3,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,0,cnt+7);
        ex(a,b,3,cnt+7);

        spay(a,b,0,cnt+7);
        spay(a,b,2,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,0,cnt+7);
        ex(a,b,2,cnt+7);

        spay(a,b,1,cnt+7);
        spay(a,b,2,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,1,cnt+7);
        ex(a,b,2,cnt+7);

        spay(a,b,1,cnt+7);
        spay(a,b,3,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,1,cnt+7);
        ex(a,b,3,cnt+7);
    }
    if(k==4)
    {
        spay(a,b,0,cnt+7);
        spay(a,b,1,cnt+7);
        spay(a,b,3,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,0,cnt+7);
        ex(a,b,1,cnt+7);
        ex(a,b,3,cnt+7);

        spay(a,b,0,cnt+7);
        spay(a,b,2,cnt+7);
        spay(a,b,3,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,0,cnt+7);
        ex(a,b,2,cnt+7);
        ex(a,b,3,cnt+7);

        spay(a,b,0,cnt+7);
        spay(a,b,1,cnt+7);
        spay(a,b,2,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,0,cnt+7);
        ex(a,b,1,cnt+7);
        ex(a,b,2,cnt+7);

        spay(a,b,3,cnt+7);
        spay(a,b,2,cnt+7);
        spay(a,b,1,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,3,cnt+7);
        ex(a,b,2,cnt+7);
        ex(a,b,1,cnt+7);
    }
    if(k==5)
    {
        spay(a,b,0,cnt+7);
        spay(a,b,1,cnt+7);
        spay(a,b,2,cnt+7);
        spay(a,b,3,cnt+7);
        if(cnt+1==v.size()) dfs(0,0,0,cnt+1);
        else dfs(v[cnt+1].first,v[cnt+1].second,arr[v[cnt+1].first][v[cnt+1].second],cnt+1);
        ex(a,b,3,cnt+7);
        ex(a,b,2,cnt+7);
        ex(a,b,1,cnt+7);
        ex(a,b,0,cnt+7);
    }
    return 0;

}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int zcnt = 0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
            if(arr[i][j]!=0&&arr[i][j]!=6)
            {
                v.push_back(make_pair(i,j));
            }
            if(arr[i][j]==0) zcnt++;
        }
    }
    if(v.size()==0) mn = zcnt;
    else dfs(v[0].first, v[0].second,arr[v[0].first][v[0].second],0);
    cout<<mn<<"\n";
    return 0;
}  