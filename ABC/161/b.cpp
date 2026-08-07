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
    float N, M;
    cin >> N >> M;
    vi A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int cnt = 0;
    float sum = 0;
    for(int i=0; i<N; i++){
        sum += A[i];
    }
    for(int i=0; i<N; i++){
        if(A[i]*4*M >= sum) cnt++;
    }
    if(cnt >= M){
        cyes;
    }else{
        cno;
    }
}