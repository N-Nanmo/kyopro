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

class RollbackBoard {
private:
    struct Change {
        int x;
        int y;
        int oldOwner;
    };

    vvi board;
    vector<Change> history;

public:
    explicit RollbackBoard(const vvi& initialBoard)
        : board(initialBoard) {
        history.reserve(10000);
    }

    // 現在の変更履歴位置を保存する。
    int checkpoint() const {
        return (int)history.size();
    }

    // 必ずこの関数を通して盤面を変更する。
    void setCell(int x, int y, int newOwner) {
        if(board[x][y] == newOwner) return;

        history.push_back({
            x,
            y,
            board[x][y]
        });

        board[x][y] = newOwner;
    }

    // checkpoint以降の変更を逆順に戻す。
    void rollback(int checkpoint) {
        while((int)history.size() > checkpoint) {
            Change change = history.back();
            history.pop_back();

            board[change.x][change.y] = change.oldOwner;
        }
    }

    const vvi& get() const {
        return board;
    }
};

constexpr int MAX_MOVE_CANDIDATES = 5; // about -55s
constexpr int MAX_BLOCKERS = 2; // あんまり意味ない

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Candidate {
    int perimeter;
    vector<pi> cells;
};

struct Move {
    int groupId;
    Candidate destination;
};

struct PlacementEvaluation {
    bool feasible = false;

    ll incomingFee = 0;
    ll moveCost = 0;
    ll feeLoss = 0;
    ll netProfit = LLONG_MIN;

    Candidate incoming;
    vector<Move> moves;
};

// 移動先探索をまだ行っていない、到着候補の軽量な評価結果。
// optimisticProfit は既存グループの料金低下を 0 と仮定した利益の上界。
struct MoveCandidateSummary {
    ll optimisticProfit = LLONG_MIN;
    ll moveCost = 0;
    int cachedIndex = -1;
    int perimeter = 0;
    int blockerCount = 0;
    int generationOrder = 0;
    vector<int> blockers;
};

struct GroupInfo{
    bool active = false;

    int departure = 0;
    int people = 0;
    ll value = 0;

    vpi cells;

    int maxPerimeter = 0;
};

struct GreedyWorkspace {
    vector<uint16_t> cellIds;
    array<vector<int>, 5> buckets;
    vi selectedStamp;
    vi frontierStamp;
    vector<unsigned char> touch;
    vector<array<int, 4>> neighbors;
    vector<unsigned char> degree;
    int currentStamp = 0;

    explicit GreedyWorkspace(int N)
        : selectedStamp(N * N, 0),
          frontierStamp(N * N, 0),
          touch(N * N, 0),
          neighbors(N * N),
          degree(N * N, 0) {
        cellIds.reserve(150);
        for(auto& bucket : buckets){
            bucket.reserve(150 * 4);
        }

        // 探索順を保ったまま、境界判定と隣接座標の計算を前処理へ移す。
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                int id = x * N + y;
                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    neighbors[id][degree[id]++] = nx * N + ny;
                }
            }
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

        cellIds.clear();
        for(auto& bucket : buckets){
            bucket.clear();
        }
    }

    bool isSelected(int id) const {
        return selectedStamp[id] == currentStamp;
    }
};

struct BlockerWorkspace {
    vector<int> stamp;
    vector<int> blockers;
    int currentStamp = 0;

    explicit BlockerWorkspace(int M) : stamp(M, 0) {
        blockers.reserve(150);
    }

    void beginSearch(){
        if(currentStamp == numeric_limits<int>::max()){
            fill(stamp.begin(), stamp.end(), 0);
            currentStamp = 1;
        }else{
            currentStamp++;
        }
        blockers.clear();
    }
};

struct CachedIncomingCandidate {
    int perimeter;
    vector<uint16_t> cellIds;
};

struct MoveCandidateCache {
    bool built = false;
    vector<CachedIncomingCandidate> candidates;
    vector<vector<uint16_t>> candidatesContainingCell;

    // 現在の盤面で占有マスと重なる候補だけを列挙するための作業領域。
    vi touchedStamp;
    vi groupStamp;
    vi blockerCount;
    vll moveCost;
    int currentTurnStamp = 0;
    int currentGroupStamp = 0;
};

