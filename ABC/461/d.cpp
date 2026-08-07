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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, K;
    cin >> H >> W >> K;
    vvll G(H, vll(W));
    for(int i=0; i<H; i++){
        string S;
        cin >> S;
        for(int j=0; j<W; j++){
            G[i][j] = S[j]-'0';
        }
    }
    for(int i=0; i<H; i++){
        for(int j=1; j<W; j++){
            G[i][j] += G[i][j-1];
        }
    }
    for(int j=0; j<W; j++){
        for(int i=1; i<H; i++){
            G[i][j] += G[i-1][j];
        }
    }
    ll ans = 0;
    for(int is=0; is<H; is++){
        for(int ie=is; ie<H; ie++){
            int je = 0;
            for(int js=0; js<W && je<W;){
                int crr = 0;
                crr += G[ie][je];
                if(is != 0 && js != 0) crr += G[is-1][js-1];
                if(is != 0) crr -= G[is-1][je];
                if(js != 0) crr -= G[ie][js-1];
                if(crr == K){
                    ans++;
                    je++;
                }else if(crr < K){
                    je++;
                }else if(crr > K){
                    js++;
                }
            }
        }
    }
    cout << ans << "\n";
}