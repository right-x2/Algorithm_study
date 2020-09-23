#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

vector<int> v;

int n;
long long m;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int answer = -1;
    int len = 0;
    long long sum = 0;
    int a,b;
    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }

    a = 0;
    b = 0;
    while(b<=v.size())
    {
        if(sum>=m)
        {
            if(answer==-1||answer>len) answer = len;
            len--;
            sum = sum - v[a];
            a++;
        }
        else
        {
            if(b==v.size()) break;
            sum += v[b];
            len++;
            b++;
        }
    }

    if(answer==-1) cout<<0<<"\n";
    else cout<<answer<<"\n";

    return 0;
}