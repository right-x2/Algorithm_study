#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int n,m;
vector< pair<long long,long long> >v;
int arr[1000001];
int chk[16];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(make_pair(num,i));
    }
    sort(v.begin(),v.end()); 
    int cnt = 0;  
    arr[v[0].second] = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        if(v[i-1].first==v[i].first)
        {
            arr[v[i].second] = cnt;
        }
        else
        {
            cnt++;
            arr[v[i].second] = cnt;
        }
    }
    for (int i = 0; i < v.size(); ++i)
     {
        cout<<arr[i]<<" ";
     } 
}   