#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int n,m;

struct Robot
{
    int y;
    int x;
    int way;
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
        }
    }
    Robot s;
    cin>>a>>b>>c;
    s.y = a;
    s.x = b;
    s.way = c;


    Robot e;
    cin>>a>>b>>c;
    e.y = a;
    e.x = b;
    e.way = c;
    return 0;
}