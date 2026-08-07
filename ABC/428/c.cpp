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
    int Q;
    cin >> Q;
    int jd = 0;
    stack<int> lastst;
    bool ok = true;
    int cnt = 0;
    int outnum = 0;
    for(int i=0; i<Q; i++){
        int a;
        cin >> a;
        if(a == 1){
            char c;
            cin >> c;
            if(c == '('){
                jd--;
                cnt++;
                lastst.push(-1);
            }else{
                if(jd == 0 && ok == true){
                    ok = false;
                    outnum = cnt+1;
                }
                jd++;
                cnt++;
                lastst.push(1);
            }
        }else{
            if(cnt == 1){
                ok = true;
            }
            jd += lastst.top()*-1;
            lastst.pop();
            if(outnum == cnt){
                ok = true;
            }
            cnt--;
        }
        if(jd == 0 && ok){
            cyes;
        }else{
            cno;
        }
    }
}