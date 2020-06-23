#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    string tmp = "UCPC";
    int idx = 0;
    getline(cin,str);
    for (int i = 0; i < str.length(); ++i)
    {
        if(idx==4) break;
        if(str[i]==tmp[idx]) idx++;
    }
    if(idx==4) cout<<"I love UCPC"<<"\n";
    else cout<<"I hate UCPC"<<"\n";
    return 0;
}