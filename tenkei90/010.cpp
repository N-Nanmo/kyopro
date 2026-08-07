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
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vll A;
    vll B;
    vll C;
    for(int i=0; i<N; i++){
        int c,p;
        cin >> c >> p;
        C.emplace_back();
    }
    for(int i=1; i<A.size(); i++){
        A[i] += A[i-1];
    }
    for(int i=1; i<B.size(); i++){
        B[i] += B[i-1];
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int l, r;
        cin >> l >> r;
        cout << A[r-1] - A[l-2] << " " << B[r-1] - B[l-2] << "\n";
    }
}