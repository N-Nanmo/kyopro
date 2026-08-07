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
using vc = vector<char>;
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
    ll N;
    cin >> N;
    vll W(N);
    vll H(N);
    vll B(N);
    for(ll i=0; i<N; i++){
        cin >> W[i] >> H[i] >> B[i];
    }
    ll he = 0;
    ll bo = 0;
    vvll dp(2, vll(N));
    dp[0][0] = B[0];
    dp[1][0] = -1;
    bo += W[0];
    for(ll i=1; i<N; i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
    }
}