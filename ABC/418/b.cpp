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
    string S;
    cin >> S;
    double ans = 0;
    for(int i=0; i<S.size(); i++){
        for(int j=i+2; j<S.size(); j++){
            if(S[i] == 't' && S[j] == 't'){
                double cnt = 2;
                for(int k=i+1; k<j; k++){
                    if(S[k] == 't'){
                        cnt++;
                    }
                }
                ans = max(ans, (cnt-2)/(j-i-1));
            }
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
}