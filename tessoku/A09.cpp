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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, N;
    cin >> H >> W >> N;
    vvi G(H, vi(W, 0));
    for(int i=0; i<N; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        G[a-1][b-1]++;
        if(c < H){
            G[c][b-1]--;
        }
        if(d < W){
            G[a-1][d]--;
        }
        if(c < H && d < W){
            G[c][d]++;
        }
    }
    for(int i=0; i<H; i++){
        for(int j=1; j<W; j++){
            G[i][j] += G[i][j-1];
        }
    }
    for(int j=0; j<W; j++){
        for(int i=1; i<H; i++){
            G[i][j] += G[i-1][j];
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W-1; j++){
            cout << G[i][j] << " ";
        }
        cout << G[i][W-1] << "\n";
    }
}