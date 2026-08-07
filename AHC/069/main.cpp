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
inline istream& operator>>(istream& is, vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i];
    }
    return is;
}
template <typename T, typename U>
inline istream& operator>>(istream& is, vector<pair<T, U>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i].first >> v[i].second;
    }
    return is;
}
template <typename T>
inline istream& operator>>(istream& is, vector<vector<T>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            is >> v[i][j];
        }
    }
    return is;
}
template <typename T, typename U, typename S, typename V>
inline istream& operator>>(istream& is,
                           vector<pair<pair<T, U>, pair<S, V>>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i].first.first >> v[i].first.second >> v[i].second.first >>
            v[i].second.second;
    }
    return is;
}
const double PI = 3.14159265359;

// 引用:https://qiita.com/sorachandu/items/041169d34b9f9b99bcf7
// std::chronoを利用した時間計測用クラス
class Timer{
    chrono::system_clock::time_point start;
    public:
        Timer() : start(chrono::system_clock::now()) {}
    
        double count(){
            chrono::duration<double> Time_ = chrono::system_clock::now() - start;
            return Time_.count();
        }

        bool is_under(double x){
            return (this -> count()) < x;
        }
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Candidate {
    int perimeter;
    vector<pi> cells;
};

bool isRectangleOk(int &x, int &y, int &h, int &w, vvi &blockedSum) {
    int blocked = blockedSum[x + h][y + w] - blockedSum[x + h][y] - blockedSum[x][y + w] + blockedSum[x][y];
    return blocked == 0;
}

bool isFreeCell(const vvll& G, int S, int x, int y, int N){
    return (0 <= x && x < N && 0 <= y && y < N && G[x][y] != -1 && G[x][y] < S);
}

struct GreedyWorkspace {
    vector<pi> cells;
    array<vector<pi>, 5> buckets;
    vi selectedStamp;
    vi frontierStamp;
    vector<unsigned char> touch;
    int currentStamp = 0;

    explicit GreedyWorkspace(int N)
        : selectedStamp(N * N, 0),
          frontierStamp(N * N, 0),
          touch(N * N, 0) {
        cells.reserve(150);
        for(auto& bucket : buckets){
            bucket.reserve(150 * 4);
        }
    }

    void beginSearch(){
        if(currentStamp == numeric_limits<int>::max()){
            fill(all(selectedStamp), 0);
            fill(all(frontierStamp), 0);
            currentStamp = 1;
        }else{
            currentStamp++;
        }

        cells.clear();
        for(auto& bucket : buckets){
            bucket.clear();
        }
    }

    bool isSelected(int id) const {
        return selectedStamp[id] == currentStamp;
    }
};

// 成功時は周長を、失敗時は -1 を返す。選んだマスは workspace.cells に残す。
int makeGreedyCandidate(const vvll& G, int S, int P, int sx, int sy,
                        int N, GreedyWorkspace& workspace){
    if(!isFreeCell(G, S, sx, sy, N)) return -1;
    workspace.beginSearch();

    // 新しく選んだマスの周囲について、領域との接触辺数を1増やす。
    auto pushNeighbors = [&](int x, int y){
        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(!isFreeCell(G, S, nx, ny, N)) continue;

            int id = nx * N + ny;
            if(workspace.isSelected(id)) continue;

            if(workspace.frontierStamp[id] != workspace.currentStamp){
                workspace.frontierStamp[id] = workspace.currentStamp;
                workspace.touch[id] = 0;
            }

            workspace.touch[id]++;
            workspace.buckets[workspace.touch[id]].emplace_back(nx, ny);
        }
    };

    workspace.selectedStamp[sx * N + sy] = workspace.currentStamp;
    workspace.cells.emplace_back(sx, sy);
    pushNeighbors(sx, sy);

    int perimeter = 4;

    while((int)workspace.cells.size() < P){
        int chosenX = -1;
        int chosenY = -1;
        int chosenTouch = 0;

        // 接触辺数が多いマスを優先する。
        for(int score=4; score>=1; score--){
            auto& bucket = workspace.buckets[score];

            while(!bucket.empty()){
                auto [x, y] = bucket.back();
                bucket.pop_back();

                int id = x * N + y;
                if(workspace.isSelected(id)) continue;
                if(workspace.frontierStamp[id] != workspace.currentStamp) continue;
                if(workspace.touch[id] != score) continue;

                chosenX = x;
                chosenY = y;
                chosenTouch = score;
                break;
            }

            if(chosenX != -1) break;
        }

        if(chosenX == -1) return -1;

        workspace.selectedStamp[chosenX * N + chosenY] = workspace.currentStamp;
        workspace.cells.emplace_back(chosenX, chosenY);

        // 新しい4辺を加え、既存領域との共有辺を両側から除く。
        perimeter += 4 - 2 * chosenTouch;
        pushNeighbors(chosenX, chosenY);
    }

