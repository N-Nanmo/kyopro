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
    vi T(12*24+1, 0);
    vpi P(N);
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        P[i].first = stoi(S.substr(0, 2)) * 60 + stoi(S.substr(2, 2));
        P[i].second = stoi(S.substr(5, 2)) * 60 + stoi(S.substr(7, 2));
    }
    for(int i=0; i<N; i++){
        P[i].first = P[i].first - P[i].first % 5;
        if(P[i].second % 5 != 0) P[i].second = P[i].second + (5 - P[i].second % 5);
    }
    for(int i=0; i<N; i++){
        T[P[i].first / 5]++;
        T[P[i].second / 5]--;
    }
    for(int i=1; i<12*24; i++){
        T[i] += T[i-1];
    }
    bool time = false;
    int st = -1;
    for(int i=0; i<=12*24; i++){
        if(T[i] > 0){
            if(!time){
                st =  i * 5;
                time = true;
            }
        }else{
            if(time){
                time = false;
                if(st / 60 < 10) cout << "0";
                cout << st / 60;
                if(st % 60 < 10) cout << "0";
                cout << st % 60 << '-';
                if(i * 5 / 60 < 10) cout << "0";
                cout << i * 5 / 60;
                if(i * 5 % 60 < 10) cout << "0";
                cout << i * 5 % 60 << '\n';
            }
        }
    }
}