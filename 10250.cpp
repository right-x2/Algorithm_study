#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c,d,e;
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>a>>b>>c;
        d = c/a;
        e = c%a;
        d++;
        if(e==0)
        {
            e = a;
            d--;
        }
        e = e *100;
        cout<<d+e<<"\n";
    }
    
    return 0;
    
}  