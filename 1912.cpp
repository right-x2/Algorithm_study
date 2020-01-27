#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>


using namespace std;

int arr[100001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,sum = 0;
    int max = -1001;
    int box = 0;
    cin>>a;
    cin>>arr[0];
    for (int i = 1; i <a ; ++i)
    {
        cin>>n;
        if(arr[i-1]+n>=n)
        {
            arr[i] = arr[i-1]+n;
        }
        else
        {
            arr[i] = n;
        }
    }
    for (int i = 0; i < a; ++i)
    {
        if(max<arr[i]) max = arr[i];
    }
    cout<<max<<"\n";
}  