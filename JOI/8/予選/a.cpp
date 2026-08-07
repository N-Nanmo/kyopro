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
    for(int i=0; i<3; i++){
        vi A(6);
        for(int j=0; j<6; j++) cin >> A[j];
        vi ans(3);
        if(A[2] > A[5]){
            A[5] += 60;
            A[4]--;
        }
        ans[2] = A[5] - A[2];
        if(A[1] > A[4]){
            A[4] += 60;
            A[3]--;
        }
        ans[1] = A[4] - A[1];
        ans[0] = A[3] - A[0];
        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }
}