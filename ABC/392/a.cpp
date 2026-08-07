#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if(A*B == C || B * C == A || A * C == B){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}