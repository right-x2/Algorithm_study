#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int sum;
vector<int> v;
int flag = 0;
int cal(int a){
	for (int i = a+1; i < 9; ++i)
	{
		if(sum-v[a]-v[i]==100){
			v[a] = 0;
			v[i] = 0;
			flag = 1;
			return 0;
		}
	}
	return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    vector<int> temp;
    for (int i = 0; i < 9; ++i)
    {
    	cin>>a;
    	v.push_back(a);
    	sum = sum + a;
    }
    for (int i = 0; i < 8; ++i)
    {
    	if(flag==0) cal(i);
    	else break;
    }

    for (int i = 0; i < 9; ++i)
    {
    	temp.push_back(v[i]);
    }
    sort(temp.begin(), temp.end());
    for (int i = 2; i < 9; ++i)
    {
    	cout<<temp[i]<<"\n";
    }
    return 0;
}  