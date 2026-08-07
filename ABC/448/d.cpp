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
using vf = vector<float>;
using vd = vector<double>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
using vvd = vector<vector<double>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T>
inline istream& operator >> (istream& is, vector<T>& v){
    for(size_t i=0; i<v.size(); i++){
        is >> v[i];
    }
    return is;
}
template <typename T, typename U>
inline istream& operator >> (istream& is, vector<pair<T,U>>& v){
    for(size_t i=0; i<v.size(); i++){
        is >> v[i].first >> v[i].second;
    }
    return is;
}
template <typename T>
inline istream& operator >> (istream& is, vector<vector<T>>& v){
    for(size_t i=0; i<v.size(); i++){
        for(size_t j=0; j<v[i].size(); j++){
            is >> v[i][j];
        }
    }
    return is;
}
template <typename T, typename U, typename S, typename V>
inline istream& operator >> (istream& is, vector<pair<pair<T,U>, pair<S,V>>>& v){
    for(size_t i=0; i<v.size(); i++){
        is >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
    }
    return is;
}

vb seen;
void dfs(const vvll &G, int v, unordered_map<ll, ll> &mp, vb &ans, bool b, vll &A){
    seen[v] = true;
    if(mp[A[v]] > 0 || b){
        ans[v] = true;
        b = true;
    }
    mp[A[v]]++;
    for(auto nv : G[v]){
        if(seen[nv]) continue;
        dfs(G, nv, mp, ans, b, A);
    }
    mp[A[v]]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vll A(N);
    cin >> A;
    vvll G(N);
    for(ll i=0; i<N-1; i++){
        ll u, v;
        cin >> u >> v;
        G[u-1].emplace_back(v-1);
        G[v-1].emplace_back(u-1);
    }
    unordered_map<ll, ll> mp;
    vb ans(N, false);
    seen.assign(N, false);
    dfs(G, 0, mp, ans, false, A);
    for(int i=0; i<N; i++){
        if(ans[i]) cyes;
        else cno;
    }
}