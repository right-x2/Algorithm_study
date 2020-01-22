#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> v;
    int a,b;
    cin>>a;
    for (int i = 0; i < a; ++i)
    {
        cin>>b;
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    cout<<v[0]<<" ";
    cout<<v[a-1]<<"\n";
    return 0;
}  