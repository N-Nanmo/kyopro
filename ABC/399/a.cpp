#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(S[i] != T[i]){
            ans++;
        }
    }
    cout << ans << "\n";
}