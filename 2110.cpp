#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> v;

int check(int k)
{
    int cnt = 1;
    int s = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if(v[i]-s>=k)
        {
            cnt++;
            s = v[i];
        }
    }
    return cnt;
}
int main(int argc, char const *argv[])
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
    }
    sort(v.begin(),v.end());
    int start = 1;
    int end = v[v.size()-1]-v[0];
    int mid = (start+end)/2;
    while(start<=end)
    {
        int std = check(mid);
        if(std>=m)
        {
            start = mid+1;
            mid = (start+end)/2;
        }
        else
        {
            end = mid - 1;
            mid = (start+end)/2;
        }
    }
    cout<<mid<<"\n";
    return 0;
}