#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> v;
int main(int argc, char** argv)
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
    int sum = 0;
    int cnt = 0;
    int s = v[0]; 
    for (int i = 1; i < v.size(); ++i)
    {
        if(v[i]-s>=m)
        {
            cnt++;
            s = v[i];
        }
    }
    cnt++;
    cout<<cnt<<"\n";
}  