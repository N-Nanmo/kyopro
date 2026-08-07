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
    ll N, Q;
    cin >> N >> Q;
    vll PC(N, 0);
    for(ll i=0; i<N; i++){
        PC[i]++;
    }
    ll left = 0;
    for(int i=0; i<Q; i++){
        ll x, y, ans=0;
        cin >> x >> y;
        for(int j=left; j<x; j++){
            PC[y-1] += PC[j];
            ans += PC[j];
            left++;
        }
        cout << ans << "\n";
    }
}