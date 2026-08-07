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
    int H, W, Q;
    cin >> H >> W >> Q;
    vvi A(H, vi(W));
    vvb used(H, vb(W, false));
    for(int i=0; i<Q; i++){
        int q;
        cin >> q;
        if(q == 1){
            int x, y, c;
            cin >> x >> y >> c;
            if(!used[x-1][y-1]){
                A[x-1][y-1] = c;
            }
            if(!used[x-1][y]){
                A[x-1][y] = c;
            }
            if(!used[x][y-1]){
                A[x][y-1] = c;
            }
            if(!used[x][y]){
                A[x][y] = c;
            }
        }else{
            int x, y;
            cin >> x >> y;
            used[x-1][y-1] = true;
            used[x][y-1] = true;
            used[x-1][y] = true;
            used[x][y] = true;
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << A[i][j];
            if(j < W-1) cout << " ";
            else cout << "\n";
        }
    }
}