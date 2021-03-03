#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[701][701];
vector<int> v[1000001];
int dy[3] = {0,-1,-1};
int dx[3] = {-1,-1,0};
int n,m;

void solve(int idx)
{
    int temp = v[idx][0];
    int y;
    int x;
    if(temp<m-1)
    {
        y = m-1-temp;
        x = 0;
    }
    else
    {
        y = 0;
        x = temp -(m-1);
    }
    
    for (int i = 1; i < 3; i++)
    {
        for(int j = 0; j < v[idx][i]; j++)
        {
            arr[y][x] = arr[y][x] + i;
            if(y>0) y--;
            else x++;
        }
    }
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>m>>n;

    for(int i = 0; i< m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3;j++)
        {
            cin>>a;
            v[i].push_back(a);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        solve(i);
    }

    for(int i = 1; i < m; i++)
    {
        
        for(int j = 1; j<m; j++)
        {
            int mx = 0;
            for(int k = 0; k < 3; k++)
            {
                if(mx<arr[i+dy[k]][j+dx[k]]) mx = arr[i+dy[k]][j+dx[k]];
            }
            arr[i][j] = mx;
        }
    }
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}  