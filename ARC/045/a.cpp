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
    vs S;
    while(true){
        string tmp;
        cin >> tmp;
        if(!tmp.empty()){
            S.emplace_back(tmp);
        }else{
            break;
        }
    }
    for(int i=0; i<S.size(); i++){
        if(S[i] == "Left"){
            cout << "<" << " \n"[i == S.size()-1];
        }else if(S[i] == "Right"){
            cout << ">" << " \n"[i == S.size()-1];
        }else{
            cout << "A" << " \n"[i == S.size()-1];
        }
    }
}