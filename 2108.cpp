#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

vector<int> v;
vector<int> s;
int arr[8001];
int wid, avg, mid, mos = 0, mx = -4001, mn = 4000;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num,n;
    double sum = 0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        sum = sum + num;
        if(num>mx) mx = num;
        if(num<mn) mn = num;
        v.push_back(num);
        if(num<0) num = num*-1 + 4000;
        arr[num]++;
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < 8001; ++i)
    {
        if(mos<=arr[i])
        {
            if(mos<arr[i]) s.clear();
            if(i>4000) s.push_back((i-4000)*-1);
            else s.push_back(i);
            mos = arr[i];
        }
    }
    sort(s.begin(),s.end());
    cout<<(int)floor((sum/n)+0.5)<<"\n";
    cout<<v[round(n/2)]<<"\n";
    if(s.size()>1) cout<<s[1]<<"\n";
    else cout<<s[0]<<"\n";
    cout<<mx-mn<<"\n";
}  