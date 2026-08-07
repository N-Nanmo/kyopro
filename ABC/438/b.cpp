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
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    int ans = INT_MAX;
    for(int i=0; i<N-M+1; i++){
        string s = S.substr(i, M);
        string t = T;
        int cnt = 0;
        for(int j=0; j<M; j++){
            while(s[j] != t[j]){
                if(t[j] =='9'){
                    t[j] = '0';
                }else{
                    t[j]++;
                }
                cnt++;
                if(s[j] == t[j]){
                    break;
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}