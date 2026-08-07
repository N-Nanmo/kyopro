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
    for (int i = 0; i < N; i++) cin >> A[i];
    vb used(N, false);
    vi ans(N, -1);
    for(int i=0; i<N; i++){
        if(A[i] == -1) continue;
        if(used[A[i]-1]){
            cno;
            return 0;
        }
        used[A[i]-1] = true;
        ans[i] = A[i];
    }
    for(int i=0; i<N; i++){
        bool ok = false;
        if(A[i] == -1){
            for(int j=0; j<N; j++){
                if(!used[j]){
                    used[j] = true;
                    ans[i] = j+1;
                    ok = true;
                    break;
                }
            }
            if(!ok){
                cno;
                return 0;
            }
        }
    }
    cyes;
    for(int i=0; i<N; i++){
        cout << ans[i];
        if(i != N-1) cout << " ";
        else cout << "\n";
    }
}