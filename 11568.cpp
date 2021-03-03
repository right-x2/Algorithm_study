#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;
int n;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        if(i==0)
        {
            v.push_back(num);
            continue;
        }
        int low = 0;
        int high = v.size()-1;
        int idx = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(v[mid]>=num)
            {
                high = mid -1;
                idx = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        if(idx==-1) v.push_back(num);
        else v[idx] = num;
    }
    
    cout<<v.size()<<"\n";
    
    
    return 0;
}  