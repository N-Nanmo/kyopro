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
    int N;
    cin >> N;
    vi D(N-1);
    cin >> D;
    for(int i=0; i<N-1; i++){
        int sumn = 0;
        for(int j=i; j<N-1; j++){
            sumn += D[j];
            cout << sumn << " \n"[j==N-2];
        }
    }
}