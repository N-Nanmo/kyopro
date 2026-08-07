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
    int N, M, C;
    cin >> N >> M >> C;
    vi B(M);
    for(int i=0; i<M; i++) cin >> B[i];
    vvi A(N, vi(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=0; j<M; j++){
            sum += B[j]*A[i][j];
        }
        if(sum+C > 0) ans++;
    }
    cout << ans << "\n";
}