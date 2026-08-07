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
    int N;
    cin >> N;
    vi A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vi ans(*max_element(A.begin(), A.end()) + N/5, 0);
    sort(A.begin(), A.end());
    for(int i=0; i<N; i++){
        ans[A[i]-1]++;
    }
    for(int i=ans.size()-1; i>0; i--){
        ans[i-1] += ans[i];
    }
    int maxn = 0;
    for(int i=0; i<ans.size(); i++){
        if(ans[i] >= 10){
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
            maxn = i+1;
        }
        if(ans[i] != 0){
            maxn = max(i, maxn);
        }
    }
    for(int i=maxn; i>=0; i--){
        cout << ans[i];
    }
    cout << "\n";
}