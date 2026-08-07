#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ull L, R, cnt=0;
    cin >> L >> R;
    vector<bool> A(sqrt(R)+3,false);
    vector<bool> B(R-L+1, false);
    if(L == R){
        cout << 1 << endl;
        return 0;
    }
    for(ull i=2; i*i<=R; i++){
        if(!A[i]){
            for(ull j=i+i; j<sqrt(R)+3; j+=i){
                A[j] = true;
            }
        }
    }
    for(ull i=2; i*i<=R; i++){
        if(!A[i]){
            ull a = (L-1)/i*i+i;
            for(ull j=a; j<=R; j+=i){
                B[j-L] = true;
            }
        }
    }
    for(ull i=2; i*i<=R; i++){
        for(ull j=i; j<=R; j*=i){
            if(j > L && j <= R){
                B[j-L] = false;
            }
        }
    }
    for(auto b : B){
        if(!b) cnt++;
    }
    cout << cnt << endl;
}