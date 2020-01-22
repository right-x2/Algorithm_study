#include <iostream>
#include <string.h>


using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    char str[1000001];
    int cnt = 1;
    cin.getline(str,1000001);
    
    if(str[0]=' ') cnt = 0;
    
    for (int i = 0; i < 1000001; ++i)
    {
        if(str[i]==' ')cnt++;
    }
    if(str[strlen(str)-1]==' ')cnt--;
    cout<<cnt<<"\n";
    return 0;
}  