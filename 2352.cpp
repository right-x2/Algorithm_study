#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<int>v;
vector<int>s;
int n;
int flag;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    s.push_back(v[0]);
    for(int i = 1; i < v.size(); i++)
    {

        
        int ans = -1;
        int low = 0;
        int high = s.size()-1;

        while(low<=high)
        {
            int mid = (low+high)/2;
            if(s[mid]>=v[i])
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid +1;
            }
        }

        if(ans==-1)
        {
            s.push_back(v[i]);
        }
        else
        {
            s[ans] = v[i];
        }
    }

    cout<<s.size()<<"\n";
    return 0;
}