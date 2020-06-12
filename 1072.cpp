#include <vector>
#include <iostream>
#include <queue>
using namespace std;



int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long x;
    long long y;
    long long z;
    
    while(true){
        cin>>x>>y;
        if(cin.eof()==true) break;
        z = (y*100)/x;
        long long high = 2000000000;
        long long low = 1;
        int ans = -1;
        while(low<=high)
        {
            long long mid = (high+low)/2;

            long long tmp = ((y+mid)*100)/(x+mid);

            if(tmp==z)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                if(ans==-1||ans>mid) ans = mid;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}