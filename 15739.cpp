#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
int arr[101][101];
int c[100001];
int check(int n)
{
    int up=0,down=0,left=0,right=0,cro=0,cooss=0;
    int flag = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; ++i)
    {
        up = up + arr[0][i];
        down = down + arr[n-1][i];
        left = left + arr[i][0];
        right = right + arr[i][n-1];
        cro = cro + arr[i][i];
        cooss = cooss + arr[n-1-i][i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum1 = sum1 + arr[i][j];
            sum2 = sum2 + arr[j][i];
        }
        if(up!=sum1||left!=sum2) return 0;
        sum1 = 0;
        sum2 = 0;
    }
    int a = n*(n*n + 1)/2;
    if(up==a&&down==a&&left==a&&right==a&&cro==a&&cooss==a) return 1;
}
int main()
{
    int n, a,kk=0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>a;
            if(c[a]==1) kk = 1;
            arr[i][j] = a;
            c[a] = 1;
        }
    }
    if(check(n)==1 && kk!=1) cout<<"TRUE"<<"";
    else cout<<"FALSE"<<"";
}