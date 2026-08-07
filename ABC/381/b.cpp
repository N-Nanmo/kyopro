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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(). (x).rend()
template <typename T>
inline istream& operator >> (istream& is, vector<T>& v){
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    for(size_t i=0; i<v.size(); i++){
        is >> v[i];
    }
    return is;
}
template <typename T>
inline istream& operator >> (istream& is, vector<pair<T,T>>& v){
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    for(size_t i=0; i<v.size(); i++){
        is >> v[i].first >> v[i].second;
    }
    return is;
}
template <typename T>
inline istream& operator >> (istream& is, vector<vector<T>>& v){
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    for(size_t i=0; i<v.size(); i++){
        for(size_t j=0; j<v[i].size(); j++){
            is >> v[i][j];
        }
    }
    return is;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    vb B(26, false);
    if(S.size()%2 == 1){
        cno;
        return 0;
    }
    for(int i=0; i<S.size(); i+=2){
        if(S[i] != S[i+1]){
            cno;
            return 0;
        }
        if(B[S[i]-'a']){
            cno;
            return 0;
        }
        B[S[i]-'a'] = true;
    }
    cyes;
}