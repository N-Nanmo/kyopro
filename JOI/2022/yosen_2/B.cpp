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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vvc grid(H, vc(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> grid[i][j];
        }
    }
    int sx=0, sy=0, gx=W-1, gy=H-1;
    queue<pair<int, int>> que;
    vvi dist(H, vi(W, -1));
    dist[0][0] = 0;
    que.push(make_pair(sx, sy));
    vi dx = {-1, 1, 0, 0};
    vi dy = {0, 0, -1, 1};
    while(!que.empty()){
        pair<int, int> crr = que.front();
        int x = crr.first;
        int y = crr.second;
        que.pop();

        for(int d=0; d<4; d++){
            int next_x = x + dx[d];
            int next_y = y + dy[d];
            if(next_x < 0 || next_y < 0 || next_x >= W || next_y >= H) continue;
            if(grid[next_y][next_x] != grid[y][x] && dist[next_y][next_x] == -1){
                que.push(make_pair(next_x, next_y));
                dist[next_y][next_x] = dist[y][x] + 1;
            }
        }
    }
    cout << dist[H-1][W-1] << "\n";
}