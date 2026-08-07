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

ll jyousan(ll n, ll m){
    ll res = 1;
    for(ll i=0; i<m; i++){
        res *=n;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    for(ll i=0; i<T; i++){
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<bool> used(S.size()+1, false);
        used[0] = true;
        while(true){
            bool ok = false;
            for(int j=0; j < S.size(); j++){
                int a;
            }
        }

    }
}