#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int flag = 0;
vector<int> v;
vector<int> ans;
vector<int> temp;
int chk[11];

int check()
{
    int cnt = 0;
    for (int i = 0; i < temp.size(); ++i)
    {
        int std = v[temp[i]-1];
        for (int j = 0; j < i; ++j)
        {
            if(temp[i]<temp[j]) cnt++;
        }
        if(cnt!=std) return 0;
        cnt = 0;
    }
    ans = temp;
    return 1;
}

int dfs()
{
    if(temp.size()==n)
    {
        if(check()==1) flag = 1;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if(chk[i]==0&&flag==0)
        {
            temp.push_back(i);
            chk[i] = 1;
            dfs();
            chk[i] = 0;
            temp.pop_back(); 
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    for (int i = 1; i <=n ; ++i)
    {
        temp.push_back(i);
        chk[i] = 1;
        dfs();
        chk[i] = 0;
        temp.pop_back();
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        cout<<ans[i]<<" ";
    }
}  