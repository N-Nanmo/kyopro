#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, N, cnt=0,sousa=0,M=1;
    cin >> A >> N;
    string S = "101";
    vs kaibun;
    while(stoi(S) < A){
        if(S.size() % 2 == 1){
            if(S[M+sousa] <= '9'){
                if(sousa == 0){
                    kaibun.emplace_back(S);
                    S[M+sousa]++;
                }else{

                }
            }else{
                S[M+sousa] = '0';
                S[M-sousa] = '0';
                if(sousa*2+M < S.size()){
                    sousa++;
                }else{
                    S = "1" + string(S.size(), '0') + "1";
                    M++;
                    sousa = 0;
                }
            }
        }else{
            
        }
    }
}