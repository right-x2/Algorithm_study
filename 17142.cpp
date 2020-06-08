#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int arr[51][51];
int chk[51][51];
int cpy[51][51];
int n,k;
int ans = -1;
vector<int> temp;
vector< pair<int,int> >pv;
int zcnt;
int  search()
{
    queue<pair<int,int> > q;
    int cnt = 0;
    int alcnt = 0;
    int len = k;
    int sum = 0;
    int recnt = 0;
    for (int i = 0; i < temp.size(); ++i)
    {
        q.push(make_pair(pv[temp[i]].first,pv[temp[i]].second));
        //cout<<pv[temp[i]].first<<" "<<pv[temp[i]].second<<"\n";
    }
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(cnt==len)
        {
            alcnt++;
            cnt = 0;
            len = sum;
            sum = 0;
            if(recnt==zcnt)
            {
                if(ans==-1||alcnt<ans) ans = alcnt;
                return 0;
            }
            
        }
        cnt++;
        if(y+1<n&&(arr[y+1][x]==0||arr[y+1][x]==2))
        {
            sum++;
            if(arr[y+1][x]==0)recnt++;
            arr[y+1][x] = -1;
            q.push(make_pair(y+1,x));
        }

        if(x+1<n&&(arr[y][x+1]==0||arr[y][x+1]==2))
        {
            sum++;
            if(arr[y][x+1]==0)recnt++;
            arr[y][x+1] = -1;
            q.push(make_pair(y,x+1));
        }

        if(y-1>=0&&(arr[y-1][x]==0||arr[y-1][x]==2))
        {
            sum++;
            if(arr[y-1][x]==0)recnt++;
            arr[y-1][x] = -1;
            q.push(make_pair(y-1,x));
        }

        if(x-1>=0&&(arr[y][x-1]==0||arr[y][x-1]==2))
        {
            sum++;
            if(arr[y][x-1]==0)recnt++;
            arr[y][x-1] = -1;
            q.push(make_pair(y,x-1));
        }
    }
    return 0;

}

void clean()
{
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cpy[i][j];
        }
    }

}
int dfs(int idx)
{
    if(temp.size()==k)
    {
        search();
        clean();
        return 0;
    }
    for (int i = idx+1; i < pv.size(); ++i)
    {
        temp.push_back(i);
        dfs(i);
        temp.pop_back();
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
            cpy[i][j] = arr[i][j];
            if(arr[i][j]==2)pv.push_back(make_pair(i,j));
            if(arr[i][j]==0) zcnt++;
        }
    }
    if(zcnt==0) cout<<0<<"\n";
    else
    {
        for (int i = 0; i < pv.size(); ++i)
        {
            temp.push_back(i);
            dfs(i);
            temp.pop_back();
        }
        cout<<ans<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}