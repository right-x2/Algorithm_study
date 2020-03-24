#include <iostream>
#include <vector>
using namespace std;
int tocnt = 0;
int tt = 0;
int arr[100001];
int chk[100001];
int tc[100001];
int play(int a){
	int cnt = 0;
	int temp = a;
	chk[temp] = tt;
	tc[temp] = cnt;
	while(true){
		if(chk[arr[temp]]==tt){
		  tocnt = tocnt + tc[temp] - tc[arr[temp]] + 1;
		  return 0; 
		} else if(chk[arr[temp]]==0){
			chk[arr[temp]] = tt;
			temp = arr[temp];
			cnt++;
			tc[temp] = cnt;
		} else return 0;
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,t;
    cin>>t;
    for(int j = 0; j < t; j++){
	    cin>>n;
	    for(int i = 1; i <= n ; i++){
	    	cin>>arr[i];
	    }

	    for(int i = 1; i <=n ; i++){
	    	if(chk[i]==0){
	    		tt++;
	    		play(i);
	    	}
	    }
	    cout<<n-tocnt<<"\n";
	    for(int i = 1 ; i <= n; i++){
	    	arr[i] = 0;
	    	chk[i] = 0;
	    	tc[i] = 0;
	    }
	    tocnt = 0;
		tt = 0;
	}
	return 0;
}