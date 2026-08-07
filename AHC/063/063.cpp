#include <bits/stdc++.h>

#include <atcoder/all>
// #pragma GCC optimize("O3")
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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool foundBFS(vvi& f, int& sx, int& sy, int& targetColor, vector<pi>& path) {
    int H = (int)f.size();
    int W = (int)f[0].size();
    if (sx < 0 || sx >= W || sy < 0 || sy >= H) return false;

    vvi dist(H, vi(W, -1));
    vector<vector<pi>> parent(H, vector<pi>(W, {-1, -1}));
    queue<pi> q;
    dist[sy][sx] = 0;
    q.emplace(sx, sy);

    int tx = -1, ty = -1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            if (dist[y][x] > H * W) continue;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (dist[ny][nx] != -1) continue;

            if (f[ny][nx] >= 100) {
                if (f[ny][nx] / 100 - dist[y][x] > 0) continue;
            } else {
                if (f[ny][nx] != 0 && f[ny][nx] != targetColor) continue;
            }

            dist[ny][nx] = dist[y][x] + 1;
            parent[ny][nx] = {x, y};

            if (f[ny][nx] == targetColor) {
                tx = nx;
                ty = ny;
                break;
            }
            q.emplace(nx, ny);
        }
        if (tx != -1) break;
    }

    if (tx == -1) return false;

    path.clear();
    int cx = tx;
    int cy = ty;
    while (!(cx == sx && cy == sy)) {
        path.push_back({cx, cy});
        auto [px, py] = parent[cy][cx];
        cx = px;
        cy = py;
    }
    path.push_back({sx, sy});
    std::reverse(path.begin(), path.end());

    return true;
}

int ColorFound(vvi& f, int& sx, int& sy, vector<pi>& path) {
    int H = (int)f.size();
    int W = (int)f[0].size();
    if (sx < 0 || sx >= W || sy < 0 || sy >= H) return -1;

    vvi dist(H, vi(W, -1));
    vector<vector<pi>> parent(H, vector<pi>(W, {-1, -1}));
    queue<pi> q;
    int tx = -1, ty = -1;
    dist[sy][sx] = 0;
    q.emplace(sx, sy);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        bool flag = false;
        for (int dir = 0; dir < 4; dir++) {
            if (dist[y][x] > H * W) continue;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (dist[ny][nx] != -1) continue;

            if (f[ny][nx] >= 100) {
                if (f[ny][nx] / 100 - dist[y][x] > 0) continue;
            }

            dist[ny][nx] = dist[y][x] + 1;
            parent[ny][nx] = {x, y};

            if (f[ny][nx] != 0 && f[ny][nx] <= 10) {
                flag = true;
                tx = nx;
                ty = ny;
                break;
            }
            if(flag) break;
            q.emplace(nx, ny);
        }
    }
    if(tx == -1) return -1;
    path.clear();
    int cx = tx;
    int cy = ty;
    while (!(cx == sx && cy == sy)) {
        path.push_back({cx, cy});
        auto [px, py] = parent[cy][cx];
        cx = px;
        cy = py;
    }
    path.push_back({sx, sy});
    std::reverse(path.begin(), path.end());
    
    return dist[ty][tx];
}

