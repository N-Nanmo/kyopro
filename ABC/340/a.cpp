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
    int A, B, C;
    cin >> A >> B >> C;
    int crr = A;
    if(A == B){
        cout << A << "\n";
        return 0;
    }
    vi ans;
    while(true){
        ans.emplace_back(crr);
        crr += C;
        if(crr == B){
            ans.emplace_back(crr);
            break;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size()-1];
    }
}