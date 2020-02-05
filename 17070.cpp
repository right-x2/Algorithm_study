#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n,cnt = 0;
int arr[20][20];

int dfs(int a, int b, int c, int d)
{
    stack< pair<int,int> > pre;
    stack< pair<int,int> > nxt;
    pre.push(make_pair(a,b));
    nxt.push(make_pair(c,d));
    while(!pre.empty())
    {
        a = pre.top().first;
        b = pre.top().second;
        c = nxt.top().first;
        d = nxt.top().second;
        pre.pop();
        nxt.pop();
        if(c==n-1&&d==n-1)
        {
            cnt++;
            continue;
        } 
        if(a==c&&b+1==d)
        {
            if(d+1<n&&arr[c][d+1]!=1)
            {
                pre.push(make_pair(c,d));
                nxt.push(make_pair(c,d+1));
            }
            if(d+1<n&&arr[c][d+1]!=1&&c+1<n&&arr[c+1][d+1]!=1&&arr[c+1][d]!=1)
            {
                pre.push(make_pair(c,d));
                nxt.push(make_pair(c+1,d+1));
            }
        }
        else if(b==d&&a+1==c)
        {
            if(c+1<n&&arr[c+1][d]!=1)
            {
                pre.push(make_pair(c,d));
                nxt.push(make_pair(c+1,d));      
            }
            if(d+1<n&&arr[c][d+1]!=1&&c+1<n&&arr[c+1][d+1]!=1&&arr[c+1][d]!=1)
            {
                pre.push(make_pair(c,d));
                nxt.push(make_pair(c+1,d+1));        
            }
        }
        else if(a+1==c&&b+1==d)
        {
            if(d+1<n&&arr[c][d+1]!=1)
            {
                pre.push(make_pair(c,d));
                nxt.push(make_pair(c,d+1));               
            }
            if(c+1<n&&arr[c+1][d]!=1)
            {
                pre.push(make_pair(c,d));
                nxt.push(make_pair(c+1,d));               
            }
            if(d+1<n&&arr[c][d+1]!=1&&c+1<n&&arr[c+1][d+1]!=1&&arr[c+1][d]!=1)
            {
                pre.push(make_pair(c,d));
                nxt.push(make_pair(c+1,d+1));               
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
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }
    dfs(0,0,0,1);
    cout<<cnt<<"\n";
}  