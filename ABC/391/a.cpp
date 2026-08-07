#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string A;
    cin >> A;
    if(A == "N"){
        cout << "S" << endl;
    }else if(A== "E"){
        cout << "W" << endl;
    }else if(A == "W"){
        cout << "E" << endl;
    }else if(A == "S"){
        cout << "N"<< endl;
    }else if(A== "NE"){
        cout << "SW" << endl;
    }else if(A == "NW"){
        cout << "SE" << endl;
    }else if(A=="SE"){
        cout << "NW" << endl;
    }else if (A== "SW"){
        cout << "NE" << endl;
    }
}