    return perimeter;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Timer timer;
    // Input
    int N, M;
    double R;
    cin >> N >> M >> R;
    vvll G(N, vll(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                G[i][j] = 0;
            } else {
                G[i][j] = -1;
            }
        }
    }

    // 全ターン・全始点の貪欲探索で使い回す。
    GreedyWorkspace greedyWorkspace(N);

    for (int m = 0; m < M; m++) {

        // Input
        int I, S, T, P, V;
        cin >> I >> S >> T >> P >> V;

        bool finished = false;

        // 累積和
        vvi blockedSum(N + 1, vi(N + 1, 0));

        //最小周長
        int lowerPerimeter = 2 * (int)ceil(2.0 * sqrt(P));

        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                int blocked = (G[x][y] == -1 || G[x][y] >= S) ? 1 : 0;
                blockedSum[x + 1][y + 1] = blockedSum[x + 1][y] + blockedSum[x][y + 1] - blockedSum[x][y] + blocked;
            }
        }

        cout << 0 << "\n";
        optional<Candidate> best;

        auto updateBest = [&](Candidate&& candidate){
            if (!best || candidate.perimeter < best->perimeter || (candidate.perimeter == best->perimeter && candidate.cells < best->cells)) {
                best = move(candidate);
            }
        };
        
        // 長方形で考える
        for(int h=1; h*h <= P; h++){
            if(P%h != 0) continue;

            int w = P/h;

            vpi shapes{{h, w}};
            if(h != w) shapes.emplace_back(w, h);
            for(auto [rh, rw] : shapes){

                for(int i=0; i+rh <= N; i++){
                    for(int j=0; j+rw <= N; j++){
                        if(!isRectangleOk(i, j, rh, rw, blockedSum)) continue;

                        vector<pi> cells;
                        cells.reserve(P);

                        for(int x=i; x<i+rh; x++){
                            for(int y=j; y<j+rw; y++){
                                cells.emplace_back(x, y);
                            }
                        }

                        updateBest({2 * (rh + rw), move(cells)});
                        if((best && best->perimeter == lowerPerimeter) || finished){
                            finished = true;
                            break;
                        }
                    }
                    if(finished) break;
                }
                if(finished) break;
            }
            if(finished) break;
        }

        bool needGreedy = !best || best->perimeter > lowerPerimeter+3;
        // 辺数貪欲で考える
        if(needGreedy){
            // 各空きマスが属する連結成分のサイズを求める。
            // サイズが P 未満なら、その成分から P マスの連結領域は作れない。
            vvi componentSize(N, vi(N, 0));
            vvb visited(N, vb(N, false));

            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    if(visited[x][y] || !isFreeCell(G, S, x, y, N)) continue;

                    queue<pi> que;
                    vector<pi> component;
                    visited[x][y] = true;
                    que.emplace(x, y);

                    while(!que.empty()){
                        auto [cx, cy] = que.front();
                        que.pop();
                        component.emplace_back(cx, cy);

                        for(int d = 0; d < 4; d++){
                            int nx = cx + dx[d];
                            int ny = cy + dy[d];

                            if(!isFreeCell(G, S, nx, ny, N)) continue;
                            if(visited[nx][ny]) continue;

                            visited[nx][ny] = true;
                            que.emplace(nx, ny);
                        }
                    }

                    int size = component.size();
                    for(auto [cx, cy] : component){
                        componentSize[cx][cy] = size;
                    }
                }
            }

            for(int sx = 0; sx < N; sx++){
                for(int sy = 0; sy < N; sy++){
                    if(componentSize[sx][sy] < P) continue;
                    int perimeter = makeGreedyCandidate(
                        G, S, P, sx, sy, N, greedyWorkspace
                    );

                    // 最良候補を更新するときだけセル列をコピーする。
                    if(perimeter != -1 &&
                       (!best || perimeter < best->perimeter ||
                        (perimeter == best->perimeter &&
                         greedyWorkspace.cells < best->cells))){
                        updateBest({perimeter, greedyWorkspace.cells});
                    }
                    if((best && best->perimeter == lowerPerimeter) || finished){
                        finished = true;
                        break;
                    }
                }
                if(finished) break;
            }
        }   

        // Output
        if(!best){
            cout << "No\n" << flush;
            continue;
        }
        cout << "Yes" << "\n";

        for(auto [x, y] : best->cells){
            G[x][y] = T;
            cout << x << ' ' << y << "\n";
        }

        cout << flush;
    }
    cerr << timer.count() << "\n";
}
