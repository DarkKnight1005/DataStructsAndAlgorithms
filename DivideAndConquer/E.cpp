#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;

int a,b,n;

ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll _gcd, ll a, ll b)
{
    return a * b / _gcd;
}

ll func(ll n)
{
    ll _gcd = gcd(a, b);
    ll _lcm = lcm(_gcd, a,b);
    ll ans = n/a + n/b - n/_lcm;
    return ans;
}

int main(){

    ll left = 1, right = 1e9, middle;
    cin>>a>>b>>n;

    while (left < right)
    {
        middle = (left + right) / 2;

        if (func(middle) >= n){
            right = middle;
        }
        else{
            left = middle + 1;
        }
    }

    cout<<left<<endl;

    return 0;
}