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
    vvi G(1501, vi(1501, 0));
    for(int i=0; i<N; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c--;
        d--;
        G[a][b]++;
        if(c < 1500){
            G[c+1][b]--;
        }
        if(d < 1500){
            G[a][d+1]--;
        }
        if(c < 1500 && d < 1500){
            G[c+1][d+1]++;
        }
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
    int ans = 0;
    for(int i=0; i<1500; i++){
        for(int j=0; j<1500; j++){
            if(G[i][j] > 0) ans++;
        }
    }
    cout << ans << "\n";
}