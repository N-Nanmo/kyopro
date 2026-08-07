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
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N, M;
        cin >> N >> M;
        vll A(M), B(M), C(M);
        for(int j=0; j<N; j++){
            ll a;
            cin >> a;
            A[a%M]++;
        }
        for(int j=0; j<N; j++){
            ll b;
            cin >> b;
            B[b%M]++;
        }
        for(int j=1; j<M-1; j++){
            if(A[j] >= B[M-j]){
                A[j] = A[j] - B[M-j];
                B[M-j] = 0;
            }else{
                B[M-j] = B[M-j] - A[j];
                A[j] = 0;
            }
        }
        ll ans = 0;
        sort(A.begin(), A.end());
        sort(B.rbegin(), B.rend());
        int j=0,k=0;
        while(true){
            if(A[j] >= B[k]){
                ans += A[j] * j;
                B[k] = 0;
                k++;
                if(B[k] == 0) break;
            }else{
                ans += B[k] * j;
                A[j] = 0;
                j++;
                if(A[j] == 0) break;
            }
        }
        cout << ans << "\n";
    }
}