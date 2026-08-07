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
    vb get(N, false);
    int ans = 0;
    vpi P(N);
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        P[i] = {a, b};
    }
    while(true){
        bool got = false;
        for(int i=0; i<N; i++){
            if(get[i]) continue;
            if(P[i].first == 0 && P[i].second == 0){
                ans++;
                get[i] = true;
                got = true;
                continue;
            }
            if(get[P[i].first-1] || get[P[i].second-1]){
                ans++;
                get[i] = true;
                got = true;
                continue;
            }
        }
        if(!got) break;
    }
    cout << ans << "\n";
}