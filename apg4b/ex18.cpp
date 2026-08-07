#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<char>> H(N,vector<char>(N,'-'));
  for(int i=0;i<M;i++){
    int a,b;
    a=A.at(i)-1;
    b=B.at(i)-1;
    H.at(a).at(b) = 'o';
    H.at(b).at(a) = 'x';
}
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << H.at(i).at(j);
      if(j!=N-1){
        cout << " ";
      }
    }
    cout << endl;
  }
}
