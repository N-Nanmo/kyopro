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
    int N;
    cin >> N;
    vi A(N);
    vi R(N+1);
    R[0] = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(A[i] == 0){
            R[i+1] = R[i] - 1;
        }else{
            R[i+1] = R[i] + 1;
        }
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int l, r;
        cin >> l >> r;
        if(R[r] - R[l-1] > 0){
            cout << "win\n";
        }else if(R[r] - R[l-1] < 0){
            cout << "lose\n";
        }else{
            cout << "draw\n";
        }
    }
}