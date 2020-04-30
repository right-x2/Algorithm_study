#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long divide(long long a, long long b, long long c)
{
    if(b==0) return 1;
    if(b==1) return a;
    long long half = divide(a,b/2,c);
    if(b%2==0) return (half*half)%c;
    else return ((half*half)%c*a)%c;

}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<divide(a%c,b,c)<<"\n";
    return 0;
}