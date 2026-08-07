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
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    for(int i=0; i<A; i++) cin >> a[i];
    for(int i=0; i<B; i++) cin >> b[i];
    int min_a = *min_element(a.begin(), a.end());
    int min_b = *min_element(b.begin(), b.end());
    int ans = min_a + min_b;
    for(int i=0; i<M; i++){
        int x, y, c;
        cin >> x >> y >> c;
        ans = min(ans, a[x-1] + b[y-1] - c);
    }
    cout << ans << "\n";
}