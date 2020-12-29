#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int ans;
vector<int> v;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int i = 0;
    int a;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    while(i<v.size())
    {
        if(i==v.size()-1)
        {
            if(v[i]<=0) ans = ans + v[i];
            break;
        }
        else
        {
            if(v[i]<=0&&v[i+1]<=0)
            {
                ans = ans + v[i]*v[i+1];
                i = i + 2;
            }
            else if(v[i]<=0)
            {
                ans = ans + v[i];
                break;
            }
            else break;
        }
    }

    i = v.size()-1;

    while(i>=0)
    {
        if(i==0)
        {
            if(v[i]>0)ans = ans + v[i];
            break;
        }
        else if(v[i]==1)
        {
            ans = ans + v[i];
            i--;
        }
        else
        {
            if(v[i]>0&&v[i-1]>0)
            {
                if(v[i-1]==1)
                {
                    ans = ans + v[i];
                    i--;
                }
                else
                {
                    ans = ans + v[i]*v[i-1];
                    i = i - 2;
                }
            }
            else if(v[i]>0)
            {
                ans = ans + v[i];
                break;
            }
            else break;            
        }
    }

    cout<<ans<<"\n";
    return 0;
}