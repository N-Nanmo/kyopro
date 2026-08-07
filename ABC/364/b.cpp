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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll H, W;
    cin >> H >> W;
    ll x, y;
    cin >> y >> x;
    y--;
    x--;
    vvc C(H, vc(W));
    cin >> C;
    string S;
    cin >> S;
    for(int i=0; i<S.size(); i++){
        if(S[i] == 'U' && y-1 >= 0 && C[y-1][x] != '#'){
            y--;
        }else if(S[i] == 'D' && y+1 < H && C[y+1][x] != '#'){
            y++;
        }else if(S[i] == 'L' && x-1 >= 0 && C[y][x-1] != '#'){
            x--;
        }else if(S[i] == 'R' && x+1 < W && C[y][x+1] != '#'){
            x++;
        }
    }
    cout << y+1 << " " << x+1 << "\n";
}