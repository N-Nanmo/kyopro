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
    int N, Q;
    cin >> N >> Q;
    vll A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vll sum(2*N+1, 0);
    ll crr = 0;
    for(int i=0; i<2*N; i++){
        sum[i+1] = sum[i] + A[i%N];
    }
    for(int i=0; i<Q; i++){
        int q;
        cin >> q;
        if(q == 1){
            int c;
            cin >> c;
            crr = (crr + c) % N;
        }else{
            ll l, r;
            cin >> l >> r;
            ll ans = sum[crr + r] - sum[crr + l - 1];
            cout << ans << "\n";
        }
    }
}