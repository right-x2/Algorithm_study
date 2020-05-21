#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

int x[1001];
int y[1001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c,d;
    for (int i = 0; i < 3; ++i)
    {
        cin>>a>>b;
        x[a]++;
        y[b]++;
    }
    for (int i = 0; i < 1000; ++i)
    {
        if(x[i]==1) c = i;
        if(y[i]==1) d = i;
    }
    cout<<c<<" "<<d<<"\n";
}  