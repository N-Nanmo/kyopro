#include <bits/stdc++.h>
#include <atcoder/all>

#pragma GCC optimize("O3")

using namespace std;
using namespace atcoder;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using pi = pair<int, int>;

const int INF = numeric_limits<int>::max();

const int DX[4] = {1, -1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

struct RegionResult {
    vector<pi> cells;
    int perimeter = INF;

    bool valid() const {
        return !cells.empty();
    }
};

struct Candidate {
    int adjacent;
    int distance;
    int x;
    int y;
};

struct CompareCandidate {
    bool operator()(
        const Candidate& a,
        const Candidate& b
    ) const {
        // 現在の領域と接している辺数が多い方を優先
        if (a.adjacent != b.adjacent) {
            return a.adjacent < b.adjacent;
        }

        // 開始地点から近い方を優先
        if (a.distance != b.distance) {
            return a.distance > b.distance;
        }

        // 同点時は座標順
        if (a.x != b.x) {
            return a.x > b.x;
        }

        return a.y > b.y;
    }
};

bool inside(int x, int y, int N) {
    return 0 <= x && x < N &&
           0 <= y && y < N;
}

// 時刻Sに利用可能なマスか
bool isFreeCell(
    const vvll& G,
    int x,
    int y,
    int S
) {
    // 池
    if (G[x][y] == -1) {
        return false;
    }

    // T >= S のグループは時刻Sではまだ利用中
    if (G[x][y] >= S) {
        return false;
    }

    return true;
}

// 長方形を配置可能か調べる
bool isRectangleOk(
    const vvll& G,
    int N,
    int S,
    int x,
    int y,
    int h,
    int w
) {
    if (x + h > N || y + w > N) {
        return false;
    }

    for (int i = x; i < x + h; i++) {
        for (int j = y; j < y + w; j++) {
            if (!isFreeCell(G, i, j, S)) {
                return false;
            }
        }
    }

    return true;
}

// 座標集合を辞書順比較できる形にする
vector<pi> normalizeCells(vector<pi> cells) {
    sort(cells.begin(), cells.end());
    return cells;
}

bool isBetterRegion(
    const RegionResult& candidate,
    const RegionResult& current
) {
    if (!candidate.valid()) {
        return false;
    }

    if (!current.valid()) {
        return true;
    }

    if (candidate.perimeter != current.perimeter) {
        return candidate.perimeter < current.perimeter;
    }

    vector<pi> candidateCells =
        normalizeCells(candidate.cells);

    vector<pi> currentCells =
        normalizeCells(current.cells);

    return candidateCells < currentCells;
}

// Pマスの連結ポリオミノが取り得る理論最小周長
int minimumPossiblePerimeter(int P) {
    /*
     * 最小周長は 2 * ceil(2 * sqrt(P))
     *
     * 浮動小数点誤差を避けるため、
     * 2Pに近い整数ではなく、
     * k^2 >= 4P となる最小のkを求める。
     */
    int k = static_cast<int>(
        sqrt(4.0 * static_cast<double>(P))
    );

    while (1LL * k * k < 4LL * P) {
        k++;
    }

    while (
        k > 0 &&
        1LL * (k - 1) * (k - 1) >= 4LL * P
    ) {
        k--;
    }

    return 2 * k;
}

// Pの約数から長方形の形状候補を作る
vector<pi> getRectangleShapes(int P) {
    vector<pi> shapes;

    for (int h = 1; 1LL * h * h <= P; h++) {
        if (P % h != 0) {
            continue;
        }

        int w = P / h;

        shapes.emplace_back(h, w);

        if (h != w) {
            shapes.emplace_back(w, h);
        }
    }

    sort(
        shapes.begin(),
        shapes.end(),
        [](const pi& a, const pi& b) {
            int perimeterA =
                2 * (a.first + a.second);

            int perimeterB =
                2 * (b.first + b.second);

            if (perimeterA != perimeterB) {
                return perimeterA < perimeterB;
            }

            return a < b;
        }
    );

    return shapes;
}

// 最良の長方形領域を探す
RegionResult findBestRectangle(
    const vvll& G,
    int N,
    int S,
    int P
) {
    RegionResult best;

    vector<pi> shapes =
        getRectangleShapes(P);

    for (auto [h, w] : shapes) {
        int perimeter = 2 * (h + w);

        /*
         * 形状は周長昇順なので、
         * 既にこれより小さい周長が見つかっていれば終了。
         */
        if (
            best.valid() &&
            perimeter > best.perimeter
        ) {
            break;
        }

        for (int x = 0; x + h <= N; x++) {
            for (int y = 0; y + w <= N; y++) {
                if (
                    !isRectangleOk(
                        G,
                        N,
                        S,
                        x,
                        y,
                        h,
                        w
                    )
                ) {
                    continue;
                }

                RegionResult candidate;
                candidate.perimeter = perimeter;
                candidate.cells.reserve(P);

                for (int i = x; i < x + h; i++) {
                    for (int j = y; j < y + w; j++) {
                        candidate.cells.emplace_back(i, j);
                    }
                }

                if (isBetterRegion(candidate, best)) {
                    best = move(candidate);
                }
            }
        }
    }

    return best;
}

// 空き領域の連結成分を列挙
vector<vector<pi>> getFreeComponents(
    const vvll& G,
    int N,
    int S
) {
    vector<vector<pi>> components;
    vector<char> visited(N * N, false);

    for (int sx = 0; sx < N; sx++) {
        for (int sy = 0; sy < N; sy++) {
            int startIndex = sx * N + sy;

            if (visited[startIndex]) {
                continue;
            }

            if (!isFreeCell(G, sx, sy, S)) {
                continue;
            }

            vector<pi> component;
            queue<pi> que;

            visited[startIndex] = true;
            que.emplace(sx, sy);

            while (!que.empty()) {
                auto [x, y] = que.front();
                que.pop();

                component.emplace_back(x, y);

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + DX[dir];
                    int ny = y + DY[dir];

                    if (!inside(nx, ny, N)) {
                        continue;
                    }

                    int index = nx * N + ny;

                    if (visited[index]) {
                        continue;
                    }

                    if (!isFreeCell(G, nx, ny, S)) {
                        continue;
                    }

                    visited[index] = true;
                    que.emplace(nx, ny);
                }
            }

            components.push_back(move(component));
        }
    }

    return components;
}

