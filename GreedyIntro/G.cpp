#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<int> vect;
    int i, n, l, elem;
    double ans;

	cin>>l>>n;

	for (i = 0; i < n; i++){
        cin>>elem;
        vect.push_back(elem);
    }
	sort(vect.begin(), vect.end());

	ans = l - vect[n - 1] + vect[0];

	for (i = 0; i < n - 1; i++){
        double delta = vect[i + 1] - vect[i];
         ans = max(ans, delta);
    }
    
    ans /= 2;
	cout<<fixed<<setprecision(1)<<ans<<endl;
	return 0;
}