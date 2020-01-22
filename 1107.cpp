#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t,n,idx,a,spot;
    vector<int> v;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>n>>idx;
        for (int j = 0; j < n; ++j)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
    }
}  