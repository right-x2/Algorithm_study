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
    deque<string>dq;
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
            if(str[5]=='b') dq.push_back(temp.substr(10,temp.length()));
            else 
            {
               dq.push_front(temp.substr(11,temp.length()));
    
            }
        }
        else if(str.substr(0,2)=="po")
        {
            if(dq.size()==0) cout<<-1<<"\n";
            else
            {
                if(str[4]=='b')
                {
                    cout<<dq.back()<<"\n";
                    dq.pop_back();
                }
                else 
                {
                    cout<<dq.front()<<"\n";
                    dq.pop_front();
                }
            }
        }
        else if(str[0]=='s')
        {
            cout<<dq.size()<<"\n";
        }
        else if(str[0]=='e')
        {
            if(dq.size()==0) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(str[0]=='f')
        {
            if(dq.size()==0) cout<<-1<<"\n";
            else
            {
                cout<<dq.front()<<"\n";
            }
        }
        else if(str[0]=='b')
        {
            if(dq.size()==0) cout<<-1<<"\n";
            else
            {
                cout<<dq.back()<<"\n";
            }
        }
    }
    return 0;
}  