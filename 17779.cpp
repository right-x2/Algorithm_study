#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int d1,d2;
int n;
int arr[21][21];
int chk[21][21];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int x,y;
int sum;



int solve()
{

    int mx,mn;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            chk[i][j] = 0;
        }
    }
    for (int i = 0; i <= d1; ++i)
    {
        if(y+i<n&&x-i>0) chk[y+i][x-i] = 5;
        if(y+d2+i<=n&&x+d2-i<=n) chk[y+d2+i][x+d2-i] = 5;
    }
    for (int i = 0; i <= d2; ++i)
    {
        if(y+i<=n&&x+i<=n) chk[y+i][x+i] = 5;
        if(y+d1+i<=n&&x-d1+i<=n) chk[y+d1+i][x-d1+i] = 5;
    }

    int total = 0;
    queue<pair<int,int> >q;
    q.push(make_pair(1,1));
    int asum = arr[1][1];
    chk[1][1] = 1;
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if(a+dy[i]>0&&a+dy[i]<=n&&b+dx[i]>0&&b+dx[i]<=n&&chk[a+dy[i]][b+dx[i]]==0&&a+dy[i]<y+d1&&b+dx[i]<=x)
            {
                chk[a+dy[i]][b+dx[i]] = 1;
                q.push(make_pair(a+dy[i],b+dx[i]));
                asum = asum + arr[a+dy[i]][b+dx[i]];
            }
        }
    }

    total = asum;
    mx = asum;
    mn = asum;

    q.push(make_pair(1,n));
    asum = arr[1][n];
    chk[1][n] = 2;
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if(a+dy[i]>0&&a+dy[i]<=n&&b+dx[i]>0&&b+dx[i]<=n&&chk[a+dy[i]][b+dx[i]]==0&&a+dy[i]<=y+d2&&b+dx[i]<=n)
            {
                chk[a+dy[i]][b+dx[i]] = 2;
                q.push(make_pair(a+dy[i],b+dx[i]));
                asum = asum + arr[a+dy[i]][b+dx[i]];
            }
        }
    }


    total = total + asum;
    if(mx<asum) mx = asum;
    if(mn>asum) mn = asum;

    q.push(make_pair(n,1));
    asum = arr[n][1];
    chk[n][1] = 3;
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if(a+dy[i]>0&&a+dy[i]<=n&&b+dx[i]>0&&b+dx[i]<=n&&chk[a+dy[i]][b+dx[i]]==0&&y+d1<=a+dy[i]&&a+dy[i]<=n&&b+dx[i]<x-d1+d2)
            {
                chk[a+dy[i]][b+dx[i]] = 3;
                q.push(make_pair(a+dy[i],b+dx[i]));
                asum = asum + arr[a+dy[i]][b+dx[i]];
            }
        }
    }

    total = total + asum;
    if(mx<asum) mx = asum;
    if(mn>asum) mn = asum;

    q.push(make_pair(n,n));
    asum = arr[n][n];
    chk[n][n] = 4;
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if(a+dy[i]>0&&a+dy[i]<=n&&b+dx[i]>0&&b+dx[i]<=n&&chk[a+dy[i]][b+dx[i]]==0&&y+d2<a+dy[i]&&a+dy[i]<=n&&b+dx[i]>=x-d1+d2&&b+dx[i]<=n)
            {
                chk[a+dy[i]][b+dx[i]] = 4;
                q.push(make_pair(a+dy[i],b+dx[i]));
                asum = asum + arr[a+dy[i]][b+dx[i]];
            }
        }
    }



    total = total + asum;
    if(mx<asum) mx = asum;
    if(mn>asum) mn = asum;

    if(mx<sum-total) mx = sum-total;
    if(mn>sum-total) mn = sum-total;

    return mx - mn;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int answer = -1;

    cin>>n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin>>arr[i][j];
            sum = sum + arr[i][j];
        }
    }

    for (int i = 1; i <= n-2; ++i)
    {
        for (int j = 2; j <= n-1; ++j)
        {
            y = i;
            x = j;
            for (int k = 1; k < n; ++k)
            {
                d1 = k;
                for (int l = 1; l < n; ++l)
                {
                    d2 = l;
                    if(y+k+l>n||x-k<1||x+l>n) break;
                    int temp = solve();
                    if(answer==-1||temp<answer) answer = temp;
                }
            }
        }
    }
    cout<<answer<<"\n";
    return 0;
}