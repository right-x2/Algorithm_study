#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int arr[51][51];
int tmp[51][51];
int n,m,k;
int ans = -1;
int chk[7];
struct Spin
{
    int r;
    int c;
    int s;
};
vector<Spin> v;
vector<int> box;
void reset()
{
    int mn = -1;
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= m; ++j)
        {
            sum = sum + arr[i][j];
            arr[i][j] = tmp[i][j];
        }
        if(mn==-1||mn>sum) mn = sum;
    }
    if(ans==-1||ans>mn) ans = mn;
}
void run(int idx)
{
    int r = v[idx].r;
    int c = v[idx].c;
    int s = v[idx].s;
    
    int y = r-s;
    int x = c-s;
    int w = c+s;
    int h = r+s;
    int temp = 0;
    while(x<w)
    {
        int pre = arr[y][x];
        for (int i = x; i <w ; ++i)
        {
            temp = arr[y][i+1];
            arr[y][i+1] = pre;
            pre = temp;
        }

        for (int i = y; i <h ; ++i)
        {
            temp = arr[i+1][w];
            arr[i+1][w] = pre;
            pre = temp;
        }

        for (int i = w; i>x ; --i)
        {
            temp = arr[h][i-1];
            arr[h][i-1] = pre;
            pre = temp;
        }

        for (int i = h; i>y; --i)
        {
            temp = arr[i-1][x];
            arr[i-1][x] = pre;
            pre = temp;
        }
        x++;
        y++;
        w--;
        h--;
    }
}

int solve()
{
    if(box.size()==k)
    {
        for (int i = 0; i < box.size(); ++i)
        {
            run(box[i]);
        }
        reset();
    }
    for (int i = 0; i <k; ++i)
    {
        if(chk[i]==0)
        {
            box.push_back(i);
            chk[i] = 1;
            solve();
            chk[i] = 0;
            box.pop_back();
        }        
    }
    return 0;
}



int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int r,c,s;
    cin>>n>>m>>k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < k; i++)
    {
        cin>>r>>c>>s;
        Spin spin;
        spin.r = r;
        spin.c = c;
        spin.s = s;
        v.push_back(spin);
    }
    for(int i = 0; i < k; i++)
    {
        box.push_back(i);
        chk[i] = 1;
        solve();
        chk[i] = 0;
        box.pop_back();
    }

    cout<<ans<<"\n";
    return 0;
}