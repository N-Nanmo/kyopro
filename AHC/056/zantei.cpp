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



// 最短経路を復元するBFS
// - 入力: N(グリッドサイズ), V(縦の壁情報: (N-1)×N), H(横の壁情報: N×(N-1)), s(開始), g(終了)
// - 壁の意味: '1' なら通行不可、'0' なら通行可（仮定。問題仕様に合わせて調整してください）
// - 座標系: (r,c) は 0-index 想定。入力が1-indexなら呼び出し側で-1補正してください。
// - 出力: s→g の最短経路の座標列（到達不能なら空ベクタ）
static inline bool can_move(int r, int c, int nr, int nc, int N, const vvc& V, const vvc& H){
    // 盤外はここではチェックしない（呼び出し側で実施）
    if(nr == r-1 && nc == c){
        // 上に行く: r-1 と r の間の縦壁 -> V[r-1][c]
        return V[r-1][c] != '1';
    }
    if(nr == r+1 && nc == c){
        // 下に行く: r と r+1 の間の縦壁 -> V[r][c]
        return V[r][c] != '1';
    }
    if(nr == r && nc == c-1){
        // 左に行く: c-1 と c の間の横壁 -> H[r][c-1]
        return H[r][c-1] != '1';
    }
    if(nr == r && nc == c+1){
        // 右に行く: c と c+1 の間の横壁 -> H[r][c]
        return H[r][c] != '1';
    }
    return false; // 斜めなどは不可
}

static vector<pi> bfs_path(int N, const vvc& V, const vvc& H, pi s, pi g){
    const int INF = 1e9;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<vector<pi>> parent(N, vector<pi>(N, {-1,-1}));
    queue<pi> q;
    auto inb = [&](int r, int c){ return 0 <= r && r < N && 0 <= c && c < N; };

    dist[s.first][s.second] = 0;
    q.push(s);
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    while(!q.empty()){
        auto [r,c] = q.front(); q.pop();
        if(r == g.first && c == g.second) break; // 最短距離が確定
        for(int k=0; k<4; k++){
            int nr = r + dr[k], nc = c + dc[k];
            if(!inb(nr,nc)) continue;
            // 壁判定
            if(dr[k] == -1){ // 上
                if(r-1 < 0) continue;
                if(!can_move(r,c,nr,nc,N,V,H)) continue;
            }else if(dr[k] == 1){ // 下
                if(r >= N-1) continue;
                if(!can_move(r,c,nr,nc,N,V,H)) continue;
            }else if(dc[k] == -1){ // 左
                if(c-1 < 0) continue;
                if(!can_move(r,c,nr,nc,N,V,H)) continue;
            }else{ // 右
                if(c >= N-1) continue;
                if(!can_move(r,c,nr,nc,N,V,H)) continue;
            }
            if(dist[nr][nc] != INF) continue;
            dist[nr][nc] = dist[r][c] + 1;
            parent[nr][nc] = {r,c};
            q.push({nr,nc});
        }
    }

    vector<pi> path;
    if(dist[g.first][g.second] == INF) return path; // 空（到達不可）
    for(pi cur = g; cur.first != -1; cur = parent[cur.first][cur.second]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //入力受け取り
    int N, K, T;
    cin >> N >> K >> T;
    vvc V(N-1, vector<char>(N));     // h: (N-1)×N, between (i,j) and (i+1,j)
    vvc H(N, vector<char>(N-1));     // v: N×(N-1), between (i,j) and (i,j+1)
    vpll goal(K);
    // 入力仕様: 先に v (N 行×(N-1 列)), 次に h ((N-1) 行×N 列)
    for(int i=0; i<N; i++)   for(int j=0; j<N-1; j++) cin >> H[i][j]; // v -> H
    for(int i=0; i<N-1; i++) for(int j=0; j<N; j++)   cin >> V[i][j]; // h -> V
    for(int i=0; i<K; i++){
        cin >> goal[i].first >> goal[i].second;
    }
    // 目的地ごとに最短経路を繋いだ全ステップを作成
    struct Move{int r,c,nr,nc; char d;};
    vector<Move> moves;
    vector<vector<vector<char>>> CellMove(N, vector<vector<char>>(N));
    // 経路に含まれるマスのマーキング（非経路は色0固定にするため）
    vvb used(N, vb(N, false));
    for(int i=0; i<K-1; i++){
        pi start = {(int)goal[i].first, (int)goal[i].second};
        pi end   = {(int)goal[i+1].first, (int)goal[i+1].second};
        auto path = bfs_path(N, V, H, start, end);
        for(const auto &p: path){ used[p.first][p.second] = true; }
        for(size_t j=0; j + 1 < path.size(); j++){
            int r1 = path[j].first;
            int c1 = path[j].second;
            int r2 = path[j+1].first;
            int c2 = path[j+1].second;
            char dir='U';
            if(r2 == r1-1 && c2 == c1) dir='U';
            else if(r2 == r1+1 && c2 == c1) dir='D';
            else if(r2 == r1 && c2 == c1-1) dir='L';
            else if(r2 == r1 && c2 == c1+1) dir='R';
            moves.push_back({r1,c1,r2,c2,dir});
            CellMove[r1][c1].emplace_back(dir);
        }
    }

    //各マスの最大使用回数を調べる
    int colorsize = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            colorsize = max(colorsize, (int)CellMove[i][j].size());
        }
    }

    // 出力: C=各マスの最大使用回数, Q=N*N, M=総移動数
    int C = colorsize + 1;
    int Q = N*N;
    int M = (int)moves.size();
    cout << C << " " << Q << " " << M << "\n";

    // 盤面の色: 最初はi=0,j=0以外0に初期化
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j) cout << ' ';
            if(i == 0 && j == 0) cout << 1;
            else cout << 0;
        }
        cout << "\n";
    }

    bool first_move = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int col=0; col<(int)CellMove[i][j].size(); col++){
                if(i == 0 && j == 0) cout << col + 1 << ' ';
                else cout << col << ' ';
                if(goal[0].first * N + goal[0].second == i * N + j && first_move){
                    first_move = false;
                    cout << 0 << " ";
                }else{
                    cout << i * N + j << ' ';
                }
                if(i == 0 && j == 0 && col+2 < colorsize) cout << col + 2 << " ";
                else if(col+1 < colorsize) cout << col + 1 << " ";
                else cout << col << " ";
                if(CellMove[i][j][col] == 'U') cout << i * N + j - N << " ";
                else if(CellMove[i][j][col] == 'D') cout << i * N + j + N << " ";
                else if(CellMove[i][j][col] == 'L') cout << i * N + j - 1 << " ";
                else if(CellMove[i][j][col] == 'R') cout << i * N + j + 1 << " ";
                cout << CellMove[i][j][col] << "\n";
            }
        }
    }
}