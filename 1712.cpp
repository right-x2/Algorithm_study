#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long a,b,c,sum,sumc,cnt= 1;
    cin>>a>>b>>c;
    if(b>=c) cout<<-1<<"\n";
    else cout<<(a/(c-b))+1<<"\n";
    return 0;
}  