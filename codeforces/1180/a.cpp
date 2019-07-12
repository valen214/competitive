#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main(){
    ull n;
    cin >> n;
    /*
    1
    1 + 4
    1 + 4 + 8
    1 + 4 + 8 + 12
    1 + 4 + 8 + 12 + 16
    */
    if(n == 1){
        cout << 1 << endl;
    } else{
        --n;
        ull a = (4 + n * 4) * n / 2 + 1;
        cout << a << endl;
    }
}
