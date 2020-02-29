#include <iostream>
#include <queue>

int arr[6][6];
int chk[6][6];
using namespace std;

int solution()
{
    int y;
    int x;
    int cnt = 0;
    queue< pair<int,int> > pq;
    pq.push(make_pair(0,0));
    chk[0][0] = 1;
    int answer = -1;
    while(!pq.empty())
    {
        y = pq.front().first;
        x = pq.front().second;
        pq.pop();
        if(x==4&&y==4) return chk[y][x];
        if(y+1<5&&chk[y+1][x]==0&&arr[y+1][x]==1)
        {
            pq.push(make_pair(y+1,x));
            chk[y+1][x] = chk[y][x] + 1;
        }
        if(x+1<5&&chk[y][x+1]==0&&arr[y][x+1]==1)
        {
            pq.push(make_pair(y,x+1));
            chk[y][x+1] = chk[y][x] + 1;
        }
        if(y-1>=0&&chk[y-1][x]==0&&arr[y-1][x]==1) 
        {
            pq.push(make_pair(y-1,x));
            chk[y-1][x] = chk[y][x] + 1;
        }
        if(x-1>=0&&chk[y][x-1]==0&&arr[y][x-1]==1)
        {
            pq.push(make_pair(y,x-1));
            chk[y][x-1] = chk[y][ x] + 1;
        }
    }
    return answer;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin>>arr[i][j];
        }
    }
    cout<<solution()<<"\n";
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout<<chk[i][j]<<" ";
        }
        cout<<"\n"<<"";
    }
} 