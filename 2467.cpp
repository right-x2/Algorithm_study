#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

vector<int>v;
int n;
int a;
int b;
int adx;
int bdx;
int mx;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int flag = 0,num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(num<0) flag = 1;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    if(flag==0) cout<<v[0]<<" "<<v[1]<<"\n";
    else
    {
        mx = abs(v[0]+v[v.size()-1]);
        a = v[0];
        b = v[v.size()-1];
        for (int i = 0; i < v.size(); ++i)
        {
            int low = i+1;
            int high = v.size()-1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(v[mid]+v[i]>0)
                {
                    if(abs(v[mid]+v[i])<mx)
                    {
                        mx = abs(v[mid]+v[i]);
                        a = v[i];
                        b = v[mid];
                    }
                    high = mid - 1;
                }
                else
                {
                    if(abs(v[mid]+v[i])<mx)
                    {
                        mx = abs(v[mid]+v[i]);
                        a = v[i];
                        b = v[mid];
                    }
                    low = mid + 1;
                }
            }
        }
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}  