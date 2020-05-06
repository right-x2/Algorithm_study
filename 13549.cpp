#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[100001];
int mn = 0;
int n,m;
int search(int idx)
{
    queue<int> q;
    q.push(idx);
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        if(tp==m)
        {
            if(arr[tp]<mn||mn==0)
            {
                mn = arr[tp];
            }
            continue;
        }
        if(tp<m)
        {
            if(tp*2<=100000&&(arr[tp*2]==0||arr[tp*2]>arr[tp]))
            {
                q.push(tp*2);
                arr[tp*2] = arr[tp];
            }
            if(tp+1<=100000&&(arr[tp+1]==0||arr[tp+1]>arr[tp]+1)) 
            {
                q.push(tp+1);
                arr[tp+1] = arr[tp]+1;
            }
        }
        if(tp-1>=0&&(arr[tp-1]==0||arr[tp-1]>arr[tp]+1)) 
        {
            q.push(tp-1);
            arr[tp-1] = arr[tp]+1;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    arr[n] = 1;
    search(n);
    cout<<mn-1<<"\n";
    return 0;
}  