// 各連結成分から代表的な開始地点を選ぶ
vector<pi> selectStartCells(
    const vector<pi>& component
) {
    vector<pi> starts;

    if (component.empty()) {
        return starts;
    }

    auto addUnique = [&](pi cell) {
        for (const pi& existing : starts) {
            if (existing == cell) {
                return;
            }
        }

        starts.push_back(cell);
    };

    pi lexicographicMin = component.front();
    pi lexicographicMax = component.front();

    pi minSum = component.front();
    pi maxSum = component.front();

    pi minDifference = component.front();
    pi maxDifference = component.front();

    ll sumX = 0;
    ll sumY = 0;

    for (auto [x, y] : component) {
        pi cell = {x, y};

        lexicographicMin =
            min(lexicographicMin, cell);

        lexicographicMax =
            max(lexicographicMax, cell);

        int sum = x + y;
        int currentMinSum =
            minSum.first + minSum.second;

        int currentMaxSum =
            maxSum.first + maxSum.second;

        if (
            sum < currentMinSum ||
            (
                sum == currentMinSum &&
                cell < minSum
            )
        ) {
            minSum = cell;
        }

        if (
            sum > currentMaxSum ||
            (
                sum == currentMaxSum &&
                cell < maxSum
            )
        ) {
            maxSum = cell;
        }

        int difference = x - y;

        int currentMinDifference =
            minDifference.first -
            minDifference.second;

        int currentMaxDifference =
            maxDifference.first -
            maxDifference.second;

        if (
            difference < currentMinDifference ||
            (
                difference == currentMinDifference &&
                cell < minDifference
            )
        ) {
            minDifference = cell;
        }

        if (
            difference > currentMaxDifference ||
            (
                difference == currentMaxDifference &&
                cell < maxDifference
            )
        ) {
            maxDifference = cell;
        }

        sumX += x;
        sumY += y;
    }

    // 連結成分の重心に近いマス
    pi centerCell = component.front();
    ll bestCenterDistance =
        numeric_limits<ll>::max();

    ll componentSize =
        static_cast<ll>(component.size());

    for (auto [x, y] : component) {
        ll dx = static_cast<ll>(x) *
                    componentSize -
                sumX;

        ll dy = static_cast<ll>(y) *
                    componentSize -
                sumY;

        ll distance = dx * dx + dy * dy;

        if (
            distance < bestCenterDistance ||
            (
                distance == bestCenterDistance &&
                pi{x, y} < centerCell
            )
        ) {
            bestCenterDistance = distance;
            centerCell = {x, y};
        }
    }

    addUnique(centerCell);
    addUnique(lexicographicMin);
    addUnique(lexicographicMax);
    addUnique(minSum);
    addUnique(maxSum);
    addUnique(minDifference);
    addUnique(maxDifference);

    return starts;
}

