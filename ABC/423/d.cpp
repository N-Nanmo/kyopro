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
    ull N, K;
    cin >> N >> K;
    vector<tuple<ull, ull, ull>> A(N);
    for(ull i=0; i<N; i++){
        cin >> get<0>(A[i]) >> get<1>(A[i]) >> get<2>(A[i]);
    }
    sort(A.begin(), A.end());
    priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, greater<pair<ull, ull>>> q;
    ull los = 0;
    ull crrp = 0;
    for(ull i=0; i<N; i++){
        if(get<2>(A[i]) + crrp <= K){
            crrp += get<2>(A[i]);
            q.emplace(max(get<0>(A[i]), los) + get<1>(A[i]), get<2>(A[i]));
            cout << max(get<0>(A[i]), los) << "\n";
        }else{
            while(get<2>(A[i]) + crrp > K){
                los = q.top().first;
                crrp -= q.top().second;
                q.pop();
            }
            crrp += get<2>(A[i]);
            q.emplace(max(los + get<1>(A[i]), get<0>(A[i]) + get<1>(A[i])), get<2>(A[i]));
            cout << max(los, get<0>(A[i])) << "\n";
        }
    }
}