#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
#include<map>

#define ll long long
using namespace std;

int main(){

    map<ll, ll> mp;
    vector<int> vect;
    ll n, elem, k, l, q;
    cin>>n>>q;
    
    for (size_t i = 0; i < n; i++)
    {
        cin>>elem;
        if(mp.find(elem) == mp.end()){
            mp.insert(make_pair<int, int>(elem, 1));
        }else{
            mp[elem]++;
        }
    }
    for (size_t i = 0; i < q; i++)
    {
        cin>>elem;
        if(mp.find(elem) == mp.end()){
            cout<<0<<endl;
        }else{
            cout<<mp[elem]<<endl;
        }
    }
    

    
    
    return 0;
}