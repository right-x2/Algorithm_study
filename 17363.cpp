#include <iostream>
#include <string>
#include <queue>

using namespace std;
char arr[101][101];
int main(void)
{
    int n,m;
    string str="";
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < m; ++j)
        {
            if(str[j]== 124) arr[m-1-j][i]= 45;
            else if(str[j]== 45) arr[m-1-j][i]= 124;
            else if(str[j]== 92) arr[m-1-j][i]= 47;
            else if(str[j]== 47) arr[m-1-j][i]= 92;
            else if(str[j]== 62) arr[m-1-j][i]= 94;
            else if(str[j]== 94) arr[m-1-j][i]= 60;
            else if(str[j]== 60) arr[m-1-j][i]= 118;
            else if(str[j]== 118) arr[m-1-j][i]= 62;
            else arr[m-1-j][i]= str[j];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<arr[i][j]<<"";
        }
        if(i < m-1)cout<<"\n"<<"";
    }
    return 0;
}