// 現在の領域と接している辺数を数える
int countAdjacent(
    int x,
    int y,
    int N,
    const vector<int>& selectedStamp,
    int stamp
) {
    int adjacent = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + DX[dir];
        int ny = y + DY[dir];

        if (!inside(nx, ny, N)) {
            continue;
        }

        int index = nx * N + ny;

        if (selectedStamp[index] == stamp) {
            adjacent++;
        }
    }

    return adjacent;
}

// 一つの開始地点からコンパクトな自由形状を作る
RegionResult makeCompactRegion(
    const vvll& G,
    int N,
    int S,
    int P,
    int startX,
    int startY,
    vector<int>& selectedStamp,
    int stamp
) {
    RegionResult result;

    if (!isFreeCell(G, startX, startY, S)) {
        return result;
    }

    priority_queue<
        Candidate,
        vector<Candidate>,
        CompareCandidate
    > pq;

    result.cells.reserve(P);
    result.cells.emplace_back(startX, startY);
    result.perimeter = 4;

    selectedStamp[startX * N + startY] = stamp;

    auto pushCandidate = [&](int x, int y) {
        if (!inside(x, y, N)) {
            return;
        }

        if (!isFreeCell(G, x, y, S)) {
            return;
        }

        int index = x * N + y;

        if (selectedStamp[index] == stamp) {
            return;
        }

        int adjacent = countAdjacent(
            x,
            y,
            N,
            selectedStamp,
            stamp
        );

        if (adjacent == 0) {
            return;
        }

        int distance =
            abs(x - startX) +
            abs(y - startY);

        pq.push({
            adjacent,
            distance,
            x,
            y
        });
    };

    for (int dir = 0; dir < 4; dir++) {
        pushCandidate(
            startX + DX[dir],
            startY + DY[dir]
        );
    }

    while (
        !pq.empty() &&
        static_cast<int>(result.cells.size()) < P
    ) {
        Candidate candidate = pq.top();
        pq.pop();

        int x = candidate.x;
        int y = candidate.y;
        int index = x * N + y;

        // 同じマスが複数回入っている可能性がある
        if (selectedStamp[index] == stamp) {
            continue;
        }

        int currentAdjacent = countAdjacent(
            x,
            y,
            N,
            selectedStamp,
            stamp
        );

        if (currentAdjacent == 0) {
            continue;
        }

        /*
         * priority_queueへ追加した後に領域が変化し、
         * 接触辺数が変わっている場合は入れ直す。
         */
        if (currentAdjacent != candidate.adjacent) {
            candidate.adjacent = currentAdjacent;
            pq.push(candidate);
            continue;
        }

        selectedStamp[index] = stamp;
        result.cells.emplace_back(x, y);

        /*
         * k辺接するマスを追加したとき、
         * 周長変化は 4 - 2k。
         */
        result.perimeter +=
            4 - 2 * currentAdjacent;

        for (int dir = 0; dir < 4; dir++) {
            pushCandidate(
                x + DX[dir],
                y + DY[dir]
            );
        }
    }

    if (
        static_cast<int>(result.cells.size()) != P
    ) {
        result.cells.clear();
        result.perimeter = INF;
    }

    return result;
}

