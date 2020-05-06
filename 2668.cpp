#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[101];
vector<int> s;
int arr[101];
int chk[101];
int check(int idx, vector<int> ans)
{
    if(arr[v[idx][0]]==0&&chk[v[idx][0]]==0)
    {
        ans.push_back(v[idx][0]);
        arr[v[idx][0]] = 1;
        chk[v[idx][0]] = 1;
        check(v[idx][0],ans);
        arr[v[idx][0]] = 0;
    }
    else if(chk[v[idx][0]]==1&&arr[v[idx][0]]==0) return 0;
    else if(arr[v[idx][0]]==1&&chk[v[idx][0]]==1)
    {
        int k = 0;

        for (int i = 0; i < ans.size(); ++i)
        {
            if(ans[i]==v[idx][0])
            {
                k = i;
            }
        }
        for (int i = k; i < ans.size(); ++i)
        {
            s.push_back(ans[i]);
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    int n;
    vector<int> ans;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a;
        v[i].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(chk[i]==0)
        {
            ans.push_back(i);
            arr[i] = 1;
            chk[i] = 1;
            check(i,ans);
            ans.pop_back();
            arr[i] = 0;           
        }
    }
    cout<<s.size()<<"\n";
    sort(s.begin(),s.end());
    for (int i = 0; i < s.size(); ++i)
    {
        cout<<s[i]<<"\n";
    }
    return 0;
}  