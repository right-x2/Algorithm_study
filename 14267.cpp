#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


vector<int> v[100001];
int cnt[100001];
int chk[100001];

int play(int k){
	stack< pair<int,int> >stk;
	stk.push(make_pair(k,cnt[k]));
	while(!stk.empty()){
		int tp = stk.top().first;
		int w = stk.top().second;
		chk[tp] = 1;
		stk.pop();
		for(int i = 0; i < v[tp].size() ;i++){
			cnt[v[tp][i]] = cnt[v[tp][i]] + w;
			stk.push(make_pair(v[tp][i],cnt[v[tp][i]]));
		}
	}
	return 0;
} 
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,k,w,sv;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
    	cin>>sv;
    	if(sv>0) v[sv].push_back(i+1);
    }

    for(int i = 0; i < m; i++){
    	cin>>k>>w;
    	cnt[k] = cnt[k] + w;
    }
    for(int i = 2; i <= n; i++){
    	if(chk[i]==0) play(i);
    }
    for(int i = 1; i <= n; i++){
    	cout<<cnt[i]<<" ";
    }
	return 0;
}