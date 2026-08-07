#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    string ans = "";
    for(int i=0; i<S.size(); i++){
        if(S[i] == '2'){
            ans += "2";
        }
    }
    cout << ans << "\n";
}