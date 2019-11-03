#include <iostream>

using namespace std;
long long arr[4]={0,1,2,0};
int fibo(long long x, long long n)
{
	long long a;
	if (n==1) return 1;
	else if(n==2) return 2;
	else if(x==n) return arr[3];
	else 
	{
		arr[3] = (arr[2]+arr[1])%1000000;
		a = arr[2];
		arr[2] = arr[3];
		arr[1] = a;
		x++;
		fibo(x, n);
	}
}
int main()
{
	long long x;
	cin>>x;
	int k = (x/1000);
	int a = x - (x/1000);
	for (int i = 0; i < k; ++i)
	{
		fibo(3,1000);
	}
	//int a = x/1000;
	x = fibo(3,a);
	cout<<x<<"";
}