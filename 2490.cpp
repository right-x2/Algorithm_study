#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int cnt = 0,num;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin>>num;
            cnt = cnt + num;
        }
        if(cnt==0) cout<<'D'<<"\n";
        else if(cnt==1) cout<<'C'<<"\n";
        else if(cnt==2) cout<<'B'<<"\n";
        else if(cnt==3) cout<<'A'<<"\n";
        else if(cnt==4) cout<<'E'<<"\n";
        cnt = 0;
    }
    return 0;
}  