#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int mx = 0;
vector<int> ans;
int n,m;
vector<int> v[10001];
int arr[10001];
int chk[10001];
void solve(int a){
	int cnt = 0;
	chk[a] = a; 
	queue<int>pq;
	pq.push(a);
	while(!pq.empty()){
		cnt++;
		int way = pq.front();
		pq.pop();
		for (int i = 0; i < v[way].size(); ++i)
		{
			if(chk[v[way][i]]!=a){
				pq.push(v[way][i]);
				chk[v[way][i]] = a;
			}
		}
	}
	if(cnt>mx){
		ans.clear();
		ans.push_back(a);
		mx = cnt;
	}
	else if(cnt==mx) ans.push_back(a);
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
    	cin>>a>>b;
    	v[b].push_back(a);
    	arr[b] = 1;
    }
    for (int i = 1; i < 10001; ++i)
    {
    	if(arr[i]==1) solve(i);
    }
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout<<ans[i]<<" ";
    }
	return 0;
}