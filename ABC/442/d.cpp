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
    int N, Q;
    cin >> N >> Q;
    vll A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    vll R(N);
    R[0] = A[0];
    for(int i=1; i<N; i++){
        R[i] = A[i] + R[i-1];
    }
    vll Im(N, 0);
    bool change = false;
    int left = N-1, right = 0;
    for(int i=0; i<Q; i++){
        int a;
        cin >> a;
        if(a == 1){
            int x;
            cin >> x;
            R[x-1] += A[x] - A[x-1];
            int tmp = A[x-1];
            A[x-1] = A[x];
            A[x] = tmp;
        }else{
            int l, r;
            cin >> l >> r;
            if(l-2 < 0){
                cout << R[r-1] << "\n";
                continue;
            }
            cout << R[r-1] - R[l-2] << "\n";
        }
    }
}