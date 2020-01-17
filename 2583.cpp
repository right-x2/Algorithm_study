#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int alcnt = 0;

int arr[102][102];
int n,m;
vector<int> v;

int spray(int a, int b, int c, int d)
{
    for (int i = a; i < c; ++i)
    {
        for (int j = b; j < d; ++j)
        {
            if(arr[i][j]==0) arr[i][j] = 1;
        }
    }
    return 0;
}

int bfs(int i , int j)
{
    alcnt++;
    arr[i][j] = 1;
    int cnt = 0;
    if(i+1<n)
    {
        if(arr[i+1][j]==0)
        {
            bfs(i+1,j);
        }   
    }
    if(j+1<m)
    {
        if(arr[i][j+1]==0)
        {
            bfs(i,j+1);
        }
        
    }
    if(i-1>=0)
    {
        if(arr[i-1][j]==0)
        {
            bfs(i-1,j);
        } 
    }
    if(j-1>=0)
    {
        if(arr[i][j-1]==0)
        {
            bfs(i,j-1);
        } 
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int k,a,b,c,d;
    cin>>n>>m>>k;
    for (int i = 0; i < k; ++i)
    {
        cin>>b>>a>>d>>c;
        spray(a,b,c,d);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(arr[i][j]==0) 
            {
                bfs(i,j);
                v.push_back(alcnt);
                alcnt = 0;
            }
        }
    }

    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<" ";
    }
}  