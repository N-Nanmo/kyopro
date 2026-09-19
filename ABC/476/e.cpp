#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vf = vector<float>;
using vd = vector<double>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvull = vector<vector<ull>>;
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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
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
const double PI = 3.14159265359;
vi dx = {0, -1, 0, 1};
vi dy = {1, 0, -1, 0}; 

struct S {
    ll x;
    ll i;
};

S emn(){
    return S{(ll)(1e9), -1};
}

S emx(){
    return S{(ll)(-1), -1};
}

S opmx(S a, S b){
    if(a.x > b.x){
        return a;
    }else{
        return b;
    }
}

S opmn(S a, S b){
    if(a.x > b.x){
        return b;
    }else{
        return a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    ll N, M;
    cin >> N >> M;
    vll P(N);
    cin >> P;
    segtree<S, opmx, emx> segmx(N);
    segtree<S, opmn, emn> segmn(N);
    for(int i=0; i<N; i++){
        segmx.set(i, S{P[i], i});
        segmn.set(i, S{P[i], i});
    }
    while(M--){
        ll l, r;
        cin >> l >> r;
        l--;
        // cout << l << " " << r << "\n" << flush;
        S mn = segmn.prod(l, r);
        S mx = segmx.prod(l, r);
        // cout << "mx:" << mx.x << " " << mx.i << "\n";
        // cout << "mn:" << mn.x << " " << mn.i << "\n";
        segmx.set(mx.i, S{mn.x, mx.i});
        segmx.set(mn.i, S{mx.x, mn.i});
        segmn.set(mn.i, S{mx.x, mn.i});
        segmn.set(mx.i, S{mn.x, mx.i});
        // for(int i=0; i<N; i++){
        //     cout << segmx.get(i).x << ":" << segmx.get(i).i << " \n"[i==N-1];
        // }
        // for(int i=0; i<N; i++){
        //     cout << segmn.get(i).x << ":" << segmn.get(i).i << " \n"[i==N-1];
        // }
    }
    for(int i=0; i<N; i++){
        cout << segmn.get(i).x << " \n"[i==N-1];
    }
}