#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    int ans = 0;
    
    for (int i = 2; i < n; i++)
    {
        int s = 0;
        int e = i-1;
        while(s<e)
        {
            if(v[e]+v[s]==v[i])
            {
                ans++;
                break;
            }
            else if (v[e]+v[s]<v[i])
            {
                s++;
            }
            else
            {
                e--;
            }
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}  