#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,S=0;
  cin >> N;
  vector<int> A(N);
  for(int i =0;i<N;i++){
    cin >> A.at(i);
    S += A.at(i);
  }
  S = S/N;
  for(int j=0;j<N;j++){
    int T;
    T = A.at(j);
    //cout << "T: " << T << " S: " << S << endl;
    if(S<=T){
        cout << T-S << endl;
    }else{
        cout << S-T << endl;
    }
  }
}