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
    string str="-1";
    while(str!="0")
    {
        cin>>str;
        if(str=="0") break;
        int flag = 0;
        for (int i = 0; i < str.length()-1/2; ++i)
        {
            if(str[i]!=str[str.length()-1-i])
            {
                flag = 1;
                break;
            }
        }
        if(flag==1) cout<<"no"<<"\n";
        else cout<<"yes"<<"\n";
    }
    return 0;
}  