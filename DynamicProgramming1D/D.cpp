#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 1000001
#define ll long long

ll arr[MAX], sums[MAX];

using namespace std;

void init(ll n){
    sums[1] = arr[1];
    if(n > 1){
        sums[2] = max(arr[1], arr[2]);
    }
}

int main(){

    ll n;
    cin>>n;
    for (size_t i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    init(n);
    

    for (size_t i = 3; i <= n; i++){

        sums[i] = max(sums[i - 1], sums[i - 2] + arr[i]);
    }
    cout<<sums[n]<<endl;    

    return 0;
}