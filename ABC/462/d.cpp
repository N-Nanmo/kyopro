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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    ll D;
    cin >> D;
    ll ans = 0;
    vpll S(N);
    vpll T(N);
    vpll ST(N);
    ll mt = 0;
    for(ll i=0; i<N; i++){
        cin >> S[i].first;
        cin >> T[i].first;
        S[i].second = i;
        T[i].second = i;
        ST[i].first = S[i].first;
        ST[i].second = T[i].first;
        mt = max(mt, T[i].first);
    }
    vb B(N, false);
    ll s = 0;
    ll t = 0;
    ll h = 0;
    vll H(mt+1, 0);
    for(ll i=0; i<mt+1-D; i++){
        while(S[s].first == i && !B[S[s].second]){
            if( ST[S[s].second].second <= i+D){
                s++;
                continue;
            }
            h++;
            B[S[s].second] = true;
            while(B[S[s].second]){
                s++;
            }
        }
        while(T[t].first == i+D && !B[T[t].second]){
            while(B[T[t].second]){
                t++;
            }
            h--;
            B[T[t].second] = true;
        }
        H[i] = h;
    }
    for(ll i=0; i<=mt-D; i++){
        ans += H[i] * (H[i]-1) / 2;
    }
    cout << ans << "\n";
    for(int i=0; i<=mt+1; i++){
        cout << H[i] << "\n";
    }
}