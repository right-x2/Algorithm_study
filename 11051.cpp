#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;


int arr[1001][1001];

int solve(int n, int k)
{
    if(n==k||k==0) return 1;

    if(arr[n][k]!=0) return arr[n][k];

    return arr[n][k] = (solve(n-1,k-1)+solve(n-1,k))%10007;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    
    cout<<solve(n,k)<<"\n";
    return 0;
}