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
    vi Num(N+1);
    for(int i=1; i<3175; i++){
        for(int j=i+1; j<3175; j++){
            int tmp = i * i + j * j;
            if(tmp > N) continue;
            Num[tmp]++;
        }
    }
    vi ans;
    for(int i=0; i<N+1; i++){
        if(Num[i] == 1){
            ans.emplace_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    if(ans.size() == 0){
        cout << "\n";
        return 0;
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
}