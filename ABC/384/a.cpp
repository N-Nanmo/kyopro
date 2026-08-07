#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    char c1, c2;
    string S;
    cin >> N >> c1 >> c2 >> S;
    for(int i=0; i<S.size(); i++){
        if(S[i] != c1){
            S[i] = c2;
        }
    }
    cout << S << "\n";
}