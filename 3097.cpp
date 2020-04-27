#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long  n,m;
vector<long long> v;

long long check(long long mid)
{
    long long cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        cnt = cnt + mid/v[i];
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long mid = 0;;
    long long num;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    long long high = v[v.size()-1]*m;
    long long low = 1;
    long long mn = high;
    while(low<=high)
    {
        mid = (high+low)/2;
        long long cnt = check(mid);
        if(cnt>=m){
            high = mid-1;
            if(mn>mid) mn = mid;

        }else{
            low = mid + 1;
        }
    }
    cout<<mn<<"\n";
    return 0;
}