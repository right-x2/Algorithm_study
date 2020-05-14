#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<string> v;
    int n;
    string str;
    int idx = 0;
    cin>>n;
    for (int i = 0; i < n+1; ++i)
    {
        getline(cin,str);
        string temp = str;
        if(str.substr(0,2)=="pu")
        {
            v.push_back(temp.substr(5,temp.length()));
        }
        else if(str.substr(0,2)=="po")
        {
            if(idx==v.size()) cout<<-1<<"\n";
            else
            {
                cout<<v[idx]<<"\n";
                idx++;
            }
        }
        else if(str[0]=='s')
        {
            cout<<v.size()-idx<<"\n";
        }
        else if(str[0]=='e')
        {
            if(v.size()==idx) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(str[0]=='f')
        {
            if(idx==v.size()) cout<<-1<<"\n";
            else
            {
                cout<<v[idx]<<"\n";
            }
        }
        else if(str[0]=='b')
        {
            if(idx==v.size()) cout<<-1<<"\n";
            else
            {
                cout<<v[v.size()-1]<<"\n";
            }
        }
    }
    return 0;
}  