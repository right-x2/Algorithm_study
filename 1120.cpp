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
    int mx = 0;
    string str,temp;
    cin>>str>>temp;
    int mn = str.length();
    for (int i = 0; i <= temp.length()-str.length(); ++i)
    {
    	int cnt = 0;
    	for (int j = 0; j < str.length(); ++j)
    	{
    		if(str[j]!=temp[j+i]) cnt++;
    	}
    	if(cnt<mn) mn = cnt;
    }
    cout<<mn<<"\n";

	return 0;
}