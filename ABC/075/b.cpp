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
    int H, W;
    cin >> H >> W;
    vvc G(H, vc(W));
    cin >> G;
    vvc ans(H, vc(W, '0'));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(G[i][j] == '#'){
                ans[i][j] = '#';
                if(0 < i && ans[i-1][j] != '#') ans[i-1][j]++;
                if(0 < j && ans[i][j-1] != '#') ans[i][j-1]++;
                if(i+1 < H && ans[i+1][j] != '#') ans[i+1][j]++;
                if(j+1 < W && ans[i][j+1] != '#') ans[i][j+1]++;
                if(0 < i && 0 < j && ans[i-1][j-1] != '#')ans[i-1][j-1]++;
                if(0 < i && j+1 < W && ans[i-1][j+1] != '#') ans[i-1][j+1]++;
                if(i+1 < H && 0 < j && ans[i+1][j-1] != '#') ans[i+1][j-1]++;
                if(i+1 < H && j+1 < W && ans[i+1][j+1] != '#') ans[i+1][j+1]++;
            }
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}