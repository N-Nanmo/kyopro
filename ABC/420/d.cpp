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
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    int x, y, cnt=0;
    bool switching = false;
    queue<tuple<int,int,bool, int, bool>> st;
    vvc C(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> C[i][j];
            if(C[i][j] == 'S'){
                st.push({i, j, false, 0, false});
            }
        }
    }
    vvc backup(H, vector<char>(W));
    backup = C;
    while(!st.empty()){
        tuple p = st.front();
        st.pop();
        for(int i=0; i<4; i++){
            int px = get<0>(p);
            int py = get<1>(p);
            bool sw = get<2>(p);
            int cnt = get<3>(p);
            int nx = px + dx[i];
            int ny = py + dy[i];
            bool back = get<4>(p);
            if(nx == px && ny == py && !back){
                continue;
            }
            back = false;
            if(cnt > H*W){
                continue;
            }
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(C[nx][ny] == '#' || C[nx][ny] == 'x' && !sw || C[nx][ny] == 'o' && sw) continue;
            if(C[nx][ny] == '.' || C[nx][ny] == 'o' && !sw || C[nx][ny] == 'x' && sw){
                cnt++;
                st.push({nx, ny, sw, cnt, back});
                continue;
            }
            if(C[nx][ny] == '?'){
                cnt++;
                sw = !sw;
                back = true;
                st.push({nx, ny, sw, cnt, back});
                continue;
            }
            if(C[nx][ny] == 'G'){
                cnt++;
                cout << cnt << "\n";
                return 0;
            }
        }
    }
    cout << "-1\n";
}