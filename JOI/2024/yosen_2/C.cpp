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
    ll X, Y, Z, P,sum=0;
    cin >> X >> Y >> Z >> P;
    vll A(X);
    vll B(Y);
    vll C(Z);
    for(int i=0; i<X; i++) cin >> A[i];
    for(int i=0; i<Y; i++) cin >> B[i];
    for(int i=0; i<Z; i++) cin >> C[i];
    sort(A.begin(),A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    if(abs(A[0] - P) >= abs(A[X-1] - P)){
        sum += A[0];
    }else{
        sum += A[X-1];
    }
    ll best = 0;
    ll temp = LLONG_MAX;
    for(int i=0; i<Y; i++){
        ll b = abs(B[i] + sum - P);
        if(b < temp){
            temp = b;
            best = B[i];
        }
    }
    sum += best;
    
    ll a = abs(sum + C[0] - P);
    ll b = abs(sum + C[Z-1] - P);
    if(a >= b){
        cout << a << "\n";
    }else{
        cout << b << "\n";
    }
}