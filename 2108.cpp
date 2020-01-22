#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[8001];
int mx = -4001;
int mn = 4001;
vector<int> v;
vector<int> c;
int main(int argc, char** argv)
{
    //ios::sync_with_stdio(false); 
    //cin.tie(NULL); 
    //cout.tie(NULL);
    int n,a,cm = 1,mxct = 1, cnt=1;
    double sum = 0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        sum = sum + a;
        if(a>mx) mx = a;
        if(a<mn) mn = a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int fst = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if(fst==v[i])
        {
            cnt++;
        }
        else
        {
            fst = v[i];
            if(mxct==cnt)
            {
                c.push_back(v[i-1]);
                cnt = 1;
            }
            else if(mxct<cnt)
            {
                mxct = cnt;
                cnt = 1;
                c.clear();
                c.push_back(v[i-1]);
            }
        }
    }
    if(cnt==mxct)
    {
        c.push_back(v[n-1]);
    }
    else if(cnt>mxct)
    {
        c.clear();
        c.push_back(v[n-1]);
    }
    if(round(sum/n)==-0) cout<<0<<"\n";
    else cout<<round(sum/n)<<"\n";
    cout<<v[n/2]<<"\n";
    sort(c.begin(),c.end());
    if(c.size()==1)
    {
        cout<<c[0]<<"\n";
    }
    else
    {
        cout<<c[1]<<"\n";
    }
    cout<<mx-mn<<"\n";
}  