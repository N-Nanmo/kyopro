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
    vi A(9);
    vi B(8);
    for(int i=0; i<9; i++){
        cin >> A[i];
    }
    for(int i=0; i<8; i++){
        cin >> B[i];
    }
    int sumA = 0;
    int sumB = 0;
    for(int i=0; i<9; i++){
        sumA += A[i];
    }
    for(int i=0; i<8; i++){
        sumB += B[i];
    }
    cout << sumA - sumB + 1 << "\n";
}