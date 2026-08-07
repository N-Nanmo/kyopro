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
    vi tmp(N+1, 0);
    tmp[0] = 1;
    for(int i=1; i<N+1; i++){
        tmp[i] += tmp[i-1]/10000 + tmp[i-1]%10000/1000 + tmp[i-1]%1000 / 100 + tmp[i-1]%100/10 + tmp[i-1]%10;
        if(i != 1){
            tmp[i] += tmp[i-1];
        }
    }
    cout << tmp[N] << "\n";
}