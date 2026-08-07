#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N,Y;
    cin >> N >> Y;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N-i;j++){
            for(int k=0;k<=N-i-j;k++){
                if(i*10000+j*5000+k*1000==Y&&i+j+k==N){
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}