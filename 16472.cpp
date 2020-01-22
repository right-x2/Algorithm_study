#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[30]={0,};
int check(string str, int n)
{
	int max = 0;
	int tot = 0;
	int cnt = 0;
	int cc = 1; 
	int num = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if((int)str[i]>96)
		{
			num = (int)str[i]-96;
		}
		else
		{
			num = (int)str[i]-64;
		}
		cout<<arr[num]<<"num  ";
		cout<<cc<<"cc\n";
		if(arr[num]==cc)
		{
			tot++;
		}
		else if(arr[num]!=cc)
		{
			cnt++;
			if(cnt>n)
			{
				if(max<tot) max = tot;
				cnt = 0;
				cc++;
				tot = 1;
				arr[num]=cc;
			}
			else
			{
				tot++;
				arr[num]=cc;
			}
		}
	}
	return max;
}
int main()
{
	int n;
	string str = "";
	int cnt  = 0;
	cin>>n;
	cin>>str;
	cout<<check(str,n)<<"\n";
}
