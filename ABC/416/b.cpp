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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    string T = "";
    bool flag = true;;
    for(int i=0; i<S.size(); i++){
        if(S[i] == '#'){
            T += '#';
            flag = true;
        }else if(flag){
            T += 'o';
            flag = false;
        }else{
            T += '.';
        }
    }
    cout << T << "\n";
}