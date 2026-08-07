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
    int N, M;
    cin >> N >> M;
    vi A(N);
    cin >> A;
    vi m(M);
    for(int i=0; i<N; i++){
        m[A[i]-1]++;
    }
    for(int i=0; i<M; i++){
        if(m[i] == 0){
            cout << 0 << "\n";
            return 0;
        }
    }
    int cnt = 0;
    for(int i=0; i<N; i++){
        int tmp = A.back();
        A.pop_back();
        m[tmp-1]--;
        if(m[tmp-1] == 0){
            cout << i+1 << "\n";
            return 0;
        }
    }
}