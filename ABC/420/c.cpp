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
    int N, Q;
    cin >> N >> Q;
    vi A(N);
    vi B(N);
    vb isminA(N, false);
    vb same(N, false);
    vi minAB(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    for(int i=0; i<N; i++){
        if(A[i] < B[i]){
            isminA[i] = true;
            minAB[i] = A[i];
        }else if(A[i] > B[i]){
            isminA[i] = false;
            minAB[i] = B[i];
        }else{
            minAB[i] = A[i];
            same[i] = true;
        }
    }
    ll sum = 0;
    for(int i=0; i<N; i++){
        sum += minAB[i];
    }
    for(int q=0; q<Q; q++){
        char c;
        int X, V;
        cin >> c >> X >> V;
        if(c == 'A'){
            if(same[X-1]){
                sum -= minAB[X-1] - V;
                minAB[X-1] = min(minAB[X-1], V);
            }else{
                if(isminA[X-1]){
                    sum -= max(0, minAB[X-1] - V);
                    minAB[X-1] = min(minAB[X-1], V);
                }else{
                    if(minAB[X-1] > V){
                        isminA[X-1] = true;
                        sum -= max(0, minAB[X-1] - V);
                        minAB[X-1] = V;
                    }
                }
            }
        }else{
            if(same[X-1]){
                sum -= max(0, minAB[X-1] - V);
                minAB[X-1] = min(minAB[X-1], V);
            }else if(!isminA[X-1]){
                sum -= max(0, minAB[X-1] - V);
                minAB[X-1] = min(minAB[X-1], V);
            }else{
                if(minAB[X-1] > V){
                    isminA[X-1] = false;
                    sum -= max(0, minAB[X-1] - V);
                    minAB[X-1] = V;
                }
            }
        }
        cout << sum << "\n";
    }
}