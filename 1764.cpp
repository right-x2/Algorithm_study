#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<string> v;
vector<string> ans;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    cin>>n>>m;
    for (int i = 0; i < n+m; ++i)
    {
    	cin>>str;
    	v.push_back(str);
    }

    sort(v.begin(),v.end());

    for (int i = 1; i < v.size(); ++i)
    {
    	if(v[i]==v[i-1]) ans.push_back(v[i]);
    }

    cout<<ans.size()<<"\n";
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout<<ans[i]<<"\n";
    }

	return 0;
}