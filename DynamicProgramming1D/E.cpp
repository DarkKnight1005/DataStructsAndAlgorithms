#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 1000001
#define ll long long

ll arr[MAX], en[MAX];

using namespace std;

void init(ll n){
    en[1] = 0;
    if(n == 2){
        en[2] = (ll)pow(arr[2] - arr[1], 2);
    }else{
        ll a = pow(arr[1] - arr[2], 2);
        ll b = 3 * pow(arr[1] - arr[3], 2) + pow(arr[2] - arr[3], 2);
        en[2] = min(a, b);
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

        ll a = en[i - 1] + pow(arr[i - 1] - arr[i], 2);
        ll b = en[i - 2] + 3 * pow(arr[i - 2] - arr[i], 2);
        ll c = en[i - 1] + 3 * pow(arr[i - 1] - arr[i + 1], 2) + pow(arr[i] - arr[i + 1], 2);

        en[i] = min(a,b);
        if(i < n){
            en[i] = min(en[i], c);
        }
    }
    cout<<en[n]<<endl;    

    return 0;
}