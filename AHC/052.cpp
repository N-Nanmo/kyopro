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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vpi T(M);
    for(int i=0; i<M; i++){
        cin >> T[i].first >> T[i].second;
    }
    random_device rd;
    mt19937 gen(rd());
    
    for(int i=0; i<M-1; i++){
        cout << 'L' << ' ';
    }
    cout << 'L' << "\n";
    for(int i=0; i<M-1; i++){
        cout << 'R' << ' ';
    }
    cout << 'R' << "\n";
    for(int i=0; i<M-1; i++){
        cout << 'U' << ' ';
    }
    cout << 'U' << "\n";
    for(int i=0; i<M-1; i++){
        cout << 'D' << ' ';
    }
    cout << 'D' << "\n";
    for(int i=0; i<K-4; i++){
        for(int j=0; j<M-1; j++){
            cout << 'L' << ' ';
        }
        cout << 'L' << "\n";
    }

    vvb used_X(N-2, vb(N-1, false));
    vvb used_Y(N-1, vb(N-2, false));
    for(int i=0; i<N-2; i++){
        for(int j=0; j<N-1; j++){
            char a;
            cin >> a;
            used_X[i][j] = (a == '1');
        }
    }
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-2; j++){
            char a;
            cin >> a;
            used_Y[i][j] = (a == '1');
        }
    }

    vvb painted(N, vb(N, false));
    for(int i=0; i<M; i++){
        painted[T[i].first][T[i].second] = true;
    }

    auto canMove = [&](int x, int y, int dir) -> bool {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
        
        if(dir == 0 && x > 0 && y < N-2 && used_Y[x-1][y]) return false;
        if(dir == 1 && x < N-2 && y < N-2 && used_Y[x][y]) return false;
        if(dir == 2 && x < N-2 && y > 0 && used_X[x][y-1]) return false;
        if(dir == 3 && x < N-2 && y < N-1 && used_X[x][y]) return false;
        
        return true;
    };

    auto isPaintedOrEmpty = [&](int x, int y) -> int {
        if(painted[x][y]) return 0;
        return 1;
    };

    for(int i=0; i<1800; i++){
        vi dir_priority(4, 0);
        
        for(int j=0; j<M; j++){
            for(int dir=0; dir<4; dir++){
                if(canMove(T[j].first, T[j].second, dir)){
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, -1, 1};
                    int nx = T[j].first + dx[dir];
                    int ny = T[j].second + dy[dir];
                    dir_priority[dir] += isPaintedOrEmpty(nx, ny);
                }
            }
        }
        
        int best_dir = 0;
        for(int dir=1; dir<4; dir++){
            if(dir_priority[dir] > dir_priority[best_dir]){
                best_dir = dir;
            }
        }
        
        if(dir_priority[best_dir] == 0){
            best_dir = gen() % 10;
        }
        
        cout << best_dir << "\n";
        
        if(best_dir < 4){
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int j=0; j<M; j++){
                if(canMove(T[j].first, T[j].second, best_dir)){
                    T[j].first += dx[best_dir];
                    T[j].second += dy[best_dir];
                }
            }
            // 全タンクの移動後に、全ての位置を塗り済みとして記録
            for(int j=0; j<M; j++){
                painted[T[j].first][T[j].second] = true;
            }
        }
    }
}