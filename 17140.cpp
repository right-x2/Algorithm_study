#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int arr[101][101];
int cnt[101];
int r,c,k,y,x;




int solve()
{
    int mx = 0;
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    if(y>=x)
    {
        for (int i = 0; i < y; ++i)
        {
            for (int j = 0; j < x; ++j)
            {
                cnt[arr[i][j]]++;
                arr[i][j] = 0;
            }
            for (int j = 1; j <= 100; ++j)
            {
                if(cnt[j]!=0)
                {

                    pq.push(make_pair(cnt[j],j));
                    cnt[j] = 0;
                }
            }
            int idx = 0;
            while(!pq.empty())
            {
                int a = pq.top().first;
                int b = pq.top().second;

                pq.pop();
                arr[i][idx] = b;
                idx++;
                arr[i][idx] = a;
                idx++;
                if(idx>100) break;
            }
            if(mx<idx) mx = idx;
        }
        x = mx;
    }
    else
    {
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                cnt[arr[j][i]]++;
                arr[j][i] = 0;
            }
            for (int j = 1; j <= 100; ++j)
            {
                if(cnt[j]!=0)
                {
                    pq.push(make_pair(cnt[j],j));
                    cnt[j] = 0;
                }
            }
            int idx = 0;
            while(!pq.empty())
            {
                int a = pq.top().first;
                int b = pq.top().second;
                pq.pop();
                arr[idx][i] = b;
                idx++;
                arr[idx][i] = a;
                idx++;
                if(idx>100) break;
            }
            if(mx<idx) mx = idx;
        }  
        y = mx;      
    }

    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans = -1;
    cin>>r>>c>>k;

    y = 3;
    x = 3;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin>>arr[i][j];
        }
    }


    for (int i = 0; i < 100; ++i)
    {
        if(arr[r-1][c-1]==k)
        {
            ans = i;
            break;
        }
        solve();
    }
    if(ans==-1&&arr[r-1][c-1]==k) ans = 100;

    cout<<ans<<"\n";
    return 0;
}