#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
int arr[300001];
int len;


int n,m;

int search(int num)
{
    int low = 0;
    int high = len;
    int ans = 0;
    while(low<=high)
    {
        //cout<<low<<" "<<high<<" "<<ans<<"\n";
        int mid = (high+low)/2;

        if(arr[mid]>=num)
        {
            ans = mid;
            low = mid +1;
        }
        else
        {
            high = mid-1;
        }
    }
    len = ans-1;

    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,mx;
    cin>>n>>m;
    len = n-1;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        if(i==0) 
        {
            arr[i] = a;
            mx = a;
        }
        else
        {
            if(mx<a) arr[i] = mx;
            else
            {
                mx = a;
                arr[i] = mx;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin>>a;
        v.push_back(a);
    }

    for (int i = 0; i < m; ++i)
    {
        if(len==-1) break;
        search(v[i]);
    }

    if(len==-1)cout<<0<<"\n";
    else
    {
        cout<<len+2<<"\n";
    }
    return 0;
}