#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

int arr[10000];
int chk[10000];
string n,m;
int ans = -1;
int conv(string str)
{
    int temp = 0;
    int d = 1000;
    for (int i = 0; i < 4; ++i)
    {
        temp = temp + (str[i]-'0')*d;
        d = d/10;
    }
    return temp;
}
int bfs()
{
    queue< pair<string,int> > q;
    q.push(make_pair(n,0));
    while(!q.empty())
    {
        string str = q.front().first;
        string temp = str;
        int cnt = q.front().second;
        q.pop();
        if(str==m)
        {
            ans = cnt;
            return 0;
        }
        for (int i = 1; i < 10; ++i)
        {
            temp[0] = (i+'0');
            int num = conv(temp);
            if(arr[num]==0&&chk[num]==0)
            {
                chk[num] = 1;
                q.push(make_pair(temp,cnt+1));
            }
            temp = str;
        }
        for (int i = 0; i < 10; ++i)
        {
            temp[1] = (i+'0');
            int num = conv(temp);
            if(arr[num]==0&&chk[num]==0)
            {
                chk[num] = 1;
                q.push(make_pair(temp,cnt+1));
            }
            temp = str;  
        }
        for (int i = 0; i < 10; ++i)
        {
            temp[2] = (i+'0');
            int num = conv(temp);
            if(arr[num]==0&&chk[num]==0)
            {
                chk[num] = 1;
                q.push(make_pair(temp,cnt+1));
            }
            temp = str; 
        }
        for (int i = 0; i < 10; ++i)
        {
            temp[3] = (i+'0');
            int num = conv(temp);
            if(arr[num]==0&&chk[num]==0)
            {
                chk[num] = 1;
                q.push(make_pair(temp,cnt+1));
            }
            temp = str; 
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int j = 0; j < t; j++)
    {
        for (int i = 2; i <=101; ++i)
        {
            if(i*i>9999) break;
            else if(arr[i]==0)
            {
                int cnt = 2;
                int temp = i * 2;
                while(temp<=9999)
                {
                    arr[temp] = 1;
                    cnt++;
                    temp = i*cnt;
                }
            }
        }
        cin>>n>>m;
        bfs();
        if(ans==-1) cout<<"Impossible"<<"\n";
        else cout<<ans<<"\n";
        for (int i = 1000; i < 10000; ++i)
        {
            chk[i] = 0;
        }
        ans = -1;
    }

}  