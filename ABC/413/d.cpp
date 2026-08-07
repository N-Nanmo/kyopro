#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Vll = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull T;
    cin >> T;
    for(ull i=0; i<T; i++){
        ull N;
        bool ok = true;
        cin >> N;
        Vll A(N);
        ll cnta=0, cntb=0;
        for(ull j=0; j<N; j++){
            cin >> A[j];
            if(A[j]<0) cnta++;
            else cntb++;
        }
        sort(A.begin(), A.end(), [](ll a, ll b){ return abs(a) < abs(b);});
        if(abs(A[0]) == abs(A[N-1])){
            if(abs(cnta - cntb) <= 1 || cnta == 0 || cntb == 0){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
            continue;
        }
        for(ull j=2; j<N; j++){
            if(A[j-1]*A[j-1] != A[j-2]*A[j]){
                cout << "No\n";
                ok = false;
                break;
            }
        }
        if(ok){
            cout <<"Yes\n";
        }
    }
}