struct FreeBoardAnalysis {
    vector<unsigned char> available;
    vector<int> componentSize;
    vvi blockedSum;
    array<uint64_t, 40> freeMask{};
    int largestComponent = 0;
};

struct PlacementCacheKey {
    array<uint64_t, 40> freeMask{};
    uint16_t people = 0;

    bool operator==(const PlacementCacheKey& other) const {
        return people == other.people && freeMask == other.freeMask;
    }
};

struct PlacementCacheKeyHash {
    size_t operator()(const PlacementCacheKey& key) const {
        uint64_t hash = 0x9e3779b97f4a7c15ULL ^ key.people;
        for(uint64_t value : key.freeMask){
            hash ^= value + 0x9e3779b97f4a7c15ULL
                    + (hash << 6) + (hash >> 2);
        }
        return (size_t)hash;
    }
};

using PlacementCache = unordered_map<
    PlacementCacheKey,
    optional<Candidate>,
    PlacementCacheKeyHash
>;

bool isRectangleOk(int x, int y, int h, int w, const vvi& blockedSum) {
    int blocked = blockedSum[x + h][y + w] - blockedSum[x + h][y] - blockedSum[x][y + w] + blockedSum[x][y];
    return blocked == 0;
}

bool inside(int& x, int& y, int& N){
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool isFreeCell(const vvi& owner, int& x, int& y, int& N){
    return (inside(x, y, N) && owner[x][y] == -1);
}

bool isLawnCell(const vvi& owner, int& x, int &y, int& N){
    return (inside(x, y, N) && owner[x][y] != -2);
}

ll calcFee(ll V, int P, int perimeter){
    double compactness = 4.0 * sqrt((double)P) / perimeter;

    return llround(V*compactness);
}

// 成功時は周長を、失敗時は-1を返す。選択マスはIDのままworkspaceに残す。
int makeGreedyCandidate(const vector<unsigned char>& available, int P,
                        int startId, GreedyWorkspace& workspace){
    if(!available[startId]) return -1;
    workspace.beginSearch();

    // 新しく選んだマスの周囲について、領域との接触辺数を1増やす。
    auto pushNeighbors = [&](int id){
        for(int k = 0; k < workspace.degree[id]; k++){
            int nextId = workspace.neighbors[id][k];
            if(!available[nextId]) continue;
            if(workspace.isSelected(nextId)) continue;

            if(workspace.frontierStamp[nextId] != workspace.currentStamp){
                workspace.frontierStamp[nextId] = workspace.currentStamp;
                workspace.touch[nextId] = 0;
            }

            workspace.touch[nextId]++;
            workspace.buckets[workspace.touch[nextId]].push_back(nextId);
        }
    };

    workspace.selectedStamp[startId] = workspace.currentStamp;
    workspace.cellIds.push_back((uint16_t)startId);
    pushNeighbors(startId);

    int perimeter = 4;

    while((int)workspace.cellIds.size() < P){
        int chosenId = -1;
        int chosenTouch = 0;

        // 接触辺数が多いマスを優先する。
        for(int score=4; score>=1; score--){
            auto& bucket = workspace.buckets[score];

            while(!bucket.empty()){
                int id = bucket.back();
                bucket.pop_back();

                if(workspace.isSelected(id)) continue;
                if(workspace.frontierStamp[id] != workspace.currentStamp) continue;
                if(workspace.touch[id] != score) continue;

                chosenId = id;
                chosenTouch = score;
                break;
            }

            if(chosenId != -1) break;
        }

        if(chosenId == -1) return -1;

        workspace.selectedStamp[chosenId] = workspace.currentStamp;
        workspace.cellIds.push_back((uint16_t)chosenId);

        // 新しい4辺を加え、既存領域との共有辺を両側から除く。
        perimeter += 4 - 2 * chosenTouch;
        pushNeighbors(chosenId);
    }

    return perimeter;
}

PlacementEvaluation makeNoMoveEvaluation(Candidate candidate, ll V, int P){
    PlacementEvaluation result;

    result.feasible = true;
    result.incomingFee = calcFee(
        V, P, candidate.perimeter
    );

    result.moveCost = 0;
    result.feeLoss = 0;
    result.netProfit = result.incomingFee;

    result.incoming = move(candidate);
    result.moves.clear();

    return result;
}

PlacementEvaluation makeMultiMoveEvaluation(Candidate incoming, vector<Move> moves, const vector<GroupInfo>& groups, ll incomingValue, int incomingPeople, double R){
    PlacementEvaluation result;

    result.incomingFee = calcFee(
        incomingValue,
        incomingPeople,
        incoming.perimeter
    );

    result.moveCost = 0;
    result.feeLoss = 0;

    for(const Move& move : moves){
        const GroupInfo& movingGroup = groups[move.groupId];

        result.moveCost += max(llround(R * movingGroup.value), 1LL);

        ll oldFee = calcFee(
            movingGroup.value, movingGroup.people, movingGroup.maxPerimeter
        );

        int newMaxPerimeter = max(movingGroup.maxPerimeter, move.destination.perimeter);

        ll newFee = calcFee(
            movingGroup.value, movingGroup.people, newMaxPerimeter
        );

        result.feeLoss += oldFee - newFee;
    }

    result.netProfit = result.incomingFee - result.moveCost - result.feeLoss;

    result.incoming = move(incoming);
    result.moves = move(moves);
    result.feasible = true;

    return result;
}

const vector<int>& getsxers(const Candidate& candidate, const vvi& owner,
                               BlockerWorkspace& workspace){
    workspace.beginSearch();

    for(auto [x, y] : candidate.cells){
        int groupId = owner[x][y];

        if(groupId < 0) continue;

        if(workspace.stamp[groupId] == workspace.currentStamp) continue;

        workspace.stamp[groupId] = workspace.currentStamp;

        workspace.blockers.push_back(groupId);
    }

    // 以前の sort + unique と同じID順を保ち、同人数グループの探索順も変えない。
    sort(all(workspace.blockers));
    return workspace.blockers;
}

const vector<int>& getBlockers(const CachedIncomingCandidate& candidate,
                               const vvi& owner, int N,
                               BlockerWorkspace& workspace){
    workspace.beginSearch();

    for(uint16_t cellId : candidate.cellIds){
        int id = cellId;
        int groupId = owner[id / N][id % N];
        if(groupId < 0) continue;
        if(workspace.stamp[groupId] == workspace.currentStamp) continue;

        workspace.stamp[groupId] = workspace.currentStamp;
        workspace.blockers.push_back(groupId);
    }

    sort(all(workspace.blockers));
    return workspace.blockers;
}

Candidate restoreCandidate(const CachedIncomingCandidate& cached, int N){
    Candidate candidate;
    candidate.perimeter = cached.perimeter;
    candidate.cells.reserve(cached.cellIds.size());

    for(uint16_t cellId : cached.cellIds){
        int id = cellId;
        candidate.cells.emplace_back(id / N, id % N);
    }

    return candidate;
}

Candidate restoreCandidate(int perimeter,
                           const vector<uint16_t>& cellIds, int N){
    Candidate candidate;
    candidate.perimeter = perimeter;
    candidate.cells.reserve(cellIds.size());
    for(uint16_t cellId : cellIds){
        int id = cellId;
        candidate.cells.emplace_back(id / N, id % N);
    }
    return candidate;
}

// 1回の盤面走査で、長方形判定・連結成分枝刈り・貪欲探索に必要な情報を作る。
FreeBoardAnalysis analyzeFreeBoard(const vvi& board, int N){
    FreeBoardAnalysis analysis;
    analysis.available.assign(N * N, 0);
    analysis.componentSize.assign(N * N, 0);
    analysis.blockedSum.assign(N + 1, vi(N + 1, 0));

    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            int id = x * N + y;
            bool free = board[x][y] == -1;
            analysis.available[id] = free;
            if(free){
                analysis.freeMask[id >> 6] |= 1ULL << (id & 63);
            }

            int blocked = !free;
            analysis.blockedSum[x + 1][y + 1]
                = analysis.blockedSum[x + 1][y]
                  + analysis.blockedSum[x][y + 1]
                  - analysis.blockedSum[x][y] + blocked;
        }
    }

    vector<unsigned char> visited(N * N, 0);
    vector<int> que(N * N);

    for(int start = 0; start < N * N; start++){
        if(visited[start] || !analysis.available[start]) continue;

        int head = 0;
        int tail = 0;
        que[tail++] = start;
        visited[start] = 1;

        while(head < tail){
            int id = que[head++];
            int x = id / N;
            int y = id % N;

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                int nextId = nx * N + ny;
                if(visited[nextId] || !analysis.available[nextId]) continue;
                visited[nextId] = 1;
                que[tail++] = nextId;
            }
        }

        analysis.largestComponent = max(analysis.largestComponent, tail);
        for(int i = 0; i < tail; i++){
            analysis.componentSize[que[i]] = tail;
        }
    }

    return analysis;
}

