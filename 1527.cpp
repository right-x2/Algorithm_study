#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string s,e;
int cnt = 0;
int comp(string a, string b)
{
    for (int i = 0; i < a.length(); ++i)
    {
        if(a[i]-'0'>b[i]-'0') return 0;
        else if(a[i]-'0'<b[i]-'0') return 1;
    }
    return 1;
}
int dp(string str)
{
    if(str.length()>e.length()) return 0;
    if(str.length()>s.length()||(str.length()==s.length()&&comp(s,str)==1))
    {
        if(str.length()<e.length())
        {
            cnt++;
        }
        else if(str.length()==e.length())
        {
            if(comp(str,e)==1) cnt++;
            return 0;
        }
    }
    dp(str+'4');
    dp(str+'7');
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;

    cin>>s>>e;
    dp("4");
    dp("7");
    cout<<cnt<<"\n";
    return 0;
}