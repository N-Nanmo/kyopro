#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> ab(N);
    for(int i = 0;i<N;i++){
        cin >> ab.at(i).second >> ab.at(i).first;
    }
    sort(ab.begin(),ab.end());
    for(int i=0;i<N;i++){
        cout << ab.at(i).second << " " << ab.at(i).first << endl;
    }
}