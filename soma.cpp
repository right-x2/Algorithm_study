#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int n,m,e;
vector<int> v;
vector<int> s;
int chk[1000001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n>>m>>e;
    for(int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }

    int low = 0;
    int high = n-1;
 
    int spot = 0;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]<=e)
        {
            low = mid +1;
            spot = mid;
        }
        else
        {
            high = mid -1;
        }
    }
    for ( i = 0; i <n; i++)
    {
        if(e-v[i]<0) chk[i] = -1;
        s.push_back(abs(e-v[i]));
    }
    sort(s.begin(),s.end());
    int ans = 0;
    return 0;
}  