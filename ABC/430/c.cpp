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
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;
    vi a_cnt;
    vi b_cnt;
    bool isa;
    bool fa;
    if(S[0] == 'a'){
        isa = true;
        fa = true;
    }else{
        isa = false;
        fa = false;
    }
    int a_tmp = 0;
    int b_tmp = 0;
    for(int i=0; i<N; i++){
        if(isa){
            if(S[i] == 'a'){
                a_tmp++;
            }else{
                a_cnt.emplace_back(a_tmp);
                isa = false;
                a_tmp = 0;
                b_tmp++;
            }
        }else{
            if(S[i] == 'b'){
                b_tmp++;
            }else{
                b_cnt.emplace_back(b_tmp);
                isa = true;
                b_tmp = 0;
                a_tmp++;
            }
        }
    }
    if(a_cnt.size() < b_cnt.size()){
        a_cnt.emplace_back(0);
    }else if(a_cnt.size() > b_cnt.size()){
        b_cnt.emplace_back(0);
    }
    ll ans = 0;
    for(int i=0; i<a_cnt.size(); i++){
        for(int k=0; k<2; k++){
            bool sa;
            if((fa && k == 0) || (!fa && k == 1)){
                sa = true;
            }else{
                sa = false;
            }
            int a_n = 0;
            int b_n = 0;
            int cnt = 0;
            for(int j=i; j<a_cnt.size(); j++){
                a_n += a_cnt[j];
                b_n += b_cnt[j];
                if(sa){
                    if(b_n >= B){
                        cnt = a_n + B-1;
                        break;
                    }
                }else{
                    if(b_n >= B){
                        cnt = a_n - a_cnt[i] + B-1;
                        a_n;
                        break;
                    }
                }
            }
            if(a_n >= A){
                for(int j=1; j<=cnt-A; j++){
                    ans += j;
                }
            }
        }
    }
    cout << ans << "\n";
}