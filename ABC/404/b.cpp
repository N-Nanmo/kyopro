#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int hantei(vector<vector<char>> A, vector<vector<char>> B, int N) {
    int cnt =0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != B[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

void rotation(vector<vector<char>>& A,int N){
    vector<vector<char>> S(N, vector<char>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            S[j][N-i-1] = A[i][j];
        }
    }
    A = S;
}
int main() {
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> B[i][j];
        }
    }
    int hanteiA = hantei(A, B, N);
    rotation(A, N);
    int hanteiB = hantei(A, B, N)+1;
    rotation(A, N);
    int hanteiC = hantei(A, B, N)+2;
    rotation(A, N);
    int hanteiD = hantei(A, B, N)+3;
    rotation(A, N);
    int minAB = min(hanteiA, hanteiB);
    int minCD = min(hanteiC, hanteiD);
    int ans = min(minAB, minCD);
    cout << ans << endl;
    return 0;
}