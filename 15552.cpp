#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int c;
    long long a,b;
    cin>>c;
    for (int i = 1; i <= c; ++i)
    {
        cin>>a>>b;
        cout<<a+b<<"\n";
    }
    
    return 0;
}  