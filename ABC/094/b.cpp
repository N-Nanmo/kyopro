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
    int N, M, X;
    cin >> N >> M >> X;
    vb R(N,false);
    for(int i=0; i<M; i++){
        int tmp;
        cin >> tmp;
        R[tmp-1] = true;
    }
    int leftc = 0;
    for(int i=X-2; i>=0; i--){
        if(R[i]){
            leftc++;
        }
    }
    int rightc = 0;
    for(int i=X; i<N; i++){
        if(R[i]){
            rightc++;
        }
    }
    cout << min(leftc, rightc) << "\n";
}