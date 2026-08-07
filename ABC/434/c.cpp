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
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N, H;
        cin >> N >> H;
        int ma = H;
        int mi = H;
        bool ng = false;
        int lt = 0;
        vvi In(3, vi(N));
        for(int j=0; j<N; j++){
            for(int k=0; k<3; k++){
                cin >> In[k][j];
            }
        }
        for(int j=0; j<N; j++){
            int t, l, u;
            t = In[0][j];
            l = In[1][j];
            u = In[2][j];
            int ma_n, mi_n;
            int crrt = t;
            t -= lt;
            lt = crrt;
            if(!((ma+t < u && ma+t < l) || (mi-t > u && mi-t > l))){
                if(ma+t <= u){
                    ma_n = ma+t;
                }else{
                    ma_n = u;
                }
                if(mi-t >= l){
                    mi_n = mi-t;
                }else{
                    mi_n = l;
                }
                ma = ma_n;
                mi = mi_n;
            }else{
                ng = true;
                break;
            }
        }
        if(ng){
            cno;
        }else{
            cyes;
        }
    }
}