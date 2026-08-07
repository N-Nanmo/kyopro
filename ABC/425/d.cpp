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
    vvc T(H, vc(W));
    queue<pi> q;
    int ans = 0;
    vpi move = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> T[i][j];
            if(T[i][j] == '#'){
                q.push({i, j});
                ans++;
            }
        }
    }
    queue<pi> next_q;
    while(true){
        queue<pi> next_H;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            T[x][y] = '#';
            q.pop();
            for(auto m : move){
                int nx = x + m.first;
                int ny = y + m.second;
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(T[nx][ny] == '#') continue;
                int cnt = 0;
                for(auto mm : move){
                    int nnx = nx + mm.first;
                    int nny = ny + mm.second;
                    if(nnx < 0 || nnx >= H || nny < 0 || nny >= W) continue;
                    if(T[nnx][nny] == '#') cnt++;
                }
                if(cnt == 1){
                    ans++;
                    next_q.push({nx, ny});
                }
            }
        }
        if(next_q.empty()) break;
        q = next_q;
        next_q = queue<pi>();
    }
    cout << ans << "\n";
}