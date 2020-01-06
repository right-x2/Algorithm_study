#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    vector<int> v;
    for (int i = 0; i < 3; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout<<v[1]<<"\n";
    return 0;
}  