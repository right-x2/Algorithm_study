#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int arr[9][9];
int aflag = 0;
int solve(int y, int x)
{
    int ans = 0;
    int box[10] ={0,0,0,0,0,0,0,0,0,0};
    int a,b,c,d;
    int flag = 0;

    for (int i = y; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if(arr[i][j]==0)
            {
                flag = 1;
                a = i;
                b = j;
                break;
            }
        }
        if(flag==1) break;
    }
    
    if(flag==0)
    {
        aflag = 1;
        return 0; 
    } 
    for (int i = 0; i < 9; ++i)
    {
        box[arr[a][i]]++;
        box[arr[i][b]]++;
    }
    c = a-(a%3);
    d = b-(b%3);
    
    for (int i = c; i <c+3 ; ++i)
    {
        for (int j = d; j < d+3; ++j)
        {
            box[arr[i][j]]++;
        }
    }
    for (int i = 1; i < 10; ++i)
    {

        if(box[i]==0)
        {
            arr[a][b] = i;
            solve(a,b);
            if(aflag==1) return 0;
            arr[a][b] = 0;
        }
    }
    
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin>>arr[i][j];
        }
    }

    solve(0,0);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}