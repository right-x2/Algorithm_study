#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int n,m;
map<int, string> mp;
map<string, int> mp2;

int conv(string str)
{
    int ans = 0;
    int mul = 1;
    for (int i = str.length()-1; i >=0; i--)
    {
        ans = ans + mul*(str[i]-'0');
        mul = mul * 10;
    }
    return ans;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    string str;
    cin>>n>>m;
    for (int i = 1; i <=n ; ++i)
    {
        cin>>str;
        mp.insert(make_pair(i,str));
        mp2.insert(make_pair(str,i));
    }
    for (int i = 0; i < m; ++i)
    {
        cin>>str;
        if(str[0]>='A'&&str[0]<='Z')
        {
            cout<<mp2.find(str)->second<<"\n";
        }
        else
        {
            int n = conv(str);
            cout<<mp.find(n)->second<<"\n";
        }
    }
}   