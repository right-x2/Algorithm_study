#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>


using namespace std;

vector< pair<int,int> >v;
vector< pair<int,int> >tmp;
int n,m;
int arr[20001][20001];
int c[20001];
stack< pair<int,int> > stk;

int dfs(int s)
{
    int a,b;
    c[s] = 1;
    for (int i = 1; i <=n ; ++i)
    {
        if(arr[s][i]!=0)
        {
            stk.push(make_pair(i,arr[s][i]));
        }
    }
    while(!stk.empty())
    {
        a = stk.top().first;
        b = stk.top().second;
        stk.pop();
        for (int i = 1; i <=n ; ++i)
        {
            if(arr[a][i]!=0&&c[i]==0)
            {
                if(arr[s][i]==0)
                {
                    
                    stk.push(make_pair(i,b+arr[a][i]));
                    arr[s][i] = b+arr[a][i];
                }
                else if(arr[s][i]>b+arr[a][i])
                {
                    
                    stk.push(make_pair(i,b+arr[a][i]));
                    arr[s][i] = b+arr[a][i];
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
    int s,a,b,c;
    cin>>n>>m;
    cin>>s;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b>>c;
        if(arr[a][b]==0)
        {
            arr[a][b] = c;
        }
        else if(arr[a][b]>c)
        {
            arr[a][b] = c;
        }
    }
    dfs(s);
    for (int i = 1; i <= n; ++i)
    {
        if(s==i) cout<<0<<"\n";
        else if(arr[s][i]==0) cout<<"INF"<<"\n";
        else cout<<arr[s][i]<<"\n";
    }
}  