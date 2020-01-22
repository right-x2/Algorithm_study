#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[200];
int cal(string str , int n, int sum,int right, char oper)
{
	int temp;
	if(oper=='*')
	{
		temp = sum * right;
		if(str.length()==2)
		{
			if(temp>arr[1]) arr[1] = temp;
			return 0;
		}
		cal(str.substr(2,str.length()-2) , n, temp,str[3],str[2]);
		if(str.length()>=4)
		{
			if(str[2]=='*')
			{
				temp = (str[1]-'0')*(str[3]-'0');
				if(str.length()==4) 
				{
					if(temp*sum>arr[1]) arr[1] = temp*sum;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
			else if(str[2]=='-')
			{
				temp = (str[1]-'0')-(str[3]-'0');
				if(str.length()==4) 
				{
					if(sum*temp>arr[1]) arr[1] = sum-temp;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
			else if(str[2]=='+')
			{
				temp = (str[1]-'0')+(str[3]-'0');
				if(str.length()==4) 
				{
					if(sum*temp>arr[1]) arr[1] = sum+temp;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
		}
	}
	else if(oper=='-')
	{
		temp = sum - right;
		if(str.length()==2)
		{
			if(temp>arr[1]) arr[1] = temp;
			return 0;
		}
		cal(str.substr(2,str.length()-2) , n, temp,str[3],str[2]);
		if(str.length()>=4)
		{
			if(str[2]=='*')
			{
				temp = (str[1]-'0')*(str[3]-'0');
				if(str.length()==4) 
				{
					if(temp-sum>arr[1]) arr[1] = temp*sum;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
			else if(str[2]=='-')
			{
				temp = (str[1]-'0')-(str[3]-'0');
				if(str.length()==4) 
				{
					if(sum-temp>arr[1]) arr[1] = sum-temp;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
			else if(str[2]=='+')
			{
				temp = (str[1]-'0')+(str[3]-'0');
				if(str.length()==4) 
				{
					if(sum-temp>arr[1]) arr[1] = sum+temp;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
		}
	}
	else if(oper=='+')
	{
		temp = sum + right;
		if(str.length()==2)
		{
			if(temp>arr[1]) arr[1] = temp;
			return 0;
		}
		cal(str.substr(2,str.length()-2) , n, temp,str[3],str[2]);
		if(str.length()>=4)
		{
			if(str[2]=='*')
			{
				temp = (str[1]-'0')*(str[3]-'0');
				if(str.length()==4) 
				{
					if(temp+sum>arr[1]) arr[1] = temp*sum;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
			else if(str[2]=='-')
			{
				temp = (str[1]-'0')-(str[3]-'0');
				if(str.length()==4) 
				{
					if(sum+temp>arr[1]) arr[1] = sum-temp;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
			else if(str[2]=='+')
			{
				temp = (str[1]-'0')+(str[3]-'0');
				if(str.length()==4) 
				{
					if(sum+temp>arr[1]) arr[1] = sum+temp;
					return 0;
				}
				cal(str.substr(4,str.length()-4) , n,sum, temp,oper);
			}
		}
	}
}

int main()
{
	int n;
	int f;
	string str;
	char a;
	int r;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		str = str + a;
	}
	f = str[0]-'0';
	r = str[2]-'0';
	a = str[1];
	str = str.substr(1,str.length()-1);
	cal(str,n,f,r,a);

	cout<<arr[1]<<"\n";
}
