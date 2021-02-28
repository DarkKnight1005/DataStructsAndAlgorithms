#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vect;

int func(int n, bool showPath)
{
	int firstPath, secondPath, minPath;
	if (n == 1){
		// showPath ? cout<<vect[0]<<endl : NULL;
        if(showPath){
            cout<<vect[0]<<endl;
        }
		return vect[0];
	} if (n == 2) {
		// showPath ? cout<<vect[0]<<" "<<vect[1]<<endl : NULL;
        if (showPath){
            cout<<vect[0]<<" "<<vect[1]<<endl;
        }
        
		return vect[1];
	} if (n == 3) {
		if (showPath) {
			cout<<vect[0]<<" "<<vect[1]<<endl;
			cout<<vect[0]<<endl;
			cout<<vect[0]<<" "<<vect[2]<<endl;
		}

		return vect[0] + vect[1] + vect[2];
	}
	firstPath = vect[0] + (2 * vect[1]) + vect[n - 1];
	secondPath = (2 * vect[0]) + vect[n - 2] + vect[n - 1];
	minPath = min(firstPath, secondPath);
	if (showPath){
		if (minPath == firstPath){
			cout<<vect[0]<<" "<<vect[1]<<endl;
			cout<<vect[0]<<endl;
			cout<<vect[n - 2]<<" "<<vect[n - 1]<<endl;
			cout<<vect[1]<<endl;
		} else {
			cout<<vect[0]<<" "<<vect[n - 2]<<endl;
			cout<<vect[0]<<endl;
			cout<<vect[0]<<" "<<vect[n - 1]<<endl;
			cout<<vect[0]<<endl;
		}
	}
	return minPath + func(n - 2, showPath);
}

int main() {

    int n, s, score = 0, i = 1;

    while(cin>>n){
        vect.clear();
        for (i = 0; i < n; i++)
        {
            cin>>s;
            vect.push_back(s);
        }
        sort(vect.begin(), vect.end());
        score = func(n, false); 
        cout<<score<<endl;
        func(n, true);
    }
	return 0;
}