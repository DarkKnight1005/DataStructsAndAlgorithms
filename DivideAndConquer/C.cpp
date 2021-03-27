#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<cmath>

#define MAX 1000000000000000000LL
// #define MAX 10e18
#define ll long long

using namespace std;

vector<ll> vect;

void generate_vect() {
  ll x = 1, y = 1, i = 0, j = 0;
  while (x < MAX){
    while (x * y < MAX){
      vect.push_back(x * y);
      y *= 3;
    // y = powl(3, j);
    // j++;
    }
    // x = powl(2, i);
    // i++;
    x *= 2;
    y = 1;
    // j = 0;
  }
}

int main(){

    ll a, b, ans;
    generate_vect();
    sort(vect.begin(), vect.end());
    while (cin>>a>>b)
    {
        ans = upper_bound(vect.begin(), vect.end(), b) - upper_bound(vect.begin(), vect.end(), a - 1);
        cout<<ans<<endl;
        // copy(vect.begin() + a, vect.begin() + a + b, ostream_iterator<int>(cout, " "));
    }
    
    return 0;
}