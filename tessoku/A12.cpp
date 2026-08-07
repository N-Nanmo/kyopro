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
    ll N, K;
    cin >> N  >> K;
    ll left = 0, right = 1000000000 - 1, m;
    vi A(N);
    for(ll i=0; i<N; i++) cin >> A[i];
    while(right - left > 0){
        m = (left+right)/2;
        ll cnt = 0;
        for(ll i=0; i<N; i++){
            cnt += m / A[i];
        }
        if(cnt < K){
            left = m+1;
        }else{
            right = m;
        }
    }
    cout << left << "\n";
}