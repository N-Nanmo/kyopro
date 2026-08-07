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
    int N;
    string S;
    cin >> N >> S;
    int J_cnt = 0;
    int OI_cnt = 0;
    char last = -1;
    bool zone = false;
    string ans = "";
    for(int i=0; i<N; i++){
        if(zone){
            if((last == 'J' && S[i] == 'J') || (last == 'I' && S[i] == 'J')){
                J_cnt++;
            }else if((last == 'J' || last == 'I') && S[i] == 'O'){

            }else if(last == 'O' && S[i] == 'I'){
                OI_cnt++;
            }else{
                for(int j=0; j<OI_cnt; j++){
                    ans += "OI";
                }
                for(int j=0; j<J_cnt; j++){
                    ans += "J";
                }
                OI_cnt = 0;
                J_cnt = 0;
                zone = false;
                if(last == 'O'){
                    ans += 'O';
                }
            }
        }
        if(S[i] == 'J' && zone == false){
            J_cnt++;
            zone = true;
        }else if(!zone){
            ans += S[i];
        }
        last = S[i];
    }
    if(zone){
        for(int j=0; j<OI_cnt; j++){
            ans += "OI";
        }
        for(int j=0; j<J_cnt; j++){
            ans += "J";
        }
        if(S[N-1] == 'O'){
            ans += "O";
        }
    }
    cout << ans << "\n";
}