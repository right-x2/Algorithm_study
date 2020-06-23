#include <iostream>
using namespace std;


struct P
{
    int num;
    char col;
};
int n;
int chk[10];
int mx;
P arr[5][5];
P box[10][4][4];
P temp[4][4];
int start[4][2] = {{0,0},{0,1},{1,0},{1,1}};
int pl[4][2] = {{0,1},{2,0},{3,2},{1,3}};
int pl2[4][2] = {{0,2},{1,0},{3,1},{2,3}};
void turn()
{
    P tmp = temp[0][0];   
    temp[0][0] = temp[0][3];
    temp[0][3] = temp[3][3];
    temp[3][3] = temp[3][0];
    temp[3][0] = tmp;

    tmp = temp[1][1];   
    temp[1][1] = temp[1][2];
    temp[1][2] = temp[2][2];
    temp[2][2] = temp[2][1];
    temp[2][1] = tmp;


    P tmp1 = temp[pl[3][0]][pl[3][1]];
    P tmp2 = temp[pl2[3][0]][pl2[3][1]];
    for (int i = 0; i < 4; ++i)
    {
        P tmp3 = temp[pl[i][0]][pl[i][1]];
        P tmp4 = temp[pl2[i][0]][pl2[i][1]];
        temp[pl[i][0]][pl[i][1]] = tmp1;
        temp[pl2[i][0]][pl2[i][1]] = tmp2;
        tmp1 = tmp3;
        tmp2 = tmp4;
    }
}
int cal()
{
    int r=0;
    int b=0;
    int g=0;
    int y=0;
    int w=0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if(arr[i][j].col=='R') r = r + arr[i][j].num;
            else if(arr[i][j].col=='B')b = b + arr[i][j].num;
            else if(arr[i][j].col=='G')g = g + arr[i][j].num;
            else if(arr[i][j].col=='Y')y = y + arr[i][j].num;
            //cout<<arr[i][j].num<<" ";
        }
        //cout<<"\n"<<"";
    }
    //cout<<"\n"<<"";   
    return 7*r+5*b+3*g+2*y;
}

void cpy(int idx)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            temp[i][j] = box[idx][i][j]; 
        }
    }    
}
void pls(int y, int x)
{
    for (int i = y; i < 4+y; ++i)
    {
        for (int j = x; j < 4+x; ++j)
        {
            if(temp[i-y][j-x].num+arr[i][j].num<0)
            {   
                arr[i][j].num = 0;
            }
            else if(temp[i-y][j-x].num+arr[i][j].num>9)
            {
                arr[i][j].num = 9;
            }
            else
            {
                arr[i][j].num = temp[i-y][j-x].num+arr[i][j].num;
            }

            if(temp[i-y][j-x].col!='W') arr[i][j].col = temp[i-y][j-x].col;
        }
    }      
}
int dfs(int idx,int cnt)
{
    P atp[5][5];
    if(cnt==3)
    {
        int ans = cal();
        if(ans>mx) mx = ans;
        return 0;
    }
    for (int j = 0; j < 5; ++j)
    {
        for (int m = 0; m < 5; ++m)
        {
            atp[j][m] = arr[j][m];
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for (int k = 0; k < n; ++k)
        {
            if(chk[k]==0)
            {
                chk[k] = 1;
                
                for (int l = 0; l < 4; ++l)
                {
                    cpy(k);
                    for (int j = 0; j < l; ++j)
                    {
                        turn();
                    }
                    pls(start[i][0],start[i][1]);
                    dfs(k,cnt+1);
                    turn();
                    for (int j = 0; j < 5; ++j)
                    {
                        for (int m = 0; m < 5; ++m)
                        {
                            arr[j][m] = atp[j][m];
                        }
                    }
                }
                chk[k] = 0;
            }
        }
    }
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    char c;
    P atp[5][5];
    for (int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; j++)
        {
            P p;
            p.num = 0;
            p.col = 'W';
            arr[i][j] = p;
            atp[i][j] = p;
        }
    }
    cin>>n;
    for(int k = 0; k < n; k++)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin>>a;
                P p;
                p.num = a;
                box[k][i][j] = p;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin>>c;
                box[k][i][j].col = c;
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for (int k = 0; k < n; ++k)
        {
            chk[k] = 1;
            for (int l = 0; l < 4; ++l)
            {
                cpy(k);
                for (int j = 0; j < l; ++j)
                {
                    turn();
                }
                pls(start[i][0],start[i][1]);
                dfs(k,1);
                for (int j = 0; j < 5; ++j)
                {
                    for (int m = 0; m < 5; ++m)
                    {
                        arr[j][m] = atp[j][m];
                    }
                }
            }
            chk[k] = 0;
        }
    } 
    cout<<mx<<"\n";
    return 0;
}