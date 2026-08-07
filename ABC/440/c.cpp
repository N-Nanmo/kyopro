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
using vf = vector<float>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int N, W;
        cin >> N >> W;
        vll C(N);
        for(int i=0; i<N; i++) cin >> C[i];
        vll A(W*2);
        for(int i=0; i<max(W*2, N); i++){
            if(i >= N){
                A[i] = 0;
                continue;
            }
            A[i%(W*2)] += C[i];
        }
        for(int i=0; i<W*2-1; i++){
            A[i+1] += A[i];
        }
        ll ans = A[W-1];
        for(int i=1; i<2*W; i++){
            if(i >= W+1){
                ans = min(ans, A[2*W-1]-A[i-1]+A[(i+W-1)%(2*W)]);
                continue;
            }
            ans = min(ans, A[i+W-1]-A[i-1]);
        }
        cout << ans << "\n";
    }
}