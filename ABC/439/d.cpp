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
using vf = vector<float>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
    ll N;
    cin >> N;
    vi A(N);
    for(ll i=0; i<N; i++) cin >> A[i];
    map<ll, ll> mp;
    for(int i=0; i<N; i++){
        mp[A[i]]++;
    }
    map<ll, ll> mc = mp;
    ll ans = 0;
    for(ll i=0; i<N; i++){
        if(A[i]%5 == 0){
            ans += mc[A[i]/5*7] * mc[A[i]/5*3];
        }
        mc[A[i]]--;
    }
    mc = mp;
    for(ll i=N-1; i>=0; i--){
        if(A[i]%5 == 0){
            ans += mc[A[i]/5*7] * mc[A[i]/5*3];
        }
        mc[A[i]]--;
    }
    cout << ans << "\n";
}