#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int c;
    long long a,b;
    while(1)
    {
        cin>>a>>b;
        if(a==0&&b==0) break;
        cout<<a+b<<"\n";
    }
    
    return 0;
}  