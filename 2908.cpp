#include <iostream>


using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string a,b;
    int c=0,d=0;
    int mul = 1;
    cin>>a>>b;
    for (int i = 0; i < a.length(); ++i)
    {
        c = c + (a[i]-'0')*mul;
        mul = mul*10;
    }
    mul = 1;
    for (int i = 0; i < b.length(); ++i)
    {
        d = d + (b[i]-'0')*mul;
        mul = mul*10;
    }

    if(c>d) cout<<c<<"\n";
    else cout<<d<<"\n";
    return 0;
}  