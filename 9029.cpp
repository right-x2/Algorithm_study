#include <iostream>
#include <vector>

using namespace std;


vector<int> v;
int arr[10001];
int a,b;
int chk(int a)
{
    int mid = 10000/a;
    for (int i = 2; i <= mid; ++i)
    {
        if(arr[a*i]==0)arr[a*i] = 1;
    }
    return 0;
}

int find(int t)
{
    a = 0;
    b = 0;
    int av=10000;
    for (int i = 0; i < v.size(); ++i)
    {
        if(v[i]>t)break;
        for (int j = i; j < v.size(); ++j)
        {
            if(v[i]+v[j]>t)break;
            if(v[i]+v[j]==t)
            {
                if(av>v[j]-v[i])
                {
                    av = v[j]-v[i];
                    a = v[i];
                    b = v[j];
                }
            }
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int cnt = 0;
    int n,t;
    arr[1] = 1;
    
    for (int i = 2; i <5001; ++i)
    {
        chk(i);
    }
    for (int i = 2; i < 10001; ++i)
    {
        if(arr[i]==0) v.push_back(i);
    }
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>t;
        find(t);
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
    
}  