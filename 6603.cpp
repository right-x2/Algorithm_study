#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10];
vector<int> v;
vector<int> tmp;

int dfs(int start, int end)
{
    if(tmp.size()==6)
    {
        for (int i = 0; i < tmp.size(); ++i)
        {
            cout<<tmp[i]<<" ";
        }
        cout<<""<<"\n";
        return 0;
    }
    for (int i = start+1; i < end; ++i)
    {
        tmp.push_back(v[i]);
        dfs(i,end);
        tmp.pop_back();
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n = 1,k,a;
    while(n!=0)
    {
        cin>>n;
        for (int i = 0; i < n; ++i)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < n; ++i)
        {
            tmp.push_back(v[i]);
            dfs(i,v.size());
            tmp.pop_back();
        }
        cout<<""<<"\n";
        tmp.clear();
        v.clear();
    }

}  