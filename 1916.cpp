#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
vector<pair<int, int> > a[100000];
int d[100000];
int c[100000];
int dijikstra(int start, int end)
{
	d[start] = 0;
	priority_queue< pair<int , int> > pq; 
	pq.push(make_pair(start, 0));
	while(!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if(d[current]<distance) continue;
		for (int i = 0; i < a[current].size(); ++i)
		{
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 더 저렴하면 교체가능
			if(nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
	return d[end];
}
int main()
{
	int n,m,x,s,e,cost;
	int INF = 100000000;
	cin>>n;
	cin>>m;
	for (int i = 1; i <= n; ++i)
	{
		d[i] = INF;
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>s>>e>>cost;
		a[s].push_back(make_pair(e, cost));
	}

	cin>>s>>e;
	cout<<dijikstra(s,e)<<"";
}