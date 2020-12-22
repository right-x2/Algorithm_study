#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int n;
int arr[51][10];
int chk[10];
int ans = 0;
vector<int> v;

int play()
{
    int b1,b2,b3,ocnt,s,x;
    int sum = 0;
    s = 0;
    for (int i = 0; i < n; ++i)
    {
        b1 = 0;
        b2 = 0;
        b3 = 0;
        ocnt = 0;

        
        while(ocnt<3)
        {
            if(s==9) s = 0;
            x = arr[i][v[s]-1];

            if(x==0) ocnt++;
            else if(x==1)
            {
                if(b3==1) 
                {
                    sum++;
                    b3 = 0;
                }
                if(b2==1)
                {
                    b3 = 1;
                    b2 = 0;
                }
                if(b1==1)
                {
                    b2 = 1;
                    b1 = 0;
                }
                b1 = 1;
            }
            else if(x==2)
            {
                if(b3==1) 
                {
                    sum++;
                    b3 = 0;
                }
                if(b2==1)
                {
                    sum++;
                    b2 = 0;
                }
                if(b1==1)
                {
                    b3 = 1;
                    b1 = 0;
                }
                b2 = 1;
            }
            else if(x==3)
            {
                if(b3==1) 
                {
                    sum++;
                    b3 = 0;
                }
                if(b2==1)
                {
                    sum++;
                    b2 = 0;
                }
                if(b1==1)
                {
                    sum++;
                    b1 = 0;
                }
                b3 = 1;
            }
            else if(x==4)
            {
                if(b3==1) 
                {
                    sum++;
                    b3 = 0;
                }
                if(b2==1)
                {
                    sum++;
                    b2 = 0;
                }
                if(b1==1)
                {
                    sum++;
                    b1 = 0;
                }
                sum++;
            }
            s++;
        }
        
    }

    if(sum>ans) ans = sum;
    return 0;
}


int gen(int cnt)
{
    if(cnt==9)
    {
        play();
        return 0;
    }
    if(cnt==3)
    {
        v.push_back(1);
        chk[1] = 1;
        gen(4);
        chk[1] = 0;
        v.pop_back();
        return 0;
    }

    for (int i = 2; i <=9 ; ++i)
    {
        if(chk[i]==0)
        {
            v.push_back(i);
            chk[i] = 1;
            gen(cnt+1);
            chk[i] = 0;
            v.pop_back();            
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin>>arr[i][j];
        }
    }

    for (int i = 2; i <= 9; ++i)
    {
        chk[i] = 1;
        v.push_back(i);
        gen(1);
        v.pop_back();
        chk[i] = 0;
    }

    cout<<ans<<"\n";
    return 0;
}