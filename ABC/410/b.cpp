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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T>
inline istream& operator >> (istream& is, vector<T>& v){
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    for(size_t i = 0; i < v.size(); i++){
        is >> v[i];
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vi X(Q);
    cin >> X;
    vi B(N, 0);
    vi ans;
    for(int i=0; i<Q; i++){
        if(X[i] != 0){
            B[X[i]-1]++;
            ans.emplace_back(X[i]-1);
        }else{
            int tmp = min_element(all(B)) - B.begin();
            B[tmp]++;
            ans.emplace_back(tmp);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i]+1 << " \n"[i == ans.size()-1];
    }
}