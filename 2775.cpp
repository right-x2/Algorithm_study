#include <iostream>

using namespace std;
int arr[15][15];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,b;
    cin>>n;
    for (int i = 0; i < 15; ++i)
    {
        arr[0][i] = i+1;
    }
    for (int i = 1; i < 15; ++i)
    {
        for (int j = 0; j < 15; ++j)
        {
            if(j==0) arr[i][j] = 1;
            else
            {
                arr[i][j] = arr[i][j-1] +arr[i-1][j];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        cout<<arr[a][b-1]<<"\n";
    }

    return 0;
    
}  