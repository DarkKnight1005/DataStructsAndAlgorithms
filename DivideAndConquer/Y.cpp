#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

#define ll long long
#define MAX 1000010
vector<ll> vect;


int main(){

    ll a,b,c,d,n,m,k, elem, l = 0, maxx;
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        cin>>elem;
        vect.push_back(elem);
    }
    cin>>k;

    maxx = *max_element(vect.begin(), vect.end());

    if (k > 1){
        while(maxx - l > 1){
            m = (maxx + l) / 2; d = 0;
            for(int i = 0; i < n; i++) {
                if (vect[i] > m){
                    d += (vect[i] - m + k - 2) / (k - 1);
                }
                if (d > m){
                    break;
                }
            }
            if (d > m){
                l = m; 
            }else{ 
                maxx = m;
            }
        }
    }
    cout<<maxx<<endl;
    return 0;
}