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
void rekkyo(int N,vs &ans, int cnt, string s, vb used) {
    if(cnt == N){
        ans.emplace_back(s);
        return;
    }
    for(int i=1; i<=N; i++){
        if(used[i-1]) continue;
        used[i-1] = true;
        rekkyo(N,ans, cnt + 1, s + to_string(i), used);
        used[i-1] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vi P(N);
    vi Q(N);
    for(int i=0; i<N; i++) cin >> P[i];
    for(int i=0; i<N; i++) cin >> Q[i];
    string ps = "";
    string qs = "";
    for(int i=0; i<N; i++){
        ps += to_string(P[i]);
        qs += to_string(Q[i]);
    }
    int cnt = 0;
    vs ans;
    vb used(N, false);
    rekkyo(N,ans, cnt, "",used);
    sort(ans.begin(), ans.end());
    int a, b;
    a = find(ans.begin(), ans.end(), ps) - ans.begin() + 1;
    b = find(ans.begin(), ans.end(), qs) - ans.begin() + 1;
    cout << abs(a - b) << "\n";
}