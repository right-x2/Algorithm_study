#include <iostream>

using namespace std;

char arr[21][21];
int chk [32];
int n,m;
int mx = 0;
void dfs(int y, int x,int cnt){
		chk[arr[y][x]-'A'] = 1;
		if(cnt>mx) mx = cnt;
		if(y-1>=0)
		{
			if(chk[arr[y-1][x]-'A']==0)
			{
				dfs(y-1,x,cnt+1);
				chk[arr[y-1][x]-'A'] = 0;
			}
		}
		if(y+1<n)
		{
			if(chk[arr[y+1][x]-'A']==0)
			{
				dfs(y+1,x,cnt+1);
				chk[arr[y+1][x]-'A'] = 0;
			}
		}
		if(x-1>=0)
		{
			if(chk[arr[y][x-1]-'A']==0)
			{
				dfs(y,x-1,cnt+1);
				chk[arr[y][x-1]-'A'] = 0;
			}
		}
		if(x+1<m)
		{
			if(chk[arr[y][x+1]-'A']==0)
			{
				dfs(y,x+1,cnt+1);
				chk[arr[y][x+1]-'A'] = 0;
			}
		}
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cin>>arr[i][j];
    	}
    }

    dfs(0,0,1);
    cout<<mx<<"\n";
    return 0;
}  