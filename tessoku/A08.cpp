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
    int H, W;
    cin >> H >> W;
    vvi A(H, vi(W));
    vvi R(H, vi(W, 0));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(j == 0){
                R[i][j] = A[i][j];
            }else{
                R[i][j] = R[i][j-1] + A[i][j];
            }
        }
    }
    for(int j=0; j<W; j++){
        for(int i=1; i<H; i++){
            R[i][j] += R[i-1][j];
        }
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = R[c-1][d-1];
        if(a != 1){
            ans -= R[a-2][d-1];
        }
        if(b != 1){
            ans -= R[c-1][b-2];
        }
        if(a != 1 && b != 1){
            ans += R[a-2][b-2];
        }
        cout << ans << "\n";
    }
}