#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;

vector<int> v;
vector<int> s;
int chk[100001][2];

int dp(int idx, int flag)
{
    if(idx==0&&flag==0) return v[0];
    if(idx==0&&flag==1) return s[0];
    if(idx<0) return 0;
    if(chk[idx][flag]!=-1) return chk[idx][flag];
    if(flag==0)
    {
        chk[idx][flag] = v[idx] + max(dp(idx-1,1),dp(idx-2,1));
    }
    else
    {
        chk[idx][flag] = s[idx] + max(dp(idx-1,0),dp(idx-2,0));
    }
    return chk[idx][flag];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int t;
    cin>>t;
    for(int j = 0; j < t; j++)
    {
        cin>>n;
        for (int i = 0; i < n; ++i)
        {
            chk[i][0] = -1;
            chk[i][1] = -1;
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>num;
            v.push_back(num);
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>num;
            s.push_back(num);
        }
        cout<<max(dp(n-1,0),dp(n-1,1))<<"\n";
        v.clear();
        s.clear();

    }
}  