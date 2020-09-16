#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int n,m;
int arr[101][101];

int solve1(int idx)
{
    int pre = arr[idx][0];
    int row = 1;
    int b = 0;
    for (int i = 1; i < n; ++i)
    {
        row++;
        if(abs(arr[idx][i]-pre)>1) return 0;
        else if(pre==arr[idx][i])
        {
            if(b==1&&row-1==m) 
            {
                b = 0;
                row = 1;
            }
        }
        else if(pre<arr[idx][i])
        {
            if(b==1||row-1<m) return 0;
            else row = 1;
            pre = arr[idx][i];
        }
        else if(pre>arr[idx][i])
        {
            if(b==1&&row-1<m) return 0;
            else
            {
                row = 1;
                b = 1;
            }
            pre = arr[idx][i];
        }
    }
    //cout<<row<<" "<<m<<"\n";
    if(b==1&&m>row) return 0;
    return 1;
}

int solve2(int idx)
{
    int pre = arr[0][idx];
    int row = 1;
    int b = 0;
    
    for (int i = 1; i < n; ++i)
    {
        row++;
        if(abs(arr[i][idx]-pre)>1) return 0;
        else if(pre==arr[i][idx])
        {
            if(b==1&&row-1==m) 
            {
                b = 0;
                row = 1;
            }
        }
        else if(pre<arr[i][idx])
        {
            if(b==1||row-1<m) return 0;
            else row = 1;
            pre = arr[i][idx];
        }
        else if(pre>arr[i][idx])
        {
            if(b==1&&row-1<m) return 0;
            else
            {
                row = 1;
                b = 1;
            }
            pre = arr[i][idx];
        }
    }
    //cout<<row<<" "<<m<<"\n";
    if(b==1&&m>row) return 0;
    return 1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int answer = 0;
    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        answer = answer + solve2(i) + solve1(i);
    }
    cout<<answer<<"\n";
    return 0;
}