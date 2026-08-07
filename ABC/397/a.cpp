#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    float X;
    cin >> X;
    if(X >= 38){
        cout << 1 << "\n";
    }else if(X >= 37.5){
        cout << 2 << "\n";
    }else{
        cout << 3 << "\n";
    }
}