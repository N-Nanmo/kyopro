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
    ull T;
    cin >> T;
    while(T--){
        vpll P(4);
        for(int i=0; i<4; i++){
            ll a, b;
            cin >> a >> b;
            P[i].first = a;
            P[i].second = b;
        }
        if((P[1].second-P[0].second)*(P[3].first-P[2].first) == (P[1].first-P[0].first)*(P[3].second-P[2].second) && !((P[2].second+P[3].second-P[1].second-P[0].second)/gcd((P[2].second+P[3].second-P[1].second-P[0].second), (P[4].first+P[3].first-P[0].first-P[1].first))*(P[1].second-P[0].second) == (P[4].first+P[3].first-P[0].first-P[1].first)/gcd((P[2].second+P[3].second-P[1].second-P[0].second), (P[4].first+P[3].first-P[0].first-P[1].first))*(P[0].first-P[1].first))){
            cno;
        }else{
            cyes;
        }
    }
}