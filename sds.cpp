#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[3][3] = {{10,11,12},{13,14,15},{16,17,18}};
int row1[3][3] = {{46,47,48},{49,50,51},{52,53,54}};
int row2[3][3] = {{37,38,39},{40,41,42},{43,44,45}};
int back[3][3] = {{28,29,30},{31,32,33},{34,35,36}};
int top[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int bottom[3][3] = {{19,20,21},{22,23,24},{25,26,27}};

void topLeft(){
    
    int tmp1 = ans[0][0];
    int tmp2 = ans[0][1];
    int tmp3 = ans[0][2];
    ans[0][0] = row2[0][0];
    ans[0][1] = row2[0][1];
    ans[0][2] = row2[0][2];
    row2[0][2] = back[2][0];
    row2[0][1] = back[2][1];
    row2[0][0] = back[2][2];
    back[2][0] = row1[0][2];
    back[2][1] = row1[0][1];
    back[2][2] = row1[0][0];
    row1[0][0] = tmp1;
    row1[0][1] = tmp2;
    row1[0][2] = tmp3;
    tmp1 = top[0][0];
    top[0][0] = top[0][2];
    top[0][2] = top[2][2];
    top[2][2] = top[2][0];
    top[2][0] = tmp1;
    tmp1 = top[0][1];
    top[0][1] = top[1][2];
    top[1][2] = top[2][1];
    top[2][1] = top[1][0];
    top[1][0] = tmp1;
    
}
void topRight(){
    int tmp1 = ans[0][0];
    int tmp2 = ans[0][1];
    int tmp3 = ans[0][2];
    ans[0][0] = row1[0][0];
    ans[0][1] = row1[0][1];
    ans[0][2] = row1[0][2];
    row1[0][2] = back[2][0];
    row1[0][1] = back[2][1];
    row1[0][0] = back[2][2];
    back[2][2] = row2[0][0];
    back[2][1] = row2[0][1];
    back[2][0] = row2[0][2];
    row2[0][0] = tmp1;
    row2[0][1] = tmp2;
    row2[0][2] = tmp3;
    tmp1 = top[0][0];
    top[0][0] = top[2][0];
    top[2][0] = top[2][2];
    top[2][2] = top[0][2];
    top[0][2] = tmp1;
    tmp1 = top[0][1];
    top[0][1] = top[1][0];
    top[1][0] = top[2][1];
    top[2][1] = top[1][2];
    top[1][2] = tmp1;
}
void midLeft(){
    int tmp1 = ans[1][0];
    int tmp2 = ans[1][1];
    int tmp3 = ans[1][2];
    ans[1][0] = row2[1][0];
    ans[1][1] = row2[1][1];
    ans[1][2] = row2[1][2];
    row2[1][0] = back[1][2];
    row2[1][1] = back[1][1];
    row2[1][2] = back[1][0];
    back[1][2] = row1[1][0];
    back[1][1] = row1[1][1];
    back[1][0] = row1[1][2];
    row1[1][0] = tmp1;
    row1[1][1] = tmp2;
    row1[1][2] = tmp3;
}
void midRight(){
    int tmp1 = ans[1][0];
    int tmp2 = ans[1][1];
    int tmp3 = ans[1][2];
    ans[1][0] = row1[1][0];
    ans[1][1] = row1[1][1];
    ans[1][2] = row1[1][2];
    row1[1][0] = back[1][2];
    row1[1][1] = back[1][1];
    row1[1][2] = back[1][0];
    back[1][2] = row2[1][0];
    back[1][1] = row2[1][1];
    back[1][0] = row2[1][2];
    row2[1][0] = tmp1;
    row2[1][1] = tmp2;
    row2[1][2] = tmp3;
}
void bottomLeft(){
    int tmp1 = ans[2][0];
    int tmp2 = ans[2][1];
    int tmp3 = ans[2][2];
    ans[2][0] = row2[2][0];
    ans[2][1] = row2[2][1];
    ans[2][2] = row2[2][2];
    row2[2][0] = back[0][2];
    row2[2][1] = back[0][1];
    row2[2][2] = back[0][0];
    back[0][2] = row1[2][0];
    back[0][1] = row1[2][1];
    back[0][0] = row1[2][2];
    row1[2][0] = tmp1;
    row1[2][1] = tmp2;
    row1[2][2] = tmp3;
    tmp1 = bottom[0][0];
    bottom[0][0] = bottom[2][0];
    bottom[2][0] = bottom[2][2];
    bottom[2][2] = bottom[0][2];
    bottom[0][2] = tmp1;
    tmp1 = bottom[0][1];
    bottom[0][1] = bottom[1][0];
    bottom[1][0] = bottom[2][1];
    bottom[2][1] = bottom[1][2];
    bottom[1][2] = tmp1;
}
void bottomRight(){
    int tmp1 = ans[2][0];
    int tmp2 = ans[2][1];
    int tmp3 = ans[2][2];
    ans[2][0] = row1[2][0];
    ans[2][1] = row1[2][1];
    ans[2][2] = row1[2][2];
    row1[2][0] = back[0][2];
    row1[2][1] = back[0][1];
    row1[2][2] = back[0][0];
    back[0][2] = row2[2][0];
    back[0][1] = row2[2][1];
    back[0][0] = row2[2][2];
    row2[2][0] = tmp1;
    row2[2][1] = tmp2;
    row2[2][2] = tmp3;
    tmp1 = bottom[0][0];
    bottom[0][0] = bottom[0][2];
    bottom[0][2] = bottom[2][2];
    bottom[2][2] = bottom[2][0];
    bottom[2][0] = tmp1;
    tmp1 = bottom[0][1];
    bottom[0][1] = bottom[1][2];
    bottom[1][2] = bottom[2][1];
    bottom[2][1] = bottom[1][0];
    bottom[1][0] = tmp1;
}
void leftDown(){
    int tmp1 = ans[0][0];
    int tmp2 = ans[1][0];
    int tmp3 = ans[2][0];
    ans[0][0] = top[0][0];
    ans[1][0] = top[1][0];
    ans[2][0] = top[2][0];
    top[0][0] = back[0][0];
    top[1][0] = back[1][0];
    top[2][0] = back[2][0];
    back[0][0] = bottom[0][0];
    back[1][0] = bottom[1][0];
    back[2][0] = bottom[2][0];
    bottom[0][0] = tmp1;
    bottom[1][0] = tmp2;
    bottom[2][0] = tmp3;
    tmp1 = row2[0][0];
    row2[0][0] = row2[2][0];
    row2[2][0] = row2[2][2];
    row2[2][2] = row2[0][2];
    row2[0][2] = tmp1;
    tmp1 = row2[0][1];
    row2[0][1] = row2[1][0];
    row2[1][0] = row2[2][1];
    row2[2][1] = row2[1][2];
    row2[1][2] = tmp1;
}
void midDown(){
    int tmp1 = ans[0][1];
    int tmp2 = ans[1][1];
    int tmp3 = ans[2][1];
    ans[0][1] = top[0][1];
    ans[1][1] = top[1][1];
    ans[2][1] = top[2][1];
    top[0][1] = back[0][1];
    top[1][1] = back[1][1];
    top[2][1] = back[2][1];
    back[0][1] = bottom[0][1];
    back[1][1] = bottom[1][1];
    back[2][1] = bottom[2][1];
    bottom[0][1] = tmp1;
    bottom[1][1] = tmp2;
    bottom[2][1] = tmp3;
}
void rightDown(){
    int tmp1 = ans[0][2];
    int tmp2 = ans[1][2];
    int tmp3 = ans[2][2];
    ans[0][2] = top[0][2];
    ans[1][2] = top[1][2];
    ans[2][2] = top[2][2];
    top[0][2] = back[0][2];
    top[1][2] = back[1][2];
    top[2][2] = back[2][2];
    back[0][2] = bottom[0][2];
    back[1][2] = bottom[1][2];
    back[2][2] = bottom[2][2];
    bottom[0][2] = tmp1;
    bottom[1][2] = tmp2;
    bottom[2][2] = tmp3;
    tmp1 = row1[0][0];
    row1[0][0] = row1[0][2];
    row1[0][2] = row1[2][2];
    row1[2][2] = row1[2][0];
    row1[2][0] = tmp1;
    tmp1 = row1[0][1];
    row1[0][1] = row1[1][2];
    row1[1][2] = row1[2][1];
    row1[2][1] = row1[1][0];
    row1[1][0] = tmp1;
}
void leftUp(){
    int tmp1 = ans[0][0];
    int tmp2 = ans[1][0];
    int tmp3 = ans[2][0];
    ans[0][0] = bottom[0][0];
    ans[1][0] = bottom[1][0];
    ans[2][0] = bottom[2][0];
    bottom[0][0] = back[0][0];
    bottom[1][0] = back[1][0];
    bottom[2][0] = back[2][0];
    back[0][0] = top[0][0];
    back[1][0] = top[1][0];
    back[2][0] = top[2][0];
    top[0][0] = tmp1;
    top[1][0] = tmp2;
    top[2][0] = tmp3;
    tmp1 = row2[0][0];
    row2[0][0] = row2[0][2];
    row2[0][2] = row2[2][2];
    row2[2][2] = row2[2][0];
    row2[2][0] = tmp1;
    tmp1 = row2[0][1];
    row2[0][1] = row2[1][2];
    row2[1][2] = row2[2][1];
    row2[2][1] = row2[1][0];
    row2[1][0] = tmp1;
}
void midUp(){
    int tmp1 = ans[0][1];
    int tmp2 = ans[1][1];
    int tmp3 = ans[2][1];
    ans[0][1] = bottom[0][1];
    ans[1][1] = bottom[1][1];
    ans[2][1] = bottom[2][1];
    bottom[0][1] = back[0][1];
    bottom[1][1] = back[1][1];
    bottom[2][1] = back[2][1];
    back[0][1] = top[0][1];
    back[1][1] = top[1][1];
    back[2][1] = top[2][1];
    top[0][1] = tmp1;
    top[1][1] = tmp2;
    top[2][1] = tmp3;
}
void rightUp(){
    int tmp1 = ans[0][2];
    int tmp2 = ans[1][2];
    int tmp3 = ans[2][2];
    ans[0][2] = bottom[0][2];
    ans[1][2] = bottom[1][2];
    ans[2][2] = bottom[2][2];
    bottom[0][2] = back[0][2];
    bottom[1][2] = back[1][2];
    bottom[2][2] = back[2][2];
    back[0][2] = top[0][2];
    back[1][2] = top[1][2];
    back[2][2] = top[2][2];
    top[0][2] = tmp1;
    top[1][2] = tmp2;
    top[2][2] = tmp3;
    tmp1 = row1[0][0];
    row1[0][0] = row1[2][0];
    row1[2][0] = row1[2][2];
    row1[2][2] = row1[0][2];
    row1[0][2] = tmp1;
    tmp1 = row1[0][1];
    row1[0][1] = row1[1][0];
    row1[1][0] = row1[2][1];
    row1[2][1] = row1[1][2];
    row1[1][2] = tmp1;
}



int main() {
    int m,c,p,a,n,cnt = 0;
    //topRight();
    cin>>m;
    
    for(int i = 0; i < m; i++)
    {
        cin>>n;
        for (int j = 0; j < n; ++j)
        {
            cin>>a;
            if(a==1)
            {
                leftUp();
            }
            else if(a==2)
            {
                midUp();
            }
            else if(a==3)
            {
                rightUp();
            }
            else if(a==4)
            {
                leftDown();
            }
            else if(a==5)
            {
                midDown();
            }
            else if(a==6)
            {
                rightDown();
            }
            else if(a==7)
            {
                topRight();
            }
            else if(a==8)
            {
                midRight();
            }
            else if(a==9)
            {
                bottomRight();
            }
            else if(a==10)
            {
                topLeft();
            }
            else if(a==11)
            {
                midLeft();
            }
            else if(a==12)
            {
                bottomLeft();
            }
        }
        cin>>p;
        if(p==1)
        {
            cout<<"#"<<"";
            cout<<i+1<<" ";
            for(int j = 0; j <3; j ++)
            {
                for(int k = 0; k < 3 ; k++)
                {
                    cout<<top[j][k]<<" ";
                }
            }
            cout<<""<<"\n";
        }
        else if(p==2)
        {
            cout<<"#"<<"";
            cout<<i+1<<" ";
            for(int j = 0; j <3; j ++)
            {
                for(int k = 0; k < 3 ; k++)
                {
                    cout<<ans[j][k]<<" ";
                }
            }
            cout<<""<<"\n";
        }
        else if(p==3)
        {
            cout<<"#"<<"";
            cout<<i+1<<" ";
            for(int j = 0; j <3; j ++)
            {
                for(int k = 0; k < 3 ; k++)
                {
                    cout<<bottom[j][k]<<" ";
                }
            }
            cout<<""<<"\n";
        }
        else if(p==4)
        {
            cout<<"#"<<"";
            cout<<i+1<<" ";
            for(int j = 0; j <3; j ++)
            {
                for(int k = 0; k < 3 ; k++)
                {
                    cout<<back[j][k]<<" ";
                }
            }
            cout<<""<<"\n";
        }
        else if(p==5)
        {
            cout<<"#"<<"";
            cout<<i+1<<" ";
            for(int j = 0; j <3; j ++)
            {
                for(int k = 0; k < 3 ; k++)
                {
                    cout<<row2[j][k]<<" ";
                }
            }
            cout<<""<<"\n";
        }
        else if(p==6)
        {
            cout<<"#"<<"";
            cout<<i+1<<" ";
            for(int j = 0; j <3; j ++)
            {
                for(int k = 0; k < 3 ; k++)
                {
                    cout<<row1[j][k]<<" ";
                }
            }
            cout<<""<<"\n";
        }
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                ans[j][k] = 10+cnt;
                row1[j][k] = 46+cnt;
                row2[j][k] = 37+cnt;
                back[j][k] = 28+cnt;
                top[j][k] = 1+cnt;
                bottom[j][k] = 19+cnt;
                cnt++;
            }
        }
        cnt = 0;
    }
    return 0;
}

