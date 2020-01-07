#include <iostream>


using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    int sum=0;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]=='A'||str[i]=='B'||str[i]=='C') sum = sum + 2;
        else if(str[i]=='D'||str[i]=='E'||str[i]=='F') sum = sum + 3;
        else if(str[i]=='G'||str[i]=='H'||str[i]=='I') sum = sum + 4;
        else if(str[i]=='J'||str[i]=='K'||str[i]=='L') sum = sum + 5;
        else if(str[i]=='M'||str[i]=='N'||str[i]=='O') sum = sum + 6;
        else if(str[i]=='P'||str[i]=='Q'||str[i]=='R'||str[i]=='S') sum = sum + 7;
        else if(str[i]=='T'||str[i]=='U'||str[i]=='V') sum = sum + 8;
        else if(str[i]=='X'||str[i]=='Y'||str[i]=='Z'||str[i]=='W') sum = sum + 9;
    }
    cout<<sum+str.length()<<"\n";
    return 0;
}  