#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int n,m;


int solve(int a, int b)

{

    if (a%b == 0)return b;
    return solve(b, a%b);

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);


    cin>>n>>m;
    cout<<m-solve(n,m)<<"\n";
    return 0;
}