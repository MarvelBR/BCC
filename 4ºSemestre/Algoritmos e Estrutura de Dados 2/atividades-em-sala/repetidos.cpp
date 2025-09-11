#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
bool haRepetidos(vector<T> &v){
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (i+1 == v.size())
        {
            break;
        }
        
        if (v[i] == v[i+1])
        {
            return true;
        }
        
    }
    return false;
}

int main(){

    vector<int> v = { 1, 8, 0, 9, 4, 2};
    vector<int> u = { 6, 0, 9, 2, 8, 1, 1};
    vector<string> s = {"banana", "melão",
    "mamão", "melão"};

    cout << haRepetidos(v) << '\n';
    cout << haRepetidos(u) << '\n';
    cout << haRepetidos(s) << '\n';

}