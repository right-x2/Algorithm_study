#include <iostream>
#include <queue>


using namespace std;


vector< pair<int,int> >v[20001];
int arr[20001];
int visited[20001];

int play(int k){
    priority_queue< pair<int,int>, vector< pair<int,int> >,greater< pair<int,int> > > pq;

    pq.push(make_pair(0,k));
    while(!pq.empty()){
        int cost = pq.top().first;
        int way = pq.top().second;
        pq.pop();
        if(visited[way]==0&&(arr[way]==0||arr[way]>cost))
        {
            visited[way] = 1;
            arr[way] = cost;
            for (int i = 0; i < v[way].size(); ++i)
            {
                pq.push(make_pair(v[way][i].first+cost,v[way][i].second));
            }
        }
    }   
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,w,k;
    int a,b,c;
    cin>>n>>w;
    cin>>k;

    for (int i = 0; i < w; ++i)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(c,b));         
    }
    play(k);


    for (int i = 1; i <=n ; ++i)
    {
        if(i==k) cout<<0<<"\n";
        else if(arr[i]==0) cout<<"INF"<<"\n";
        else cout<<arr[i]<<"\n";
    }
    return 0;
    
}  