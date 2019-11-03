#include <iostream>
using namespace std;
int main(){
    int a,b,c,temp;
    cin >>a;
    int arr[1001] = {0,};
    for (int i = 0; i < a; ++i)
    {
        cin >>b;
        arr[i] = b;
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a-1-i ; j++)
        {
            if( arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < a; ++i)
    {
        printf("%d ", arr[i] );
    }

}