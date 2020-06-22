#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[10];
int n,cost;
string ans;
int mn = 0;
int comp(string a, string b)
{
    for (int i = 0; i < a.length(); ++i)
    {
        if(a[i]>b[i]) return 1;
        else if(a[i]==b[i]) continue;
        else return 0;
    }
    return 1;
}
int dfs(string str, int idx, int sum)
{
    if(ans!="")
    {
        int len = ans.length()-str.length();
        if((cost-sum)/mn<=len) return 0;
    }
    if(str=="0")
    {
        if(ans=="") ans = str;
        return 0;
    }
    for (int i = idx; i >= 0; --i)
    {
        char k = (i+'0');
        if(cost<sum+arr[i])
        {
            if(str.length()>ans.length()) ans = str;
            else if(str.length()==ans.length())
            {
                if(comp(str,ans)==1) ans = str;
            }
        }
        else 
        {
            dfs(str+k,i,sum+arr[i]);
            for (int j = i-1; j >= 0; --j)
            {
                if(arr[j]<arr[i]) dfs(str,i-1,sum);
            }
            return 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str = "";
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
        if(mn==0||mn>arr[i]) mn = arr[i];
    }
    cin>>cost;
    int idx = n-1;
    int sum = arr[idx];
    for (int i = n-1; i >= 0; --i)
    {
        if(arr[i]<=cost) 
        {
            dfs(str+char(i+'0'),i,arr[i]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}