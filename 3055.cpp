#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r,c;
int sy,sx;
int dy,dx;
char arr[51][51];
int chk[51][51];
vector< pair<int,int> >v;

void spray(){
	int len = v.size();
	for(int i = 0; i < len; i++){
		if(v[i].first+1<r&&arr[v[i].first+1][v[i].second]!='D'&&arr[v[i].first+1][v[i].second]!='X'&&arr[v[i].first+1][v[i].second]!='*'){
			arr[v[i].first+1][v[i].second]='*';
			v.push_back(make_pair(v[i].first+1,v[i].second));
		}
		if(v[i].first-1>=0&&arr[v[i].first-1][v[i].second]!='D'&&arr[v[i].first-1][v[i].second]!='X'&&arr[v[i].first-1][v[i].second]!='*'){
			arr[v[i].first-1][v[i].second]='*';
			v.push_back(make_pair(v[i].first-1,v[i].second));
		}
		if(v[i].second+1<c&&arr[v[i].first][v[i].second+1]!='D'&&arr[v[i].first][v[i].second+1]!='X'&&arr[v[i].first][v[i].second+1]!='*'){
			arr[v[i].first][v[i].second+1]='*';
			v.push_back(make_pair(v[i].first,v[i].second+1));
		}
		if(v[i].second-1>=0&&arr[v[i].first][v[i].second-1]!='D'&&arr[v[i].first][v[i].second-1]!='X'&&arr[v[i].first][v[i].second-1]!='*'){
			arr[v[i].first][v[i].second-1]='*';
			v.push_back(make_pair(v[i].first,v[i].second-1));
		}
	}
}
int play(){
	queue< pair<int, int> > pq;
	pq.push(make_pair(sy,sx));
	int y,x;
	int cnt = 0;
	while(!pq.empty()){
		y = pq.front().first;
		x = pq.front().second;
		if(y==dy&&x==dx) return chk[y][x];
		pq.pop();
		if(chk[y][x]==cnt){
			spray();
			cnt++;
		}
		if(y+1<r&&chk[y+1][x]==0&&(arr[y+1][x]=='D'||arr[y+1][x]=='.')){
			pq.push(make_pair(y+1,x));
			chk[y+1][x]=chk[y][x] + 1;
			arr[y+1][x] = 'S';
		}
		if(y-1>=0&&chk[y-1][x]==0&&(arr[y-1][x]=='D'||arr[y-1][x]=='.')){
			pq.push(make_pair(y-1,x));
			chk[y-1][x]=chk[y][x] + 1;
			arr[y-1][x] = 'S';
		}
		if(x+1<c&&chk[y][x+1]==0&&(arr[y][x+1]=='D'||arr[y][x+1]=='.')){
			pq.push(make_pair(y,x+1));
			chk[y][x+1]=chk[y][x] + 1;
			arr[y][x+1] = 'S';
		}
		if(x-1>=0&&chk[y][x-1]==0&&(arr[y][x-1]=='D'||arr[y][x-1]=='.')){
			pq.push(make_pair(y,x-1));
			chk[y][x-1]=chk[y][x] + 1;
			arr[y][x-1] = 'S';
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>r>>c;

    for(int i = 0; i < r; i++){
    	for(int j = 0; j < c; j++){
    		cin>>arr[i][j];
    		if(arr[i][j]=='S'){
    			sy = i;
    			sx = j;
    		} else if(arr[i][j]=='D'){
    			dy = i;
    			dx = j;
    		} else if(arr[i][j]=='*'){
    			v.push_back(make_pair(i,j));
    		}
    	}
    }

    int ans = play();

    if(ans==-1) cout<<"KAKTUS"<<"\n";
    else cout<<ans<<"\n";

	return 0;
}