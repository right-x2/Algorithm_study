#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m;
    queue<int> q;
    vector<int> v;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }
    int cnt = 0;
    int tmp = 0;
    while(!q.empty())
    {
        cnt++;
        tmp = q.front();
        q.pop();
        if(cnt==m)
        {
            v.push_back(tmp);
            cnt = 0;
        }
        else q.push(tmp);
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if(i==0&&v.size()==1)
        {
            cout<<"<"<<"";
            cout<<+v[i]<<">";
        }
        else if(i==0)
        {
            cout<<"<"<<"";
            cout<<+v[i]<<", ";
        }
        else if(i==v.size()-1)
        {
            cout<<+v[i]<<">";
        }
        else
        {
            cout<<+v[i]<<", ";
        }
    }
    return 0;
}  