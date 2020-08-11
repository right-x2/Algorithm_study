#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int arr[27];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string a,b;
    cin>>a;
    cin>>b;
    int ans = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        arr[a[i]-'a']++;
    }

    for (int i = 0; i < b.length(); ++i)
    {
        arr[b[i]-'a']--;
    }

    for (int i = 0; i < 27; ++i)
    {
        ans = ans + abs(arr[i]);
    }

    cout<<ans<<"\n";
    return 0;
}