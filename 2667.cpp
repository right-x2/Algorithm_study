#include <string>
#include <vector>
#include <iostream>
#include <queue>


using namespace std;

int vv[100000];
int c[1000][100];
int arr[100][100];
int count;
int nx[]={1, -1, 0, 0};
int ny[]={0, 0, -1, 1};
int bfs(int x, int y , int a)
{
    count++;
    c[y][x] = 1;
    for( int i = 0; i < 4 ; i++)
    {
        if(y+ny[i]>=0 && y+ny[i]< a && x+nx[i]>= 0 && x+nx[i] < a)
        {
            if( arr[y+ny[i]][x+nx[i]] == 1 && c[y+ny[i]][x+nx[i]] ==0)
            {
                bfs(x+nx[i],y+ny[i],a);
            }
        }
    }
    return 0;
}
int main()
{
    int k , temp = 50;
    int a, cc = 0;
    string b;
    cin>>a;
    for (int i = 0; i < a; ++i)
    {
        cin>>b;
        for (int j = 0; j < a; ++j)
        {
            if(b[j]=='1') arr[i][j] = 1;
            else if(b[j]=='0') arr[i][j] = 0;
        }
    }
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < a; ++j)
        {
            if(arr[i][j] == 1 && c[i][j] ==0)
            {
                bfs(j , i , a);
                vv[cc] = count;
                cc++;
                count = 0;
            }
        }
    }
    for (int i = 0; i < cc-1; ++i)
    {
        k = i;
        while( vv[k] > vv[k+1]){
            temp = vv[k];
            vv[k] = vv[k+1];
            vv[k+1] = temp;
            k--;
        }
    }
    cout<<cc<<'\n';
    for (int i = 0; i < cc; ++i)
    {
        if( i == cc-1)
        {
            cout<<vv[i]<<"";
        }
        else cout<<vv[i]<<'\n';
        
    }
}