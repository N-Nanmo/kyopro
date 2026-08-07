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
using vf = vector<float>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
    vector<ll> C(N, 1);
    for(ull i=0; i<M; i++){
        ll a, b;
        cin >> a >> b;
        C[a-1]++;
        C[b-1]++;
    }
    vector<ull> Cmv(N+1);
    Cmv[0] = 1;
    for(ll i=1; i<=N; i++){
        Cmv[i] = Cmv[i-1]*(i+3)/i;
    }
    vector<ull> ans(N, 0);
    for(ull i=0; i<N; i++){
        if(N-C[i]-3 < 0){
            continue;
        }
        ans[i] = Cmv[N-C[i]-3];
    }
    for(ull i=0; i<N-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[N-1] << "\n";
}