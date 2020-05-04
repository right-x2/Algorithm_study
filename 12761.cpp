#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int a,b,n,m;
int arr[100001];
int bfs()
{
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        if(k==m) return arr[k];
        if(k*a<=100000&&arr[k*a]==0) 
        {
          q.push(k*a);
          arr[k*a]  = arr[k]+1;
        }
        if(k*b<=100000&&arr[k*b]==0) 
        {
            q.push(k*b);
            arr[k*b]  = arr[k]+1; 
        }
        if(k+a<=100000&&arr[k+a]==0) 
        {
          q.push(k+a);
          arr[k+a]  = arr[k]+1;
        }
        if(k+b<=100000&&arr[k+b]==0) 
        {
            q.push(k+b);
            arr[k+b]  = arr[k]+1; 
        }
        if(k-a>=0&&arr[k-a]==0) 
        {
          q.push(k-a);
          arr[k-a]  = arr[k]+1;
        }
        if(k-b>=0&&arr[k-b]==0) 
        {
            q.push(k-b);
            arr[k-b]  = arr[k]+1; 
        }
        if(k+1<=100000&&arr[k+1]==0) 
        {
            q.push(k+1);
            arr[k+1]  = arr[k]+1; 
        }
        if(k-1>=0&&arr[k-1]==0) 
        {
            q.push(k-1);
            arr[k-1]  = arr[k]+1; 
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>a>>b>>n>>m;
    
    cout<<bfs()<<"\n";
    return 0;
}