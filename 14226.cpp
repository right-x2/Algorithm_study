#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[10001][10001];
int n;
int ans;
struct Emo
{
    int box;
    int clip;
    int cnt;
};

int bfs()
{
    arr[1][0] = 1;
    queue<Emo> q;
    Emo tmp;
    tmp.box = 1;
    tmp.clip = 0;
    tmp.cnt = 0;
    q.push(tmp);
    while(!q.empty())
    {
        int box = q.front().box;
        int clip = q.front().clip;
        int cnt = q.front().cnt;
        q.pop();
        if(box==n)
        {
            ans = cnt;
            return 0;
        }
        if(box>0)
        {
            if(arr[box][box]==0)
            {
                arr[box][box] = 1;
                Emo emo;
                emo.box = box;
                emo.clip = box;
                emo.cnt = cnt + 1;
                q.push(emo);               
            }
            if(arr[box-1][clip]==0)
            {
                arr[box-1][clip] = 1;
                Emo emo2;
                emo2.box = box-1;
                emo2.clip = clip;
                emo2.cnt = cnt + 1;
                q.push(emo2);
            }

        }
        if(clip>0&&box+clip<10001&&arr[box+clip][clip]==0)
        {
            arr[box+clip][clip] = 1;
            Emo emo;
            emo.box = box + clip;
            emo.clip = clip;
            emo.cnt = cnt + 1;
            q.push(emo);
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    bfs();
    cout<<ans<<"\n";
}  