#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 100001

int arr[MAX], arrY[MAX], plat[MAX], res[MAX];

using namespace std;

void init(){
    arr[1] = 0;
    arr[2] = abs(arrY[2] - arrY[1]);
    plat[1] = -1;
    plat[2] = 1;
}

int main(){

    int n;
    cin>>n;
    for (size_t i = 1; i <= n; i++)
    {
        cin>>arrY[i];
    }
    init();

    for (size_t i = 3; i <= n; i++){
       int temp1 = arr[i - 1] + abs(arrY[i] - arrY[i - 1]);
       int temp2 = arr[i - 2] + (3 * abs(arrY[i] - arrY[i - 2]));

       if (temp1 > temp2){
           arr[i] = temp2;
           plat[i] = i - 2;
       }else{
           arr[i] = temp1;
           plat[i] = i - 1;
       }
       
    }

    int j = 0;
    int i = n;
    while (i > 0)
    {
        res[j] = i;
        i = plat[i];
        j++;
    }

    cout<<arr[n]<<endl;
    cout<<j<<endl;
    
    for (int i = j - 1; i >= 0 ; i--){
        cout<<res[i]<<" ";
    }
    
    
    

    return 0;
}