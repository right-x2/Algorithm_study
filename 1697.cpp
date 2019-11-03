#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
int mp[1000001]= {0,};
int c[1000001]= {0,};
int cx[2] = {1,-1};
int find( int n , int m)
{
    int nx = 0;
    int cur_x = n;
    queue<int> q;
    q.push(cur_x);
    while(!q.empty())
    {
        cur_x = q.front();
        q.pop();
        if(cur_x==m) break;
        for (int i = 0; i < 3; ++i)
        {
            if(i!=2) 
            {
                if(cur_x > m && i == 1 &&c[cur_x + cx[i]]==0)
                {
                    nx = cur_x + cx[i];
                    mp[nx] = mp[cur_x] + 1;
                    q.push(nx);
                    c[nx] = 1;
                }
                else if(c[cur_x + cx[i]]==0)
                {
                    nx = cur_x + cx[i];
                    mp[nx] = mp[cur_x] + 1;
                    c[nx] = 1;
                    q.push(nx);
                }
            }
            else if( cur_x < m && cur_x * 2 <100001 && c[cur_x * 2]==0)
            {
                nx = cur_x * 2;
                c[nx] = 1;
                mp[nx] = mp[cur_x] + 1;
                q.push(nx);
            }
        }
    }
    return mp[m];
}
int main()
{	
	int n , m;
    cin>>n>>m;
    int answer = find(n,m);
    cout<<answer<<" ";
}