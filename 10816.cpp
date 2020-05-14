#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[20000001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int n,m;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(num>=0) arr[num]++;
        else 
        {
            num = num * -1;
            num = num + 10000000;
            arr[num]++;
        }
    }
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>num;
        if(num>=0) cout<<arr[num]<<" ";
        else 
        {
            num = num * -1;
            num = num + 10000000;
            cout<<arr[num]<<" ";
        }
    }
    return 0;
}  