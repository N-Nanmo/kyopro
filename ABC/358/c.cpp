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
    ll N, M;
    cin >> N >> M;
    vs S(N);
    for(ll i=0; i<N; i++){
        cin >> S[i];
    }
    ll ans = LLONG_MAX;
    for(ll bit = 0; bit < (1<<N); bit++){
        vb B(M, false);
        ll cnt = 0;
        for(ll i=0; i<N; i++){
            if(bit & (1<<i)){
                cnt++;
                for(ll j=0; j<M; j++){
                    if(S[i][j] == 'o'){
                        B[j] = true;
                    }
                }
            }
        }
        bool ok = true;
        for(int i=0; i<M; i++){
            if(!B[i]){
                ok = false;
            }
        }
        if(ok){
            ans = min(ans, cnt);
        }
    }
    cout << ans << "\n";
}