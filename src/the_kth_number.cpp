#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    vector<int> vec(m);
    for(int i = 0;i<m;i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end());
    cout << vec[m - n];
}