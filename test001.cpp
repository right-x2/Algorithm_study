#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int n,m;
int s,d;
vector<pair<int,int> > v[501];
vector<int> arr[501];
int way[501][501];
int chk[501];
int trace[501];
int bchk[501];
int cnt;


int dijkstra()
{
	
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >q;
	q.push(make_pair(0,make_pair(0,s)));
	int temp = 0;
	while(!q.empty())
	{
		int p = q.top().second.second;
		int pre = q.top().second.first;
		int cost = q.top().first;
		q.pop();
		if(trace[p]==0||cost==trace[p]) 
		{
			arr[p].push_back(pre);
			trace[p] = cost;
		}
		if(chk[p]==1) continue;

		if(temp>0&&cost>temp) return 0;
		

		if(p==d) 
		{
			if(temp==0) temp = cost;
			continue;
		}
		chk[p] = 1;
		

		for (int i = 0; i < v[p].size(); ++i)
		{
			if(chk[v[p][i].second]==0)
			{
				q.push(make_pair(cost+v[p][i].first,make_pair(p,v[p][i].second)));
			}
		}
	}
	return 0;
}

int solve()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > >pq;
	pq.push(make_pair(0,s));

	while(!pq.empty())
	{
		int cost = pq.top().first;
		int p = pq.top().second;
		pq.pop();
		if(chk[p]==2) continue;
		chk[p] = 2;
		if(p==d)
		{
			return cost;
		}

		for (int i = 0; i < v[p].size(); ++i)
		{
			if(chk[v[p][i].second]!=2&&way[p][v[p][i].second]!=cnt)
			{
				pq.push(make_pair(cost+v[p][i].first,v[p][i].second));
			}
		}
	}

	return -1;
}


int recur(int idx)
{
	bchk[idx] = 1;
	if(idx==s) return 0; 
	for (int i = 0; i < arr[idx].size(); ++i)
	{
		way[arr[idx][i]][idx] = cnt;
		if(bchk[arr[idx][i]]==0) recur(arr[idx][i]);
	}

	return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    while(1)
    {
    	cnt++;
	    cin>>n>>m;
	    if(n==0&&m==0) break;
	    cin>>s>>d;
	    int a,b,c;
	    for (int i = 0; i < m; ++i)
	    {
	        cin>>a>>b>>c;
	        v[a].push_back(make_pair(c,b));
	    }

	    dijkstra(); 	

	    recur(d);
	    cout<<solve()<<"\n";

	    for(int i = 0; i < n; i++)
	    {
	    	arr[i].clear();
	    	v[i].clear();
	    	chk[i] = 0;
	    	trace[i] = 0;
	    	bchk[i] = 0;
	    }
    }

    return 0;
}  