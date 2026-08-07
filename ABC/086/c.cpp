#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> x(N+1),t(N+1),y(N+1);
    t.at(0) = 0;
    x.at(0) = 0;
    y.at(0) = 0;
    for(int i=1;i<N+1;i++){
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }
    for(int j=0;j<N;j++){
        int A,B;
        bool D = false;
        A = abs(x.at(j)-x.at(j+1))+abs(y.at(j)-y.at(j+1));
        B = t.at(j+1)-t.at(j);
        for(int n=0;n<B;n+=2){
            if(A==B-n){
                D = true;
                break;
            }
        }
        if(!D){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}