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
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> T(N);
    vs S(N);
    for(int i=0; i<N; i++){
        cin >> S[i];
        T[i].first = 0;
        T[i].second = i+1;
    }
    for(int i=0; i<M; i++){
        int cnt = 0;
        for(int j=0; j<N; j++){
            if(S[j][i] == '0'){
                cnt++;
            }
        }
        char get = -1;
        if(cnt < N-cnt){
            get = '1';
        }else if(cnt > N-cnt){
            get = '0';
        }
        for(int j=0; j<N; j++){
            if(S[j][i] == get || get == -1){
                T[j].first++;
            }
        }
    }
    sort(T.begin(), T.end());
    int maxnum = T[0].first;
    vi ans;
    for(int i=0; i<N; i++){
        if(T[i].first == maxnum){
            ans.emplace_back(T[i].second);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i != ans.size()-1){
            cout << " ";
        }
    }
}