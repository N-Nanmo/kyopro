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

const int DX[4] = {1, -1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

bool inside(int x, int y, int N) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

// 時刻Sにおいて使用可能なマスか
bool isFreeCell(
    const vvll& G,
    int x,
    int y,
    int S
) {
    if (G[x][y] == -1) {
        return false;
    }

    // 退去時刻がS以上なら、まだ利用中
    if (G[x][y] >= S) {
        return false;
    }

    return true;
}

// 長方形領域が使用可能か
bool isRectangleOk(vvll& G, int S, int h, int w, int x, int y, int N) {
    if (x + h > N || y + w > N) return false;
    for (int i = x; i < x + h; i++) {
        for (int j = y; j < y + w; j++) {
            if (!isFreeCell) return false;
        }
    }
    return true;
}

// 候補マスが現在の領域と何辺接しているか
int countAdjacent(
    int x,
    int y,
    const vector<vector<bool>>& selected,
    int N
) {
    int result = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + DX[dir];
        int ny = y + DY[dir];

        if (
            inside(nx, ny, N) &&
            selected[nx][ny]
        ) {
            result++;
        }
    }

    return result;
}

struct Candidate {
    int adjacent;
    int distance;
    int x;
    int y;
};

// priority_queueの先頭を最も良い候補にする
struct CompareCandidate {
    bool operator()(
        const Candidate& a,
        const Candidate& b
    ) const {
        // 接している辺数が多い方を優先
        if (a.adjacent != b.adjacent) {
            return a.adjacent < b.adjacent;
        }

        // 開始地点に近い方を優先
        if (a.distance != b.distance) {
            return a.distance > b.distance;
        }

        // 同点なら座標順
        if (a.x != b.x) {
            return a.x > b.x;
        }

        return a.y > b.y;
    }
};

// 1つの開始地点から、Pマスの連結領域を作る
vector<pi> makeCompactRegion(
    const vvll& G,
    int N,
    int S,
    int P,
    int startX,
    int startY
) {
    if (!isFreeCell(G, startX, startY, S)) {
        return {};
    }

    vector<vector<bool>> selected(
        N,
        vector<bool>(N, false)
    );

    vector<pi> region;
    region.reserve(P);

    priority_queue<
        Candidate,
        vector<Candidate>,
        CompareCandidate
    > candidates;

    selected[startX][startY] = true;
    region.emplace_back(startX, startY);

    auto pushNeighbor = [&](int x, int y) {
        if (!inside(x, y, N)) {
            return;
        }

        if (selected[x][y]) {
            return;
        }

        if (!isFreeCell(G, x, y, S)) {
            return;
        }

        int adjacent = countAdjacent(
            x,
            y,
            selected,
            N
        );

        // 現在の領域に接していなければ候補ではない
        if (adjacent == 0) {
            return;
        }

        int distance =
            abs(x - startX) +
            abs(y - startY);

        candidates.push({
            adjacent,
            distance,
            x,
            y
        });
    };

    // 開始地点の周囲を候補に追加
    for (int dir = 0; dir < 4; dir++) {
        pushNeighbor(
            startX + DX[dir],
            startY + DY[dir]
        );
    }

    while (
        !candidates.empty() &&
        static_cast<int>(region.size()) < P
    ) {
        Candidate candidate = candidates.top();
        candidates.pop();

        int x = candidate.x;
        int y = candidate.y;

        // 同じマスが複数回queueに入ることがある
        if (selected[x][y]) {
            continue;
        }

        // 領域が成長したため、接触辺数を再計算
        int currentAdjacent = countAdjacent(
            x,
            y,
            selected,
            N
        );

        if (currentAdjacent == 0) {
            continue;
        }

        /*
         * queueに入れた時点より接触辺数が変わった場合、
         * 現在の値で入れ直す。
         */
        if (currentAdjacent != candidate.adjacent) {
            candidate.adjacent = currentAdjacent;
            candidates.push(candidate);
            continue;
        }

        // 領域へ追加
        selected[x][y] = true;
        region.emplace_back(x, y);

        // 新しく追加したマスの周囲を候補に追加
        for (int dir = 0; dir < 4; dir++) {
            pushNeighbor(
                x + DX[dir],
                y + DY[dir]
            );
        }
    }

    if (static_cast<int>(region.size()) != P) {
        return {};
    }

    return region;
}

