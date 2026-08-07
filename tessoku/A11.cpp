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
    int N, X;
    cin >> N >> X;
    vi A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    int l = 0, r = N-1, m;
    while(r - l > 0){
        m=(l+r)/2;
        if(A[m] == X){
            cout << m+1 << "\n";
            return 0;
        }else if(A[m] < X){
            l = m+1;
        }else{
            r = m-1;
        }
    }
    cout << l+1 << "\n";
}