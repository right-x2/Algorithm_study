#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int answer[101][101];
int c[101][101];

void bfs(int i, int j, int a)
{
	c[i][j] = 1;
    //cout<<answer[i][j]<<"arr\n";
	for(int k = 0; k < a; k++)
	{
		if( answer[j][k] == 1)
		{
			answer[i][k]=1;
			if(c[i][k] ==0)bfs(i,k,a); 
		}
	}
	
}

int main()
{
	int a;
	int b;
	cin>>a;
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			cin>>b;
			answer[i][j] = b;
		}
	}
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			if(answer[i][j] == 1) bfs(i,j,a);
			int c[101][101] = {0,};
		}
	}
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			cout<<answer[i][j]<<" ";
		}
		cout<<"\n"<<"";
	}
}