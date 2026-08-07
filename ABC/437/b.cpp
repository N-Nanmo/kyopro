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
    vvi A(H, vi(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }
    vi B(N);
    for(int i=0; i<N; i++) cin >> B[i];
    vvb D(H, vb(W, false));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for(int k=0; k<N; k++){
                if(A[i][j] == B[k]){
                    D[i][j] = true;
                }
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<H; i++){
        int cnt = 0;
        for(int j=0; j<W; j++){
            if(D[i][j] == true){
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}