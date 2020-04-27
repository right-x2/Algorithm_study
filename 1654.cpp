#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
long long n,m;

long long check(long long mid)
{
    long long cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        cnt = cnt + (v[i]/mid);
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long num;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());

    long long high = v[v.size()-1];
    long long low = 1;
    long long mx = 0;
    while(low<=high)
    {
        long long mid = (high+low)/2;
        long long std = check(mid);

        if(std>=m)
        {
            if(mid>mx) mx = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<mx<<"\n";
    return 0;
}