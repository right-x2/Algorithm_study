#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n,m;
vector<int>v;

long long check(long long mid)
{
    long long sum = 0;
    long long cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if(sum+v[i]>mid)
        {
            sum = 0;
            cnt++;
        }
        sum = sum + v[i];
    }
    if(sum!=0)cnt++;
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int mx = 0;
    long long high;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(num>mx) mx = num;
        v.push_back(num);
        high = high + num;
    }
    long long low = 1;
    while(low<=high)
    {
        long long mid = (low+high)/2;
        long long std = check(mid);
        if(std<=m)
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
        }

    }
    if(low<mx) low = mx;
    cout<<low<<"\n";
    return 0;
}