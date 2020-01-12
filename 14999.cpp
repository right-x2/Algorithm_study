#include <iostream>

using namespace std;
int arr[20][20];
int cube[7];
int rx,ry,n,m;

int move(int k)
{
    int tmp;
    if(k==1)
    {
        if(rx+1>=m) return 0;
        rx++;
        tmp = cube[1];
        cube[1] = cube[3];
        cube[3] = cube[6];
        cube[6] = cube[4];
        cube[4] = tmp;
        if(arr[ry][rx] ==0) arr[ry][rx] = cube[1];
        else 
        {
            cube[1] = arr[ry][rx];
            arr[ry][rx] = 0;
        }
        cout<<cube[6]<<"\n";
    }
    else if(k==2)
    {
        if(rx-1<0) return 0;
        rx--;
        tmp = cube[1];
        cube[1] = cube[4];
        cube[4] = cube[6];
        cube[6] = cube[3];
        cube[3] = tmp;
        if(arr[ry][rx] ==0) arr[ry][rx] = cube[1];
        else 
        {
            cube[1] = arr[ry][rx];
            arr[ry][rx] = 0;
        }
        cout<<cube[6]<<"\n";
    }
    else if(k==3)
    {
        if(ry-1<0) return 0;
        ry--;
        tmp = cube[1];
        cube[1] = cube[2];
        cube[2] = cube[6];
        cube[6] = cube[5];
        cube[5] = tmp;
        if(arr[ry][rx] ==0) arr[ry][rx] = cube[1];
        else 
        {
            cube[1] = arr[ry][rx];
            arr[ry][rx] = 0;
        }
        cout<<cube[6]<<"\n";
    }
    else
    {
        if(ry+1>=n) return 0;
        ry++;
        tmp = cube[1];
        cube[1] = cube[5];
        cube[5] = cube[6];
        cube[6] = cube[2];
        cube[2] = tmp;
        if(arr[ry][rx] ==0) arr[ry][rx] = cube[1];
        else 
        {
            cube[1] = arr[ry][rx];
            arr[ry][rx] = 0;
        }
        cout<<cube[6]<<"\n";
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t,a;
    cin>>n>>m>>ry>>rx>>t;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < t; ++i)
    {
        cin>>a;
        move(a);
    }
    return 0;
}  