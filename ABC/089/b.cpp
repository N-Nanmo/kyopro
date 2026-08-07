#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VS = vector<string>;
using VB = vector<bool>;
using VVI = vector<vector<int>>;
using VVS = vector<vector<string>>;
using VVB = vector<vector<bool>>;

int main() {
    int N;
    cin >> N;
    set<char> st;
    for(int i=0; i<N; i++){
        char C;
        cin >> C;
        st.emplace(C);
    }
    if(st.size() == 3){
        cout << "Three\n";
    }else{
        cout << "Four\n";
    }
}