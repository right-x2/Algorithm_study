#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



char arr[31][31][31];
int chk[31][31][31];
int l,r,c;
int x,y,z;
int ans= -1;
int bfs()
{
    queue<int>f;
    queue<pair<int,int> >q;
    f.push(x);
    q.push(make_pair(y,z));
    chk[x][y][z] = 1;
    while(!f.empty())
    {
        int a = f.front();
        int b = q.front().first;
        int k = q.front().second;
        if(arr[a][b][k]=='E')
        {
            ans = chk[a][b][k]-1;
            return 0;
        }
        f.pop();
        q.pop();
        if(a+1<l&&chk[a+1][b][k]==0&&arr[a+1][b][k]!='#')
        {
            chk[a+1][b][k] = chk[a][b][k] +1;
            f.push(a+1);
            q.push(make_pair(b,k));
        }
        if(a-1>=0&&chk[a-1][b][k]==0&&arr[a-1][b][k]!='#')
        {
            chk[a-1][b][k] = chk[a][b][k] +1;
            f.push(a-1);
            q.push(make_pair(b,k));
        }
        if(b+1<r&&chk[a][b+1][k]==0&&arr[a][b+1][k]!='#')
        {
            chk[a][b+1][k] = chk[a][b][k] +1;
            f.push(a);
            q.push(make_pair(b+1,k));
        }
        if(b-1>=0&&chk[a][b-1][k]==0&&arr[a][b-1][k]!='#')
        {
            chk[a][b-1][k] = chk[a][b][k] +1;
            f.push(a);
            q.push(make_pair(b-1,k));
        }
        if(k+1<c&&chk[a][b][k+1]==0&&arr[a][b][k+1]!='#')
        {
            chk[a][b][k+1] = chk[a][b][k] +1;
            f.push(a);
            q.push(make_pair(b,k+1));
        }
        if(k-1>=0&&chk[a][b][k-1]==0&&arr[a][b][k-1]!='#')
        {
            chk[a][b][k-1] = chk[a][b][k] +1;
            f.push(a);
            q.push(make_pair(b,k-1));
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1)
    {
        string str;
        int cnt = 0;
        cin>>l>>r>>c;
        if(l==0&&r==0&&c==0) break;
        for (int i = 0; i < l; ++i)
        {
            cnt = 0;
            while(1)
            {
                getline(cin,str);
                if(cnt!=0&&str=="") break;
                else if(str=="")continue;
                for(int j = 0; j < c; j++)
                {
                    arr[i][cnt][j] = str[j];
                    if(arr[i][cnt][j]=='S')
                    {
                        x = i;
                        y = cnt;
                        z = j;
                    }
                }
                cnt++;
            }
        }
        bfs();
        if(ans==-1) cout<<"Trapped!"<<"\n";
        else 
        {
            cout<<"Escaped in"<<" ";
            cout<<ans<<"";
            cout<<" minute(s)."<<"\n";
        }
        ans = -1;
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                for (int temp = 0; temp < c; ++temp)
                {
                    chk[i][j][temp] = 0;
                }
            }
        }
    }
    return 0;
}  