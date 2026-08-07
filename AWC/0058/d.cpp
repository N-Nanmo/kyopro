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
inline istream& operator>>(istream& is, vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i];
    }
    return is;
}
template <typename T, typename U>
inline istream& operator>>(istream& is, vector<pair<T, U>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i].first >> v[i].second;
    }
    return is;
}
template <typename T>
inline istream& operator>>(istream& is, vector<vector<T>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            is >> v[i][j];
        }
    }
    return is;
}
template <typename T, typename U, typename S, typename V>
inline istream& operator>>(istream& is,
                           vector<pair<pair<T, U>, pair<S, V>>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i].first.first >> v[i].first.second >> v[i].second.first >>
            v[i].second.second;
    }
    return is;
}
vector<vector<pll>> G;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M, K;
    cin >> N >> M >> K;
    G.resize(N);
    for (ll i = 0; i < M; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].emplace_back(make_pair(v, c));
        G[v].emplace_back(make_pair(u, c));
    }
    ll ansk = 0;
    vector<ll> V(N, LLONG_MAX);
    queue<pll> q;
    if (K != 1) {
        q.emplace(make_pair(0, 0));
        while (!q.empty()) {
            pll tmp = q.front();
            q.pop();
            ll crr = tmp.first;
            ll cost = tmp.second;
            for (pi g : G[crr]) {
                if (V[g.first] > g.second + cost) {
                    q.emplace(make_pair(g.first, g.second + cost));
                    V[g.first] = g.second + cost;
                }
            }
        }
        if (V[K - 1] == LLONG_MAX) {
            cout << -1 << "\n";
            return 0;
        }
        ansk = V[K - 1];
    }
    if(K == N){
        cout << ansk << "\n";
        return 0;
    }
    q.emplace(make_pair(K - 1, 0));
    for (ll i = 0; i < N; i++) {
        V[i] = LLONG_MAX;
    }
    while (!q.empty()) {
        pll tmp = q.front();
        q.pop();
        ll crr = tmp.first;
        ll cost = tmp.second;
        for (pll g : G[crr]) {
            if (V[g.first] > g.second + cost) {
                q.emplace(make_pair(g.first, g.second + cost));
                V[g.first] = g.second + cost;
            }
        }
    }
    if (V[N - 1] == LLONG_MAX) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ansk + V[N - 1] << "\n";
}