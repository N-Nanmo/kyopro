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
    
    ll R_t, C_t, R_a, C_a, N, M, L;
    cin >> R_t >> C_t >> R_a >> C_a >> N >> M >> L;
    vector<char> S_c(M);
    vector<char> T_c(L);
    vll S_l(M);
    vll T_l(L);
    bool same = (R_t == R_a && C_t == C_a);
    for(ll i=0; i<M; i++){
        cin >> S_c[i] >> S_l[i];
    }
    for(ll i=0; i<L; i++){
        cin >> T_c[i] >> T_l[i];
    }
    while(true){
        bool isSmin = (S_c.size() <= T_c.size());
        if(isSmin){
            
        }else{

        }
    }
}