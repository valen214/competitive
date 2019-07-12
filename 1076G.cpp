
/*
https://codeforces.com/problemset/problem/1076/G




*/

#include <iostream>

using namespace std;

int main()
{
    int n, m, q;
    string line;
    
    cin >> n >> m >> q;
    
    bool *a = new bool[n]; // 1 is odd
    
    long long temp = 0;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        a[i] = temp & 0x01;
    }
    
    int t, l, r, d;
    while(q--){
        cin >> t;
        switch(t){
        case 1:
            cin >> l >> r >> d;
             
            for(int i = l; i <= r; ++i){
                a[i] ^= 1;
            }
            break;
        case 2:
            cin >> l >> r;
            
            break;
        default:
            break;
        }
    }
    
    for(int i = 0; i < n; ++i){
        cout << a[i];
    }
    
    return 0;
}