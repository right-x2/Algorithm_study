#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int,int> >pv;
int n;
int mx = 0;

int force(int k,int sum)
{
    if(k==n)
    {
        if(sum>mx) mx = sum;
    }
    else if(k==n-1)
    {
        if(pv[k].first==1)
        {
            if(mx<sum+pv[k].second)
            {
                mx = sum+pv[k].second;
                return 0;
            }
        }
        else
        {
            if(sum>mx)
            {
                mx = sum;
                return 0;        
            }
        }
    }
    for (int i = k; i < n; ++i)
    {
        if(i+pv[i].first>n)
        {
            if(sum>mx)
            {
                mx = sum;
            }
        }
        else
        {
            force(i+pv[i].first,sum+pv[i].second);
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        pv.push_back(make_pair(a,b));
    }
    for (int i = 0; i < n; ++i)
    {
        if(i==n-1)
        {
            if(pv[i].first==1)
            {
                if(pv[i].second>mx) mx = pv[i].second;
            }
        }
        else if(i+pv[i].first>n) continue;
        else
        {
            force(i+pv[i].first,pv[i].second);
        }
    }
    cout<<mx<<"\n";
    return 0;
}  