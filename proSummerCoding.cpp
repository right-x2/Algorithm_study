#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector< pair<int,int> >pv[2001];
int arr[2001];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 1;
    
    for(int i = 0; i < road.size(); i++){
        pv[road[i][0]].push_back(make_pair(road[i][1],road[i][2]));
        pv[road[i][1]].push_back(make_pair(road[i][0],road[i][2]));
    }
    
    priority_queue< int, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    
    for(int i = 0; i < pv[1].size();i++){
        if(pv[1][i].second<=K) pq.push(make_pair(pv[1][i].second,pv[1][i].first));
    }
    
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int way = pq.top().second;
        pq.pop();
        if(cost<=K&&arr[way]==0)
        {
            answer++;
            cout<<way<<"\n";
            arr[way] = 1;
        }
        for(int i = 0; i < pv[way].size();i++){
            if(pv[way][i].first!=1&&arr[pv[way][i].first]==0&&pv[way][i].second+cost<=K){
                pq.push(make_pair(pv[way][i].second+cost,pv[way][i].first));
            }
        }
    }
    return answer;
}