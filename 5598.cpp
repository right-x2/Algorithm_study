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
    string str;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
    	if(str[i]>='D') str[i]=str[i]-3;
    	else str[i] = 'Z'-('C'-str[i]);
    }
    cout<<str<<"\n";

	return 0;
}