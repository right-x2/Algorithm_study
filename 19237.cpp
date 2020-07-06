#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n,m,k;


int move[401][4];

struct  Shark
{
    int y;
    int x;
    int num;
    int cnt;
    int way;
    int gbn;
};

Shark arr[21][21];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    int order = 0;
    cin>>n>>m>>k;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a;
            if(a!=0)
            {
                order++;
                Shark s;
                s.y = i;
                s.x = j;
                s.way = a;
                s.gbn = 1;
                s.num = order;                
            }
        }
    }
    return 0;
}