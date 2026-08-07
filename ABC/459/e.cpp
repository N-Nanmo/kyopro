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
const double PI = 3.14159265359;

bool exe(vector<pair<ll, pll>> &T, ll crr, ll &num){
    T[crr].first -= num;
    if(T[crr].first < 0) return false;
    if(T[crr].second.first == -1) return true;
    return exe(T, T[crr].second.first, num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vector<pair<ll, pll>> kT(N, make_pair(0, make_pair(-1, -1)));
    kT[0].second.first = -1;
    for(int i=1; i<N; i++){
        cin >> kT[i].second.first;
        kT[i].second.first--;
        kT[kT[i].second.first].second.second = i;
    }
    for(int i=0; i<N; i++){
        cin >> kT[i].first;
    }
    vector<pair<ll, pll>> T(N, make_pair(0, make_pair(-1, -1)));
    T = kT;
    for(int i=1; i<N; i++){
        int crr = i;
        while(1){
            T[kT[crr].second.first].first += kT[i].first;
            if(kT[crr].second.first == 0) break;
            crr = kT[crr].second.first;
        }
    }

    modint998244353 ans = 1;
    for(int i=0; i<N; i++){
        ll d = 0;
        cin >> d;
        int tmp = 1;
        if(T[i].first-d < 0) cout << 0 << "\n";
        for(int j=T[i].first; j > T[i].first-d; j--){
            tmp *= j;
        }
        for(int j=d; j > 0; j--){
            tmp /= j;
        }
        ans *= tmp;
        if(exe(T, i, d) == false){
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << ans.val() << "\n";
}