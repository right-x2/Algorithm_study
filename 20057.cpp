#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int n;
int arr[500][500];
int ans;

int spray(int y, int x, int way)
{

    int temp,box,a,b,c,d,e;
    if(way==1)
    {
        box = arr[y][x-1];
        a = (box*1)/100;
        b = (box*7)/100;
        c = (box*2)/100;
        d = (box*10)/100;
        e = (box*5)/100;

        temp = box;

        if(y-1>=0) arr[y-1][x] = arr[y-1][x]+a;
        else ans += a;

        temp = temp - a;

        if(y+1<n) arr[y+1][x] = arr[y+1][x]+a;
        else ans += a;

        temp = temp - a;
        if(y-1>=0) arr[y-1][x-1] = arr[y-1][x-1]+b;
        else ans += b;
        temp = temp - b;
        if(y+1<n) arr[y+1][x-1] = arr[y+1][x-1]+b;
        else ans += b;
        temp = temp - b;
        if(y-2>=0) arr[y-2][x-1] = arr[y-2][x-1]+c;
        else ans += c;
        temp = temp - c;
        if(y+2<n) arr[y+2][x-1] = arr[y+2][x-1]+c;
        else ans += c;
        temp = temp - c;
        if(y-1>=0&&x-2>=0) arr[y-1][x-2] = arr[y-1][x-2]+d;
        else ans += d;
        temp = temp - d;
        if(y+1<n&&x-2>=0) arr[y+1][x-2] = arr[y+1][x-2]+d;
        else ans += d;
        temp = temp - d;
        if(x-3>=0) arr[y][x-3] = arr[y][x-3]+e;
        else ans += e;
        temp = temp - e;
        if(x-2>=0) arr[y][x-2] = arr[y][x-2]+temp;
        else ans += temp; 

        arr[y][x-1] = 0;   
    }
    else if(way==2)
    {
        box = arr[y+1][x];
        a = (box*1)/100;
        b = (box*7)/100;
        c = (box*2)/100;
        d = (box*10)/100;
        e = (box*5)/100;

        temp = box;

        if(x-1>=0) arr[y][x-1] = arr[y][x-1]+a;
        else ans += a;
        temp = temp - a;
        if(x+1<n) arr[y][x+1] = arr[y][x+1]+a;
        else ans += a;
        temp = temp - a;
        if(x-1>=0) arr[y+1][x-1] = arr[y+1][x-1]+b;
        else ans += b;
        temp = temp - b;
        if(x+1<n) arr[y+1][x+1] = arr[y+1][x+1]+b;
        else ans += b;
        temp = temp - b;
        if(x-2>=0) arr[y+1][x-2] = arr[y+1][x-2]+c;
        else ans += c;
        temp = temp - c;
        if(x+2<n) arr[y+1][x+2] = arr[y+1][x+2]+c;
        else ans += c;
        temp = temp - c;
        if(x-1>=0&&y+2<n) arr[y+2][x-1] = arr[y+2][x-1]+d;
        else ans += d;
        temp = temp - d;
        if(x+1<n&&y+2<n) arr[y+2][x+1] = arr[y+2][x+1]+d;
        else ans += d;
        temp = temp - d;
        if(y+3<n) arr[y+3][x] = arr[y+3][x]+e;
        else ans += e;
        temp = temp - e;
        if(y+2<n) arr[y+2][x] = arr[y+2][x]+temp;
        else ans += temp;   

        arr[y+1][x] = 0; 
    }
    else if(way==3)
    {
        box = arr[y][x+1];
        a = (box*1)/100;
        b = (box*7)/100;
        c = (box*2)/100;
        d = (box*10)/100;
        e = (box*5)/100;

        temp = box;

        if(y-1>=0) arr[y-1][x] = arr[y-1][x]+a;
        else ans += a;
        temp = temp - a;
        if(y+1<n) arr[y+1][x] = arr[y+1][x]+a;
        else ans += a;
        temp = temp - a;
        if(y-1>=0) arr[y-1][x+1] = arr[y-1][x+1]+b;
        else ans += b;
        temp = temp - b;
        if(y+1<n) arr[y+1][x+1] = arr[y+1][x+1]+b;
        else ans += b;
        temp = temp - b;
        if(y-2>=0) arr[y-2][x+1] = arr[y-2][x+1]+c;
        else ans += c;
        temp = temp - c;
        if(y+2<n) arr[y+2][x+1] = arr[y+2][x+1]+c;
        else ans += c;
        temp = temp - c;
        if(y-1>=0&&x+2<n) arr[y-1][x+2] = arr[y-1][x+2]+d;
        else ans += d;
        temp = temp - d;
        if(y+1<n&&x+2<n) arr[y+1][x+2] = arr[y+1][x+2]+d;
        else ans += d;
        temp = temp - d;
        if(x+3<n) arr[y][x+3] = arr[y][x+3]+e;
        else ans += e;   
        temp = temp - e;
        if(x+2<n) arr[y][x+2] = arr[y][x+2]+temp;
        else ans += temp;   

        arr[y][x+1] = 0;       
    }
    else if(way==4)
    {
        box = arr[y-1][x];
        a = (box*1)/100;
        b = (box*7)/100;
        c = (box*2)/100;
        d = (box*10)/100;
        e = (box*5)/100;

        temp = box;

        if(x-1>=0) arr[y][x-1] = arr[y][x-1]+a;
        else ans += a;
        temp = temp - a;
        if(x+1<n) arr[y][x+1] = arr[y][x+1]+a;
        else ans += a;
        temp = temp - a;
        if(x-1>=0) arr[y-1][x-1] = arr[y-1][x-1]+b;
        else ans += b;
        temp = temp - b;
        if(x+1<n) arr[y-1][x+1] = arr[y-1][x+1]+b;
        else ans += b;
        temp = temp - b;
        if(x-2>=0) arr[y-1][x-2] = arr[y-1][x-2]+c;
        else ans += c;
        temp = temp - c;
        if(x+2<n) arr[y-1][x+2] = arr[y-1][x+2]+c;
        else ans += c;
        temp = temp - c;
        if(x-1>=0&&y-2>=0) arr[y-2][x-1] = arr[y-2][x-1]+d;
        else ans += d;
        temp = temp - d;
        if(x+1<n&&y-2>=0) arr[y-2][x+1] = arr[y-2][x+1]+d;
        else ans += d;
        temp = temp - d;
        if(y-3>=0) arr[y-3][x] = arr[y-3][x]+e;
        else ans += e;
        temp = temp - e;
        if(y-2>=0) arr[y-2][x] = arr[y-2][x]+temp;
        else ans += temp;    

        arr[y-1][x] = 0;
    }
  
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int len = 1;
    int way = 1;
    int y,x;
    cin>>n;

    y = n/2;
    x = n/2;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>num;
            arr[i][j] = num;
        }
    }

    while(1)
    {
        if(y==0&&x==-1) break;
        
        for(int i = 0; i < len; i++)
        {
            spray(y,x,way);
            if(way==1) x--;
            else if(way==2) y++;
            else if(way==3) x++;
            else if(way==4) y--; 
        }
        if(way==2||way==4) len++;
        way++;
        if(way==5) way = 1;
        
    }
    


    cout<<ans<<"\n";

    return 0;
}