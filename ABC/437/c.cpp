#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
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
    ll T;
    cin >> T;
    for(ll t=0; t<T; t++){
        ll N;
        cin >> N;
        vll W(N);
        vll P(N);
        vb B(N, false); 
        for(ll i=0; i<N; i++){
            cin >> W[i] >> P[i];
        }
        ll ans_1 = 0;
        ll ans_2 = 0;
        vector<vector<pair<ll, ll>>> dp(2, vpll(N+1));
        dp[0][0].first = -W[0];
        dp[1][0].first = P[0];
        dp[0][0].second = 0;
        dp[1][0].second = 0;
        for(ll i=0; i<N; i++){
            ll tmp1 = LLONG_MIN;
            if(dp[0][i].first - W[i+1] >= 0){
                dp[0][i+1].first = dp[0][i+1].first - W[i+1];
                dp[0][i+1].second = dp[0][i+1].second + 1;
            }
        }
    }
}