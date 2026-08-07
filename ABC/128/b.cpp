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
    vector<tuple<string, int, int>> A(N);
    for(int i=0; i<N; i++){
        string S;
        int P;
        cin >> S >> P;
        A[i] = {S, P, i+1};
    }
    sort(A.begin(), A.end(), [](auto a, auto b){
        if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });
    for(int i=0; i<N; i++){
        cout << get<2>(A[i]) << "\n";
    }
}