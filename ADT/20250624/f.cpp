#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> A(2, vector<ll>(N));
    vector<vector<bool>> dp(2, vector<bool>(N, false));
    dp[0][0] = true;
    dp[1][0] = true;
    for(ll i=0; i<2; i++){
        for(ll j=0; j<N; j++){
            cin >> A[i][j];
        }
    }
    for(ll i=0; i<N-1; i++){
        if(dp[0][i]){
            if(abs(A[0][i] - A[0][i+1]) <= K){
                dp[0][i+1] = true;
            }
            if(abs(A[0][i] - A[1][i+1]) <= K){
                dp[1][i+1] = true;
            }
        }
        if(dp[1][i]){
            if(abs(A[1][i] - A[1][i+1]) <= K){
                dp[1][i+1] = true;
            }
            if(abs(A[1][i] - A[0][i+1]) <= K){
                dp[0][i+1] = true;
            }
        }
        if(!dp[0][i+1] && !dp[1][i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}