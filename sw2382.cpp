#include<iostream>

using namespace std;
struct Robot
{
    long long sum;
    int way;
};



int sarr[101][101];
Robot arr[101][101];
Robot temp[101][101];
int n,m,k;

int move()
{
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j].way==1)
            {
                if(temp[i-1][j].way==0)
                {
                    if(i-1>0)
                    {
                        temp[i-1][j].sum = arr[i][j].sum;
                        temp[i-1][j].way = arr[i][j].way;
                    }
                    else
                    {
                        if(arr[i][j].sum/2>0)
                        {
                            temp[i-1][j].sum = arr[i][j].sum/2;
                            temp[i-1][j].way = 2;
                        }
                    }
                    sarr[i-1][j] = temp[i-1][j].sum;
                }
                else
                {
                    if(sarr[i-1][j]<arr[i][j].sum)
                    {
                        sarr[i-1][j] = arr[i][j].sum;
                        temp[i-1][j].way = arr[i][j].way;
                    }
                    temp[i-1][j].sum = temp[i-1][j].sum + arr[i][j].sum;
                }
                arr[i][j].sum = 0;
                arr[i][j].way = 0;
            }
            else if(arr[i][j].way==2)
            {
                if(temp[i+1][j].way==0)
                {
                    if(i+1<n-1)
                    {
                        temp[i+1][j].sum = arr[i][j].sum;
                        temp[i+1][j].way = arr[i][j].way;
                    }
                    else
                    {
                        if(arr[i][j].sum/2>0)
                        {
                            temp[i+1][j].sum = arr[i][j].sum/2;
                            temp[i+1][j].way = 1;
                        }
                    }
                    sarr[i+1][j] = temp[i+1][j].sum;
                }
                else
                {
                    if(sarr[i+1][j]<arr[i][j].sum)
                    {
                        sarr[i+1][j] = arr[i][j].sum;
                        temp[i+1][j].way = arr[i][j].way;
                    }
                    temp[i+1][j].sum = temp[i+1][j].sum + arr[i][j].sum;
                }
                arr[i][j].sum = 0;
                arr[i][j].way = 0;
            }
            else if(arr[i][j].way==3)
            {
                if(temp[i][j-1].way==0)
                {
                    if(j-1>0)
                    {
                        temp[i][j-1].sum = arr[i][j].sum;
                        temp[i][j-1].way = arr[i][j].way;
                    }
                    else
                    {
                        if(arr[i][j].sum/2>0)
                        {
                            temp[i][j-1].sum = arr[i][j].sum/2;
                            temp[i][j-1].way = 4;
                        }
                    }
                    sarr[i][j-1] = temp[i][j-1].sum;
                }
                else
                {
                    if(sarr[i][j-1]<arr[i][j].sum)
                    {
                        sarr[i][j-1] = arr[i][j].sum;
                        temp[i][j-1].way = arr[i][j].way;
                    }
                    temp[i][j-1].sum = temp[i][j-1].sum + arr[i][j].sum;
                }
                arr[i][j].sum = 0;
                arr[i][j].way = 0;
            }
            else if(arr[i][j].way==4)
            {
                if(temp[i][j+1].way==0)
                {
                    if(j+1<n-1)
                    {
                        temp[i][j+1].sum = arr[i][j].sum;
                        temp[i][j+1].way = arr[i][j].way;
                    }
                    else
                    {
                        if(arr[i][j].sum/2>0)
                        {
                            temp[i][j+1].sum = arr[i][j].sum/2;
                            temp[i][j+1].way = 3;
                        }
                    }
                    sarr[i][j+1] = temp[i][j+1].sum;
                }
                else
                {
                    if(sarr[i][j+1]<arr[i][j].sum)
                    {
                        sarr[i][j+1] = arr[i][j].sum;
                        temp[i][j+1].way = arr[i][j].way;
                    }
                    temp[i][j+1].sum = temp[i][j+1].sum + arr[i][j].sum;
                }
                arr[i][j].sum = 0;
                arr[i][j].way = 0;
            }
        }        
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j].sum = temp[i][j].sum;
            arr[i][j].way = temp[i][j].way;
            sarr[i][j] = 0;
            temp[i][j].sum = 0;
            temp[i][j].way = 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
            long long answer = 0;
            int a,b,c,d;


            cin>>n>>m>>k;
            for (int i = 0; i < k; ++i)
            {
                cin>>a>>b>>c>>d;
                Robot r;
                r.sum = c;
                r.way = d;
                arr[a][b] = r;
            }


            for (int i = 0; i < m; ++i)
            {
                move();
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    answer = answer + arr[i][j].sum;
                    arr[i][j].sum = 0;
                    arr[i][j].way = 0;
                }
            }
            cout<<"#"<<test_case<<" "<<answer<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}