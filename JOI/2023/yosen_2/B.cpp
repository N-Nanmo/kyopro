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
    vi A(N), B(N), C(N), D(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    for(int i=0; i<N; i++){
        cin >> C[i];
    }
    for(int i=0; i<N; i++){
        cin >> D[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    int ans = INT_MAX;
    for(int i=0; i<4; i++){
        for(int j=0; j<N; j++){
            int minnum;
            if(i == 0){
                minnum = A[j];
            }else if(i==1){
                minnum = B[j];
            }else if(i == 2){
                minnum = C[j];
            }else{
                minnum = D[j];
            }
            int a = *upper_bound(A.begin(), A.end(), minnum);
            int b = *upper_bound(B.begin(), B.end(), minnum);
            int c = *upper_bound(C.begin(), C.end(), minnum);
            int d = *upper_bound(D.begin(), D.end(), minnum);
            ans = min(ans , abs(minnum - max(max(a, b), max(c, d))));
        }
    }
    cout << ans << "\n";
}