#include <iostream>
#include <algorithm>
#include <vector>

#define MIN -2147483647

using namespace std;

int main() {

    vector<int> vectKrishki, vectKastruli;
    int n,m, elem, ans = 0, i = 0, j = 0;


    cin>>n>>m;
    for (i = 0; i < n; i++)
    {
        cin>>elem;
        vectKastruli.push_back(elem);
    }
    for (i = 0; i < m; i++)
    {
        cin>>elem;
        vectKrishki.push_back(elem);
    }

    sort(vectKrishki.begin(), vectKrishki.end());
    sort(vectKastruli.begin(), vectKastruli.end());

    i = 0;
    for(j = 0; i < n && j < m; j++){
        if(vectKastruli.at(i) <= vectKrishki.at(j)){
            i++;
        }
    }   
    cout<<i<<endl;
	return 0;
}

/*
5 5
4 8 1 2 5
7 2 4 6 5
*/