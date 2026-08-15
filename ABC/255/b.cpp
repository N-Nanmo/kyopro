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
    ll N, M, T;
    cin >> N >> M >> T;
    vll A(N, 0);
    vll B(N, 0);
    for(ll i=0; i<N-1; i++) cin >> A[i];
    while(M--){
        ll x, y;
        cin >> x >> y;
        if(x == 1) T += y;
        else B[x-2] += y;
    }
    for(ll i=0; i<N-1; i++){
        T -= A[i];
        if(T <= 0){
            cno;
            return 0;
        }
        T += B[i];
    }
    cyes;
}