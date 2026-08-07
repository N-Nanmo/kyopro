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
    string S;
    cin >> S;
    int mode = 0;
    string year = "";
    string month = "";
    string day = "";
    for(int i=0; i<S.size(); i++){
        if(S[i] == '/'){
            mode++;
            continue;
        }
        if(mode == 0){
            year += (char)S[i];
        }else if(mode == 1){
            month += (char)S[i];
        }else{
            day += (char)S[i];
        }
    }
    int Y = stoi(year);
    int M = stoi(month);
    int D = stoi(day);
    while(true){
        if(Y%(M*D) == 0){
            cout << Y << "/";
            if(M < 10){
                cout << "0";
            }
            cout << M << "/";
            if(D < 10){
                cout << "0";
            }
            cout << D << "\n";
            return 0;
        }
        if(Y%4 == 0 && !(Y%100 == 0 && Y%400 != 0) && M == 2 && D == 29){
            M++;
            D = 1;
        }else if(!(Y%4 == 0 && !(Y%100 == 0 && Y%400 != 0)) && M == 2 && D == 28){
            M++;
            D = 1;
        }else if((M == 4 || M == 6 || M == 9 || M == 11) && D == 30){
            M++;
            D = 1;
        }else if(!(M == 4 || M == 6 || M == 9 || M == 11) && D == 31){
            M++;
            D = 1;
        }else{
            D++;
        }
        if(M == 13){
            M = 1;
            Y++;
        }
    }
}