#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> v;
int s,e;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    long long a;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    
    sort(v.begin(),v.end());
    if(v[0]>=0)
    {
        for (int i = 0; i < 3; i++)
        {
            cout<<v[i]<<" ";
        }
    }
    else
    {
        s = 0;
        e = 2;
        int low = s;
        int high = e;
        long long mn = 2000000000;
        while(e<n)
        {
            if(v[e]+v[s]==0)
            {
                low = s;
                high = e;
                break;
            }
            else if(v[e]+v[s]>0)
            {
                e--;
            }
            else
            {
                
            }
        }
    }

    
    return 0;
}