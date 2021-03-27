#include<iostream>
#include<algorithm>

#define MAX 10000000

int arr[MAX];

using namespace std;

int func(int n){
    if (n == 1){
        return 0;
    }
    else if(arr[n] != -1){
        return arr[n];
    }else{
        int temp = min(n%2 == 0 ? func(n/2) : MAX, n%3 == 0 ? func(n/3) : MAX);
        arr[n] = min(func(n-1), temp) + 1;
        return arr[n];
    }
}

int main(){

    int n;
    memset(arr, -1, sizeof(arr)/sizeof(arr[0]));
    while (cin>>n)
    {
        cout<<func(n)<<endl;
    }

    return 0;
}