#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N,Q,skip=0;
    cin >> N >> Q;
    vector<ll> A(N,0);
    for(ll i=1; i<=N; i++){
        A[i-1] =i;
    }
    for(ll i = 0; i<Q; i++){
        ll a,p;
        cin >> a >> p;
        if(a == 1){
            ll x;
            cin >> x;
            A[(p-1+skip)%N] = x;
        }else if(a==2){
            cout << A[(p-1+skip)%N] << endl;
        }else{
            skip+= p;
        }
    }
}