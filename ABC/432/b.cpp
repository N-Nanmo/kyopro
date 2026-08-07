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
    string X;
    cin >> X;
    vi A(X.size());
    for(int i=0; i<X.size(); i++) A[i] = X[i] - '0';
    sort(A.begin(), A.end());
    int zero = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] == 0){
            zero++;
        }else{
            break;
        }
    }
    cout << A[zero];
    for(int i=0; i<zero; i++) cout << '0';
    for(int i=zero+1; i<A.size(); i++){
        cout << A[i];
    }
    cout << "\n";
}