#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

#define ll long long
#define MAX 1000010
vector<ll> vect;

ll count_dosk(ll m, ll n){
    ll ans = 0;

    if (m == 0){
        return INFINITY;
    }
    for(ll i = 0; i < n; i++){
        ans += vect[i] / m;
    }

    return ans;
}

int main(){

    int n, m_inp, m, elem, left = 0, right = INFINITY;
    cin>>n>>m_inp;
    for (size_t i = 0; i < n; i++)
    {
        cin>>elem;
        vect.push_back(elem);
    }

    while (left < right){   
        m = (left + right) / 2;
        if (count_dosk(m, n) < m_inp){
            right = m;
        }
        else{
            left = m + 1;
        }
    }
    cout<<left - 1<<endl;
    
    return 0;
}