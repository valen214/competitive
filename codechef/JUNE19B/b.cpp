#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

#define forab(i, a, b) for(ll i=a, max=b; i < b; ++i)
#define repeat(i, n) for(ll i=0, max=n; i < max; ++i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )

ll logll(ll l){
    ll out = 0;
    while(l /= 10){
        ++out;
    }
    return out;
}

using namespace std;

int main() {
    /*
      19 (1),  28,  37,  46,  55,  64,  73,  82,  91,
(10) 109, 118, 127, 136, 145, 154, 163, 172, 181, 190,
          208, 217, 226, 235, 244, 253, 262, 271, 280,
     299,      307, 316, 325, 334, 343, 352, 361, 370,
     389, 398,      406, XXX, XXX, XXX, XXX, XXX, XXX,
     479, 488, 497,      505, XXX, XXX, XXX, XXX, XXX,
     XXX, XXX, XXX, XXX,      604, XXX, XXX, XXX, XXX,
     XXX, XXX, XXX, XXX, XXX,      703, XXX, XXX, XXX,
     XXX, XXX, XXX, XXX, XXX, XXX,      802, 811, 820,
     839, XXX, XXX, XXX, XXX, XXX, XXX,      901, 910 (91),
     929, 938, 947, 956, 965, 974, 983, 992,
    1009 (100), 
    */
    ll T;
    cin >> T;
    repeat(unused, T){
        ll N;
        cin >> N;
        
        
        ll out_i = logll(N);
        
        
        ll base = pow(10, out_i);
        ll base10 = base * 10;
        ll now = base10 + 9;
        
        // cout << "N:" << N << " " << out_i << " " << base << " " << base10 << " " << now << endl;
        
        out_i = base;
        while(out_i < N){
            
            if(out_i + base > N){
                base10 = base;
                base /= 10;
                continue;
            }
            cout << "N:" << N << " " << out_i << " " << base << " " << base10 << " " << now << endl;
            if(now % base10 == 0){
                now += base10 * (logll(base10) + 1) - 1;
            } else{
                now += base10 - 1;
            }
            out_i += base;
        }
        
        cout << now << endl;
        // cout << endl;
    }
}