int cutBodyBFS(vvi& f, int& sx, int& sy, vector<pi>& cutPath,
               char& LastAction) {
    int H = (int)f.size();
    int W = (int)f[0].size();
    if (sx < 0 || sx >= W || sy < 0 || sy >= H) return 0;

    vvi dist(H, vi(W, -1));
    vector<vector<pi>> parent(H, vector<pi>(W, {-1, -1}));
    vvc action(H, vc(W, 'N'));
    queue<pi> q;
    dist[sy][sx] = 0;
    action[sy][sx] = LastAction;
    q.emplace(sx, sy);

    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    int tx = -1, ty = -1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        bool flag = false;
        for (int dir = 0; dir < 4; dir++) {
            if (dist[y][x] > 20*20) continue;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (dist[ny][nx] != -1) continue;
            if (action[y][x] == 'L' && "RLDU"[dir] == 'R') continue;
            if (action[y][x] == 'R' && "RLDU"[dir] == 'L') continue;
            if (action[y][x] == 'U' && "RLDU"[dir] == 'D') continue;
            if (action[y][x] == 'D' && "RLDU"[dir] == 'U') continue;

            dist[ny][nx] = dist[y][x] + 1;
            parent[ny][nx] = {x, y};
            action[ny][nx] = "RLDU"[dir];

            if (f[ny][nx] > 10 && f[ny][nx] / 100 > dist[ny][nx]) {
                tx = nx;
                ty = ny;
                flag = true;
                break;
            }
            q.emplace(nx, ny);
        }
        if(flag) break;
    }

    if (tx == -1) return 0;

    cutPath.clear();
    int cx = tx, cy = ty;
    while (!(cx == sx && cy == sy)) {
        cutPath.push_back({cx, cy});
        auto [px, py] = parent[cy][cx];
        cx = px;
        cy = py;
    }
    cutPath.push_back({sx, sy});
    std::reverse(cutPath.begin(), cutPath.end());

    return dist[ty][tx];
}