// 最良の自由形状を探す
RegionResult findBestFreeRegion(
    const vvll& G,
    int N,
    int S,
    int P,
    int currentBestPerimeter
) {
    RegionResult best;

    vector<vector<pi>> components =
        getFreeComponents(G, N, S);

    vector<int> selectedStamp(N * N, 0);
    int stamp = 0;

    int theoreticalMinimum =
        minimumPossiblePerimeter(P);

    for (const vector<pi>& component : components) {
        if (
            static_cast<int>(component.size()) < P
        ) {
            continue;
        }

        vector<pi> starts =
            selectStartCells(component);

        for (auto [startX, startY] : starts) {
            stamp++;

            /*
             * intのstampが上限に近づく可能性は通常ありませんが、
             * 安全のためリセットする。
             */
            if (stamp == INF) {
                fill(
                    selectedStamp.begin(),
                    selectedStamp.end(),
                    0
                );

                stamp = 1;
            }

            RegionResult candidate =
                makeCompactRegion(
                    G,
                    N,
                    S,
                    P,
                    startX,
                    startY,
                    selectedStamp,
                    stamp
                );

            if (!candidate.valid()) {
                continue;
            }

            if (
                candidate.perimeter >
                currentBestPerimeter
            ) {
                continue;
            }

            if (isBetterRegion(candidate, best)) {
                best = move(candidate);

                currentBestPerimeter =
                    best.perimeter;
            }

            // これ以上周長を改善できない
            if (
                currentBestPerimeter ==
                theoreticalMinimum
            ) {
                return best;
            }
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

        if (!(cin >> I >> S >> T >> P >> V)) {
            return 0;
        }

        // 今回は既存グループを移動しない
        cout << 0 << '\n';

        /*
         * まず長方形候補を探す。
         */
        RegionResult bestRegion =
            findBestRectangle(
                G,
                N,
                S,
                P
            );

        int theoreticalMinimum =
            minimumPossiblePerimeter(P);

        /*
         * 長方形が見つからない場合、または長方形の周長が
         * 理論最小でない場合は自由形状も調べる。
         */
        if (
            !bestRegion.valid() ||
            bestRegion.perimeter >
                theoreticalMinimum
        ) {
            int currentBestPerimeter =
                bestRegion.valid()
                    ? bestRegion.perimeter
                    : INF;

            RegionResult freeRegion =
                findBestFreeRegion(
                    G,
                    N,
                    S,
                    P,
                    currentBestPerimeter
                );

            if (
                isBetterRegion(
                    freeRegion,
                    bestRegion
                )
            ) {
                bestRegion = move(freeRegion);
            }
        }

        if (!bestRegion.valid()) {
            cout << "No\n";
            cout << flush;
            continue;
        }

        /*
         * 出力順も固定する。
         * 座標の順番は領域の連結性には影響しない。
         */
        sort(
            bestRegion.cells.begin(),
            bestRegion.cells.end()
        );

        cout << "Yes\n";

        for (auto [x, y] : bestRegion.cells) {
            G[x][y] = T;
            cout << y << ' ' << x << '\n';
        }

        cout << flush;
    }

    return 0;
}