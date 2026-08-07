#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        if(a < b){
            ans++;
        }
    }
    cout << ans << "\n";
}