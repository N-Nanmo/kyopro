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
    int H, W, D;
    cin >> H >> W >> D;
    vvc G(H, vc(W));
    cin >> G;
    int ans = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for(int I=0; I<H; I++){
                for(int J=0; J<W; J++){
                    if(G[i][j] == '#' || G[I][J] == '#')continue;
                    vvc tmp = G;
                    int cnt = 0;
                    for(int i2=max(0, i-D); i2<=min(H-1, i+D); i2++){
                        for(int j2=max(0, j-D); j2<=min(W-1, D+j); j2++){
                            if(abs(i2-i)+abs(j2-j) > D)continue;
                            if(tmp[i2][j2] == '.'){
                                tmp[i2][j2] = '#';
                                cnt++;
                            }
                        }
                    }
                    for(int i2=max(0, I-D); i2<=min(H-1, I+D); i2++){
                        for(int j2=max(0, J-D); j2<=min(W-1, D+J); j2++){
                            if(abs(i2-I)+abs(j2-J) > D)continue;
                            if(tmp[i2][j2] == '.'){
                                tmp[i2][j2] = '#';
                                cnt++;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout << ans << "\n";
}