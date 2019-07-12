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

int main(){

}