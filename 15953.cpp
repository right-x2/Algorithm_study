#include<iostream>

using namespace std;
int main(){
    int a, b, number;
    cin>>number;
    int at[101];
    int bt[101];
    for (int i = 1; i <= 21 ; ++i)
    {
        if(i<2){
            at[i] = 500;
        }
        else if(i<4){
            at[i] = 300;
        }
        else if(i<7){
            at[i] = 200;
        }
        else if(i<11){
            at[i] = 50;
        }
        else if(i<16){
            at[i] = 30;
        }   
        else if(i<22){
            at[i] = 10;
        }
    }
    for (int i = 1; i <= 31 ; ++i)
    {
        if(i<2){
            bt[i] = 512;
        }
        else if(i<4){
            bt[i] = 256;
        }
        else if(i<8){
            bt[i] = 128;
        }
        else if(i<16){
            bt[i] = 64;
        }
        else if(i<32){
            bt[i] = 32;
        }   
    }
    for (int i = 0; i < number; i++)
    {   
        
        cin>>a>>b;
        if (a>21||a==0) at[a] = 0;
        if (b>31||b==0) bt[b] = 0;
        cout<<(at[a]+bt[b])*10000<<'\n';
    }
}