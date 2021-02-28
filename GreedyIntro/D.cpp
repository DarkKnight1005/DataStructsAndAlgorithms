#include <iostream>
#include <algorithm>
#include <vector>

#define MIN -2147483647

using namespace std;

int main() {

    vector<int> vect;
    int n, elem, ans = 0;

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>elem;
        vect.push_back(elem);
    }
    sort(vect.rbegin(), vect.rend());
    
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, vect.at(i) + i + 2);
    }
    
    cout<<ans<<endl;
	return 0;
}