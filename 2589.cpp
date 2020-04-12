#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char arr[51][51];
int chk[51][51];
int n,m,mx = 0;
vector< pair<int,int> > v;

void solve(int a, int b){
	queue< pair<int,int> > q;
	q.push(make_pair(a,b));
	chk[a][b] = 1;
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if(chk[a][b]>mx) mx = chk[a][b];
		if(a+1<n&&arr[a+1][b]=='L'&&chk[a+1][b]==0){
			q.push(make_pair(a+1,b));
			chk[a+1][b] = chk[a][b] + 1;
		}
		if(a-1>=0&&arr[a-1][b]=='L'&&chk[a-1][b]==0){
			q.push(make_pair(a-1,b));
			chk[a-1][b] = chk[a][b] + 1;
		}
		if(b+1<m&&arr[a][b+1]=='L'&&chk[a][b+1]==0){
			q.push(make_pair(a,b+1));
			chk[a][b+1] = chk[a][b] + 1;
		}
		if(b-1>=0&&arr[a][b-1]=='L'&&chk[a][b-1]==0){
			q.push(make_pair(a,b-1));
			chk[a][b-1] = chk[a][b] + 1;
		}
	}
}

void init(){
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		chk[i][j] = 0;
    	}
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
    	cin>>str;
    	for (int j = 0; j < m; ++j)
    	{
    		arr[i][j] = str[j];
    		if(arr[i][j]=='L') v.push_back(make_pair(i,j));
    	}
    }

    for (int i = 0; i < v.size(); ++i)
    {
    	solve(v[i].first,v[i].second);
    	init();
    }

    cout<<mx-1<<"\n";
    return 0;
}  