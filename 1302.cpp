#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> v;
vector<string> ans;
int arr[1001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    string str;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        int flag = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            if(v[j]==str)
            {
                flag = 1;
                arr[j]++;
                break;
            }
        }
        if(flag==0) v.push_back(str);  
    }
    int mx = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if(arr[i]==0) break;
        else if(mx<arr[i])
        {
            ans.clear();
            ans.push_back(v[i]);
            mx = arr[i];
        }
        else if(mx==arr[i])
        {
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0]<<"\n";
    return 0;
}  