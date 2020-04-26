#include <iostream>
using namespace std;

int arr[3];
int marr[3];
int n;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c,d,e,f,x,y,z;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b>>c;
        if(i==0)
        {
            arr[0] = a;
            arr[1] = b;
            arr[2] = c;

            marr[0] = a;
            marr[1] = b; 
            marr[2] = c;

        }
        else
        {
            d = arr[0];
            e = arr[1];
            f = arr[2];

            x = marr[0];
            y = marr[1];
            z = marr[2];

            arr[0] = a + max(d,e);
            if(d>=e&&d>=f){
                arr[1] = b + d;
            }else if(e>=d&&e>=f){
                arr[1] = b + e;
            }else if(f>=e&&f>=d){
                arr[1] = b + f;
            }
            arr[2] = c + max(e,f);

            marr[0] = a + min(x,y);
            if(x<=y&&x<=z){
                marr[1] = b + x;
            }else if(y<=x&&y<=z){
                marr[1] = b + y;
            }else if(z<=x&&z<=y){
                marr[1] = b + z;
            }
            marr[2] = c + min(y,z);
        }
    }
    int mx = 0;
    int mn = marr[0];
    for (int i = 0; i < 3; ++i)
    {
        if(mx<arr[i]) mx = arr[i];
        if(mn>marr[i]) mn = marr[i];
    }

    cout<<mx<<" "<<mn<<"\n";
    return 0;
}