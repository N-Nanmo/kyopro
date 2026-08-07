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
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vll A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    while(A.size() > 1){
        vll tmp(A.size()-1);
        for(int i=1; i<A.size(); i++){
            tmp[i-1] = A[i-1] + A[i];
        }
        for(int i=0; i<tmp.size(); i++){
            cout << tmp[i];
            if(i < tmp.size()-1){
                cout << " ";
            }
        }
        cout << "\n";
        A = tmp;
    }
}