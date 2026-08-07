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
    // 貪欲逐次最適化: 各区間について候補最短経路を複数生成し、累積セル出発回数の最大値を最小化する経路を選択
    std::mt19937_64 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    vector<vector<int>> depart(N, vector<int>(N,0)); // セルからの出発回数
    auto eval_with_path = [&](const vector<pi>& path)->int{
        int mx = 0;
        // 現状の最大
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) mx = max(mx, depart[i][j]);
        // 仮に追加する出発増分を反映
        for(size_t k=0; k+1 < path.size(); k++){
            int r = path[k].first, c = path[k].second;
            int newVal = depart[r][c] + 1;
            if(newVal > mx) mx = newVal;
        }
        return mx;
    };
    // 最短距離条件を満たしつつ「既訪問回数の小さいマスを多く踏む」経路選択
    // dist 計算後、dist[r][c]+1=dist[nr][nc] を満たす遷移のみ使い、コスト= depart[r][c] の最小経路(Dijkstra)を構築
    for(int seg=0; seg<K-1; seg++){
        pi S={(int)goal[seg].first,(int)goal[seg].second};
        pi G={(int)goal[seg+1].first,(int)goal[seg+1].second};
        // BFS で距離
        vector<vector<int>> dist(N, vector<int>(N,-1));
        queue<pi> qd; dist[S.first][S.second]=0; qd.push(S);
        int dr[4]={-1,1,0,0}; int dc[4]={0,0,-1,1};
        while(!qd.empty()){
            auto [r,c]=qd.front(); qd.pop();
            if(r==G.first && c==G.second) break;
            for(int k=0;k<4;k++){
                int nr=r+dr[k], nc=c+dc[k];
                if(nr<0||nr>=N||nc<0||nc>=N) continue;
                if(!can_move(r,c,nr,nc,N,V,H)) continue;
                if(dist[nr][nc]!=-1) continue;
                dist[nr][nc]=dist[r][c]+1;
                qd.push({nr,nc});
            }
        }
        if(dist[G.first][G.second]==-1) continue; // 到達不可
        int targetDist = dist[G.first][G.second];
        // Dijkstra (実質幅優先層内の最小重み) for shortest-layer graph
        const long long INFLL = (1LL<<60);
        vector<vector<long long>> dp(N, vector<long long>(N, INFLL));
        vector<vector<pi>> parent(N, vector<pi>(N, {-1,-1}));
        using Node = tuple<long long,int,int>; // cost,r,c
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dp[S.first][S.second]=0; pq.emplace(0,S.first,S.second);
        while(!pq.empty()){
            auto [cost,r,c]=pq.top(); pq.pop();
            if(cost!=dp[r][c]) continue;
            if(r==G.first && c==G.second) break;
            for(int k=0;k<4;k++){
                int nr=r+dr[k], nc=c+dc[k];
                if(nr<0||nr>=N||nc<0||nc>=N) continue;
                if(!can_move(r,c,nr,nc,N,V,H)) continue;
                // shortest constraint
                if(dist[r][c]==-1 || dist[nr][nc]==-1) continue;
                if(dist[nr][nc] != dist[r][c]+1) continue;
                long long ncost = cost + depart[r][c]; // 出発コスト: 現在セルの使用回数を加算
                if(ncost < dp[nr][nc]){
                    dp[nr][nc]=ncost; parent[nr][nc]={r,c};
                    pq.emplace(ncost,nr,nc);
                }
            }
        }
        // 経路復元
        vector<pi> path;
        if(dp[G.first][G.second]==INFLL){
            // フォールバック: 通常最短経路
            path = bfs_path(N,V,H,S,G);
        }else{
            for(pi cur=G; cur.first!=-1; cur=parent[cur.first][cur.second]) path.push_back(cur);
            reverse(path.begin(), path.end());
        }
        // 反映
        for(size_t j=0;j+1<path.size();j++){
            int r1=path[j].first, c1=path[j].second; int r2=path[j+1].first, c2=path[j+1].second;
            char dir='U';
            if(r2==r1-1&&c2==c1) dir='U'; else if(r2==r1+1&&c2==c1) dir='D'; else if(r2==r1&&c2==c1-1) dir='L'; else if(r2==r1&&c2==c1+1) dir='R';
            moves.push_back({r1,c1,r2,c2,dir});
            CellMove[r1][c1].push_back(dir);
            depart[r1][c1]++;
        }
    }

    //各マスの最大使用回数を調べる
    int colorsize = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            colorsize = max(colorsize, (int)CellMove[i][j].size());
        }
    }

    // 出力ヘッダ: C=最大訪問回数+1(色0..max), Q=状態数(位置数), M=移動数
    int C = max(1, colorsize);
    // 状態ID再割当: 開始マス(goal[0])を状態0、それ以外を1..に
    vector<vector<int>> stateId(N, vector<int>(N, -1));
    int sr = (int)goal[0].first, sc = (int)goal[0].second;
    int nid = 1; stateId[sr][sc] = 0;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(!(i==sr && j==sc)) stateId[i][j] = nid++;
    int Q = N*N; // 状態数は全マス
    int M = (int)moves.size();
    cout << C << ' ' << Q << ' ' << M << '\n';

    // 初期盤面色: (0,0)=1 それ以外=0 （開始マスが(0,0)でなければ state0 は色0）
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j) cout << ' ';
            if(i==0 && j==0) cout << 1; else cout << 0;
        }
        cout << '\n';
    }

    // 規則出力: (現色, 現状態, 次色, 次状態, 方向)
    // (0,0)のみ色列 1->2->.. 他は 0->1->..
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int q = stateId[i][j];
            int useCnt = (int)CellMove[i][j].size();
            for(int col=0; col<useCnt; col++){
                bool isTL = (i==0 && j==0);
                int curColor = isTL ? (col+1) : col;
                int nextColorProg = isTL ? (col+2) : (col+1);
                int nextColor = (col+1 < useCnt) ? nextColorProg : curColor; // 最終は据え置き
                char d = CellMove[i][j][col];
                int ni=i, nj=j;
                if(d=='U') ni=i-1; else if(d=='D') ni=i+1; else if(d=='L') nj=j-1; else if(d=='R') nj=j+1;
                int S = stateId[ni][nj];
                cout << curColor << ' ' << q << ' ' << nextColor << ' ' << S << ' ' << d << '\n';
            }
        }
    }
}