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
    vvi G(1500, vi(1500, 0));
    int N;
    cin >> N;
    vpi A(N);
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
        G[x-1][y-1]++;
    }
    for(int i=0; i<1500; i++){
        for(int j=1; j<1500; j++){
            G[i][j] += G[i][j-1];
        }
    }
    for(int j=0; j<1500; j++){
        for(int i=1; i<1500; i++){
            G[i][j] += G[i-1][j];
        }
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = G[c-1][d-1];
        if(a != 1){
            ans -= G[a-2][d-1];
        }
        if(b != 1){
            ans -= G[c-1][b-2];
        }
        if(a != 1 && b != 1){
            ans += G[a-2][b-2];
        }
        cout << ans << "\n";
    }
}