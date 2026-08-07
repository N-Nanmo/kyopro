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
    int N;
    cin >> N;
    vi A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vi ans;
    sort(A.begin(), A.end());
    if(N%2 == 0){
        vi tmp;
        int checkn = -1;
        bool ok = true;
        for(int j=0; j<N/2; j++){
            tmp.emplace_back(A[j] + A[N-j-1]);
            if(checkn == -1) checkn = tmp[j];
            else{
                if(checkn != tmp[j]) ok = false;
            }
        }
        if(ok){
            ans.emplace_back(tmp[0]);
        }
    }
    int maxn = *max_element(A.begin(), A.end());
    int mcnt = 0;
    for(int i=0; i<N; i++){
        if(maxn == A[i]) mcnt++;
    }
    vi tmp;
    int checkn = maxn;
    bool ok = true;
    if((N-mcnt)%2 == 0){
        for(int j=0; j<(N-mcnt)/2; j++){
            tmp.emplace_back(A[j] + A[N-j-1-mcnt]);
            if(checkn != tmp[j]) ok = false;
        }
        if(ok){
            ans.emplace_back(maxn);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
}