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
using vf = vector<float>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
    string S, T;
    cin >> S >> T;
    map<char, int> mp;
    for(int i=0; i<T.size(); i++) mp[T[i]]++;
    for(int i=1; i<S.size(); i++){
        if(isupper(S[i])){
            if(mp[S[i-1]] == 0){
                cno;
                return 0;
            }
        }
    }
    cyes;
}