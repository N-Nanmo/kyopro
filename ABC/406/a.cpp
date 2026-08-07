#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  if(A > C || A == C && B > D){
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }
}