#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
char ans[2000001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    stack<int> stk;
    vector<int> v;
    int num;
    int idx = 0;
    int cnt = 0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }
    for(int i = 1; i <=n ;i++)
    {
        stk.push(i);
        ans[cnt] = '+';
        cnt++;
        while(!stk.empty()&&stk.top()==v[idx])
        {
            idx++;
            stk.pop();
            ans[cnt] = '-';
            cnt++;
        }
    }
    if(stk.empty())
    {
        for (int i = 0; i < cnt; ++i)
        {
            cout<<ans[i]<<"\n";
        }        
    }
    else cout<<"NO"<<"\n";

}  