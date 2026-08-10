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
    vi P(N), Q(N);
    for(int i=0; i<N; i++) cin >> P[i];
    for(int i=0; i<N; i++) cin >> Q[i];
    vi R(N);
    for(int i=0; i<N; i++) R[i] = i+1;
    int a=0, b=0;
    int cnt = 0;
    do {
        cnt++;
        bool pa=true, qb=true;
        for(int i=0; i<N; i++){
            if(P[i] != R[i]) pa = false;
            if(Q[i] != R[i]) qb = false;
        }
        if(pa) a = cnt;
        if(qb) b = cnt;
    }while (next_permutation(R.begin(), R.end()));
    cout << abs(a-b) << "\n";
}