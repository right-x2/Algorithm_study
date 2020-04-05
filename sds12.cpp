#include <iostream>

using namespace std;


int match(string a, string b)
{
	int cnt = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if(a[i]==b[i]) cnt++;
	}
	return cnt;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    string a,b;
    cin>>n;
    cin>>a>>b;
    cout<<match(a,b)<<"\n";
    return 0;
}  