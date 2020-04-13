#include <iostream>
#include <queue>
using namespace std;


int arr[101][101];
int chk[101][101];

int n, m;
int mn = 0;
struct Hm 
{
    int y;
    int x;
    Hm(int a, int b) : y(a), x(b) {}
};
bool operator<(Hm t, Hm u){
    return t.y > u.y;
}

int move(){
	priority_queue<pair<int,Hm>,vector< pair<int,Hm> >,greater< pair<int,Hm > > >pq;
	pq.push(make_pair(0,Hm(0,0)));
	while(!pq.empty()){
		int a = pq.top().second.y;
		int b = pq.top().second.x;
		int dis = pq.top().first;
		pq.pop();
		if(dis>=mn) break;
		if(a==m-1&&b==n-1){
			if(mn>dis) mn = dis;
			return 0;
		}
		if(chk[a][b]==1) continue;
		chk[a][b] = 1;
		if(a+1<m&&chk[a+1][b]==0){
			if(arr[a+1][b]==1) pq.push(make_pair(dis+1,Hm(a+1,b)));
			else pq.push(make_pair(dis,Hm(a+1,b)));
		} 

		if(b+1<n&&chk[a][b+1]==0){
			if(arr[a][b+1]==1) pq.push(make_pair(dis+1,Hm(a,b+1)));
			else pq.push(make_pair(dis,Hm(a,b+1)));
		}

		if(a-1>=0&&chk[a-1][b]==0){
			if(arr[a-1][b]==1) pq.push(make_pair(dis+1,Hm(a-1,b)));
			else pq.push(make_pair(dis,Hm(a-1,b)));
		}

		if(b-1>=0&&chk[a][b-1]==0){
			if(arr[a][b-1]==1) pq.push(make_pair(dis+1,Hm(a,b-1)));
			else pq.push(make_pair(dis,Hm(a,b-1)));
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
    	cin>>str;
    	for(int j = 0; j < n; j++){
    		arr[i][j] = str[j]-'0';
    		if(arr[i][j]==1) mn++;
    	}
    }
    move();
    cout<<mn<<"\n";
	return 0;
}