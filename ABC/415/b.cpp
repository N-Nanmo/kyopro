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
    string S;
    cin >> S;
    vi ans;
    for(int i=0; i<S.size(); i++){
        if(S[i] == '#'){
            ans.emplace_back(i+1);
        }
    }
    for(int i=0; i<ans.size(); i+=2){
        cout << ans[i] << "," << ans[i+1] << "\n";
    }
}