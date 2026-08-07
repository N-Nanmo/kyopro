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
    for(int i=0; i<N; i++) cin >> A[i];
    int cnt_1 = 0;
    int cnt_2 = 0;
    for(int i=0; i<N; i++){
        if(A[i] == 0) cnt_1++;
        else break;
        if(i == N-1){
            cout << 0 << "\n";
            return 0;
        }
    }
    for(int i=N-1; i>=0; i--){
        if(A[i] == 0) cnt_2++;
        else break;
    }
    cout << N - 1 - cnt_1 - cnt_2 << "\n";
}