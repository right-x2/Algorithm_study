#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

vector<long long> v;
vector<long long> s;
long long low;
long long high;
long long cnt;
int n;
long long search1(long long mid)
{
    long long sum = 0;
    for (int i = 0; i <= n/2; ++i)
    {
        if(i==0)
        {
            sum = sum + abs(v[n/2]-mid);
        }
        else
        {
            sum = sum + abs(v[n/2-i]-(mid+i)) + abs(v[n/2+i]-(mid+i));
        }
    }
    for (int i = 0; i <= n/2; ++i)
    {
        if(i==0)
        {
            sum = sum + abs(s[n/2]-mid);
        }
        else
        {
            sum = sum + abs(s[n/2-i]-(mid+i)) + abs(s[n/2+i]-(mid+i));
        }
    }
    return sum;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long num;
    long long mn = -1;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(i==0)
        {
            low = num;
            high = num;
        }
        else
        {
            if(low>num) low = num;
            if(high<num) high = num;
        }
        v.push_back(num);
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(low>num) low = num;
        if(high<num) high = num;
        s.push_back(num);
    }
    while(low<=high)
    {
        long long mid = (low+high)/2;
        long long mid2 = mid + 1;
        long long std = search1(mid);
        long long std2 = search1(mid2);
        if(std<std2)
        {
            if(mn==-1||mn>std) mn = std;
            high = mid - 1; 
        }
        else
        {
            if(mn==-1||mn>std2) mn = std2;
            low = mid2 + 1; 
        }

    }
    cnt = cnt + mn;
    cout<<cnt<<"\n";
}  