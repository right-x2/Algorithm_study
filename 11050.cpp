#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int facto(int a)
{
    if(a==1||a==0) return 1;
    return a*facto(a-1);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    int i = facto(a);
    int j = facto(b);
    int k = facto(a-b); 
    cout<<i/(j*k)<<"\n";
    return 0;
}  