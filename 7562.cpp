#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>


using namespace std;

int t,n,s1,s2,f1,f2,ans;
int arr[300][300];
int bfs()
{
    int a,b;
    a = s1;
    b = s2;
    arr[a][b] = 1;
    queue< pair<int,int> >q;
    q.push(make_pair(a,b));
    while(!q.empty())
    {
        a = q.front().first;
        b = q.front().second;
        q.pop();
       // cout<<a<<" "<<b<<"\n";
        if(a==f1&&b==f2)
        {
            ans = arr[a][b];
            break;
        } 
        if((a-2>=0&&b-1>=0)&&arr[a-2][b-1]==0)
        {
            q.push(make_pair(a-2,b-1));
            arr[a-2][b-1] = arr[a][b] +1;
        }
        if((a-1>=0&&b-2>=0)&&arr[a-1][b-2]==0)
        {
            q.push(make_pair(a-1,b-2));
            arr[a-1][b-2] = arr[a][b] +1;
        }
        if((a-2>=0&&b+1<n)&&arr[a-2][b+1]==0)
        {
            q.push(make_pair(a-2,b+1));
            arr[a-2][b+1] = arr[a][b] +1;
        }
        if((a-1>=0&&b+2<n)&&arr[a-1][b+2]==0)
        {
            q.push(make_pair(a-1,b+2));
            arr[a-1][b+2] = arr[a][b] +1;
        }
        if((a+1<n&&b+2<n)&&arr[a+1][b+2]==0)
        {
            q.push(make_pair(a+1,b+2));
            arr[a+1][b+2] = arr[a][b] +1;
        }
        if((a+2<n&&b+1<n)&&arr[a+2][b+1]==0)
        {
            q.push(make_pair(a+2,b+1));
            arr[a+2][b+1] = arr[a][b] +1;
        }
        if((a+2<n&&b-1>=0)&&arr[a+2][b-1]==0)
        {
            q.push(make_pair(a+2,b-1));
            arr[a+2][b-1] = arr[a][b] +1;
        }
        if((a+1<n&&b-2>=0)&&arr[a+1][b-2]==0)
        {
            q.push(make_pair(a+1,b-2));
            arr[a+1][b-2] = arr[a][b] +1;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>n;
        cin>>s1>>s2;
        cin>>f1>>f2;
        bfs();
        cout<<ans-1<<"\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                arr[i][j] = 0;
            }
        }
    }

}  