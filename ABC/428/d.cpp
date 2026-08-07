#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
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
    ll T;
    cin >> T;
    ll fans = 0;
    for(int i=0; i<T; i++){
        ull C, D;
        cin >> C >> D;
        ull j = 4;
        ll ans = 0;
        ull seigen = stoull(to_string(C) + to_string(D+C));
        while(seigen >= j*j){
            string heihou = to_string(j*j);
            int cnt_c = 0;
            int sum_c = 0;
            for(int k=to_string(C).size()-1; k>=0; k--){
                sum_c += (heihou[k] - '0') * pow(10, cnt_c);
                cnt_c++;
            }
            if(sum_c == C){
                if(heihou[to_string(C).size()] == '0'){
                    j++;
                    continue;
                }
                int cnt = 0;
                int sum = 0;
                for(int k=heihou.size()-1; k >= to_string(C).size(); k--){
                    sum += (heihou[k] - '0') * pow(10, cnt);
                    cnt++;
                }
                if(sum - C <= D){
                    ans++;
                }
            }
            j++;
        }
        cout << ans << "\n";
    }
}