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
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    vi A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int l = P;
    int r = R;
    for(int i=0; i<Q-P+1; i++){
        swap(A[l-1], A[r-1]);
        l++;
        r++;
    }
    for(int i=0; i<N; i++){
        cout << A[i] << " \n"[i == N-1];
    }
}