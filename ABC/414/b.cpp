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
    int N;
    cin >> N;
    string ans = "";
    int cnt = 0;
    for(int i=0; i<N; i++){
        char c;
        int A;
        cin >> c >> A;
        cnt += A;
        if(cnt > 100){
            cout << "Too Long\n";
            return 0;
        }
        for(int j=0; j<A; j++){
            ans += (char)c;
        }
    }
    cout << ans << "\n";
}