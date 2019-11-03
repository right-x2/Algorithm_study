#include <iostream>
int main(){
    int a,b,c,temp;
    std::cin >>a >>b >>c;
    int arr[3] = {0 , 0 , 0};
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2-i ; j++)
        {
            if( arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        printf("%d ", arr[i] );
    }

}