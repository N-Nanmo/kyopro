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
using vf = vector<float>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    int Q;
    cin >> Q;
    vs W(Q);
    for(int i=0; i<Q; i++) cin >> W[i];
    map<char, int> mpT;
    map<char, int> mpA;
    for(int i=0; i<S.size(); i++){
        mpT[S[i]]++;
    }
    for(int i=0; i<T.size(); i++){
        mpA[T[i]]++;
    }
    for(int i=0; i<Q; i++){
        bool ok = false;
        for(int j=0; j<W[i].size(); j++){
            if(mpT[W[i][j]] > 0 && mpA[W[i][j]] == 0){
                cout << "Takahashi\n";
                ok = true;
                break;
            }else if(mpT[W[i][j]] == 0 && mpA[W[i][j]] > 0){
                cout << "Aoki\n";
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << "Unknown\n";
        }
    }
}