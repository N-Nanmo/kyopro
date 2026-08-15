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
vi dx = {0, -1, 0, 1};
vi dy = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R, C;
    cin >> R >> C;
    pi s;
    cin >> s.first >> s.second;
    s.first--;
    s.second--;
    pi g;
    cin >> g.first >> g.second;
    g.first--;
    g.second--;
    if(s == g){
        cout << 0 << "\n";
        return 0;
    }
    vvc G(R, vc(C));
    cin >> G;
    queue<pi> q;
    q.emplace(s);
    G[s.first][s.second] = 0;
    vvi D(R, vi(C, -1));
    D[s.first][s.second] = 0;
    while(!q.empty()){
        pi crr = q.front();
        q.pop();
        for(int d=0; d<4; d++){
            int x = crr.second + dx[d];
            int y = crr.first + dy[d];
            if(x < 0 || C <= x || y < 0 || R <= y || G[y][x] != '.' || D[y][x] != -1) continue;
            if(x == g.second && y == g.first){
                cout << D[crr.first][crr.second]+ 1 << "\n";
                return 0;
            }
            D[y][x] = D[crr.first][crr.second]+1;
            q.emplace(make_pair(y, x));
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << G[i][j];
        }
        cout << "\n";
    }
    cout << -1 << "\n";
}