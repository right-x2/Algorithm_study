#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


vector<int> v[101];
int arr[101][101];
int chk[101];
vector<int> temp;

int solve(int a){
	int sum = 0;
	arr[a][a] = 1;
	queue<pair<int,int> > queue;
	for (int i = 0; i < v[a].size(); ++i){
		if(arr[a][v[a][i]]==0){
			queue.push(make_pair(v[a][i],1));
			arr[a][v[a][i]] = 1;			
		}
	}
	while(!queue.empty()){
		int way = queue.front().first;
		int cnt = queue.front().second;
		sum = sum + cnt;
		queue.pop();
		for (int i = 0; i < v[way].size(); ++i){
			if(arr[a][v[way][i]]==0){
				queue.push(make_pair(v[way][i],cnt+1));
				arr[a][v[way][i]] = cnt+1;
			} 
		}
	}
	return sum;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
    	cin>>a>>b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    	if(chk[a]==0){
    		temp.push_back(a);
    		chk[a] = 1;
    	}
    	if(chk[b]==0){
    		temp.push_back(b);
    		chk[b] = 1;
    	}
    }

    int min = 0;
    int sum = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
    	sum  = solve(temp[i]);
    	if(idx==0){
    		idx = temp[i];
    		min = sum;
    	}
    	else{
    		if(min>sum){
    			idx = temp[i];
    			min = sum;
    		} else if(min==sum){
    			if(idx>temp[i]) idx = temp[i];
    		}
    	}
    }

    cout<<idx<<"\n";
    return 0;
}  