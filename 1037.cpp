#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> v;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cout<<v[0]*v[v.size()-1]<<"\n";
    return 0;
}  