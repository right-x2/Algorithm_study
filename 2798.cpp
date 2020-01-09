#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int mx,m;

int force(int a,int n,int sum,int cnt)
{
    if(cnt == 3)
    {
        if(sum>mx&&sum<=m) mx = sum;
        return 0;
    }
    for (int i = a+1; i < n; ++i)
    {
        force(i,n,sum+v[i],cnt+1);
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    for (int i = 0; i < v.size(); ++i)
    {
        force(i,n,v[i],1);
    }
    cout<<mx<<"\n";
    return 0;
}  