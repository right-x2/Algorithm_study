#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
     
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
    	long long n;
 		cin>>n;
 		int flag = 0;
 		long long ans = n;
 		while(n>1)
 		{
 			if(n%2==0) n = n/2;
 			else n = 3*n+3;

 			if(n%3==0)
 			{
 				flag = 1;
 				break;
 			}
 		}
 		cout<<"#"<<test_case<<" ";
 		if(flag==0) cout<<"YES"<<"\n";
 		else cout<<"NO"<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}