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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, Q;
    cin >> N >> Q;
    vpll CP(Q);
    cin >> CP;
    vector<pll> cs(N, make_pair(-1, -1));
    for(int i=Q-1; i>=0; i--){
        int a = CP[i].first;
        int b = CP[i].second;
        a--;
        b--;
        if(cs[b].first == -1 && cs[a].second == -1){
            cs[a].second = b;
            cs[b].first = a;
        }
    }
    for(int i=0; i<N; i++){
        if(cs[i].first == -1 && cs[i].second == -1){
            cout << 1 << " \n"[i==N-1];
        }else if(cs[i].second != -1){
            cout << 0 << " \n"[i==N-1];
        }else{
            ll cnt = 2;
            ll crr = cs[i].first;
            while(cs[crr].first != -1){
                cnt++;
                crr = cs[crr].first;
            }
            cout << cnt << " \n"[i==N-1];
        }
    }
}