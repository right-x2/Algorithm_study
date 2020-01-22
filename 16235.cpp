#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

int arr[11][11];
int grd[11][11];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = 5;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        /* code */
    }

}  