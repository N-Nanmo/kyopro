#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
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
    cin >> N >> M;
    vpi H(M);
    for(int i=0; i<M; i++){
        cin >> H[i].first >> H[i].second;
    }
    ll ans = LONG_MAX;
    for(int bit=0; bit < (1 << N); bit++){
        ll cnt=0;
        for(int i=0; i<M; i++){
            if(bit & (1 << (H[i].first-1))){
                if(bit & (1 << (H[i].second-1))){
                    cnt++;
                }
            }else{
                if((bit & (1 << (H[i].second-1))) == 0){
                    cnt++;
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}