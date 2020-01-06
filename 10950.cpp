#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    cin>>c;
    for (int i = 0; i < c; ++i)
    {
        cin>>a>>b;
        cout<<a+b<<"\n";
    }
    return 0;
}  