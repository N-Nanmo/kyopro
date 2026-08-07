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
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C, cnt=0;
    cin >> A >> B >> C;
    if(A%2 == 1 || B%2 == 1 || C%2 == 1){
        cout << "0\n";
        return 0;
    }
    if(A == B && B == C){
        cout << "-1\n";
        return 0;
    }
    int middle = B/2;
    while(A%2 == 0 && B%2 == 0 && C%2 == 0){
        cnt++;
        int a = A/2;
        int b = B;
        int c = C/2;
        A = c + middle;
        C = a + middle;
    }
    cout << cnt << "\n";
}