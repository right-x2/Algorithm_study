#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[4000001];
int n;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;

    int ans = 0;
    int a = 2;
    int mul = 1;
    int sum = 0;
    int s,e;
    while(a<=n)
    {
        if(arr[a]==0)
        {
            v.push_back(a);
            for (int i = 2; i < n; ++i)
            {
                if(a*i>n) break;
                if(arr[a*i]==0) arr[a*i]=1;
            }
        }
        a++;
    }
    s = 0;
    e = 0;

    while(s<=e)
    {
        if(sum<n)
        {
            if(e==v.size()) break;
            sum = sum + v[e];
            e++;
        }
        else if(sum>n)
        {
            sum = sum - v[s];
            s++;
        }
        else if(sum==n)
        {
            sum = sum - v[s];
            s++;
            ans++;
        }
    }
    cout<<ans<<"\n";
}  