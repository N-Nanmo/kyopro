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
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;
    vi P(N);
    for(int i=0; i<N; i++) cin >> P[i];
    int first = 0;
    int second = 0;
    int third = 0;
    for(int i=0; i<N; i++){
        if(P[i] <= A){
            first++;
        }else if(P[i] <= B){
            second++;
        }else{
            third++;
        }
    }
    cout << min(first, min(second, third)) << "\n";
}