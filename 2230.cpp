#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> v;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    long long answer = -1;
    int n;
    long long m;
    long long a;
    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    int f = 0;
    int b = 0;

    while(b<=f&&f<v.size())
    {
        if(v[f]-v[b]>=m)
        {
            if(answer==-1||v[f]-v[b]<answer) answer = v[f]-v[b];
            b++;
        }
        else
        {
            f++;
        }
    }

    cout<<answer<<"\n";
    return 0;
}