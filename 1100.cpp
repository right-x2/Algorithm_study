#include <iostream>

using namespace std;
int cnt = 0;
void solve(string str, int flag){
	for (int i = 0; i < str.length(); ++i)
	{
		if(i%2==flag&&str[i]=='F'){
			cnt++;
		}
	}
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    int flag = 0;
    for (int i = 0; i < 8; ++i)
    {
    	cin>>str;
    	solve(str,flag);
    	if(flag==1) flag = 0;
    	else flag = 1;
    }
    cout<<cnt<<"\n";
    return 0;
}  