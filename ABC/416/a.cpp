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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L, R;
    string S;
    cin >> N >> L >> R >> S;
    for(int i=L-1; i<R; i++){
        if(S[i] != 'o'){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}