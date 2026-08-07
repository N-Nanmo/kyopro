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
    cin >> N >> K;
    vll A(N);
    for(ll i=0; i<N; i++){
        cin >> A[i];
    }
    //二分探索解法
    /*
    ll ans = 0;
    for(ll i=0; i<N; i++){
        ll a = upper_bound(A.begin(), A.end(), A[i]+K) - A.begin();
        ans += a - i - 1;
    }
    cout << ans << "\n";
    */
    //尺取り法
    vll R(N, 0);
    for(ll i=0; i<N; i++){
        if(i == 0){
            R[i] = 0;
        }else{
            R[i] = R[i-1];
        }
        while(R[i]+1 < N && A[R[i]+1] <= A[i] + K){
            R[i]++;
        }
    }
    ll ans = 0;
    for(ll i=0; i<N; i++){
        ans += R[i] - i;
    }
    cout << ans << "\n";
}