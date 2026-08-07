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
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll R_max = -1, C_max = -1, R_min = LLONG_MAX, C_min = LLONG_MAX;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        ll R, C;
        cin >> R >> C;
        R_max = max(R_max, R);
        C_max = max(C_max, C);
        R_min = min(R_min, R);
        C_min = min(C_min, C);
    }
    ll R_ans = R_max - R_min;
    ll C_ans = C_max - C_min;
    if(R_ans % 2 == 1) R_ans++;
    if(C_ans % 2 == 1) C_ans++;
    R_ans /= 2;
    C_ans /= 2;
    ll ans = max(R_ans, C_ans);
    cout << ans << "\n";
}