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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
vs ans;
void rekkyo(int cnt, int &K, string crr,int &N, vs &S){
    if(cnt == K){
        ans.emplace_back(crr);
        return;
    }
    for(int i=0; i<N; i++){
        rekkyo(cnt+1, K, crr+S[i], N, S);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, X;
    cin >> N >> K >> X;
    string crr = "";
    vs S(N);
    for(int i=0; i<N; i++) cin >> S[i];
    rekkyo(0, K, crr, N, S);
    sort(ans.begin(), ans.end());
    cout << ans[X-1] << "\n";
}