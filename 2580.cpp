#include <iostream>

using namespace std;

int arr[10][10];
int zero;

int chk(int y, int x)
{
    int cnt = 0;
    int ans[9] = { 0 , };
    for (int i = 0; i < 9; ++i)
    {
        if(i!=x)
        {
            if(arr[y][i]==0)
            {
                cnt++;
            }
            else
            {
                ans[arr[y][i]] = 1;
            }
        }
    }
    ans[9] = { 0 , };
    for (int i = 0; i < 9; ++i)
    {
        if(i!=y)
        {
            if(arr[i][x]==0)
            {
                cnt++;
            }
            else
            {
                ans[arr[i][x]] = 1;
            }
        }
    }
    ans[9] = { 0 , };
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0) zero++;
        }
    }
    while(zero>0)
    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < count; ++j)
        {
            if(arr[i][j]==0) chk(i,j);
        }
    }
    return 0;
}  