#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    string str;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        cout<<(str[0]-'0')+(str[2]-'0')<<"\n";
    }
    return 0;
}  