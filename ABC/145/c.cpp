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
    vpi XY(N);
    for(int i=0; i<N; i++){
        cin >> XY[i].first >> XY[i].second;
    }
    double ans = 0;
    vi P(N);
    for(int i=0; i<N; i++)P[i] = i;
    ll cnt = 0;
    do {
        for(int i=1; i<N; i++){
            ans += sqrt((XY[P[i-1]].first-XY[P[i]].first)*(XY[P[i-1]].first-XY[P[i]].first)+(XY[P[i]].second-XY[P[i-1]].second)*(XY[P[i]].second-XY[P[i-1]].second));
        }
        cnt++;
    }while(next_permutation(P.begin(), P.end()));
    cout << fixed << setprecision(10);
    cout << ans/cnt << "\n";
}