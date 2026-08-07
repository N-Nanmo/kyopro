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
    int D;
    double S;
    cin >> D >> S;
    string C;
    if(D <= 112){
        C = "N";
    }else if(D <= 337){
        C = "NNE";
    }else if(D <= 562){
        C = "NE";
    }else if(D <= 787){
        C = "ENE";
    }else if(D <= 1012){
        C = "E";
    }else if(D <= 1237){
        C = "ESE";
    }else if(D <= 1462){
        C = "SE";
    }else if(D <= 1687){
        C = "SSE";
    }else if(D <= 1912){
        C = "S";
    }else if(D <= 2137){
        C = "SSW";
    }else if(D <= 2362){
        C = "SW";
    }else if(D <= 2587){
        C = "WSW";
    }else if(D <= 2812){
        C = "W";
    }else if(D <= 3037){
        C = "WNW";
    }else if(D <= 3262){
        C = "NW";
    }else if(D <= 3487){
        C = "NNW";
    }else{
        C = "N";
    }
    S /= 60.0;
    S = round(S * 10);
    if(S <= 2){
        cout << 'C' << " " << 0 << "\n";
    }else if(S <= 15){
        cout << C << " " << 1 << "\n";
    }else if(S <= 33){
        cout << C << " " << 2 << "\n";
    }else if(S <= 54){
        cout << C << " " << 3 << "\n";
    }else if(S <= 79){
        cout << C << " " << 4 << "\n";
    }else if(S <= 107){
        cout << C << " " << 5 << "\n";
    }else if(S <= 138){
        cout << C << " " << 6 << "\n";
    }else if(S <= 171){
        cout << C << " " << 7 << "\n";
    }else if(S <= 207){
        cout << C << " " << 8 << "\n";
    }else if(S <= 244){
        cout << C << " " << 9 << "\n";
    }else if(S <= 284){
        cout << C << " " << 10 << "\n";
    }else if(S <= 326){
        cout << C << " " << 11 << "\n";
    }else{
        cout << C << " " << 12 << "\n";
    }
}