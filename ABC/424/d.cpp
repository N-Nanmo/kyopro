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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int H, W;
        cin >> H >> W;
        vvb C(H, vb(W, false));
        for(int j=0; j<H; j++){
            string s;
            cin >> s;
            for(int k=0; k<W; k++){
                if(s[k] == '.') C[j][k] = true;
            }
        }
        vvb possible(H, vb(W, true));
        for(int j=0; j<H; j++){
            for(int k=0; k<W; k++){
                if(C[j][k]) possible[j][k] = false;
                int cnt = 0;
                if(j > 0 && C[j-1][k]) cnt++;
                if(j < H-1 && C[j+1][k]) cnt++;
                if(k > 0 && C[j][k-1]) cnt++;
                if(k < W-1 && C[j][k+1]) cnt++;
                if(j > 0 && k > 0 && C[j-1][k-1]) cnt++;
                if(j > 0 && k < W-1 && C[j-1][k+1]) cnt++;
                if(j < H-1 && k > 0 && C[j+1][k-1]) cnt++;
                if(j < H-1 && k < W-1 && C[j+1][k+1]) cnt++;
                if(cnt >= 2) possible[j][k] = false;
            }
        }
        
    }
}