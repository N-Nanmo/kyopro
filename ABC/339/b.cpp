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
    ll H, W, N;
    cin >> H >> W >> N;
    vvb G(H, vb(W, false));
    ll x = 0, y = 0;
    ll dir = 0;
    for(int i=0; i<N; i++){
        if(G[y][x]){
            G[y][x] = false;
            if(dir == 0){
                dir = 3;
            }else{
                dir--;
            }
        }else{
            G[y][x] = true;
            dir = (dir+1)%4;
        }
        if(dir == 0){
            if(y == 0){
                y = H-1;
            }else{
                y--;
            }
        }else if(dir == 1){
            if(x == W-1){
                x = 0;
            }else{
                x++;
            }
        }else if(dir == 2){
            if(y == H-1){
                y = 0;
            }else{
                y++;
            }
        }else{
            if(x == 0){
                x = W-1;
            }else{
                x--;
            }
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(G[i][j]){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << "\n";
    }
}