#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
int chk[1000001];
vector<int> v;
priority_queue<int, vector<int>, greater<int> >q;


int dfs(int i, int sum)
{
    
    if(i==n-1) return 0;

    for (int j = i+1; j < v.size(); ++j)
    {
        //cout<<v[i]<<" "<<sum+v[j]<<"\n";
        if(sum+v[j]<1000001&&chk[sum+v[j]]==0)
        {
            q.push(sum+v[j]);
            chk[sum+v[j]] = 1;
            dfs(j,sum+v[j]);
        }
        else if(v[j]+sum>=1000001)
        {
            q.push(sum+v[j]);
            dfs(j,sum+v[j]);
        }
    }    
    return 0;    
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans = 0;
    int cnt = 1;
    int a;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    //for (int i = 0; i < v.size(); ++i) cout<<v[i]<<" ";

    //cout<<"\n"<<"";
    for (int i = 0; i < v.size(); ++i)
    {
        if(chk[v[i]]==1) continue;
        else 
        {
            //cout<<v[i]<<" vivi\n";
            q.push(v[i]);
            chk[v[i]] = 1;
        }
        for (int j = i+1; j < v.size(); ++j)
        {
            if(v[i]+v[j]<1000001&&chk[v[i]+v[j]]==0)
            {
                q.push(v[i]+v[j]);
                chk[v[i]+v[j]] = 1;
                dfs(j,v[i]+v[j]);
            }
            else if(v[i]+v[j]>=1000001)
            {
                q.push(v[i]+v[j]);
                dfs(j,v[i]+v[j]);
            }
        }       
    }

/*
    while(!q.empty())
    {
        cout<<q.top()<<"\n";
        //if(q.top()!=cnt)
        //{
            //ans = cnt;
            //break;
        //}
        q.pop();
        //cnt++;
    }
*/
    for (int i = 1; i < 1000001; ++i)
    {
        if(chk[i]==0)
        {
            cout<<i<<"\n";
            break;
        }
    }
    //cout<<ans<<"\n";
    return 0;
}