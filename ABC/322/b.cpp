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
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    int ans = 3;
    bool A = true, B = true;
    if(N > M) cout << 3 << "\n";
    for(int i=0; i<N; i++){
        if(S[i] != T[i]){
            A = false;
            break;
        }
    }
    for(int i=N-1; i>=0; i--){
        if(S[i] != T[M+i-N]){
            B = false;
            break;
        }
    }
    if(A && B){
        ans = 0;
    }else if(A){
        ans = 1;
    }else if(B){
        ans = 2;
    }
    cout << ans << "\n";
}