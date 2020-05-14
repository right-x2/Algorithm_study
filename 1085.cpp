#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int w,h,x,y;
    cin>>x>>y>>w>>h;
    int mn = h-y;
    if(y<mn) mn = y;
    if(x<mn) mn = x;
    if(w-x<mn) mn = w-x;
    cout<<mn<<"\n";
    return 0;
}  