#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
#include<map>
#include<set>

using namespace std;

vector<int> vect;

long bs(int j, int n){

    if(n == 1 && vect.at(n) != j){
        return NULL;
    }else if(n == 1 && vect.at(n) == j){
        return n;
    }
    // if(vect.at(0) == j){
    //     return -1;
    // }else if(vect.at(vect.size() - 1) == j){
    //     return vect.size() - 1;
    // }
    
    long semi = n/2;
    if(semi < 0 || semi >= vect.size()){
        return NULL;
    }

    if(semi + 1 < vect.size() && vect.at(semi) > j && semi - 1 >= 0 && vect.at(semi - 1) < j){
        return NULL;
    }

    if(vect.at(semi) == j){
        return semi == 0 ? -1 : semi;
    }
    if(semi + 1 < vect.size() && vect.at(semi + 1) == j){
        return semi + 1;
    }
    if(semi - 1 >= 0 && vect.at(semi - 1) == j){
        return semi - 1 == 0 ? -1 : semi - 1;
    }
    else if (vect.at(semi) > j){
        return bs(j, semi);
    }else{
        return bs(j, semi + n);
    }
}


int main(){

    
    long n, k, elem, num;
    cin>>k>>n;
    for (size_t i = 0; i < k; i++)
    {
        cin>>elem;
        vect.push_back(elem);
    }
    for (size_t i = 0; i < n; i++)
    {   
        cin>>num;
        
        if(bs(num, k) == NULL){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    
    
    

    return 0;
}