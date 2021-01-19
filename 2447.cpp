#include <iostream>


using namespace std;


char arr[10001][10001];
int n;


int solve(int y, int x,int len)
{
    int a = len/3;

    if(a==1)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if(i==1&&j==1) continue;
                arr[y+i][x+j] = '*';      
            }
        } 
        return 0;       
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if(i==1&&j==1) continue;
            solve(y+a*i,x+a*j,a);       
        }
    }

    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;

    solve(0,0,n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(arr[i][j]=='*') cout<<arr[i][j]<<"";
            else cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}