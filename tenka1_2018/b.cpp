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
    int A, B, K;
    cin >> A >> B >> K;
    bool TA = false;
    for(int i=0; i<K; i++){
        if(!TA){
            if(A%2 == 1){
                A--;
            }
            B += A/2;
            A /= 2;
        }else{
            if(B%2 == 1){
                B--;
            }
            A += B/2;
            B /= 2;
        }
        TA = !TA;
    }
    cout << A << " " << B << "\n";
}