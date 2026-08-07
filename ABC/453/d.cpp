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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vvc G(H, vc(W));
    cin >> G;
    int sx = 0;
    int sy = 0;
    vi dx = {0, 1, 0, -1};
    vi dy = {1, 0, -1, 0};
    for(int i=0; i<H; i++){
        bool flag = false;
        for(int j=0; j<W; j++){
            if(G[i][j] == 'S'){
                sx = j;
                sy = i;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    vvb visited(H, vb(W, false));
    visited[sy][sx] = true;
    vvc lastAction(H, vc(W, 'N'));
    vector<vpi> parent(H, vpi(W, make_pair(-1, -1)));
    queue<pair<pi, int>> q;
    q.emplace(make_pair(make_pair(sx, sy), -1));
    bool gf = false;
    int tx = -1;
    int ty = -1;
    while(!q.empty()){
        auto crr = q.front();
        q.pop();
        int x = crr.first.first;
        int y = crr.first.second;
        int nd = crr.second;
        for(int dir = 0; dir < 4; dir++){
            if(nd == dir) continue;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if(visited[ny][nx]) continue;
            if(G[ny][nx] == '#') continue;
            if(G[ny][nx] == '.'){
                q.emplace(make_pair(make_pair(nx, ny), -1));
                visited[ny][nx] = true;
            }else if(G[ny][nx] == 'o'){
                int nnx = nx + dx[dir];
                int nny = ny + dy[dir];
                while(nnx >= 0 && nnx < W && nny >= 0 && nny < H){
                    if(G[nny][nnx] != 'o'){
                        q.emplace(make_pair(make_pair(nnx, nny), -1));
                        break;
                    }
                    nnx += dx[dir];
                    nny += dy[dir];
                }
            }else if(G[ny][nx] == 'x'){
                q.emplace(make_pair(make_pair(nx, ny),dir));
            }else if(G[ny][nx] == 'G'){
                gf = true;
                tx = nx;
                ty = ny;
                parent[ny][nx] = make_pair(x, y);
                break;
            }
            parent[ny][nx] = make_pair(x, y);
        }
        if(gf){
            break;
        }
    }
    if(gf){
        cyes;
        vpi route;
        int x = tx;
        int y = ty;
        route.emplace_back(make_pair(x, y));
        while(true){
            pi tmp = parent[y][x];
            x = tmp.first;
            y = tmp.second;
            if(x == -1) break;
            route.emplace_back(tmp);
        }
        reverse(all(route));
        for(int i=1; i<route.size(); i++){
            if(route[i-1].first-1 == route[i].first){
                cout << 'L';
            }else if(route[i-1].first+1 == route[i].first){
                cout << 'R';
            }else if(route[i-1].second-1 == route[i].second){
                cout << 'U';
            }else{
                cout << 'D';
            }
        }
        return 0;
    }else{
        cno;
    }
}