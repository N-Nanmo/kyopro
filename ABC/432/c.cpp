#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
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
    int N, X, Y;
    cin >> N >> X >> Y;
    vi A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    vll S(N);
    for(int i=0; i<N; i++){
        S[i] = A[i] * Y;
    }
    ll sabun = Y - X;
    sort(S.begin(), S.end());
    sort(A.begin(), A.end());
    ll amari = S[0] % sabun;
    for(int j=A[0]; j>=0; j--){
        ull ans = j;
        bool ok = true;
        for(int i=1; i<N; i++){
            if(S[i] % sabun == amari){
                ll s = S[i] - (j * Y + (A[0] - j) * X);
                ll sa = sabun * A[i];
                if(s <= sa){
                    ans += A[i] - (s/sabun);
                }else{
                    ok = false;
                    break;
                }
            }else{
                ok = false;
                break;
            }
        }
        if(!ok){
            continue;
        }
        cout << ans << "\n";
        return 0;
    }
    cout << -1 << "\n";
    return 0;
}