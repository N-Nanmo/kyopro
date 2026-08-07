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
    ll ans = 0;
    vpll RC(M);
    map<pi, int> mp;
    for(ll i=0; i<M; i++){
        cin >> RC[i].first >> RC[i].second;
    }
    for(ll i=0; i<M; i++){
        ll r = RC[i].first - 1;
        ll c = RC[i].second - 1;
        if(mp[make_pair(r, c)] == 0 && mp[make_pair(r+1, c)] == 0 && mp[make_pair(r+1, c+1)] == 0 && mp[make_pair(r, c+1)] == 0){
            ans++;
            mp[make_pair(r, c)]++;
            mp[make_pair(r+1, c)]++;
            mp[make_pair(r, c+1)]++;
            mp[make_pair(r+1, c+1)]++;
        }
    }
    cout << ans << "\n";
}