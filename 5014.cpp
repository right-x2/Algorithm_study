#include <iostream>
#include <queue>
using namespace std;


int arr[1000001];
int f,s,g,u,d;

int bfs()
{
    queue<int> q;
    q.push(s);
    arr[s] = 1;
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        if(a==g) return arr[a];
        if(a-d>=1&&arr[a-d]==0)
        {
            q.push(a-d);
            arr[a-d] = arr[a] + 1;
        }


        if(a+u<=f&&arr[a+u]==0)
        {
            q.push(a+u);
            arr[a+u] = arr[a] + 1;
        }

    }
    return -1;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>f>>s>>g>>u>>d;
    int ans = bfs();
    if(ans==-1) cout<<"use the stairs"<<"\n";
    else cout<<ans-1<<"\n";
    return 0;
}  