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
    string _S;
    cin >> _S;
    string S(_S.size()*2+1, '#');
    for(int i=0; i<_S.size(); i++) S[2*i+1] = _S[i];
    vll M(S.size(), 1);
    M[1] = 2;
    ll r = 2;
    ll i = 2;
    while(i < _S.size()){
        bool b = false;
        while(0 <= i - r && i + r < _S.size()){
            r++;
            if(S[i-r] != S[i+r]){
                if(b) break;
                b = true;
            }
        }
        M[i] = r;

        ll k = 1;
        while(0 <= i - k && k + M[i-k] < r){
            M[i+k] = M[i - k];
            k++;
        }
        
        i += k;
        r -= k;

        for(int j=0; j<_S.size(); j++){
            if(j%2 == 0){
                M[i] = (M[i] - 1) / 2;
            }else{
                M[i] /= 2;
            }
        }
    }
    ll ans = 0;
    for(int i=0; i<S.size(); i++){
        ans += M[i];
    }
    cout << ans << "\n";
}