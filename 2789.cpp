#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int chk[30];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str,ans,tmp="";
    str = "CAMBRIDGE";
    cin>>ans;
    for (int i = 0; i < str.length(); ++i)
    {
        chk[str[i]-'A'] = 1;
    }
    for (int i = 0; i < ans.length(); ++i)
    {
        if(chk[ans[i]-'A']==0) tmp =tmp + ans[i];
    }
    cout<<tmp<<"\n";
    return 0;
}   