optional<Candidate> findBestFreePlacement(
    const FreeBoardAnalysis& analysis, int P, int N,
    GreedyWorkspace& workspace, PlacementCache& cache
){
    PlacementCacheKey key{analysis.freeMask, (uint16_t)P};
    auto cached = cache.find(key);
    if(cached != cache.end()) return cached->second;

    optional<Candidate> best;
    int lowerPerimeter = 2 * (int)ceil(2.0 * sqrt(P));

    auto saveResult = [&]() -> optional<Candidate> {
        // キャッシュ削除は再計算を増やすだけで、探索結果には影響しない。
        if(cache.size() >= 4096) cache.clear();
        cache.emplace(key, best);
        return best;
    };

    // 従来と同じ順序で、まず面積Pの長方形を調べる。
    for(int h = 1; h * h <= P; h++){
        if(P % h != 0) continue;

        int w = P / h;
        vpi shapes{{h, w}};
        if(h != w) shapes.emplace_back(w, h);

        for(auto [rh, rw] : shapes){
            int perimeter = 2 * (rh + rw);
            for(int i = 0; i + rh <= N; i++){
                for(int j = 0; j + rw <= N; j++){
                    if(!isRectangleOk(i, j, rh, rw, analysis.blockedSum)){
                        continue;
                    }

                    if(!best || perimeter < best->perimeter){
                        vector<pi> cells;
                        cells.reserve(P);
                        for(int x = i; x < i + rh; x++){
                            for(int y = j; y < j + rw; y++){
                                cells.emplace_back(x, y);
                            }
                        }
                        best = Candidate{perimeter, move(cells)};
                    }

                    if(best->perimeter == lowerPerimeter){
                        return saveResult();
                    }
                }
            }
        }
    }

    // 始点を調べる。
    for(int sx = 0; sx < N; sx += 3){
        for(int sy = 0; sy < N; sy += 3){
            int startId = sx * N + sy;
            if(analysis.componentSize[startId] < P) continue;

            int perimeter = makeGreedyCandidate(
                analysis.available, P, startId, workspace
            );
            if(perimeter == -1) continue;

            // セル列の復元は最良周長を更新するときだけ行う。
            if(!best || perimeter < best->perimeter){
                best = restoreCandidate(perimeter, workspace.cellIds, N);
            }
            if(best->perimeter == lowerPerimeter){
                return saveResult();
            }
        }
    }

    return saveResult();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //Timer timer;
    // Input
    int N, M;
    double R;
    cin >> N >> M >> R;
    vvi owner(N, vi(N, -1));// 盤面グループ情報 -2:池,-1:空き,0以上:グループ番号
    int freeCellCount = 0;
    int activeGroupCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                owner[i][j] = -2;
            }else{
                freeCellCount++;
            }
        }
    }

    // 池配置は全ターンで不変なので、移動候補生成用の盤面と累積和も使い回す。
    vector<unsigned char> lawnAvailable(N * N, 0);
    vvi pondSum(N + 1, vi(N + 1, 0));
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            int pond = owner[x][y] == -2;
            lawnAvailable[x * N + y] = !pond;
            pondSum[x + 1][y + 1] = pondSum[x + 1][y]
                                      + pondSum[x][y + 1]
                                      - pondSum[x][y] + pond;
        }
    }

    // 全ターン・全始点の貪欲探索で使い回す。
    GreedyWorkspace greedyWorkspace(N);

    // 妨害グループ探索で使い回す。
    BlockerWorkspace blockerWorkspace(M);

    // グループ情報
    vector<GroupInfo> groups(M);

    // 同じ空き盤面・同じPに対する配置探索結果を厳密に再利用する。
    PlacementCache placementCache;
    placementCache.reserve(4096);

    // 池以外の連結成分サイズ
    vvi lawnComponentSize(N, vi(N, 0));
    vvb visitedLawn(N, vb(N, false));

    // 移動ありの到着候補をPについてキャッシュする。Pの最大値150も添字に含む。
    array<MoveCandidateCache, 151> cachedMoveCandidates;

    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(visitedLawn[x][y] || !isLawnCell(owner, x, y, N)) continue;

            queue<pi> que;
            vector<pi> component;
            visitedLawn[x][y] = true;
            que.emplace(x, y);

            while(!que.empty()){
                auto [cx, cy] = que.front();
                que.pop();
                component.emplace_back(cx, cy);

                for(int d = 0; d < 4; d++){
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];

                    if(!isLawnCell(owner, nx, ny, N)) continue;
                    if(visitedLawn[nx][ny]) continue;

                    visitedLawn[nx][ny] = true;
                    que.emplace(nx, ny);
                }
            }

            int size = component.size();
            for(auto [cx, cy] : component){
                lawnComponentSize[cx][cy] = size;
            }
        }
    }

    // 池以外を全て使用可能とする移動候補は現在の占有状況に依存しない。
    // 同じPの候補生成と重複除去を
    // 最初の一度だけ行い、以後のターンでは保存済み候補を再利用する。
    auto getCachedMoveCandidates = [&](int people)
        -> MoveCandidateCache& {
        MoveCandidateCache& cache = cachedMoveCandidates[people];
        if(cache.built){
            return cache;
        }
        cache.built = true;
        cache.candidatesContainingCell.assign(N * N, {});

        set<vector<uint16_t>> seen;

        auto addCachedCandidate = [&](int perimeter,
                                      const vector<uint16_t>& cellIds){
            vector<uint16_t> normalized = cellIds;
            sort(all(normalized));
            if(!seen.insert(move(normalized)).second) return;

            int candidateId = cache.candidates.size();
            cache.candidates.push_back({perimeter, cellIds});
            for(uint16_t cellId : cellIds){
                cache.candidatesContainingCell[cellId].push_back(
                    (uint16_t)candidateId
                );
            }
        };

        // 従来と同じ順序で、池を含まない長方形候補を追加する。
        for(int h = 1; h * h <= people; h++){
            if(people % h != 0) continue;

            int w = people / h;
            vpi shapes{{h, w}};
            if(h != w) shapes.emplace_back(w, h);

            for(auto [rh, rw] : shapes){
                for(int i = 0; i + rh <= N; i++){
                    for(int j = 0; j + rw <= N; j++){
                        if(!isRectangleOk(i, j, rh, rw, pondSum)) continue;

                        vector<uint16_t> cellIds;
                        cellIds.reserve(people);
                        for(int x = i; x < i + rh; x++){
                            for(int y = j; y < j + rw; y++){
                                cellIds.push_back((uint16_t)(x * N + y));
                            }
                        }
                        addCachedCandidate(2 * (rh + rw), cellIds);
                    }
                }
            }
        }

        // 池以外の全始点から生成される自由形状も一度だけ保存する。
        for(int sx = 0; sx < N; sx++){
            for(int sy = 0; sy < N; sy++){
                if(lawnComponentSize[sx][sy] < people) continue;

                int perimeter = makeGreedyCandidate(
                    lawnAvailable, people, sx * N + sy, greedyWorkspace
                );
                if(perimeter == -1) continue;
                addCachedCandidate(perimeter, greedyWorkspace.cellIds);
            }
        }

        int candidateCount = cache.candidates.size();
        cache.touchedStamp.assign(candidateCount, 0);
        cache.groupStamp.assign(candidateCount, 0);
        cache.blockerCount.assign(candidateCount, 0);
        cache.moveCost.assign(candidateCount, 0);
        return cache;
    };

    for (int m = 0; m < M; m++) {

        // Input
        int I, S, T, P;
        ll V;
        cin >> I >> S >> T >> P >> V;

        // 情報更新
        for(int j=0; j<I; j++){
            if(!groups[j].active) continue;
            if(groups[j].departure >= S) continue;

            for(auto [x, y] : groups[j].cells){
                if(owner[x][y] == j){
                    owner[x][y] = -1;
                    freeCellCount++;
                }
            }

            groups[j].active = false;
            groups[j].cells.clear();
            activeGroupCount--;
        }

        groups[I].active = false;
        groups[I].departure = T;
        groups[I].people = P;
        groups[I].value = V;

        //最小周長
        int lowerPerimeter = 2 * (int)ceil(2.0 * sqrt(P));

        optional<PlacementEvaluation> best;

        auto updateBest = [&](PlacementEvaluation&& evaluation){
            if (!evaluation.feasible) return;

            bool update = false;

            if(!best) update = true;
            else if(evaluation.netProfit > best->netProfit) update = true;
            else if(evaluation.netProfit == best->netProfit && evaluation.moves.size() < best->moves.size()) update = true;
            else if(evaluation.netProfit == best->netProfit && evaluation.moves.size() == best->moves.size() && evaluation.incoming.perimeter < best->incoming.perimeter) update = true;

            if(update){
                best = move(evaluation);
            }
        };

        // 通常配置も移動先配置と同じ盤面解析・探索処理を使う。
        FreeBoardAnalysis currentAnalysis = analyzeFreeBoard(owner, N);
        optional<Candidate> noMoveCandidate = findBestFreePlacement(
            currentAnalysis, P, N, greedyWorkspace, placementCache
        );
        if(noMoveCandidate){
            updateBest(makeNoMoveEvaluation(move(*noMoveCandidate), V, P));
        }

        /// 移動する場合の候補
        vector<MoveCandidateSummary> moveCandidateSummaries;
        moveCandidateSummaries.reserve(MAX_MOVE_CANDIDATES);
        MoveCandidateCache* moveCacheForTurn = nullptr;

        // 上界順位を完全に定義する。同じ上界・妨害数・周長なら、従来の
        // 候補生成順を優先し、上位K件の選択を決定的にする。
        auto isBetterMoveCandidate = [](const MoveCandidateSummary& a,
                                        const MoveCandidateSummary& b){
            if(a.optimisticProfit != b.optimisticProfit){
                return a.optimisticProfit > b.optimisticProfit;
            }
            if(a.blockerCount != b.blockerCount){
                return a.blockerCount < b.blockerCount;
            }
            if(a.perimeter != b.perimeter){
                return a.perimeter < b.perimeter;
            }
            return a.generationOrder < b.generationOrder;
        };

        // 全候補を保存・ソートせず、現在の上位K件だけを保持する。
        // K=5なので、保持中の最悪候補を線形探索する方が単純で十分高速。
        auto keepTopMoveCandidate = [&](MoveCandidateSummary candidate){
            int replaceIndex = -1;

            if((int)moveCandidateSummaries.size() < MAX_MOVE_CANDIDATES){
                replaceIndex = moveCandidateSummaries.size();
            }else{
                int worstIndex = 0;
                for(int i = 1; i < MAX_MOVE_CANDIDATES; i++){
                    if(isBetterMoveCandidate(
                        moveCandidateSummaries[worstIndex],
                        moveCandidateSummaries[i]
                    )){
                        worstIndex = i;
                    }
                }

                if(!isBetterMoveCandidate(
                    candidate, moveCandidateSummaries[worstIndex]
                )){
                    return;
                }
                replaceIndex = worstIndex;
            }

            if(replaceIndex == (int)moveCandidateSummaries.size()){
                moveCandidateSummaries.push_back(move(candidate));
            }else{
                moveCandidateSummaries[replaceIndex] = move(candidate);
            }
        };

        // 逆引き走査で集計済みの妨害数・移動費用から、候補の上界を評価する。
        auto addMoveCandidate = [&](const CachedIncomingCandidate& cached,
                                    int cachedIndex, int blockerCount,
                                    ll moveCost){
            ll incomingFee = calcFee(V, P, cached.perimeter);

            // 既存グループの料金低下を 0 と仮定した、実利益の上界。
            ll optimisticProfit = incomingFee - moveCost;
            if(optimisticProfit <= 0) return;

            // 同利益時には移動数などのタイブレークがあるため、等号の場合は残す。
            if(best && optimisticProfit < best->netProfit) return;

            MoveCandidateSummary candidate;
            candidate.optimisticProfit = optimisticProfit;
            candidate.moveCost = moveCost;
            candidate.cachedIndex = cachedIndex;
            candidate.perimeter = cached.perimeter;
            candidate.blockerCount = blockerCount;
            candidate.generationOrder = cachedIndex;
            keepTopMoveCandidate(move(candidate));
        };

        // 移動なしで理論最小周長なら、移動費用を払って改善する余地はない。
        const bool optimalWithoutMove =
            best && best->moves.empty() &&
            best->incoming.perimeter == lowerPerimeter;

        // 移動は占有マス総数を変えない。現在の空きがP未満なら、移動しても
        // 新しいPマスを追加できないため、候補生成自体を安全に省略できる。
        if(!optimalWithoutMove && activeGroupCount > 0 && freeCellCount >= P){
            moveCacheForTurn = &getCachedMoveCandidates(P);
            MoveCandidateCache& cache = *moveCacheForTurn;

            if(cache.currentTurnStamp == numeric_limits<int>::max()){
                fill(all(cache.touchedStamp), 0);
                cache.currentTurnStamp = 1;
            }else{
                cache.currentTurnStamp++;
            }

            vector<int> touchedCandidates;
            touchedCandidates.reserve(cache.candidates.size());

            // 使用中マスから、そのマスを含む候補だけへ逆引きする。
            // 同じグループが候補内の複数マスを占めても、移動費用は1回だけ加える。
            for(int groupId = 0; groupId < I; groupId++){
                if(!groups[groupId].active) continue;

                if(cache.currentGroupStamp == numeric_limits<int>::max()){
                    fill(all(cache.groupStamp), 0);
                    cache.currentGroupStamp = 1;
                }else{
                    cache.currentGroupStamp++;
                }

                ll groupMoveCost = max(
                    llround(R * groups[groupId].value), 1LL
                );
                for(auto [x, y] : groups[groupId].cells){
                    int cellId = x * N + y;
                    for(uint16_t candidateId
                        : cache.candidatesContainingCell[cellId]){
                        int id = candidateId;
                        if(cache.groupStamp[id] == cache.currentGroupStamp){
                            continue;
                        }
                        cache.groupStamp[id] = cache.currentGroupStamp;

                        if(cache.touchedStamp[id] != cache.currentTurnStamp){
                            cache.touchedStamp[id] = cache.currentTurnStamp;
                            cache.blockerCount[id] = 0;
                            cache.moveCost[id] = 0;
                            touchedCandidates.push_back(id);
                        }
                        cache.blockerCount[id]++;
                        cache.moveCost[id] += groupMoveCost;
                    }
                }
            }

            for(int cachedIndex : touchedCandidates){
                addMoveCandidate(
                    cache.candidates[cachedIndex], cachedIndex,
                    cache.blockerCount[cachedIndex],
                    cache.moveCost[cachedIndex]
                );
            }
        }

        // 候補生成中に移動なしの理論最適解が見つかった場合も、移動先探索は不要。
        if(best && best->moves.empty() &&
           best->incoming.perimeter == lowerPerimeter){
            moveCandidateSummaries.clear();
        }

        // 上界が高い候補を先に処理し、早期に強い best を得る。
        sort(all(moveCandidateSummaries), isBetterMoveCandidate);

        // 詳細評価する最大K件についてだけ、正確な妨害グループ列を復元する。
        for(MoveCandidateSummary& summary : moveCandidateSummaries){
            summary.blockers = getBlockers(
                moveCacheForTurn->candidates[summary.cachedIndex],
                owner, N, blockerWorkspace
            );
        }

        RollbackBoard temporaryBoard(owner);

        // 第2段階で初めて仮盤面を作り、妨害グループの移動先を探索する。
        for(int i=0; i<(int)moveCandidateSummaries.size(); i++){
            auto& summary = moveCandidateSummaries[i];
            // 上界の降順なので、現在最良を下回った後の候補は全て省略できる。
            if(best && summary.optimisticProfit < best->netProfit) break;

            int checkpoint = temporaryBoard.checkpoint();
            Candidate incoming = restoreCandidate(
                moveCacheForTurn->candidates[summary.cachedIndex], N
            );

            // 移動は同時なので、全妨害グループの旧領域を先に仮解放する。
            for(int groupId : summary.blockers){
                for(auto [x, y] : groups[groupId].cells){
                    temporaryBoard.setCell(x, y, -1);
                }
            }

            // 到着グループの領域を、移動先として使えないよう予約する。
            for(auto [x, y] : incoming.cells){
                temporaryBoard.setCell(x, y, -3);
            }

            vector<int> moveOrder = summary.blockers;
            sort(all(moveOrder), [&](int a, int b){
                return groups[a].people > groups[b].people;
            });

            // 最大グループが入る空き連結成分すらなければ、以降の逐次配置は
            // 必ず失敗する。これは必要条件なので、実行可能候補は捨てない。
            FreeBoardAnalysis temporaryAnalysis = analyzeFreeBoard(
                temporaryBoard.get(), N
            );
            if(temporaryAnalysis.largestComponent
               < groups[moveOrder.front()].people){
                temporaryBoard.rollback(checkpoint);
                continue;
            }

            vector<Move> moves;
            moves.reserve(moveOrder.size());
            bool feasible = true;

            // 大きいグループから順に移動先を確定し、後続探索では占有済みにする。
            for(int moveIndex = 0;
                moveIndex < (int)moveOrder.size();
                moveIndex++){
                int groupId = moveOrder[moveIndex];
                optional<Candidate> destination = findBestFreePlacement(
                    temporaryAnalysis,
                    groups[groupId].people,
                    N,
                    greedyWorkspace,
                    placementCache
                );
                if(!destination){
                    feasible = false;
                    break;
                }

                for(auto [x, y] : destination->cells){
                    temporaryBoard.setCell(x, y, groupId);
                }

                moves.push_back({groupId, move(*destination)});

                // 後続グループがある場合だけ、更新後の空き盤面を解析する。
                if(moveIndex + 1 < (int)moveOrder.size()){
                    temporaryAnalysis = analyzeFreeBoard(
                        temporaryBoard.get(), N
                    );
                }
            }
            if(!feasible){
                temporaryBoard.rollback(checkpoint);
                continue;
            }

            PlacementEvaluation evaluation = makeMultiMoveEvaluation(
                move(incoming),
                move(moves),
                groups,
                V,
                P,
                R
            );
            updateBest(move(evaluation));
            temporaryBoard.rollback(checkpoint);
        }

        // Output
        if(!best || !best->feasible || best->netProfit <= 0){
            cout << 0 << "\n";
            cout << "No\n" << flush;
            continue;
        }

        cout << best->moves.size() << "\n";

        for(const Move& move : best->moves){
            cout << move.groupId << "\n";

            for(auto [x, y] : move.destination.cells){
                cout << x << ' ' << y << "\n";
            }
        }

        cout << "Yes" << "\n";

        for(auto [x, y] : best->incoming.cells){
            cout << x << ' ' << y << "\n";
        }

        cout << flush;

        // Update
        for(const Move& move : best->moves){
            int groupId = move.groupId;

            for(auto [x, y] : groups[groupId].cells){
                if(owner[x][y] == groupId){
                    owner[x][y] = -1;
                }
            }
        }
        for(const Move& move : best->moves){
            int groupId = move.groupId;

            groups[groupId].cells = move.destination.cells;

            groups[groupId].maxPerimeter = max(
                groups[groupId].maxPerimeter,
                move.destination.perimeter
           );

            for(auto [x, y] : move.destination.cells){
                owner[x][y] = groupId;
            }
        }
        groups[I].active = true;
        groups[I].cells = best->incoming.cells;
        groups[I].maxPerimeter = best->incoming.perimeter;
        activeGroupCount++;
        freeCellCount -= P;

        for(auto [x, y] : best->incoming.cells){
            owner[x][y] = I;
        }
    }
    //cerr << timer.count() << "\n";
}
