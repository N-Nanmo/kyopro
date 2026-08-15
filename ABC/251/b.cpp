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
    int N, W;
    cin >> N >> W;
    vi A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    unordered_set<int> S;
    for(int i=0; i<N; i++){
        if(A[i] <= W) S.emplace(A[i]);
        for(int j=i+1; j<N; j++){
            if(A[i]+A[j] <= W) S.emplace(A[i]+A[j]);
            for(int k=j+1; k<N+2; k++){
                if(A[i]+A[j]+A[k] <= W) S.emplace(A[i]+A[j]+A[k]);
            }
        }
    }
    cout << S.size() << "\n";
}