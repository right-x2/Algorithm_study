#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int alcnt;
int idx = 1;
int arr[51][51];
int ck[51][51];
int n,l,r;
int mn = 64;
vector<int> v;

vector< pair<int,int> > pv[10000001];

int dfs(int i, int j)
{
    pv[idx].push_back(make_pair(i,j));
    ck[i][j] = idx;
    int cnt = 0;
    if(i+1<n)
    {
        if(abs(arr[i][j]-arr[i+1][j])>=l&&abs(arr[i][j]-arr[i+1][j])<=r)
        {
            cnt++;
            if(ck[i+1][j]==0)
            {
                dfs(i+1,j);
            }
        }
    }
    if(i-1>=0)
    {
        if(abs(arr[i][j]-arr[i-1][j])>=l&&abs(arr[i][j]-arr[i-1][j])<=r)
        {
            cnt++;
            if(ck[i-1][j]==0)
            {
                dfs(i-1,j);
            }
        }
    }
    if(j+1<n)
    {
        if(abs(arr[i][j]-arr[i][j+1])>=l&&abs(arr[i][j]-arr[i][j+1])<=r)
        {
            cnt++;
            if(ck[i][j+1]==0)
            {
                dfs(i,j+1);               
            }

        }        
    }
    if(j-1>=0)
    {
        if(abs(arr[i][j]-arr[i][j-1])>=l&&abs(arr[i][j]-arr[i][j-1])<=r)
        {
            cnt++;
            if(ck[i][j-1]==0)
            {
                dfs(i,j-1); 
            }
        }        
    }
    if(cnt>0) return 1;
    else return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int kk = 1;
    int sum = 0;
    
    cin>>n>>l>>r;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }
    while(kk!=0)
    {

        kk = 0;
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(ck[i][j]==0)
                {
                    
                    if(dfs(i,j))
                    {
                        kk++;
                        v.push_back(idx);
                    }
                }
                idx++;
            }
        }

        for (int i = 0; i < v.size(); ++i)
        {          
            for (int j = 0; j < pv[v[i]].size(); ++j)
            {
                sum = sum + arr[pv[v[i]][j].first][pv[v[i]][j].second];
            }
            
            for (int j = 0; j < pv[v[i]].size(); ++j)
            {
                arr[pv[v[i]][j].first][pv[v[i]][j].second] = sum/pv[v[i]].size();
            }
            
            pv[v[i]].clear();
            sum = 0;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ck[i][j] = 0;
            }
        }
        alcnt++;
        v.clear();
    }
    
    cout<<alcnt-1<<"\n";
    return 0;
}  