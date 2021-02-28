#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
#include<map>

using namespace std;

bool comparator(vector<int> vect1, vector<int> vect2){

    if (vect1.at(0) * vect2.at(1) == vect2.at(0) * vect1.at(1))
    {
        return vect1.at(2) < vect2.at(2); 
    }else{
        return vect1.at(0) * vect2.at(1) < vect2.at(0) * vect1.at(1);
    }
    
}

int main(){

    vector<int> temp_vect;
    vector<vector<int> > vect;
    vector<vector<int> >::iterator it;
    int n, t, s;

    while(cin>>n){
        vect.clear();
        for(int i = 0; i < n; i++){
            cin>>t>>s;
            temp_vect.push_back(t);
            temp_vect.push_back(s);
            temp_vect.push_back(i + 1);
            vect.push_back(temp_vect);
            temp_vect.clear();
        }

        sort(vect.begin(), vect.end(), comparator);

        // cout<<endl;
        // copy(vect.begin(), vect.end(), ostream_iterator<pair<int, int> >(cout, " "));
        for(int i = 0; i < vect.size(); i++){
            cout<<vect[i][2]<<" ";
        }
        cout<<endl;
    }
    return 0;
}