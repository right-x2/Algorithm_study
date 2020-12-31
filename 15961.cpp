#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n,d,k,c;
int arr[3001];

vector<int> v;
vector<int> s;
int ans = 1;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int cnt = 1;
    cin>>n>>d>>k>>c;

    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
        s.push_back(num);
    }

    for (int i = 0; i < n; ++i)
    {
        v.push_back(s[i]);
    }

    n = n * 2;

    int s = 0;
    int e = 0;

    arr[v[0]] = 1;

    for (int i = 1; i <k ; ++i)
    {
        e++;
        if(arr[v[e]]==0)
        {
            cnt++;
        }
        arr[v[e]]++;
    }
    if(arr[c]==0)
    {
        if(ans<cnt+1) ans = cnt;
    }
    else
    {
        if(ans<cnt) ans = cnt;
    }

    while(e<n-1)
    {
        arr[v[s]]--;
        if(arr[v[s]]==0) cnt--;
        s++;
        e++;
        arr[v[e]]++;
        if(arr[v[e]]==1)
        {
            cnt++;
        }
        if(arr[c]==0)
        {
            if(ans<cnt+1) ans = cnt+1;
        }
        else
        {
            if(ans<cnt) ans = cnt;
        }       
    }

    cout<<ans<<"\n";
    return 0;
}