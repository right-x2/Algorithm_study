#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>a;
    if(a%4==0)
    {
        if(a%100!=0||a%400==0) cout<<"1"<<"\n";
        else cout<<"0"<<"\n";
    }
    else cout<<"0"<<"\n";

    return 0;
}  