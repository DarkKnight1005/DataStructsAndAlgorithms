#include<iostream>

#define MAX 1000000

int arr[MAX];

using namespace std;

int func(int n) {

    if (n == 1){
        return 2;
    }
    else if (n == 2){
        return 4;
    }
    else if (n == 3){
        return 7;
    }
    else if (arr[n] != -1){
        return arr[n];
    }
    arr[n] = (func(n-1) + func(n-2) + func(n-3)) % 12345;
    return arr[n];

}

 

int main(void)

{
    int n;
    memset(arr,-1,sizeof(arr)/sizeof(arr[0]));

    cin>>n;
    cout<<func(n)<<endl;


  return 0;

}