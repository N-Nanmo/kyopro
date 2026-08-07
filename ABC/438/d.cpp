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
    ull N;
    cin >> N;
    vector<unsigned long long> A(N), B(N), C(N);
    for(ull i=0; i<N; i++) cin >> A[i];
    for(ull i=0; i<N; i++) cin >> B[i];
    for(ull i=0; i<N; i++) cin >> C[i];
    ull a = A[0] + A[1] + A[2];
    ull b = A[0] + max(A[1], B[1]) + B[2];
    ull c = A[0] + B[1] + C[2];
    for(ull i=3; i<N; i++){
        ull na = A[i] + a;
        ull nb = B[i] + max(a, b);
        ull nc = C[i] + max(b, c);
        a = na;
        b = nb;
        c = nc;
    }
    cout << c << "\n";
}