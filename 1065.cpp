#include <iostream>

using namespace std;

int cnt = 0;
void check(int n)
{
    int a,b,c,d;
    if(n<100) cnt++;
    else 
    {
        a = n/100;
        b = (n%100)/10;
        c = n%10;
        if(c-b==b-a) cnt++;
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    for (int i = 1; i <=n; ++i)
    {
        check(i);  
    }
    cout<<cnt<<"\n";
    return 0;
}  