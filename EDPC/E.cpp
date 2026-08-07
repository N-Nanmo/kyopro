#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, W;
    cin >> N >> W;
    vpll A(N);
    for(int i=0; i<N; i++){
        cin >> A[i].first >> A[i].second;
    }
    ll sm = 0;
    for(int i=0; i<N; i++){
        sm += A[i].second;
    }
    vvll dp(N, vll(sm+1, LLONG_MAX-INT_MAX));
    for(int i=0; i<=sm; i++){
        if(i == A[0].second){
            dp[0][i] = A[0].first;
        }
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<=sm; j++){
            if(j == A[i].second){
                dp[i][j] = min(dp[i-1][j], A[i].first);
            }else{
                dp[i][j] = min(dp[i-1][j], A[i].first + dp[i-1][j-A[i].second]);
            }
        }
    }
    ll ans = 0;
    for(int i=0; i<=sm; i++){
        if(dp[N-1][i] <= W){
            ans = i;
        }
    }
    cout << ans << "\n";
}