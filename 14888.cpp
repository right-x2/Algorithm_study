#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

int mx = -1000000001;
int mn = 1000000001;
vector<int> v;

vector<int> box;
int arr[4];

int dfs(int n,vector<int> p)
{
    if(p.size()==n)
    {
        int sum = v[0];
        for (int i = 0; i < p.size(); ++i)
        {
            if(box[p[i]]==0) sum = sum + v[i+1];
            else if(box[p[i]]==1) sum = sum - v[i+1];
            else if(box[p[i]]==2) sum = sum * v[i+1];
            else if(box[p[i]]==3) sum = sum / v[i+1];
        }
        if(sum>mx) mx = sum;
        if(sum<mn) mn = sum;
        return 0;
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < p.size(); ++j)
            {
                if(p[j]==i) cnt++;
            }
            if(cnt==0)
            {
                p.push_back(i);
                dfs(n,p);
                p.pop_back();
            }
            cnt = 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> p;
    int n,a,opr;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    for (int i = 0; i < 4; ++i)
    {
        cin>>opr;
        for (int j = 0; j < opr; ++j)
        {
            box.push_back(i);
        }
    }
    for (int i = 0; i < n-1; ++i)
    {
        p.push_back(i);
        dfs(n-1,p);
        p.pop_back();
    }
    cout<<mx<<"\n";
    cout<<mn<<"\n";
    return 0;
}  