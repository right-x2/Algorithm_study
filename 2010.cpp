#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> v;
    int n,num,sum = 0;;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    sum = v[v.size()-1];
    int cnt = 0;
    for(int i = v.size()-2; i>=0; i--)
    {
        sum = sum + v[i]-1;
        cnt++;
    }
    cout<<sum<<"\n";
    return 0;
}  