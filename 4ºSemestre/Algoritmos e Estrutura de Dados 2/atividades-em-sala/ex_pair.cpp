#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

pair<int, int> twoSum(const vector<int>& v, int k) {;
    vector<int> copy = v;
    sort(copy.begin(), copy.end());
    
    int low = 0, high = copy.size()-1;

    if(k <= copy[low]) return make_pair(-1, -1);

    while (low < high)
    {
        if(copy[low] + copy[high] == k) return make_pair(copy[low], copy[high]);
        if(copy[low] + copy[high] < k) low++;
        if(copy[low] + copy[high] > k) high--;
    }
    
    return make_pair(-1, -1);
}

int main() {
    vector<int> v = { 9, 14, 2, 1, 17, 10 };
    int k = 99;
    pair<int, int> par = twoSum(v, k);
    cout<<par.first<<" "<<par.second<<endl;

    return 0;
}