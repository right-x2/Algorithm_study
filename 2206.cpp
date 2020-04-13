#include <iostream>
#include <queue>
using namespace std;


int arr[1001][1001];
int chk[1001][1001];
int blk[1001][1001];

int n, m;
int mn = 1000001;
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
	queue< pair<int,Hm> >pq;
	pq.push(make_pair(0,Hm(0,0)));
	chk[0][0] = 1;
	while(!pq.empty()){
		/*
		for(int i = 0; i < n; i++){
	    	for(int j = 0; j < m; j++){
	    		cout<<blk[i][j]<<" ";
	    	}
	    	cout<<"\n"<<"";
    	}
    	cout<<"\n"<<"";
    	*/
		int a = pq.front().second.y;
		int b = pq.front().second.x;
		int dis = pq.front().first;
		pq.pop();
		if(a==n-1&&b==m-1){
			if(chk[a][b]==0) mn = blk[a][b];
			else mn = chk[a][b];
			return 0;
		}
		if(a+1<n&&chk[a+1][b]==0){
			if(arr[a+1][b]==1&&dis==0){
				pq.push(make_pair(dis+1,Hm(a+1,b)));
				blk[a+1][b] = chk[a][b] + 1; 
			}
			else if(arr[a+1][b]==0&&dis==0){
				pq.push(make_pair(dis,Hm(a+1,b)));
				chk[a+1][b] = chk[a][b] + 1;
			}else if(arr[a+1][b]==0&&dis==1&&blk[a+1][b]==0){
				pq.push(make_pair(dis,Hm(a+1,b)));
				blk[a+1][b] = blk[a][b] + 1; 
			}
		} 

		if(b+1<m&&chk[a][b+1]==0){
			if(arr[a][b+1]==1&&dis==0){
				pq.push(make_pair(dis+1,Hm(a,b+1)));
				blk[a][b+1] = chk[a][b] + 1;
			}
			else if(arr[a][b+1]==0&&dis==0){
				pq.push(make_pair(dis,Hm(a,b+1)));
				chk[a][b+1] = chk[a][b] + 1;
			}else if(arr[a][b+1]==0&&dis==1&&blk[a][b+1]==0){
				pq.push(make_pair(dis,Hm(a,b+1)));
				blk[a][b+1] = blk[a][b] + 1; 
			}
		}

		if(a-1>=0&&chk[a-1][b]==0){
			if(arr[a-1][b]==1&&dis==0){
				pq.push(make_pair(dis+1,Hm(a-1,b)));
				blk[a-1][b] = chk[a][b] + 1;
			}
			else if(arr[a-1][b]==0&&dis==0){
				pq.push(make_pair(dis,Hm(a-1,b)));
				chk[a-1][b] = chk[a][b] + 1;
			}else if(arr[a-1][b]==0&&dis==1&&blk[a-1][b]==0){
				pq.push(make_pair(dis,Hm(a-1,b)));
				blk[a-1][b] = blk[a][b] + 1; 
			}
		}

		if(b-1>=0&&chk[a][b-1]==0){
			if(arr[a][b-1]==1&&dis==0){
				pq.push(make_pair(dis+1,Hm(a,b-1)));
				blk[a][b-1] = chk[a][b] + 1;
			}
			else if(arr[a][b-1]==0&&dis==0){
				pq.push(make_pair(dis,Hm(a,b-1)));
				chk[a][b-1] = chk[a][b] + 1;
			}else if(arr[a][b-1]==0&&dis==1&&blk[a][b-1]==0){
				pq.push(make_pair(dis,Hm(a,b-1)));
				blk[a][b-1] = blk[a][b] + 1; 
			}
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
    for(int i = 0; i < n; i++){
    	cin>>str;
    	for(int j = 0; j < m; j++){
    		arr[i][j] = str[j]-'0';
    	}
    }
    move();
    if(mn==1000001) cout<<-1<<"\n";
    else cout<<mn<<"\n";
	return 0;
}