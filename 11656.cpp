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
    string str,temp;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
    	temp = str.substr(i,str.length()-i);
    	ans.push_back(temp);
    }

    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout<<ans[i]<<"\n";
    }

	return 0;
}