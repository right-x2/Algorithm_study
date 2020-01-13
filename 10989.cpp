#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> v;
    int n,a;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        arr[a]++;
    }
    for (int i = 0; i < 10001; ++i)
    {
        for (int j = 0; j < arr[i]; ++j)
        {
            cout<<i<<"\n";
        }
    }
    return 0;
}  