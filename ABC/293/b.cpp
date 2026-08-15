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
    int N;
    cin >> N;
    vi A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    map<int, int> P;
    vi X;
    for(int i=0; i<N; i++){
        if(P[i+1] == 0){
            P[A[i]]++;
        }
    }
    for(int i=0; i<N; i++){
        if(P[i+1] == 0) X.emplace_back(i+1);
    }
    cout << X.size() << "\n";
    for(int i=0; i<X.size(); i++) cout << X[i] << " \n"[i==N-1];
}