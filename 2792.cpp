#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n,m;
vector<long long>v;

long long check(long long mid)
{
    long long cnt = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i]/mid==0) cnt++;
        else if(v[i]%mid==0) cnt = cnt + v[i]/mid;
        else
        {
            cnt = cnt + v[i]/mid + 1;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long num;
    long long high = 0;
    long long low = 1;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>num;
        if(num>high) high = num;
        v.push_back(num);
    }
    long long mn = high;
    while(low<=high)
    {
        long long mid = (low+high)/2;
        long long std = check(mid);
        if(std>n)
        {
            low = mid+1;
            
        }
        else
        {
            if(mid<mn) mn = mid;
            high = mid-1;
        }
    }
    cout<<mn<<"\n";
    return 0;
}