#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> v;

int arr[9];
void solve(vector<int> vt, int a)
{
	if(a==m)
	{
		for (int i = 0; i < vt.size(); ++i)
		{
			cout<<vt[i]<<" ";
		}
		cout<<"\n"<<"";
	}
	else
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if(arr[i]==0) 
			{
				arr[i] = 1;
				vt.push_back(v[i]);
				solve(vt,a+1);
				vt.pop_back();
				arr[i] = 0;
			}
		}
	}
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    vector<int> temp;
    cin>>n>>m;
   	for (int i = 0; i < n; ++i)
   	{
   		cin>>num;
   		v.push_back(num);
   	}

   	sort(v.begin(),v.end());
   	for (int i = 0; i < v.size(); ++i)
   	{
   		arr[i] = 1;
   		temp.push_back(v[i]);
   		solve(temp,1);
   		temp.pop_back();
   		arr[i] = 0;
   	}
    return 0;
}  