#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
int mp[100][100]= {0,};
int c[100][100] = {0,};
int cx[4] = {1,-1, 0, 0};
int cy[4] = {0, 0, -1,1};

int find( int n , int m)
{
    int cur_x, cur_y = 0;
    queue< pair<int , int> > q;
    q.push( pair<int , int >(cur_x , cur_y));
    mp[cur_y][cur_x]= 1;
    while(!q.empty())
    {
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();
        if(cur_x==m-1 && cur_y==n-1) break;
        for (int i = 0; i < 4; ++i)
        {
            int nx = cur_x + cx[i];
            int ny = cur_y + cy[i];
            if(nx >= 0 && nx < m && ny < n && ny >= 0 && c[ny][nx]==1 && mp[ny][nx] ==0 )
            {
                mp[ny][nx] = mp[cur_y][cur_x] + 1;
                q.push(pair<int, int>(nx , ny));
            }
        }
    }
    return mp[n-1][m-1];
}
int main()
{	
	int n , m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string k;
        cin>>k;
        for (int j = 0; j < m; j++)
        {
            if (k[j]=='1')c[i][j] = 1;
        }
    }
    int answer = find(n,m);
    cout<<answer<<" ";
}