void syncBodyOnField(vvi& f, const deque<pi>& bodyPosition,
                     const deque<int>& bodyColor) {
    int H = (int)f.size();
    int W = (int)f[0].size();
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (f[y][x] >= 100) f[y][x] = 0;
        }
    }
    for (int j = (int)bodyPosition.size(); j >= 0; j--) {
        int x = bodyPosition[j].first;
        int y = bodyPosition[j].second;
        if (x < 0 || x >= W || y < 0 || y >= H) continue;
        int c = (j < (int)bodyColor.size() ? bodyColor[j] : 1);
        f[y][x] = c * 10 + ((int)bodyPosition.size() - j) * 100;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, C;
    cin >> N >> M >> C;
    vi d(M);
    cin >> d;
    vvi f(N, vi(N));
    cin >> f;
    deque<int> bodyColor;
    deque<pi> bodyPosition;
    for (int i = 0; i < 5; i++) {
        bodyColor.emplace_back(1);
        bodyPosition.emplace_back(make_pair(0, 4 - i));
    }
    for (int i = 0; i < bodyColor.size(); i++) {
        f[bodyPosition[i].second][bodyPosition[i].first] =
            bodyColor[i] * 10 + (bodyColor.size() - i) * 100;
    }
    int crrMatch = 5;
    int t = 0;
    int RANDOM_ACTION = 5;
    vpi path;
    vpi cutPath;
    bool haveGomi = false;
    char LastAction = 'N';
    while (crrMatch < M && t < 60000) {
        syncBodyOnField(f, bodyPosition, bodyColor);
        if (foundBFS(f, bodyPosition[0].first, bodyPosition[0].second,
                     d[crrMatch], path)) {
            for (int i = 1; i < (int)path.size(); i++) {
                int px = path[i - 1].first;
                int py = path[i - 1].second;
                int nx = path[i].first;
                int ny = path[i].second;

                if (nx == px + 1 && ny == py) {
                    cout << 'R' << '\n';
                    LastAction = 'R';
                } else if (nx == px - 1 && ny == py) {
                    cout << 'L' << '\n';
                    LastAction = 'L';
                } else if (nx == px && ny == py + 1) {
                    cout << 'D' << '\n';
                    LastAction = 'D';
                } else if (nx == px && ny == py - 1) {
                    cout << 'U' << '\n';
                    LastAction = 'U';
                }

                bodyPosition.push_front({nx, ny});
                if(f[ny][nx] != 0 && f[ny][nx] <= C){
                    bodyColor.push_back(f[ny][nx]);
                }else{
                    bodyPosition.pop_back();
                }
                f[py][px] = 0;

                for (int j = 0; j < (int)bodyPosition.size(); j++) {
                    f[bodyPosition[j].second][bodyPosition[j].first] =
                        bodyColor[j] * 10 +
                        ((int)bodyPosition.size() - j) * 100;
                }
            }
            t += (int)path.size() - 1;
            crrMatch++;
        } else {
            vvi simf = f;
            auto simBodyPosition = bodyPosition;
            auto simBodyColor = bodyColor;
            vpi cutDroppedBody;

            int csx = bodyPosition.front().first;
            int csy = bodyPosition.front().second;
            int cutDist = cutBodyBFS(f, csx, csy, cutPath, LastAction);

            if (cutDist > 0) {
                for (int i = 1; i < (int)cutPath.size(); i++) {
                    int nx = cutPath[i].first;
                    int ny = cutPath[i].second;

                    int cellVal = simf[ny][nx];
                    int hitIdx = -1;
                    for (int j = 0; j < (int)simBodyPosition.size(); j++) {
                        if (simBodyPosition[j].first == nx &&
                            simBodyPosition[j].second == ny) {
                            hitIdx = j + 1;
                            break;
                        }
                    }

                    if (hitIdx != -1) {
                        simBodyPosition.push_front({nx, ny});
                        auto [tx, ty] = simBodyPosition.back();
                        simBodyPosition.pop_back();
                        simf[ty][tx] = 0;
                        // 接触した要素以降を切り落として 1..C
                        // として盤面に残す。
                        for (int j = hitIdx + 1;
                             j < (int)simBodyPosition.size(); j++) {
                            auto [dx, dy] = simBodyPosition[j];
                            simf[dy][dx] = simBodyColor[j];
                            cutDroppedBody.push_back({dx, dy});
                        }

                        while ((int)simBodyPosition.size() > hitIdx + 1) {
                            simBodyPosition.pop_back();
                            simBodyColor.pop_back();
                        }
                    } else {
                        simBodyPosition.push_front({nx, ny});
                        auto [tx, ty] = simBodyPosition.back();

                        if (1 <= cellVal && cellVal <= C) {
                            simBodyColor.push_back(cellVal);
                        } else {
                            simBodyPosition.pop_back();
                        }

                        simf[ty][tx] = 0;
                    }

                    for (int j = 0; j < (int)simBodyPosition.size(); j++) {
                        simf[simBodyPosition[j].second]
                            [simBodyPosition[j].first] =
                                simBodyColor[j] * 10 +
                                ((int)simBodyPosition.size() - j) * 100;
                    }
                }
            }

            vector<pi> traceRoute;
            int traceStartX = simBodyPosition.front().first;
            int traceStartY = simBodyPosition.front().second;
            bool reachedAnchor = false;
            int anchorIdx = (int)bodyPosition.size() - cutDist - 1;
            if (0 <= anchorIdx && anchorIdx < (int)bodyPosition.size()) {
                pi anchorPos = bodyPosition[anchorIdx];
                if (simBodyPosition.front() == anchorPos) {
                    reachedAnchor = true;
                }
                for (auto [nx, ny] : cutDroppedBody) {
                    if (reachedAnchor) break;
                    int cellVal = simf[ny][nx];
                    simBodyPosition.push_front({nx, ny});
                    auto [tx, ty] = simBodyPosition.back();

                    if (1 <= cellVal && cellVal <= C) {
                        simBodyColor.push_back(cellVal);
                    } else {
                        simBodyPosition.pop_back();
                    }

                    simf[ty][tx] = 0;
                    for (int j = 0; j < (int)simBodyPosition.size(); j++) {
                        simf[simBodyPosition[j].second]
                            [simBodyPosition[j].first] =
                                simBodyColor[j] * 10 +
                                ((int)simBodyPosition.size() - j) * 100;
                    }

                    traceRoute.push_back({nx, ny});
                    if (simBodyPosition.front() == anchorPos) {
                        reachedAnchor = true;
                        break;
                    }
                }
            }

            bool canReachTarget = false;
            if (reachedAnchor) {
                syncBodyOnField(simf, simBodyPosition, simBodyColor);
                int sfx = simBodyPosition.front().first;
                int sfy = simBodyPosition.front().second;
                canReachTarget = foundBFS(simf, sfx, sfy, d[crrMatch], path);
            }

            if (canReachTarget) {
                f = simf;
                bodyPosition = simBodyPosition;
                bodyColor = simBodyColor;

                int moved = 0;
                for (int i = 1; i < (int)cutPath.size(); i++) {
                    int px = cutPath[i - 1].first;
                    int py = cutPath[i - 1].second;
                    int nx = cutPath[i].first;
                    int ny = cutPath[i].second;

                    if (nx == px + 1 && ny == py) {
                        cout << 'R' << '\n';
                        LastAction = 'R';
                    } else if (nx == px - 1 && ny == py) {
                        cout << 'L' << '\n';
                        LastAction = 'L';
                    } else if (nx == px && ny == py + 1) {
                        cout << 'D' << '\n';
                        LastAction = 'D';
                    } else if (nx == px && ny == py - 1) {
                        cout << 'U' << '\n';
                        LastAction = 'U';
                    }
                    t++;
                }

                int px = traceStartX;
                int py = traceStartY;
                for (auto [nx, ny] : traceRoute) {
                    if (nx == px + 1 && ny == py) {
                        cout << 'R' << '\n';
                        LastAction = 'R';
                    } else if (nx == px - 1 && ny == py) {
                        cout << 'L' << '\n';
                        LastAction = 'L';
                    } else if (nx == px && ny == py + 1) {
                        cout << 'D' << '\n';
                        LastAction = 'D';
                    } else if (nx == px && ny == py - 1) {
                        cout << 'U' << '\n';
                        LastAction = 'U';
                    }
                    px = nx;
                    py = ny;
                    t++;
                }
                foundBFS(f, bodyPosition[0].first, bodyPosition[0].second, d[crrMatch], path);
                for (int i = 1; i < (int)path.size(); i++) {
                    int px = path[i - 1].first;
                    int py = path[i - 1].second;
                    int nx = path[i].first;
                    int ny = path[i].second;

                    if (nx == px + 1 && ny == py) {
                        cout << 'R' << '\n';
                        LastAction = 'R';
                    } else if (nx == px - 1 && ny == py) {
                        cout << 'L' << '\n';
                        LastAction = 'L';
                    } else if (nx == px && ny == py + 1) {
                        cout << 'D' << '\n';
                        LastAction = 'D';
                    } else if (nx == px && ny == py - 1) {
                        cout << 'U' << '\n';
                        LastAction = 'U';
                    }

                    int cellVal = f[ny][nx];
                    bodyPosition.push_front({nx, ny});
                    auto [tx, ty] = bodyPosition.back();

                    if (1 <= cellVal && cellVal <= C) {
                        bodyColor.push_back(cellVal);
                    }else{
                        bodyPosition.pop_back();
                    }

                    f[ty][tx] = 0;
                    for (int j = 0; j < (int)bodyPosition.size(); j++) {
                        f[bodyPosition[j].second][bodyPosition[j].first] =
                            bodyColor[j] * 10 +
                            ((int)bodyPosition.size() - j) * 100;
                    }
                    t++;
                }
                crrMatch++;

            } else {
                if (ColorFound(f, bodyPosition[0].first, bodyPosition[0].second, path) != -1) {
                    int px = bodyPosition.front().first;
                    int py = bodyPosition.front().second;
                    for (auto [nx, ny] : path) {
                        if (nx == px + 1 && ny == py) {
                            cout << 'R' << '\n';
                            LastAction = 'R';
                        } else if (nx == px - 1 && ny == py) {
                            cout << 'L' << '\n';
                            LastAction = 'L';
                        } else if (nx == px && ny == py + 1) {
                            cout << 'D' << '\n';
                            LastAction = 'D';
                        } else if (nx == px && ny == py - 1) {
                            cout << 'U' << '\n';
                            LastAction = 'U';
                        }
                        px = nx;
                        py = ny;
                        bodyPosition.push_front({nx, ny});
                        auto [tx, ty] = bodyPosition.back();
                        f[ty][tx] = 0;
                        int cellVal = f[ny][nx];
                        if (1 <= cellVal && cellVal <= C) {
                            bodyColor.push_back(cellVal);
                        }else{
                            bodyPosition.pop_back();
                        }
                        t++;
                    }
                }
                // Matchしてないがしているとする
                crrMatch++;
            }
        }
        cerr << t << "\n";
    }
    cerr << "end" << "\n";
}