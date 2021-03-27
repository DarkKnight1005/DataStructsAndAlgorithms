#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
#include<map>
#include<set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    vector<int> vect;
    vector<int>::iterator it;
    int pos;
    int n, elem, h, k;
    cin>>n>>k;
    for (size_t i = 0; i < n; i++)
    {
        cin>>elem;
        // vect.insert(elem);
        vect.push_back(elem);
    }
    // cout<<endl;
    // copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
    // cout<<endl;
    sort(vect.begin(), vect.end());
    for (size_t i = 0; i < k; i++)
    {
        cin>>h;
        // it = lower_bound(vect.begin(), vect.end(), h);
        // it = binary_search(vect.begin(), vect.end(), h);
        // bool b = binary_search(vect.begin(), vect.end(), h);
        if(lower_bound(vect.begin(), vect.end(), h) != upper_bound(vect.begin(), vect.end(), h)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    
    return 0;
}