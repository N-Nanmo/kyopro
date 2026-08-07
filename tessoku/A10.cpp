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
    int N;
    cin >> N;
    vi A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vi maxf(N, 0);
    maxf[0] = A[0];
    for(int i=1; i<N; i++){
        maxf[i] = max(maxf[i-1], A[i]);
    }
    vi maxl(N, 0);
    maxl[N-1] = A[N-1];
    for(int i=N-2; i>=0; i--){
        maxl[i] = max(maxl[i+1], A[i]);
    }
    int D;
    cin >> D;
    for(int i=0; i<D; i++){
        int L, R;
        cin >> L >> R;
        int ans = 0;
        if(L != 1){
            ans = maxf[L-2];
        }
        if(R != N){
            ans = max(ans, maxl[R]);
        }
        cout << ans << "\n";
    }
}