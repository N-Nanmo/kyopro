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
    string N;
    cin >> N;
    int one = 0;
    int two = 0;
    int three = 0;
    for(int i=0; i<N.size(); i++){
        if(N[i] == '1'){
            one++;
        }else if(N[i] == '2'){
            two++;
        }else if(N[i] == '3'){
            three++;
        }
    }
    if(one == 1 && two == 2 && three == 3){
        cyes;
    }else{
        cno;
    }
}