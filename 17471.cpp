#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

vector<int>pv[11];
int chk[11];
int arr[11];
int tp[11];
int way[11][11];
int cc[11];
int n;
int ans = -1;
vector<int> v;
vector<int> s;
int a;
int b;
int divide()
{
    if(v.size()==0||s.size()==0) return 0;
    for (int i = 1; i <=n; ++i) cc[i] = 0;
    int num = v[0];
    queue<int> q;
    q.push(num);
    cc[v[0]] = 1;
    while(!q.empty())
    {
        num = q.front();
        q.pop();
        for (int i = 0; i < pv[num].size(); ++i)
        {
            if(tp[pv[num][i]]==1&&cc[pv[num][i]]==0)
            {
                cc[pv[num][i]] = 1;
                q.push(pv[num][i]);
            }
        }
    }
    cc[s[0]] = 1;
    q.push(s[0]);
    while(!q.empty())
    {
        num = q.front();
        q.pop();
        for (int i = 0; i < pv[num].size(); ++i)
        {
            if(tp[pv[num][i]]==2&&cc[pv[num][i]]==0)
            {
                cc[pv[num][i]]=1;
                q.push(pv[num][i]);
            }
        }
    }
    for (int i = 1; i <=n; ++i)
    {
        if(cc[i]==0) return 0;
    }
    return 1;
}
int search(int idx)
{   
    a = 0;
    b = 0;
    if(idx==n+1)
    {
        if(divide()==1)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                a = a + arr[v[i]];
            }
            for (int i = 0; i < s.size(); ++i)
            {
                b = b + arr[s[i]];
            }
            if(ans==-1||ans>abs(a-b)) ans = abs(a-b);
        }

        return 0;
    }
    v.push_back(idx);
    tp[idx] = 1;
    search(idx+1);
    tp[idx] = 0;
    v.pop_back();
    s.push_back(idx);
    tp[idx] = 2;
    search(idx+1);
    tp[idx] = 0;
    s.pop_back();
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num,k;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>num;
        arr[i] = num;
    }

    for (int i = 1; i <= n; ++i)
    {
        cin>>k;
        for (int j = 0; j < k; ++j)
        {
            cin>>num;
            pv[i].push_back(num);
        }
    }
    tp[1] = 1;
    v.push_back(1);
    search(2);
    v.pop_back();
    tp[1] = 0;
    tp[1] = 2;
    s.push_back(1);
    search(2);
    s.pop_back();
    tp[1] = 0;

    cout<<ans<<"\n";
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}