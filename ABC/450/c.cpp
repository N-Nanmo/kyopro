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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll H, W;
    cin >> H >> W;
    vvc S(H, vc(W));
    cin >> S;
    vvb B(H, vb(W, false));
    ll ans = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            bool Hb = false;
            if(B[i][j] == true) continue;
            B[i][j] = true;
            if(S[i][j] == '#'){
                continue;
            }else if(i==0||i==H-1||j==0||j==W-1){
                Hb = true;
            }
            queue<pair<ll, ll>> que;
            que.push(make_pair(i, j));
            while(!que.empty()){
                pair<int, int> crr = que.front();
                int x = crr.first;
                int y = crr.second;
                que.pop();

                for(int dir = 0; dir<4; dir++){
                    int nx = dx[dir] + x;
                    int ny = dy[dir] + y;
                    if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if(S[nx][ny] == '#') continue;
                    if(B[nx][ny] == false){
                        B[nx][ny] = true;
                        que.push(make_pair(nx, ny));
                        if(nx == 0 || nx == H-1|| ny == 0 || ny == W-1) Hb = true;
                    }
                }
            }
            if(!Hb) ans++;
        }
    }
    cout << ans << "\n";
}