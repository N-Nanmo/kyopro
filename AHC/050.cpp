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

bool check(const vvc& grid , int i, int j, int N){
    if(i == 0 || j == 0 || i == N-1 || j == N-1) return false;
    if(grid[i-1][j] == '#' || grid[i+1][j] == '#' || grid[i][j-1] == '#' || grid[i][j+1] == '#') return false;
    return true;
}

int check2(const vvc& grid , int i, int j, int N){
    int cnt = 0;
    if(i != 0 && grid[i-1][j] == '#') cnt++;
    if(i != N-1 && grid[i+1][j] == '#') cnt++;
    if(j != 0 && grid[i][j-1] == '#') cnt++;
    if(j != N-1 && grid[i][j+1] == '#') cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vvc grid(N, vc(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
        }
    }
    while(true){
        bool outputted = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(check(grid, i, j, N) && grid[i][j] == '.'){
                    cout << i << " " << j << "\n";
                    grid[i][j] = '#';
                    outputted = true;
                }
            }
        }
        if(!outputted) break;
    }
    while(true){
        bool shutdown = true;
        int min_cnt = INT_MAX;
        pi good = {-1, -1};
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == '.'){
                    int cnt = check2(grid, i, j, N);
                    if(cnt < min_cnt){
                        min_cnt = cnt;
                        good = {i, j};
                        shutdown = false;
                    }
                }
            }
        }
        if(shutdown) break;
        cout << good.first << " " << good.second << "\n";
        grid[good.first][good.second] = '#';
    }
}