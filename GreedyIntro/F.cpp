#include <iostream>
#include <algorithm>

#define MAX 100000000000000000L
#define ll long long

using namespace std;

ll n, k, l, temp;
ll *pos, *clockw, *anticlockw;
ll ans = MAX;

int main() {
	cin>>n>>k>>l;
	pos = new ll[n + 1];
	clockw = new ll[n + 1];
	anticlockw = new ll[n + 1];
	for (int i = 0; i < n; i++){
      cin>>pos[i];
  }
	
  for (int i = 0; i < n; i++){
		
		if (i + 1 > k){
       temp = clockw[i + 1 - k];
    }else{
      temp = 0;
    }
		clockw[i + 1] = temp + pos[i] * 2;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (n - i > k){
      temp = anticlockw[n - i - k];
    }
		else{
      temp = 0;
    }
		anticlockw[n - i] = temp + (l - pos[i]) * 2;
	}
	for (int i = 0; i <= n; i++){
     ans = min(ans, clockw[i] + anticlockw[n - i]);
  }
	for (int i = 1; i + k - 1 <= n; i++){
		ans = min(ans, clockw[i - 1] + l + anticlockw[n - (i + k - 1)]);
  }
	cout<<ans<<endl;
	return 0;
}