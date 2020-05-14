#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
vector<int>v;
long long mx = 0;
long long l = 0;
int bfs(long long mid)
{
    long long sum = mid;
    int cnt = 1;
    for (int i = 0; i < v.size(); ++i)
    {
        if(sum<v[i])
        {
            sum = mid - v[i];
            cnt++;
        }
        else sum = sum - v[i];
    }
    return cnt;
}

int search()
{
    long long low = l;
    long long high = 1000000000;
    mx = high;
    while(low<=high)
    {
        long long mid = (low+high)/2;
        int std = bfs(mid);
        if(std>m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            if(mx>mid) mx = mid;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
        if(num>l) l = num;
    }
    search();
    cout<<mx<<"\n";
    return 0;
}  