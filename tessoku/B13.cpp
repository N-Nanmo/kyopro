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
    ll N, K;
    cin >> N >> K;
    vll A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vll Ru(N);
    Ru[0] = A[0];
    for(int i=1; i<N; i++){
        Ru[i] = Ru[i-1] + A[i];
    }
    ll ans = 0, r = -1;
    for(int i=0; i<N; i++){
        ll mainasu = 0;
        if(i != 0){
            mainasu = Ru[i-1];
        }
        while(r+1 < N && Ru[r+1] - mainasu <= K){
            r++;
        }
        ans += r - i + 1;
    }
    cout << ans << "\n";
}