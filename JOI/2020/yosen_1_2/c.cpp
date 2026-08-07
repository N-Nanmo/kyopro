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
    vi A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int ansA = 0;
    for(int i=0; i<max_element(A.begin(), A.end()) - A.begin(); i++){
        ansA += A[i];
    }
    int ansB = 0;
    for(int i=max_element(A.begin(), A.end()) - A.begin() + 1; i<N; i++){
        ansB += A[i];
    }
    cout << ansA << "\n" << ansB << "\n";
}