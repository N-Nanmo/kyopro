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
    cin >> N;
    vi A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    stack<pair<int, int>> sp;
    for(int i=0; i<N; i++){
        if(sp.size() == 0){
            sp.push(make_pair(A[i], 1));
        }else{
            if(sp.top().first == A[i]){
                pi p = sp.top();
                sp.pop();
                sp.emplace(A[i], p.second+1);
                if(sp.top().second == 4){
                    sp.pop();
                }
            }else{
                sp.emplace(A[i], 1);
            }
        }
    }
    int ans = 0;
    while(!sp.empty()){
        pi p = sp.top();
        sp.pop();
        ans += p.second;
    }
    cout << ans << "\n";
}