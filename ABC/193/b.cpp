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
    vector<tuple<int, int, int>> APX(N);
    for(int i=0; i<N; i++){
        cin >> get<0>(APX[i]) >> get<1>(APX[i]) >> get<2>(APX[i]);
    }
    int ans = INT_MAX;
    for(int i=0; i<N; i++){
        if(get<2>(APX[i]) - get<0>(APX[i]) > 0){
            ans = min(ans, get<1>(APX[i]));
        }
    }
    if(ans != INT_MAX){
        cout << ans << "\n";
    }else{
        cout << -1 << "\n";
    }
}