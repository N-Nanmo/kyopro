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

modint998244353 mpow(int &a){
    modint998244353 result = 1;
    for(int i = 1; i<=a; i++){
        result *= i;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    vi cnt(10);
    for(int i=0; i<S.size(); i++){
        cnt[S[i]-1-'0']++;
    }
    modint998244353 ans = 0;
    for(int i=0; i<9; i++){
        int second = cnt[i+1];
        int first = cnt[i];
        if(second == 0 || first == 0){
            continue;
        }
        for(int j=0; j<min(cnt[i], cnt[i+1]); j++){
            modint998244353 tmp = 1;
            tmp *= mpow(first);
            tmp *= mpow(second);
            int a = first - j - 1;
            tmp /= mpow(a);
            a = j+1;
            tmp /= mpow(a);
            a = second - j - 1;
            tmp /= mpow(a);
            a = j + 1;
            tmp /= mpow(a);
            ans += tmp;
        }
    }
    if(ans.val() == 0){
        cout << 0 << "\n";
    }else{
        cout << ans.val() << "\n";
    }
}