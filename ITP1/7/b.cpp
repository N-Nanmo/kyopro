#include <bits/stdc++.h>
//#include <atcoder/all>
#pragma GCC optimize("O3")
using namespace std;
//using namespace atcoder;
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
    vpi A;
    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        A.emplace_back(a, b);
    }
    for(auto [a, b]: A){
        int cnt = 0;
        for(int i=0; i<a; i++){
            for(int j=0; j<a; j++){
                if(i == j) continue;
                for(int k=0; k<a; k++){
                    if(i == k || j == k) continue;
                    if(i+j+k == b){
                        cnt++;
                    }
                }
            }
        }
        cout << cnt/3 << "\n";
    }
}