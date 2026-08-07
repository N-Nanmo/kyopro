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
    ll N, W;
    cin >> N >> W;
    vpll H(N);
    for(int i=0; i<N; i++){
        cin >> H[i].first >> H[i].second;
    }
    vvll dp(N, vll(W, 0));
    for(int i=0; i<N; i++){
        for(int j=1; j<=W; j++){
            if(i == 0){
                if(H[i].first <= j){
                    dp[i][j-1] = H[i].second;
                }
            }else{
                if(j-H[i].first-1 >= 0){
                    dp[i][j-1] = max(dp[i-1][j-1], dp[i-1][j-H[i].first-1]+H[i].second);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout << dp[N-1][W-1] << "\n";
}