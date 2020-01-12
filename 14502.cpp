#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int,int> >pv;
vector< pair<int,int> >tmp;
int arr[10][10];
int ans[10][10];
int cb[100];
int n , m;
int mx = 0;

int dfs(int i, int j)
{
    if(j+1<m)
    {
      if(arr[i][j+1]==0)
     {
        arr[i][j+1] = 2;
        dfs(i,j+1);
     }      
    }
    if(i+1<n)
    {
        if(arr[i+1][j]==0)
        {
            arr[i+1][j] = 2;
            dfs(i+1,j);
        }       
    }
    if(i-1>=0)
    {
        if(arr[i-1][j]==0)
        {
            arr[i-1][j] = 2;
            dfs(i-1,j);
        }        
    }
    if(j-1>=0)
    {
        if(arr[i][j-1]==0)
        {
            arr[i][j-1] = 2;
            dfs(i,j-1);
        }        
    }
    return 0;
}
int play()
{

    int cnt = 0;
    for (int i = 0; i < 3; ++i)
    {
        //cout<<tmp[i].first<<" "<<tmp[i].second<<"\n";
        arr[tmp[i].first][tmp[i].second] = 1;
    }
   //cout<<"----------------------------"<<"\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(arr[i][j]==2) dfs(i,j);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(arr[i][j]==0) cnt++;
        }
    }
    if(cnt>mx) mx = cnt;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            //cout<<arr[i][j]<<" ";
            arr[i][j] = ans[i][j];
        }
        //cout<<" "<<"\n";
    }
    return 0;

}


int comb(int k,int s)
{
    vector<int>v;
    for (int i = 0; i < s; ++i)
    {
        v.push_back(1);
    }
    for (int i = 0; i < k-s; ++i)
    {
        v.push_back(0);
    }
    sort(v.begin(), v.end());
    do{
        for (int j = 0; j < v.size(); ++j)
        {
            if(v[j]==1) tmp.push_back(make_pair(pv[j].first,pv[j].second));
        }
        play();
        tmp.clear();
    }while (next_permutation(v.begin(), v.end()));
    
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            ans[i][j] = arr[i][j];
            if (arr[i][j]==0)
            {
                pv.push_back(make_pair(i,j));
            }
        }
    }
    comb(pv.size(),3);

    cout<<mx<<"\n";
    return 0;
}  