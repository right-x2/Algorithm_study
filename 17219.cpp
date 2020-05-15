#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string,string>mp;

void split(string str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]==' ')
        {
            mp.insert(make_pair(str.substr(0,i),str.substr(i+1,str.length())));
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m;
    string str;
    cin>>n>>m;
    for (int i = 0; i < n+1; ++i)
    {
        getline(cin,str);
        split(str);
    }
    string temp;
    for (int i = 0; i < m; ++i)
    {
        cin>>temp;
        cout<<mp.find(temp)->second<<"\n";
    }
}  