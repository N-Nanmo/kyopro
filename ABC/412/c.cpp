#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll T;
    cin >> T;
    for(ll i=0; i<T; i++){
        ll N;
        bool break_f = false;
        cin >> N;
        vector<ll> A(N);
        for(int j=0; j<N; j++){
            cin >> A[j];
        }
        sort(A.begin()+1, A.end()-1);
        ll a = A[0];
        ll cnt = 1;
        ll cnt2 = 1;
        ll tmp = 1;
        while(true){
            a *= 2;
            cnt++;
            if(a >= A[N-1]){
                cout << cnt << endl;
                break_f = true;
                break;
            }
            for(;cnt2<N;cnt2++){
                if(a < A[cnt2]){
                    break;
                }
            }
            if(break_f) break;
            if(tmp == cnt2 && cnt2 != N){
                cout << "-1" << endl;
                break_f = true;
                break;
            }
            tmp = cnt2;
            cnt2--;
            a = A[cnt2];
        }
        if(break_f) continue;
    }
}