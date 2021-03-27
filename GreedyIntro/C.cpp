#include <iostream>
#include <algorithm>
#include <vector>

#define MIN -2147483647

using namespace std;

int main() {

    vector<int> vect, vectMinMax;
    vector<int>::iterator it;
    int answers[4];
    int n,t, elem, sum = 0, maxElem, pos, test;
    cin>>t;
    // t = 3;
    test = t;
    while(t){
        vect.clear();
        vectMinMax.clear();
        sum = 0;
        cin>>n;
        // n = 4;
        for (int i = 0; i < n; i++)
        {
            cin>>elem;
            vect.push_back(elem);
            // vect.push_back(4);
            // vect.push_back(2);
            // vect.push_back(1);
            // vect.push_back(5);
        }
        

        sort(vect.begin(), vect.end());
        // copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
        // cout<<endl;

        vectMinMax.push_back(*vect.begin());
        vectMinMax.push_back(*(vect.end() - 1));
        // copy(vectMinMax.begin(), vectMinMax.end(), ostream_iterator<int>(cout, " "));
        sum += abs(vectMinMax.at(0) - vectMinMax.at(1));
        // cout<<sum<<endl;
        // it = find(vect.begin(), vect.end(), *vect.begin());
        vect.erase(vect.begin());
        vect.erase(vect.end() - 1);
        while(!vect.empty()){
            answers[0] = abs(*vectMinMax.begin() - *vect.begin());
            answers[1] = abs(*vectMinMax.begin() - *(vect.end() - 1));
            answers[2] = abs(*(vectMinMax.end() - 1) - *vect.begin());
            answers[3] = abs(*(vectMinMax.end() - 1) - *(vect.end() - 1));
            maxElem = *max_element(answers, answers + 4);
            pos = *find(answers, answers+4, maxElem);

            if(maxElem == answers[0]){
                vectMinMax.insert(vectMinMax.begin(), *vect.begin());
                vect.erase(vect.begin());
            }
            else if(maxElem == answers[1]){

                vectMinMax.insert(vectMinMax.begin(), *(vect.end() - 1));
                vect.erase(vect.end() - 1);
            }
            else if(maxElem == answers[2]){
                vectMinMax.push_back(*vect.begin());
                vect.erase(vect.begin());
            }
            else{
                vectMinMax.push_back(*(vect.end() - 1));
                vect.erase(vect.end() - 1);
            }
            sum += maxElem;
        }
        cout<<"Case "<<test - t + 1<<": "<<sum<<endl;
        t--;
    }
	return 0;
}