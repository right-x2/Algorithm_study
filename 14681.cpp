#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
vector<int> s;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>a;
    cin>>b;

    if(a>0&&b>0) cout<<1<<"\n";
    if(a>0&&b<0) cout<<4<<"\n";
    if(a<0&&b>0) cout<<2<<"\n";
    if(a<0&&b<0) cout<<3<<"\n";
    return 0;
}  