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
    int N;
    cin >> N;
    vi A(N+1);
    for(int i=0; i<N; i++) cin >> A[i];
    int sum = 0;
    vi S(N+1);
    S[0] = 0;
    for(int i=1; i<N+1; i++) S[i] += S[i-1] + A[i-1];
    int ans = 0;
    for(int l=1; l<N+1; l++){
        for(int r=l+1; r<N+1; r++){
            int tmp = (S[r] - S[l-1]);
            bool ng = false;
            for(int i=l; i<=r; i++){
                if(tmp%A[i-1] == 0) ng = true;
            }
            if(!ng) ans++;
        }
    }
    cout << ans << "\n";
}