// 領域の周長を計算
int calcPerimeter(
    const vector<pi>& region,
    int N
) {
    vector<vector<bool>> selected(
        N,
        vector<bool>(N, false)
    );

    for (auto [x, y] : region) {
        selected[x][y] = true;
    }

    int perimeter = 0;

    for (auto [x, y] : region) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + DX[dir];
            int ny = y + DY[dir];

            if (
                !inside(nx, ny, N) ||
                !selected[nx][ny]
            ) {
                perimeter++;
            }
        }
    }

    return perimeter;
}

// 全開始地点を試し、最も周長が短い領域を返す
vector<pi> findCompactRegion(
    const vvll& G,
    int N,
    int S,
    int P
) {
    vector<pi> bestRegion;
    vector<pi> bestNormalized;

    int bestPerimeter =
        numeric_limits<int>::max();

    for (int startX = 0; startX < N; startX++) {
        for (int startY = 0; startY < N; startY++) {
            if (!isFreeCell(G, startX, startY, S)) {
                continue;
            }

            vector<pi> region = makeCompactRegion(
                G,
                N,
                S,
                P,
                startX,
                startY
            );

            if (region.empty()) {
                continue;
            }

            int perimeter = calcPerimeter(
                region,
                N
            );

            // 同じ周長のときの比較用
            vector<pi> normalized = region;
            sort(normalized.begin(), normalized.end());

            bool update = false;

            if (perimeter < bestPerimeter) {
                update = true;
            } else if (
                perimeter == bestPerimeter &&
                (
                    bestRegion.empty() ||
                    normalized < bestNormalized
                )
            ) {
                update = true;
            }

            if (update) {
                bestPerimeter = perimeter;
                bestRegion = region;
                bestNormalized = normalized;
            }
        }
    }

    return bestRegion;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    for (int m = 0; m < M; m++) {
        int I, S, T, P, V;
        cin >> I >> S >> T >> P >> V;

        bool finish = false;

        // 移動は行わない
        cout << 0 << "\n";

        // 正方形に近い長方形(over2xX)を探す
        vector<pair<pi, pi>> Y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int h = 2; h*h <= P; h++) {
                    if (P % h == 0) {
                        Y.emplace_back(make_pair(h, P / h), make_pair(i, j));
                        if(h != P/h) Y.emplace_back(make_pair(P / h, h), make_pair(i, j));
                    }
                }
            }
        }
        sort(all(Y), [](const pair<pi, pi>& a, const pair<pi,pi>& b) {
            int diffa = abs(a.first.first - a.first.second);
            int diffb = abs(b.first.first - b.first.second);
            if (diffa != diffb)
                return diffa < diffb;
            else if(a.first.first != b.first.first){
                return a.first.first < b.first.first;
            }else if(a.first.second != b.first.second){
                return a.first.second < b.first.second;
            }else if(a.second.first != b.second.first){
                return a.second.first < b.second.first;
            }else{
                return a.second.second < b.second.second;
            }
        });
        for (auto hw : Y) {
            if (P % hw.first.first != 0) continue;
            if (isRectangleOk(G, S, hw.first.first, hw.first.second, hw.second.first, hw.second.second, N)) {
                cout << "Yes" << "\n";
                for (int ip = hw.second.first; ip < hw.second.first + hw.first.first; ip++) {
                    for (int jp = hw.second.second; jp < hw.second.second + (P / hw.first.first); jp++) {
                        G[ip][jp] = T;
                        cout << ip << " " << jp << "\n";
                    }
                }
                finish = true;
            }
            if (finish) break;
        }

        /*
         * 第2段階：
         * 長方形で配置できない場合、
         * 自由形状のコンパクトな連結領域を探す
         */
        if (!finish) {
            vector<pi> region = findCompactRegion(
                G,
                N,
                S,
                P
            );

            if (!region.empty()) {
                cout << "Yes\n";

                for (auto [x, y] : region) {
                    G[x][y] = T;
                    cout << x << ' ' << y << '\n';
                }

                finish = true;
            }
        }
        
        if (!finish) cout << "No" << "\n";
        cout << flush;
    }
}